
#ifndef _EQNET_PACKETS_H_
#define _EQNET_PACKETS_H_

#include <stdint.h>

/*
** Packet structs
*/

typedef uint16_t EQNet_Id;

#pragma pack(1)

typedef struct EQNetPacket_Buff {
	uint32_t spellId;
	uint32_t slot;
	EQNet_Id casterId;
	uint8_t casterLevel;
	uint32_t duration;
	float instrumentModifier;
	uint32_t counters;
} EQNetPacket_Buff;

typedef struct EQNetPacket_BindPoint {
	uint32_t zoneId;
	float x, y, z, heading;
} EQNetPacket_BindPoint;

typedef struct EQNetPacket_AA {
	uint32_t id;
	uint32_t value;
	uint32_t charges;
} EQNetPacket_AA;

typedef struct EQNetPacket_BandolierItem {
	const char* name;
	uint32_t id;
	int32_t icon;
} EQNetPacket_BandolierItem;

typedef struct EQNetPacket_Bandolier {
	const char* name;
	EQNetPacket_BandolierItem items[EQNET_BANDOLIER_ITEMS_COUNT];
} EQNetPacket_Bandolier;

typedef struct EQNetPacket_PlayerProfile {
	char name[64];
	char surname[32];
	uint8_t charClass;
	uint32_t race;
	uint8_t gender;
	uint8_t level;
	uint32_t currentHp;
	uint32_t currentMana;
	uint32_t currentEndurance;
	uint32_t STR, DEX, AGI, STA, WIS, INT, CHA;
	uint16_t zoneId;
	uint16_t instanceId;
	float x, y, z, heading;
	EQNetPacket_BindPoint bindPoints[EQNET_BIND_POINT_COUNT];
	uint8_t isGM, isPvP;
	uint32_t guildId;
	uint8_t guildRank;
	uint64_t experience;
	uint32_t experienceAA;
	uint32_t deity;
	uint32_t intoxication;
	uint32_t equipMaterials[EQNET_EQUIP_MATERIAL_COUNT];
	struct {
		uint32_t color;
		uint32_t color2;
	} equipMaterialTints[EQNET_EQUIP_TINT_COUNT];
	uint32_t skills[EQNET_SKILL_COUNT];
	uint32_t disciplines[EQNET_DISCIPLINE_COUNT];
	uint32_t recastTimes[20];
	uint32_t spellbook[EQNET_SPELLBOOK_COUNT];
	uint32_t memmedSpells[EQNET_MEMSPELL_COUNT];
	EQNetPacket_Buff buffs[EQNET_BUFF_COUNT];
	uint8_t hairColor;
	uint8_t beardColor;
	uint8_t eyeColor1;
	uint8_t eyeColor2;
	uint8_t hairstyle;
	uint8_t beard;
	uint8_t face;
	uint32_t drakkinHeritage;
	uint32_t drakkinTattoo;
	uint32_t drakkinDetails;
	uint32_t trainingPoints; // unspent class guild master training points
	uint32_t platinum, gold, silver, copper;
	uint32_t cursorPlatinum, cursorGold, cursorSilver, cursorCopper;
	uint32_t bankPlatinum, bankGold, bankSilver, bankCopper;
	uint32_t sharedPlatinum;
	uint32_t hunger, thirst;
	uint32_t spentAApoints;
	uint32_t availableAApoints;
	EQNetPacket_AA AAs[EQNET_AA_COUNT];
	uint32_t radiantCrystals, totalRadiantCrystals;
	uint32_t ebonCrystals, totalEbonCrystals;
	uint32_t ldonPointsGuk, ldonPointsMir, ldonPointsMmc, ldonPointsRuj, ldonPointsTak;
	uint32_t ldonPointsAvailable;
	uint8_t leadershipActive;
	double groupLeadershipExp, raidLeadershipExp;
	uint32_t groupLeadershipPoints, raidLeadershipPoints;
	uint32_t leadershipAAs[EQNET_TOTAL_LEADERSHIP_COUNT];
	EQNetPacket_Bandolier bandolier[EQNET_BANDOLIERS_COUNT];
	EQNetPacket_BandolierItem potionBelt[EQNET_POTION_BELT_ITEM_COUNT];
	uint32_t creationTime;
	uint32_t lastLoginTime;
	uint32_t minutesPlayed;
	uint32_t entitledTime;
	uint8_t languages[EQNET_LANGUAGE_COUNT];
	uint8_t showHelm;
	uint32_t restTimer;
	uint32_t tributePoints, totalTributePoints;
	struct {
		uint32_t id;
		uint32_t tier;
	} tributes[EQNET_TRIBUTE_COUNT];
	// pvp
} EQNetPacket_PlayerProfile;

