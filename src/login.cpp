
#include "stdafx.h"

void EQNet_SetLoginServer(EQNet* net, const char* ip, uint16_t port)
{
	recordAddress(net->addressLogin, ip, port);
}

int EQNet_LoginToServerSelect(EQNet* net, const char* username, const char* password)
{
	if (net->mode != MODE_LOGIN)
		return false;

	if (net->credentials)
		EQNet_Free(net->credentials);

	// encrypt username and password
	size_t len = strlen(username) + strlen(password) + 2; // include null terminators
	char buf[128];
	memset(buf, 0, sizeof(buf));

	snprintf(buf, 128, "%s", username);
	size_t clen = strlen(username) + 1;
	if (clen >= 128)
		return false;
	snprintf(buf + clen, 128 - clen, "%s", password);

	net->credentials = EQNet_Encrypt(buf, &len);
	net->credentialsLen = len;

	if (net->credentials == nullptr)
	{
		setFatalErrorMessage(net, "Encryption failed");
		return false;
	}

	net->connection->setAddress(net->addressLogin);
	net->connection->connect();
	net->connection->sendSessionRequest();
	net->connection->resetTimeout();
	return true;
}

EQNet_Server* copyServer(const EQNet_Server*);

int EQNet_LoginToWorld(EQNet* net, const EQNet_Server* server)
{
	if (net->mode != MODE_SERVER_SELECT)
		return false;

	net->selectedServer = copyServer(server);

	// inform the login server of our selection
	Packet* packet = new Packet(nullptr, 14, OP_PlayEverquestRequest);
	Login_PlayRequest* pr = (Login_PlayRequest*)packet->getDataBuffer();
	pr->sequence = 5;
	pr->serverRuntimeID = server->runtimeId;

	packet->queue(net);
	return true;
}

const EQNet_Server* EQNet_GetServerList(EQNet* net, int* count)
{
	if (count)
		*count = net->serverListCount;
	return net->serverList;
}

EQNet_Server* copyServer(const EQNet_Server* src)
{
	EQNet_Server* copy = new EQNet_Server;
	memset(copy, 0, sizeof(EQNet_Server));

	auto copyStr = [](const char* str)
	{
		size_t len = strlen(str) + 1;
		char* copyStr = new char[len];
		memcpy(copyStr, str, len);
		return copyStr;
	};

	copy->ip = copyStr(src->ip);
	copy->runtimeId = src->runtimeId;
	return copy;
}

void freeServer(EQNet_Server* s)
{
	if (s->ip)
		delete[] s->ip;
	if (s->name)
		delete[] s->name;
	if (s->language)
		delete[] s->language;
	if (s->region)
		delete[] s->region;
}

void freeServerList(EQNet* net)
{
	if (net->serverList == nullptr)
		return;

	for (int i = 0; i < net->serverListCount; ++i)
	{
		freeServer(&net->serverList[i]);
	}

	delete[] net->serverList;
	net->serverList = nullptr;
}

int EQNet_ServerIsUp(EQNet* net, const EQNet_Server* server)
{
	(void)net;
	return server->status == 0 || server->status == 2;
}

int EQNet_ServerIsLocked(EQNet* net, const EQNet_Server* server)
{
	(void)net;
	return server->status >= 4;
}