typedef struct EQNetPacket_Spawn {
	EQNet_Id mobId;
	EQNet_Id ownerId;
	uint32_t gender : 2;
	uint32_t isNpc : 1;
	uint32_t isCorpse : 1;
	uint32_t isPet : 1;
	uint32_t isInvis : 1;
	uint32_t isGM : 1;
	uint32_t isAnonymous : 1;
	uint32_t isRoleplay : 1;
	uint32_t isAfk : 1;
	uint32_t isLfg : 1;
	uint32_t isLinkdead : 1;
	uint32_t isFindable : 1;
	uint32_t isGuildOfficer : 1;
	uint32_t isGuildLeader : 1;
	uint32_t isSneaking : 1;
	uint32_t showHelm : 1;
	uint32_t isTrader : 1;
	uint32_t isTargetable : 1;
	uint32_t isTargetableWithHotkey : 1;
	uint32_t showName : 1;
	uint32_t hasTitle : 1;
	uint32_t hasSuffix : 1;
	uint32_t isMercenary : 1;
	uint8_t level;
	uint8_t charClass;
	uint32_t race;
	uint32_t deity;
	uint8_t hpPercent;
	char name[64];
	char surname[32];
	char title[32];
	char suffix[32];
	float size;
	float walkspeed;
	float runspeed;
	float x, y, z, heading;
	float deltaX, deltaY, deltaZ, deltaHeading;
	int32_t animation;
	uint8_t helm;
	uint8_t standState;
	uint8_t light;
	uint8_t flyMode;
	struct {
		uint32_t material;
		uint32_t eliteMaterial;
		uint32_t heroForgeModel;
		uint32_t material2;
	} equipMaterials[EQNET_EQUIP_MATERIAL_COUNT];
	uint32_t equipMaterialTints[EQNET_EQUIP_TINT_COUNT];
	uint32_t guildId;
	uint8_t guildRank;
	uint8_t hairColor;
	uint8_t beardColor;
	uint8_t eyeColor1;
	uint8_t eyeColor2;
	uint8_t hairstyle;
	uint8_t beard;
	uint8_t face;
	uint32_t drakkinHeritage;
	uint32_t drakkinTattoo;
	uint32_t drakkinDetails;
	uint32_t bodyType;
} EQNetPacket_Spawn;

typedef struct EQNetPacket_ZoneData {
	char shortName[32];
	char longName[278];
	uint16_t zoneId;
	uint16_t instanceId;
} EQNetPacket_ZoneData;

typedef struct EQNetPacket_HpUpdateExact {
	EQNet_Id mobId;
	int cur;
	int max;
} EQNetPacket_HpUpdateExact;

typedef struct EQNetPacket_HpUpdatePercent {
	EQNet_Id mobId;
	int8_t percent;
} EQNetPacket_HpUpdatePercent;

typedef struct EQNetPacket_TimeUpdate {
	uint8_t	hour;
	uint8_t	minute;
	uint8_t	day;
	uint8_t	month;
	uint32_t year;
} EQNetPacket_TimeUpdate;

typedef struct EQNetPacket_MoneyUpdate {
	int platinum;
	int gold;
	int silver;
	int copper;
} EQNetPacket_MoneyUpdate;

typedef struct EQNetPacket_Consider {
	EQNet_Id mobId;
	uint8_t factionCon;
	uint8_t levelCon;
	uint8_t pvpCon;
} EQNetPacket_Consider;

typedef struct EQNetPacket_ChatMessage {
	const char* senderName;
	EQNet_Id targetId;
	uint16_t channel; // make enum
	uint16_t color; // make enum
	uint32_t language;
	uint32_t len;
	const char* msg;
} EQNetPacket_ChatMessage;

typedef struct EQNetPacket_ChatMessageEQStr {
	uint16_t channel;
	uint16_t color;
	uint32_t strId;
	struct {
		uint32_t len;
		const char* str;
	} strings[9]; // max number of format strings
} EQNetPacket_ChatMessageEQStr;

#pragma pack()

/*
** Opcodes
*/

enum EQNet_OpCodes
{
	EQNET_OP_NONE,
	EQNET_OP_MessageOfTheDay,
	EQNET_OP_DeleteCharacter,
	EQNET_OP_CharacterCreate,
	EQNET_OP_RandomNameGenerator,
	EQNET_OP_ApproveName,
	EQNET_OP_WorldComplete,
	EQNET_OP_WorldClientReady,
	EQNET_OP_CharacterStillInZone,
	EQNET_OP_WorldChecksumFailure,
	EQNET_OP_WorldLoginFailed,
	EQNET_OP_WorldLogout,
	EQNET_OP_WorldLevelTooHigh,
	EQNET_OP_CharInacessable,
	EQNET_OP_PlayerSpawn,
	EQNET_OP_ZoneData,
	EQNET_OP_CharInventory,
	EQNET_OP_SetServerFilter,
	EQNET_OP_LockoutTimerInfo,
	EQNET_OP_SendZonepoints,
	EQNET_OP_DoorSpawn,
	EQNET_OP_PlayerProfile,
	EQNET_OP_TimeUpdate,
	EQNET_OP_Logout,
	EQNET_OP_LogoutReply,
	EQNET_OP_PreLogoutReply,
	EQNET_OP_LevelUpdate,
	EQNET_OP_HungerThirstUpdate,
	EQNET_OP_Petition,
	EQNET_OP_PetitionQue,
	EQNET_OP_PetitionDelete,
	EQNET_OP_ZoneGuildList,
	EQNET_OP_GetGuildMOTD,
	EQNET_OP_GetGuildMOTDReply,
	EQNET_OP_GuildMemberList,
	EQNET_OP_GuildMemberUpdate,
	EQNET_OP_GuildRemove,
	EQNET_OP_GuildPeace,
	EQNET_OP_GuildWar,
	EQNET_OP_GuildLeader,
	EQNET_OP_GuildDemote,
	EQNET_OP_GuildMOTD,
	EQNET_OP_SetGuildMOTD,
	EQNET_OP_GuildInvite,
	EQNET_OP_GuildPublicNote,
	EQNET_OP_GuildDelete,
	EQNET_OP_GuildInviteAccept,
	EQNET_OP_GuildManageBanker,
	EQNET_OP_GuildBank,
	EQNET_OP_SetGuildRank,
	EQNET_OP_LFGuild,
	EQNET_OP_GMServers,
	EQNET_OP_GMBecomeNPC,
	EQNET_OP_GMZoneRequest,
	EQNET_OP_GMSearchCorpse,
	EQNET_OP_GMHideMe,
	EQNET_OP_GMGoto,
	EQNET_OP_GMDelCorpse,
	EQNET_OP_GMApproval,
	EQNET_OP_GMToggle,
	EQNET_OP_GMZoneRequest2,
	EQNET_OP_GMSummon,
	EQNET_OP_GMEmoteZone,
	EQNET_OP_GMEmoteWorld,
	EQNET_OP_GMFind,
	EQNET_OP_GMKick,
	EQNET_OP_GMTraining,
	EQNET_OP_GMEndTraining,
	EQNET_OP_GMTrainSkill,
	EQNET_OP_Animation,
	EQNET_OP_Stun,
	EQNET_OP_MoneyUpdate,
	EQNET_OP_SetExperience,
	EQNET_OP_IncreaseStats,
	EQNET_OP_CrashDump,
	EQNET_OP_ReadBook,
	EQNET_OP_Dye,
	EQNET_OP_Consume,
	EQNET_OP_InspectRequest,
	EQNET_OP_InspectAnswer,
	EQNET_OP_BeginCast,
	EQNET_OP_ColoredText,
	EQNET_OP_Consent,
	EQNET_OP_ConsentDeny,
	EQNET_OP_ConsentResponse,
	EQNET_OP_LFGCommand,
	EQNET_OP_LFGGetMatchesRequest,
	EQNET_OP_LFGAppearance,
	EQNET_OP_LFGGetMatchesResponse,
	EQNET_OP_LootItem,
	EQNET_OP_Bug,
	EQNET_OP_BoardBoat,
	EQNET_OP_Save,
	EQNET_OP_Camp,
	EQNET_OP_EndLootRequest,
	EQNET_OP_MemorizeSpell,
	EQNET_OP_SwapSpell,
	EQNET_OP_CastSpell,
	EQNET_OP_DeleteSpell,
	EQNET_OP_LoadSpellSet,
	EQNET_OP_Consider,
	EQNET_OP_Emote,
	EQNET_OP_PetCommands,
	EQNET_OP_PetBuffWindow,
	EQNET_OP_SpawnAppearance,
	EQNET_OP_Despawn,
	EQNET_OP_ChatMessageEQStr,
	EQNET_OP_WhoAllRequest,
	EQNET_OP_WhoAllResponse,
	EQNET_OP_SetRunMode,
	EQNET_OP_SaveOnZoneReq,
	EQNET_OP_Buff,
	EQNET_OP_LootComplete,
	EQNET_OP_EnvDamage,
	EQNET_OP_Split,
	EQNET_OP_Surname,
	EQNET_OP_ClearSurname,
	EQNET_OP_MoveItem,
	EQNET_OP_FaceChange,
	EQNET_OP_ItemPacket,
	EQNET_OP_ItemLinkResponse,
	EQNET_OP_ZoneChange,
	EQNET_OP_ItemLinkClick,
	EQNET_OP_BazaarSearch,
	EQNET_OP_Spawn,
	EQNET_OP_WearChange,
	EQNET_OP_Action,
	EQNET_OP_LeaveBoat,
	EQNET_OP_WeatherUpdate,
	EQNET_OP_LFPGetMatchesRequest,
	EQNET_OP_Illusion,
	EQNET_OP_TargetsTarget,
	EQNET_OP_GMKill,
	EQNET_OP_MoneyOnCorpse,
	EQNET_OP_ClickDoor,
	EQNET_OP_MoveDoor,
	EQNET_OP_RemoveAllDoors,
	EQNET_OP_LootRequest,
	EQNET_OP_YellForHelp,
	EQNET_OP_ManaEnduranceUpdate,
	EQNET_OP_LFPCommand,
	EQNET_OP_RandomReply,
	EQNET_OP_DenyResponse,
	EQNET_OP_ConsiderCorpse,
	EQNET_OP_CorpseDrag,
	EQNET_OP_CorpseDrop,
	EQNET_OP_ConfirmDelete,
	EQNET_OP_HpUpdatePercent,
	EQNET_OP_SkillUpdate,
	EQNET_OP_RandomReq,
	EQNET_OP_ClientUpdate,
	EQNET_OP_Report,
	EQNET_OP_GroundSpawn,
	EQNET_OP_LFPGetMatchesResponse,
	EQNET_OP_Jump,
	EQNET_OP_ExperienceUpdate,
	EQNET_OP_Death,
	EQNET_OP_BecomeCorpse,
	EQNET_OP_GMLastName,
	EQNET_OP_InitialMobHealth,
	EQNET_OP_Mend,
	EQNET_OP_Feedback,
	EQNET_OP_TGB,
	EQNET_OP_InterruptCast,
	EQNET_OP_Damage,
	EQNET_OP_ChatMessage,
	EQNET_OP_LevelAppearance,
	EQNET_OP_Charm,
	EQNET_OP_Assist,
	EQNET_OP_AssistGroup,
	EQNET_OP_AugmentItem,
	EQNET_OP_DeleteItem,
	EQNET_OP_DeleteCharge,
	EQNET_OP_ControlBoat,
	EQNET_OP_FeignDeath,
	EQNET_OP_LDoNButton,
	EQNET_OP_MoveCoin,
	EQNET_OP_ZonePlayerToBind,
	EQNET_OP_Rewind,
	EQNET_OP_Translocate,
	EQNET_OP_Sacrifice,
	EQNET_OP_KeyRing,
	EQNET_OP_ApplyPoison,
	EQNET_OP_AugmentInfo,
	EQNET_OP_SetStartCity,
	EQNET_OP_SpellEffect,
	EQNET_OP_CrystalReclaim,
	EQNET_OP_CrystalCreate,
	EQNET_OP_Marquee,
	EQNET_OP_DzQuit,
	EQNET_OP_DzListTimers,
	EQNET_OP_DzAddPlayer,
	EQNET_OP_DzRemovePlayer,
	EQNET_OP_DzSwapPlayer,
	EQNET_OP_DzMakeLeader,
	EQNET_OP_DzPlayerList,
	EQNET_OP_DzJoinExpeditionConfirm,
	EQNET_OP_DzJoinExpeditionReply,
	EQNET_OP_DzExpeditionInfo,
	EQNET_OP_DzMemberStatus,
	EQNET_OP_DzLeaderStatus,
	EQNET_OP_DzExpeditionEndsWarning,
	EQNET_OP_DzExpeditionList,
	EQNET_OP_DzMemberList,
	EQNET_OP_DzCompass,
	EQNET_OP_DzChooseZone,
	EQNET_OP_TraderDelItem,
	EQNET_OP_BecomeTrader,
	EQNET_OP_TraderShop,
	EQNET_OP_Trader,
	EQNET_OP_TraderBuy,
	EQNET_OP_Barter,
	EQNET_OP_TradeRequest,
	EQNET_OP_TradeAcceptClick,
	EQNET_OP_TradeRequestAck,
	EQNET_OP_TradeCoins,
	EQNET_OP_FinishTrade,
	EQNET_OP_CancelTrade,
	EQNET_OP_TradeBusy,
	EQNET_OP_ShopPlayerSell,
	EQNET_OP_ShopEnd,
	EQNET_OP_ShopEndConfirm,
	EQNET_OP_ShopPlayerBuy,
	EQNET_OP_ShopRequest,
	EQNET_OP_ShopDelItem,
	EQNET_OP_ClickObject,
	EQNET_OP_ClickObjectAction,
	EQNET_OP_ClearObject,
	EQNET_OP_RecipeDetails,
	EQNET_OP_RecipesFavorite,
	EQNET_OP_RecipesSearch,
	EQNET_OP_RecipeReply,
	EQNET_OP_RecipeAutoCombine,
	EQNET_OP_TradeSkillCombine,
	EQNET_OP_RequestDuel,
	EQNET_OP_DuelResponse,
	EQNET_OP_DuelResponse2,
	EQNET_OP_RezzComplete,
	EQNET_OP_RezzRequest,
	EQNET_OP_RezzAnswer,
	EQNET_OP_SafeFallSuccess,
	EQNET_OP_Shielding,
	EQNET_OP_TestBuff,
	EQNET_OP_Track,
	EQNET_OP_TrackTarget,
	EQNET_OP_TrackUnknown,
	EQNET_OP_OpenTributeMaster,
	EQNET_OP_OpenTributeReply,
	EQNET_OP_SelectTribute,
	EQNET_OP_TributeItem,
	EQNET_OP_TributeMoney,
	EQNET_OP_TributeNPC,
	EQNET_OP_TributeToggle,
	EQNET_OP_TributeTimer,
	EQNET_OP_TributePointUpdate,
	EQNET_OP_TributeUpdate,
	EQNET_OP_GuildTributeInfo,
	EQNET_OP_TributeInfo,
	EQNET_OP_SendGuildTributes,
	EQNET_OP_SendTributes,
	EQNET_OP_LeaveAdventure,
	EQNET_OP_AdventureFinish,
	EQNET_OP_AdventureInfoRequest,
	EQNET_OP_AdventureInfo,
	EQNET_OP_AdventureRequest,
	EQNET_OP_AdventureDetails,
	EQNET_OP_AdventureData,
	EQNET_OP_AdventureUpdate,
	EQNET_OP_AdventureMerchantRequest,
	EQNET_OP_AdventureMerchantResponse,
	EQNET_OP_AdventureMerchantPurchase,
	EQNET_OP_AdventureMerchantSell,
	EQNET_OP_AdventurePointsUpdate,
	EQNET_OP_AdventureStatsRequest,
	EQNET_OP_AdventureStatsReply,
	EQNET_OP_AdventureLeaderboardRequest,
	EQNET_OP_AdventureLeaderboardReply,
	EQNET_OP_GroupDisband,
	EQNET_OP_GroupInvite,
	EQNET_OP_GroupFollow,
	EQNET_OP_GroupUpdate,
	EQNET_OP_GroupCancelInvite,
	EQNET_OP_GroupInvite2,
	EQNET_OP_RaidJoin,
	EQNET_OP_RaidInvite,
	EQNET_OP_RaidUpdate,
	EQNET_OP_InspectBuffs,
	EQNET_OP_DisciplineUpdate,
	EQNET_OP_DisciplineTimer,
	EQNET_OP_FindPersonRequest,
	EQNET_OP_FindPersonReply,
	EQNET_OP_Sound,
	EQNET_OP_MobRename,
	EQNET_OP_BankerChange,
	EQNET_OP_PickPocket,
	EQNET_OP_Disarm,
	EQNET_OP_InstillDoubt,
	EQNET_OP_LDoNOpen,
	EQNET_OP_TaskActivityComplete,
	EQNET_OP_CompletedTasks,
	EQNET_OP_TaskDescription,
	EQNET_OP_TaskActivity,
	EQNET_OP_TaskMemberList,
	EQNET_OP_OpenNewTasksWindow,
	EQNET_OP_AcceptNewTask,
	EQNET_OP_TaskHistoryRequest,
	EQNET_OP_TaskHistoryReply,
	EQNET_OP_CancelTask,
	EQNET_OP_TaskMemberInvite,
	EQNET_OP_TaskMemberInviteResponse,
	EQNET_OP_TaskMemberChange,
	EQNET_OP_TaskMakeLeader,
	EQNET_OP_TaskAddPlayer,
	EQNET_OP_TaskRemovePlayer,
	EQNET_OP_TaskPlayerList,
	EQNET_OP_TaskQuit,
	EQNET_OP_RequestClientZoneChange,
	EQNET_OP_SendAATable,
	EQNET_OP_UpdateAA,
	EQNET_OP_RespondAA,
	EQNET_OP_SendAAStats,
	EQNET_OP_AAAction,
	EQNET_OP_AAExpUpdate,
	EQNET_OP_PurchaseLeadershipAA,
	EQNET_OP_UpdateLeadershipAA,
	EQNET_OP_LeadershipExpUpdate,
	EQNET_OP_LeadershipExpToggle,
	EQNET_OP_MarkNPC,
	EQNET_OP_ClearNPCMarks,
	EQNET_OP_DoGroupLeadershipAbility,
	EQNET_OP_DelegateAbility,
	EQNET_OP_SetGroupTarget,
	EQNET_OP_PlayMP3,
	EQNET_OP_FriendsWho,
	EQNET_OP_MoveLogRequest,
	EQNET_OP_ReclaimCrystals,
	EQNET_OP_CrystalCountUpdate,
	EQNET_OP_CustomTitles,
	EQNET_OP_NewTitlesAvailable,
	EQNET_OP_RequestTitles,
	EQNET_OP_SendTitleList,
	EQNET_OP_SetTitle,
	EQNET_OP_SetTitleReply,
	EQNET_OP_Bandolier,
	EQNET_OP_PotionBelt,
	EQNET_OP_OnLevelMessage,
	EQNET_OP_PopupResponse,
	EQNET_OP_SlashAdventure,
	EQNET_OP_VetRewardsAvaliable,
	EQNET_OP_VetClaimRequest,
	EQNET_OP_VetClaimReply,
	EQNET_OP_BecomePVPPrompt,
	EQNET_OP_PVPStats,
	EQNET_OP_PVPLeaderBoardRequest,
	EQNET_OP_PVPLeaderBoardReply,
	EQNET_OP_PVPLeaderBoardDetailsRequest,
	EQNET_OP_PVPLeaderBoardDetailsReply,
	EQNET_OP_PickLockSuccess,
	EQNET_OP_WeaponEquip1,
	EQNET_OP_PlayerStateAdd,
	EQNET_OP_PlayerStateRemove,
	EQNET_OP_VoiceMacroIn,
	EQNET_OP_VoiceMacroOut,
	EQNET_OP_CameraEffect,
	EQNET_OP_AnnoyingZoneUnknown,
	EQNET_OP_SomeItemPacketMaybe,
	EQNET_OP_QueryResponseThing,
	EQNET_OP_FloatListThing,
	EQNET_OP_HpUpdateExact,
	EQNET_OP_SendSpellChecksum,
	EQNET_OP_SendSkillCapsChecksum,
	EQNET_OP_CharacterCreateRequest,
	EQNET_OP_WorldUnknown001,
	EQNET_OP_ClearAA,
	EQNET_OP_ClearLeadershipAbilities,
	EQNET_OP_WorldObjectsSent,
	EQNET_OP_BlockedBuffs,
	EQNET_OP_RemoveBlockedBuffs,
	EQNET_OP_ClearBlockedBuffs,
	EQNET_OP_GuildList,
	EQNET_OP_GuildUpdateURLAndChannel,
	EQNET_OP_GMNameChange,
	EQNET_OP_Action2,
	EQNET_OP_GMTrainSkillConfirm,
	EQNET_OP_PositionUpdate,
	EQNET_OP_MarkRaidNPC,
	EQNET_OP_ClearRaidNPCMarks,
	EQNET_OP_RestState,
	EQNET_OP_RespawnWindow,
	EQNET_OP_AltCurrency,
	EQNET_OP_AltCurrencyMerchantRequest,
	EQNET_OP_AltCurrencyMerchantReply,
	EQNET_OP_AltCurrencyPurchase,
	EQNET_OP_AltCurrencySell,
	EQNET_OP_AltCurrencySellSelection,
	EQNET_OP_AltCurrencyReclaim,
	EQNET_OP_RemoveNimbusEffect,
	EQNET_OP_InspectMessageUpdate,
	EQNET_OP_OpenInventory,
	EQNET_OP_OpenContainer,
	EQNET_OP_Untargetable,
	EQNET_OP_TradeMoneyUpdate,
	EQNET_OP_FinishWindow,
	EQNET_OP_FinishWindow2,
	EQNET_OP_ItemVerifyRequest,
	EQNET_OP_ItemVerifyReply,
	EQNET_OP_OpenGuildTributeMaster,
	EQNET_OP_GroupAcknowledge,
	EQNET_OP_CancelInvite,
	EQNET_OP_GroupFollow2,
	EQNET_OP_GroupMentor,
	EQNET_OP_AvaliableTask,
	EQNET_OP_LoginUnknown1,
	EQNET_OP_LoginUnknown2,
	EQNET_OP_ItemViewUnknown,
	EQNET_OP_ItemRecastDelay,
	EQNET_OP_GuildStatus,
	EQNET_OP_HideCorpse,
	EQNET_OP_TargetBuffs,
	EQNET_OP_BuffRemoveRequest,
	EQNET_OP_DestructableRelated,
	EQNET_OP_GroupLeadershipAAUpdate,
	EQNET_OP_SendFindableNPCs,
	EQNET_OP_ShroudProgress,
	EQNET_OP_SpawnPositionUpdate,
	EQNET_OP_ManaUpdate,
	EQNET_OP_EnduranceUpdate,
	EQNET_OP_MobManaUpdate,
	EQNET_OP_MobEnduranceUpdate,
	EQNET_OP_GroupUpdateB,
	EQNET_OP_GroupDelete,
	EQNET_OP_GroupDisbandYou,
	EQNET_OP_GroupDisbandOther,
	EQNET_OP_GroupLeaderChange,
	EQNET_OP_GroupRoles,
	EQNET_OP_GroupMakeLeader,
	EQNET_OP_Shroud,
	EQNET_OP_ShroudRemove,
	EQNET_OP_ShroudUnknown1,
	EQNET_OP_ShroudUnknown2,
	EQNET_OP_ShroudSelectionWindow,
	EQNET_OP_ShroudRequestStats,
	EQNET_OP_ShroudRespondStats,
	EQNET_OP_ShroudSelect,
	EQNET_OP_MercenaryDataRequest,
	EQNET_OP_MercenaryDataResponse,
	EQNET_OP_MercenaryHire,
	EQNET_OP_MercenaryAssign,
	EQNET_OP_MercenaryTimer,
	EQNET_OP_MercenaryUnknown1,
	EQNET_OP_MercenaryDataUpdate,
	EQNET_OP_MercenaryCommand,
	EQNET_OP_MercenarySuspendRequest,
	EQNET_OP_MercenarySuspendResponse,
	EQNET_OP_MercenaryUnsuspendResponse,
	EQNET_OP_MercenaryDataUpdateRequest,
	EQNET_OP_MercenaryDismiss,
	EQNET_OP_MercenaryTimerRequest,
	EQNET_OP_ChangeSize,
	EQNET_OP_GuildCreate,
	EQNET_OP_PetHoTT,
	EQNET_OP_XTargetResponse,
	EQNET_OP_XTargetRequest,
	EQNET_OP_XTargetAutoAddHaters,
	EQNET_OP_BuffCreate,
	EQNET_OP_NPCMoveUpdate,
	EQNET_OP_Weblink,
	EQNET_OP_ShroudSelectCancel,
	EQNET_OP_ShroudProgress2,
	EQNET_OP_ShieldGroup,
	EQNET_OP_SendMaxCharacters,
	EQNET_OP_SendMembership,
	EQNET_OP_SendMembershipDetails,
	EQNET_OP_GuildPromote,
	EQNET_OP_ItemPreview,
	EQNET_OP_MAX_COUNT
};

#endif/*_EQNET_PACKETS_H_*/
