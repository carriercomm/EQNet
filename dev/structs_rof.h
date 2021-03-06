
#ifndef _EQNET_STRUCTS_ROF_H_
#define _EQNET_STRUCTS_ROF_H_

#include <cstdint>

namespace RoF
{

static const size_t BANDOLIERS_SIZE = 20;		// number of bandolier instances
static const size_t BANDOLIER_ITEM_COUNT = 4;	// number of equipment slots in bandolier instance
static const size_t POTION_BELT_ITEM_COUNT = 5;
static const uint32_t PACKET_SKILL_ARRAY_SIZE = 100;

/*
** Compiler override to ensure
** byte aligned structures
*/
#pragma pack(1)

struct LoginInfo_Struct {
	/*000*/	char	login_info[64];
	/*064*/	uint8_t	unknown064[124];
	/*188*/	uint8_t	zoning;			// 01 if zoning, 00 if not
	/*189*/	uint8_t	unknown189[275];
	/*488*/
};

struct EnterWorld_Struct {
	/*000*/	char	name[64];
	/*064*/	uint32_t	tutorial;		// 01 on "Enter Tutorial", 00 if not
	/*068*/	uint32_t	return_home;		// 01 on "Return Home", 00 if not
};

//New For SoF
struct WorldObjectsSent_Struct {
};

// New for RoF - Size: 12
struct ItemSlotStruct {
	/*000*/	int16_t	SlotType;	// Worn and Normal inventory = 0, Bank = 1, Shared Bank = 2, Delete Item = -1
	/*002*/	int16_t	Unknown02;
	/*004*/	int16_t	MainSlot;
	/*006*/	int16_t	SubSlot;
	/*008*/	int16_t	AugSlot;	// Guessing - Seen 0xffff
	/*010*/	int16_t	Unknown01;	// Normally 0 - Seen 13262 when deleting an item, but didn't match item ID
	/*012*/
};

// New for RoF - Used for Merchant_Purchase_Struct
// Can't sellfrom other than main inventory so Slot Type is not needed.
struct MainInvItemSlotStruct {
	/*000*/	int16_t	MainSlot;
	/*002*/	int16_t	SubSlot;
	/*004*/	int16_t	AugSlot;
	/*006*/	int16_t	Unknown01;
	/*008*/
};

/* Name Approval Struct */
/* Len: */
/* Opcode: 0x8B20*/
struct NameApproval
{
	char name[64];
	uint32_t race;
	uint32_t class_;
	uint32_t deity;
};

/*
** Entity identification struct
** Size: 4 bytes
** OPCodes: OP_DeleteSpawn, OP_Assist
*/
struct EntityId_Struct
{
	/*00*/	uint32_t	entity_id;
	/*04*/
};

struct Duel_Struct
{
	uint32_t duel_initiator;
	uint32_t duel_target;
};

struct DuelResponse_Struct
{
	uint32_t target_id;
	uint32_t entity_id;
	uint32_t unknown;
};

//Adventure stuff,not a net one,just one for our use
static const uint32_t ADVENTURE_COLLECT = 0;
static const uint32_t ADVENTURE_MASSKILL = 1;
static const uint32_t ADVENTURE_NAMED = 2;
static const uint32_t ADVENTURE_RESCUE = 3;

static const uint32_t BUFF_COUNT = 42;			// was 25
static const uint32_t BLOCKED_BUFF_COUNT = 30;		// was 20

static const uint32_t MAX_PLAYER_TRIBUTES = 5;
static const uint32_t MAX_TRIBUTE_TIERS = 10;
static const uint32_t TRIBUTE_NONE = 0xFFFFFFFF;

static const uint32_t MAX_GROUP_LEADERSHIP_AA_ARRAY = 16;
static const uint32_t MAX_RAID_LEADERSHIP_AA_ARRAY = 16;
static const uint32_t MAX_LEADERSHIP_AA_ARRAY = (MAX_GROUP_LEADERSHIP_AA_ARRAY + MAX_RAID_LEADERSHIP_AA_ARRAY);

static const uint32_t MAX_NUMBER_GUILDS = 1500;

// Used primarily in the Player Profile:
static const uint32_t MAX_PP_LANGUAGE = 32;	// was 25
static const uint32_t MAX_PP_SPELLBOOK = 720;	// was 480
static const uint32_t MAX_PP_MEMSPELL = 16;	// was 12
static const uint32_t MAX_PP_SKILL = PACKET_SKILL_ARRAY_SIZE;	// 100 - actual skills buffer size
static const uint32_t MAX_PP_AA_ARRAY = 300;
static const uint32_t MAX_PP_DISCIPLINES = 200;	// was 100
static const uint32_t MAX_GROUP_MEMBERS = 6;
static const uint32_t MAX_RECAST_TYPES = 20;

struct AdventureInfo {
	uint32_t QuestID;
	uint32_t NPCID;
	bool in_use;
	uint32_t status;
	bool ShowCompass;
	uint32_t Objetive;// can be item to collect,mobs to kill,boss to kill and someone to rescue.
	uint32_t ObjetiveValue;// number of items,or number of needed mob kills.
	char text[512];
	uint8_t type;
	uint32_t minutes;
	uint32_t points;
	float x;
	float y;
	uint32_t zoneid;
	uint32_t zonedungeonid;
};
///////////////////////////////////////////////////////////////////////////////


/*
** Color_Struct
** Size: 4 bytes
** Used for convenience
** Merth: Gave struct a name so gcc 2.96 would compile
**
*/
struct Color_Struct
{
	union {
		struct {
			uint8_t Blue;
			uint8_t Green;
			uint8_t Red;
			uint8_t UseTint;	// if there's a tint this is FF
		} RGB;
		uint32_t Color;
	};
};

struct CharSelectEquip
{
	uint32_t Material;
	uint32_t Unknown1;
	uint32_t EliteMaterial;
	uint32_t HeroForgeModel;
	uint32_t Material2;
	Color_Struct Color;
};

struct CharacterSelectEntry_Struct
{
	/*0000*/	//char Name[1];				// Name null terminated
	/*0000*/	uint8_t Class;
	/*0000*/	uint32_t Race;
	/*0000*/	uint8_t Level;
	/*0000*/	uint8_t ShroudClass;
	/*0000*/	uint32_t ShroudRace;
	/*0000*/	uint16_t Zone;
	/*0000*/	uint16_t Instance;
	/*0000*/	uint8_t Gender;
	/*0000*/	uint8_t Face;
	/*0000*/	CharSelectEquip	Equip[9];
	/*0000*/	uint8_t Unknown15;			// Seen FF
	/*0000*/	uint8_t Unknown19;			// Seen FF
	/*0000*/	uint32_t DrakkinTattoo;
	/*0000*/	uint32_t DrakkinDetails;
	/*0000*/	uint32_t Deity;
	/*0000*/	uint32_t PrimaryIDFile;
	/*0000*/	uint32_t SecondaryIDFile;
	/*0000*/	uint8_t HairColor;
	/*0000*/	uint8_t BeardColor;
	/*0000*/	uint8_t EyeColor1;
	/*0000*/	uint8_t EyeColor2;
	/*0000*/	uint8_t HairStyle;
	/*0000*/	uint8_t Beard;
	/*0000*/	uint8_t GoHome;				// Seen 0 for new char and 1 for existing
	/*0000*/	uint8_t Tutorial;				// Seen 1 for new char or 0 for existing
	/*0000*/	uint32_t DrakkinHeritage;
	/*0000*/	uint8_t Unknown1;				// Seen 0
	/*0000*/	uint8_t Enabled;				// Swapped position with 'GoHome' 02/23/2015
	/*0000*/	uint32_t LastLogin;
	/*0000*/	uint8_t Unknown2;				// Seen 0
};

/*
** Character Selection Struct
**
*/
struct CharacterSelect_Struct
{
	/*000*/	uint32_t CharCount;	//number of chars in this packet
};

/*
* Visible equiptment.
* Size: 20 Octets
*/
struct EquipStruct
{
	/*00*/ uint32_t Material;
	/*04*/ uint32_t Unknown1;
	/*08*/ uint32_t EliteMaterial;
	/*12*/ uint32_t HeroForgeModel;
	/*16*/ uint32_t Material2;	// Same as material?
	/*20*/
};


struct Membership_Entry_Struct
{
	/*000*/ uint32_t purchase_id;		// Seen 1, then increments 90287 to 90300
	/*004*/ uint32_t bitwise_entry;	// Seen 16 to 65536 - Skips 4096
	/*008*/
};

struct Membership_Setting_Struct
{
	/*000*/ uint32_t setting_index;	// 0, 1, or 2
	/*004*/ uint32_t setting_id;		// 0 to 21
	/*008*/ int32_t setting_value;	// All can be 0, 1, or -1
	/*012*/
};

struct Membership_Details_Struct
{
	/*0000*/ uint32_t membership_setting_count;	// Seen 66
	/*0016*/ Membership_Setting_Struct settings[66];
	/*0012*/ uint32_t race_entry_count;	// Seen 15
	/*1044*/ Membership_Entry_Struct membership_races[15];
	/*0012*/ uint32_t class_entry_count;	// Seen 15
	/*1044*/ Membership_Entry_Struct membership_classes[15];
	/*1044*/ uint32_t exit_url_length;	// Length of the exit_url string (0 for none)
	/*1048*/ //char exit_url[42];		// Upgrade to Silver or Gold Membership URL
	/*1048*/ uint32_t exit_url_length2;	// Length of the exit_url2 string (0 for none)
	/*0000*/ //char exit_url2[49];		// Upgrade to Gold Membership URL
};

struct Membership_Struct
{
	/*000*/ uint32_t membership;	// Seen 2 on Gold Account
	/*004*/ uint32_t races;	// Seen ff ff 01 00
	/*008*/ uint32_t classes;	// Seen ff ff 01 01
	/*012*/ uint32_t entrysize; // Seen 22
	/*016*/ int32_t entries[22]; // Most -1, 1, and 0 for Gold Status
	/*104*/
};


/*
** Generic Spawn Struct
** Length: 897 Octets
** Used in:
**   spawnZoneStruct
**   dbSpawnStruct
**   petStruct
**   newSpawnStruct
*/
/*
showeq -> eqemu
sed -e 's/_t//g' -e 's/seto_0xFF/set_to_0xFF/g'
*/

struct Spawn_Struct_Bitfields
{
	/*00*/	unsigned   gender : 2;		// Gender (0=male, 1=female, 2=monster)
	/*02*/	unsigned   ispet : 1;			// Guessed based on observing live spawns
	/*03*/	unsigned   afk : 1;			// 0=no, 1=afk
	/*04*/	unsigned   anon : 2;			// 0=normal, 1=anon, 2=roleplay
	/*06*/	unsigned   gm : 1;
	/*06*/	unsigned   sneak : 1;
	/*08*/	unsigned   lfg : 1;
	/*09*/	unsigned   unknown09 : 1;
	/*10*/	unsigned   invis : 1;			// May have invis & sneak the wrong way around ... not sure how to tell which is which
	/*11*/	unsigned   invis1 : 1;		// GM Invis?  Can only be seen with #gm on - same for the below
	/*12*/	unsigned   invis2 : 1;		// This one also make the NPC/PC invis
	/*13*/	unsigned   invis3 : 1;		// This one also make the NPC/PC invis
	/*14*/	unsigned   invis4 : 1;		// This one also make the NPC/PC invis
	/*15*/	unsigned   invis6 : 1;		// This one also make the NPC/PC invis
	/*16*/	unsigned   invis7 : 1;		// This one also make the NPC/PC invis
	/*17*/	unsigned   invis8 : 1;		// This one also make the NPC/PC invis
	/*18*/	unsigned   invis9 : 1;		// This one also make the NPC/PC invis
	/*19*/	unsigned   invis10 : 1;		// This one also make the NPC/PC invis
	/*20*/	unsigned   invis11 : 1;		// This one also make the NPC/PC invis
	/*21*/	unsigned   invis12 : 1;		// This one also make the NPC/PC invis
	/*22*/	unsigned   linkdead : 1;		// 1 Toggles LD on or off after name. Correct for RoF
	/*23*/	unsigned   showhelm : 1;
	/*24*/	unsigned   unknown24 : 1;		// Prefixes name with !
	/*25*/	unsigned   trader : 1;
	/*26*/	unsigned   unknown26 : 1;
	/*27*/	unsigned   targetable : 1;
	/*28*/	unsigned   targetable_with_hotkey : 1;
	/*29*/	unsigned   showname : 1;
	/*30*/	unsigned   unknown30 : 1;
	/*30*/	unsigned   untargetable : 1;	// Untargetable with mouse
	/*
	// Unknown in RoF
	unsigned   betabuffed:1;
	unsigned   buyer:1;
	unsigned   buyer:1;
	*/
};

struct Spawn_Struct_Position
{
	/*000*/	signed	padding0000 : 12;
	signed	y : 19;
	signed	padding0001 : 1;

	/*004*/	signed  deltaX : 13;      // change in x
	signed  deltaHeading : 10;// change in heading
	signed  padding0008 : 9;

	/*008*/	signed	deltaY : 13;
	signed	z : 19;

	/*012*/	signed	x : 19;
	signed  animation : 10;   // animation
	signed  padding0016 : 3;

	/*004*/	signed	heading : 12;
	signed	deltaZ : 13;      // change in z
	signed	padding0020 : 7;
};

/*
struct Spawn_Struct_Position
{
signed   padding0000:12; // ***Placeholder
signed   deltaX:13;      // change in x
signed   padding0005:7;  // ***Placeholder
signed   deltaHeading:10;// change in heading
signed   deltaY:13;      // change in y
signed   padding0006:9;  // ***Placeholder
signed   y:19;           // y coord
signed   animation:13;   // animation
unsigned heading:12;     // heading
signed   x:19;           // x coord
signed   padding0014:1;  // ***Placeholder
signed   z:19;           // z coord
signed   deltaZ:13;      // change in z
}; */

struct Spawn_Struct
{
	// Note this struct is not used as such, it is here for reference. As the struct is variable sized, the packets
	// are constructed in Live.cpp
	//
	/*0000*/ char     name[1];	//name[64];
	/*0000*/ //uint8_t     nullterm1; // hack to null terminate name
	/*0064*/ uint32_t spawnId;
	/*0068*/ uint8_t  level;
	/*0069*/ float    unknown1;
	/*0073*/ uint8_t  NPC;           // 0=player,1=npc,2=pc corpse,3=npc corpse
	Spawn_Struct_Bitfields	Bitfields;
	/*0000*/ uint8_t  otherData; // & 4 - has title, & 8 - has suffix, & 1 - it's a chest or untargetable
	/*0000*/ float unknown3;	// seen -1
	/*0000*/ float unknown4;
	/*0000*/ float size;
	/*0000*/ uint8_t  face;
	/*0000*/ float    walkspeed;
	/*0000*/ float    runspeed;
	/*0000*/ uint32_t race;
	/*0000*/ uint8_t  showname; // for body types - was charProperties
	/*0000*/ uint32_t bodytype;
	/*0000*/ //uint32_t bodytype2;      // this is only present if charProperties==2
	// are there more than two possible properties?
	/*0000*/ uint8_t  curHp;
	/*0000*/ uint8_t  haircolor;
	/*0000*/ uint8_t  beardcolor;
	/*0000*/ uint8_t  eyecolor1;
	/*0000*/ uint8_t  eyecolor2;
	/*0000*/ uint8_t  hairstyle;
	/*0000*/ uint8_t  beard;
	/*0000*/ uint32_t drakkin_heritage;
	/*0000*/ uint32_t drakkin_tattoo;
	/*0000*/ uint32_t drakkin_details;
	/*0000*/ uint8_t  statue;				// was holding
	/*0000*/ uint32_t deity;
	/*0000*/ uint32_t guildID;
	/*0000*/ uint32_t guildrank;			// 0=member, 1=officer, 2=leader, -1=not guilded
	/*0000*/ uint8_t  class_;
	/*0000*/ uint8_t  pvp;					// 0 = normal name color, 2 = PVP name color
	/*0000*/ uint8_t  StandState;			// stand state - 0x64 for normal animation
	/*0000*/ uint8_t  light;
	/*0000*/ uint8_t  flymode;
	/*0000*/ uint8_t  equip_chest2;
	/*0000*/ uint8_t  unknown9;
	/*0000*/ uint8_t  unknown10;
	/*0000*/ uint8_t  helm;
	/*0000*/ char     lastName[1];
	/*0000*/ //uint8_t     lastNameNull; //hack!
	/*0000*/ uint32_t aatitle;		// 0=none, 1=general, 2=archtype, 3=class was AARank
	/*0000*/ uint8_t  unknown12;
	/*0000*/ uint32_t petOwnerId;
	/*0000*/ uint8_t  unknown13;
	/*0000*/ uint32_t PlayerState;		// Stance 64 = normal 4 = aggressive 40 = stun/mezzed
	/*0000*/ uint32_t unknown15;
	/*0000*/ uint32_t unknown16;
	/*0000*/ uint32_t unknown17;
	/*0000*/ //uint8_t  unknownRoF3;
	/*0000*/ uint32_t unknown18;
	/*0000*/ uint32_t unknown19;
	Spawn_Struct_Position Position;
	/*0000*/ union
	{
		struct
		{
			/*0000*/ Color_Struct color_helmet;    // Color of helmet item
			/*0000*/ Color_Struct color_chest;     // Color of chest item
			/*0000*/ Color_Struct color_arms;      // Color of arms item
			/*0000*/ Color_Struct color_bracers;   // Color of bracers item
			/*0000*/ Color_Struct color_hands;     // Color of hands item
			/*0000*/ Color_Struct color_legs;      // Color of legs item
			/*0000*/ Color_Struct color_feet;      // Color of feet item
			/*0000*/ Color_Struct color_primary;   // Color of primary item
			/*0000*/ Color_Struct color_secondary; // Color of secondary item
		} equipment_colors;
		/*0000*/ Color_Struct colors[9]; // Array elements correspond to struct equipment_colors above
	};

	// skip these bytes if not a valid player race
	/*0000*/ union
	{
		struct
		{
			/*0000*/ EquipStruct equip_helmet;     // Equiptment: Helmet visual
			/*0000*/ EquipStruct equip_chest;      // Equiptment: Chest visual
			/*0000*/ EquipStruct equip_arms;       // Equiptment: Arms visual
			/*0000*/ EquipStruct equip_bracers;    // Equiptment: Wrist visual
			/*0000*/ EquipStruct equip_hands;      // Equiptment: Hands visual
			/*0000*/ EquipStruct equip_legs;       // Equiptment: Legs visual
			/*0000*/ EquipStruct equip_feet;       // Equiptment: Boots visual
			/*0000*/ EquipStruct equip_primary;    // Equiptment: Main visual
			/*0000*/ EquipStruct equip_secondary;  // Equiptment: Off visual
		} equip;
		/*0000*/ EquipStruct equipment[9];
	};

	/*0000*/ //char title[1];  // only read if(hasTitleOrSuffix & 4)
	/*0000*/ //char suffix[1]; // only read if(hasTitleOrSuffix & 8)
	char unknown20[8];
	uint8_t IsMercenary;	// If NPC == 1 and this == 1, then the NPC name is Orange.
	/*0000*/ char unknown21[55];
};


/*
** Generic Spawn Struct
** Fields from old struct not yet found:
**	uint8_t	traptype;	// 65 is disarmable trap, 66 and 67 are invis triggers/traps
**	uint8_t	is_pet;		// 0=no, 1=yes
**	uint8_t	afk;		// 0=no, 1=afk
**	uint8_t	is_npc;		// 0=no, 1=yes
**	uint8_t	max_hp;		// (name prolly wrong)takes on the value 100 for players, 100 or 110 for NPCs and 120 for PC corpses...
**	uint8_t	guildrank;	// 0=normal, 1=officer, 2=leader
**	uint8_t	eyecolor2;	//not sure, may be face
**	uint8_t	aaitle;		// 0=none, 1=general, 2=archtype, 3=class
*/

/*
** New Spawn
** Length: 176 Bytes
** OpCode: 4921
*/
struct NewSpawn_Struct
{
	struct Spawn_Struct spawn;	// Spawn Information
};


/*
** Client Zone Entry struct
** Length: 68 Octets
** OpCode: ZoneEntryCode (when direction == client)
*/
struct ClientZoneEntry_Struct {
	/*00*/ uint32_t	unknown00;	// ***Placeholder
	/*04*/ char	char_name[64];	// Player firstname [32]
	/*68*/ uint32_t	unknown68;
	/*72*/ uint32_t	unknown72;
};


/*
** Server Zone Entry Struct
** Length: 452 Bytes
** OPCodes: OP_ServerZoneEntry
**
*/
struct ServerZoneEntry_Struct //Adjusted from SEQ Everquest.h Struct
{
	struct NewSpawn_Struct player;
};


//New Zone Struct - Size: 948
struct NewZone_Struct {
	/*0000*/	char	char_name[64];			// Character Name
	/*0064*/	char	zone_short_name[32];	// Zone Short Name
	/*0096*/	char    unknown0096[96];
	/*0192*/	char	zone_long_name[278];	// Zone Long Name
	/*0470*/	uint8_t	ztype;					// Zone type (usually FF)
	/*0471*/	uint8_t	fog_red[4];				// Zone fog (red)
	/*0475*/	uint8_t	fog_green[4];				// Zone fog (green)
	/*0479*/	uint8_t	fog_blue[4];				// Zone fog (blue)
	/*0483*/	uint8_t	unknown323;
	/*0484*/	float	fog_minclip[4];
	/*0500*/	float	fog_maxclip[4];
	/*0516*/	float	gravity;
	/*0520*/	uint8_t	time_type;
	/*0521*/    uint8_t   rain_chance[4];
	/*0525*/    uint8_t   rain_duration[4];
	/*0529*/    uint8_t   snow_chance[4];
	/*0533*/    uint8_t   snow_duration[4];
	/*0537*/    uint8_t   unknown537[33];
	/*0570*/	uint8_t	sky;					// Sky Type
	/*0571*/	uint8_t	unknown571[13];			// ***Placeholder
	/*0584*/	float	zone_exp_multiplier;	// Experience Multiplier
	/*0588*/	float	safe_y;					// Zone Safe Y
	/*0592*/	float	safe_x;					// Zone Safe X
	/*0596*/	float	safe_z;					// Zone Safe Z
	/*0600*/	float	min_z;					// Guessed - NEW - Seen 0
	/*0604*/	float	max_z;					// Guessed
	/*0608*/	float	underworld;				// Underworld, min z (Not Sure?)
	/*0612*/	float	minclip;				// Minimum View Distance
	/*0616*/	float	maxclip;				// Maximum View DIstance
	/*0620*/	uint8_t	unknown620[84];		// ***Placeholder
	/*0704*/	char	zone_short_name2[96];	//zone file name? excludes instance number which can be in previous version.
	/*0800*/	int32_t	unknown800;	//seen -1
	/*0804*/	char	unknown804[40]; //
	/*0844*/	int32_t	unknown844;	//seen 600
	/*0848*/	int32_t	unknown848;
	/*0852*/	uint16_t	zone_id;
	/*0854*/	uint16_t	zone_instance;
	/*0856*/	char	unknown856[20];
	/*0876*/	uint32_t	SuspendBuffs;
	/*0880*/	uint32_t	unknown880;		// Seen 50
	/*0884*/	uint32_t	unknown884;		// Seen 10
	/*0888*/	uint8_t	unknown888;		// Seen 1
	/*0889*/	uint8_t	unknown889;		// Seen 0 (POK) or 1 (rujj)
	/*0890*/	uint8_t	unknown890;		// Seen 1
	/*0891*/	uint8_t	unknown891;		// Seen 0
	/*0892*/	uint8_t	unknown892;		// Seen 0
	/*0893*/	uint8_t	unknown893;		// Seen 0 - 00
	/*0894*/	uint8_t	fall_damage;	// 0 = Fall Damage on, 1 = Fall Damage off
	/*0895*/	uint8_t	unknown895;		// Seen 0 - 00
	/*0896*/	uint32_t	unknown896;		// Seen 180
	/*0900*/	uint32_t	unknown900;		// Seen 180
	/*0904*/	uint32_t	unknown904;		// Seen 180
	/*0908*/	uint32_t	unknown908;		// Seen 2
	/*0912*/	uint32_t	unknown912;		// Seen 2
	/*0916*/	float	FogDensity;		// Most zones have this set to 0.33 Blightfire had 0.16
	/*0920*/	uint32_t	unknown920;		// Seen 0
	/*0924*/	uint32_t	unknown924;		// Seen 0
	/*0928*/	uint32_t	unknown928;		// Seen 0
	/*0932*/	int32_t  unknown932;		// Seen -1
	/*0936*/	int32_t  unknown936;		// Seen -1
	/*0940*/	uint32_t  unknown940;		// Seen 0
	/*0944*/	float   unknown944;		// Seen 1.0
	/*0948*/
};


/*
** Memorize Spell Struct
** Length: 16 Bytes
**
*/
struct MemorizeSpell_Struct {
	uint32_t slot;     // Spot in the spell book/memorized slot
	uint32_t spell_id; // Spell id (200 or c8 is minor healing, etc)
	uint32_t scribing; // 1 if memorizing a spell, set to 0 if scribing to book, 2 if un-memming
	uint32_t unknown12;
};

/*
** Make Charmed Pet
** Length: 12 Bytes
**
*/
struct Charm_Struct {
	/*00*/	uint32_t	owner_id;
	/*04*/	uint32_t	pet_id;
	/*08*/	uint32_t	command;    // 1: make pet, 0: release pet
	/*12*/
};

struct InterruptCast_Struct
{
	uint32_t spawnid;
	uint32_t messageid;
	//char	message[1];
};

struct DeleteSpell_Struct
{
	/*000*/int16_t	spell_slot;
	/*002*/uint8_t	unknowndss002[2];
	/*004*/uint8_t	success;
	/*005*/uint8_t	unknowndss006[3];
	/*008*/
};

struct ManaChange_Struct
{
	uint32_t	new_mana;                  // New Mana AMount
	uint32_t	stamina;
	uint32_t	spell_id;
	uint32_t	unknown12;
	uint32_t	unknown16;
};

struct SwapSpell_Struct
{
	uint32_t from_slot;
	uint32_t to_slot;
};

struct BeginCast_Struct
{
	/*000*/	uint32_t	spell_id;
	/*004*/	uint16_t	caster_id;
	/*006*/	uint32_t	cast_time;		// in miliseconds
	/*010*/
};

struct CastSpell_Struct
{
	/*00*/	uint32_t	slot;
	/*04*/	uint32_t	spell_id;
	/*08*/	ItemSlotStruct inventoryslot;  // slot for clicky item, Seen unknown of 131 = normal cast
	/*20*/	uint32_t	target_id;
	/*24*/	uint32_t	cs_unknown[2];
	/*32*/	float	y_pos;
	/*36*/	float	x_pos;
	/*40*/	float	z_pos;
	/*44*/
};

/*
** SpawnAppearance_Struct
** Changes client appearance for all other clients in zone
** Size: 8 bytes
** Used in: OP_SpawnAppearance
**
*/
struct SpawnAppearance_Struct
{
	/*0000*/ uint16_t spawn_id;          // ID of the spawn
	/*0002*/ uint16_t type;              // Values associated with the type
	/*0004*/ uint32_t parameter;         // Type of data sent
	/*0008*/
};

struct SpellBuff_Struct
{
	/*000*/	uint8_t slotid;				// badly named... seems to be 2 for a real buff, 0 otherwise
	/*001*/	float unknown004;			// Seen 1 for no buff
	/*005*/	uint32_t player_id;			// 'global' ID of the caster, for wearoff messages
	/*009*/ uint32_t unknown016;
	/*013*/	uint8_t bard_modifier;
	/*014*/	int32_t duration;
	/*018*/ uint8_t level;
	/*019*/ uint32_t spellid;
	/*023*/ uint32_t counters;
	/*027*/ uint8_t unknown0028[53];
	/*080*/
};

struct SpellBuff_Struct_Old
{
	/*000*/	uint8_t slotid;				// badly named... seems to be 2 for a real buff, 0 otherwise
	/*001*/ uint8_t level;
	/*002*/	uint8_t bard_modifier;
	/*003*/	uint8_t effect;				// not real
	/*004*/	float unknown004;			// Seen 1 for no buff
	/*008*/ uint32_t spellid;
	/*012*/	int32_t duration;
	/*016*/ uint32_t unknown016;
	/*020*/	uint32_t player_id;			// 'global' ID of the caster, for wearoff messages
	/*024*/ uint32_t counters;
	/*028*/ uint8_t unknown0028[60];
	/*088*/
};

// Not functional yet, but this is what the packet looks like on Live
struct SpellBuffFade_Struct_Live {
	/*000*/	uint32_t entityid;	// Player id who cast the buff
	/*004*/	uint8_t unknown004;
	/*005*/	uint8_t level;
	/*006*/	uint8_t effect;
	/*007*/	uint8_t unknown007;
	/*008*/	float unknown008;
	/*012*/	uint32_t spellid;
	/*016*/	int32_t duration;
	/*020*/ uint32_t playerId;	// Global player ID?
	/*024*/	uint32_t num_hits;
	/*028*/ uint8_t unknown0028[64];
	/*092*/	uint32_t slotid;
	/*096*/	uint32_t bufffade;
	/*100*/
};

struct SpellBuffFade_Struct {
	/*000*/	uint32_t entityid;
	/*004*/	uint8_t slot;
	/*005*/	uint8_t level;
	/*006*/	uint8_t effect;
	/*007*/	uint8_t unknown7;
	/*008*/	uint32_t spellid;
	/*012*/	int32_t duration;
	/*016*/	uint32_t num_hits;
	/*020*/	uint32_t unknown020;		// Global player ID?
	/*024*/ uint32_t playerId;		// Player id who cast the buff
	/*028*/	uint32_t slotid;
	/*032*/	uint32_t bufffade;
	/*036*/
};

struct BuffRemoveRequest_Struct
{
	/*00*/ uint32_t SlotID;
	/*04*/ uint32_t EntityID;
	/*08*/
};

#if 0
// not in use
struct BuffIconEntry_Struct {
	/*000*/ uint32_t buff_slot;
	/*004*/ uint32_t spell_id;
	/*008*/ uint32_t tics_remaining;
	/*012*/ uint32_t num_hits;
	// char name[1]; caster name is also here sometimes
	// uint8_t  unknownend; 1 when single, 0 when all opposite of all_buffs?
};

// not in use
struct BuffIcon_Struct {
	/*000*/ uint32_t entity_id;
	/*004*/ uint32_t unknown004;
	/*008*/ uint8_t  all_buffs; // 1 when updating all buffs, 0 when doing one
	/*009*/ uint16_t count;
	/*011*/ BuffIconEntry_Struct entires[1];
};
#endif

struct GMTrainee_Struct
{
	/*000*/ uint32_t npcid;
	/*004*/ uint32_t playerid;
	/*008*/ uint32_t skills[PACKET_SKILL_ARRAY_SIZE];
	/*408*/ uint8_t unknown408[40];
	/*448*/
};

struct GMTrainEnd_Struct
{
	/*000*/ uint32_t npcid;
	/*004*/ uint32_t playerid;
	/*008*/
};

struct GMSkillChange_Struct {
	/*000*/	uint16_t		npcid;
	/*002*/ uint8_t		unknown1[2];    // something like PC_ID, but not really. stays the same thru the session though
	/*002*/ uint16_t       skillbank;      // 0 if normal skills, 1 if languages
	/*002*/ uint8_t		unknown2[2];
	/*008*/ uint16_t		skill_id;
	/*010*/ uint8_t		unknown3[2];
	/*012*/
};

struct GMTrainSkillConfirm_Struct {	// SoF+ only
	/*000*/	uint32_t	SkillID;
	/*004*/	uint32_t	Cost;
	/*008*/	uint8_t	NewSkill;	// Set to 1 for 'You have learned the basics' message.
	/*009*/	char	TrainerName[64];
	/*073*/ uint8_t	Unknown073[3];
	/*076*/
};

struct ConsentResponse_Struct {
	char grantname[64];
	char ownername[64];
	uint8_t permission;
	char zonename[64];
};

/*
** Name Generator Struct
** Length: 72 bytes
** OpCode: 0x0290
*/
struct NameGeneration_Struct
{
	/*0000*/	uint32_t	race;
	/*0004*/	uint32_t	gender;
	/*0008*/	char	name[64];
	/*0072*/
};

/*
** Character Creation struct
** Length: 96 Bytes
*/
struct CharCreate_Struct
{
	/*0000*/	uint32_t	gender;
	/*0004*/	uint32_t	race;
	/*0008*/	uint32_t	class_;
	/*0012*/	uint32_t	deity;
	/*0016*/	uint32_t	start_zone;
	/*0020*/	uint32_t	haircolor;
	/*0024*/	uint32_t	beard;
	/*0028*/	uint32_t	beardcolor;
	/*0032*/	uint32_t	hairstyle;
	/*0036*/	uint32_t	face;
	/*0040*/	uint32_t	eyecolor1;
	/*0044*/	uint32_t	eyecolor2;
	/*0048*/	uint32_t	drakkin_heritage;
	/*0052*/	uint32_t	drakkin_tattoo;
	/*0056*/	uint32_t	drakkin_details;
	/*0060*/	uint32_t	STR;
	/*0064*/	uint32_t	STA;
	/*0068*/	uint32_t	AGI;
	/*0073*/	uint32_t	DEX;
	/*0076*/	uint32_t	WIS;
	/*0080*/	uint32_t	INT;
	/*0084*/	uint32_t	CHA;
	/*0088*/	uint32_t	tutorial;
	/*0092*/	uint32_t	unknown0092;
	/*0096*/
};

/*
** Character Creation struct
** Length: 0 Bytes
** OpCode: 0x
*/
struct CharCreate_Struct_Temp //Size is now 0
{
};

/*
*Used in PlayerProfile
*/
struct AA_Array
{
	uint32_t AA;
	uint32_t value;
	uint32_t charges;	// expendable charges
};

struct Disciplines_Struct {
	uint32_t values[MAX_PP_DISCIPLINES];
};



struct Tribute_Struct {
	uint32_t tribute;
	uint32_t tier;
};

// Bandolier item positions
enum
{
	bandolierPrimary = 0,
	bandolierSecondary,
	bandolierRange,
	bandolierAmmo
};

struct BandolierItem_Struct
{
	char Name[1];	// Variable Length
	uint32_t ID;
	uint32_t Icon;
};

//len = 72
struct BandolierItem_Struct_Old
{
	uint32_t ID;
	uint32_t Icon;
	char Name[64];
};

//len = 320
struct Bandolier_Struct
{
	char Name[1];	// Variable Length
	BandolierItem_Struct Items[BANDOLIER_ITEM_COUNT];
};

struct Bandolier_Struct_Old
{
	char Name[32];
	BandolierItem_Struct Items[BANDOLIER_ITEM_COUNT];
};

struct PotionBeltItem_Struct
{
	char Name[1];	// Variable Length
	uint32_t ID;
	uint32_t Icon;
};

//len = 72
struct PotionBeltItem_Struct_Old
{
	uint32_t ID;
	uint32_t Icon;
	char Name[64];
};

struct PotionBelt_Struct
{
	PotionBeltItem_Struct Items[POTION_BELT_ITEM_COUNT];
};

struct PotionBelt_Struct_Old
{
	PotionBeltItem_Struct_Old Items[POTION_BELT_ITEM_COUNT];
};

struct GroupLeadershipAA_Struct {
	union {
		struct {
			uint32_t groupAAMarkNPC;
			uint32_t groupAANPCHealth;
			uint32_t groupAADelegateMainAssist;
			uint32_t groupAADelegateMarkNPC;
			uint32_t groupAA4;
			uint32_t groupAA5;
			uint32_t groupAAInspectBuffs;
			uint32_t groupAA7;
			uint32_t groupAASpellAwareness;
			uint32_t groupAAOffenseEnhancement;
			uint32_t groupAAManaEnhancement;
			uint32_t groupAAHealthEnhancement;
			uint32_t groupAAHealthRegeneration;
			uint32_t groupAAFindPathToPC;
			uint32_t groupAAHealthOfTargetsTarget;
			uint32_t groupAA15;
		};
		uint32_t ranks[MAX_GROUP_LEADERSHIP_AA_ARRAY];
	};
};

struct RaidLeadershipAA_Struct {
	union {
		struct {
			uint32_t raidAAMarkNPC;
			uint32_t raidAANPCHealth;
			uint32_t raidAADelegateMainAssist;
			uint32_t raidAADelegateMarkNPC;
			uint32_t raidAA4;
			uint32_t raidAA5;
			uint32_t raidAA6;
			uint32_t raidAASpellAwareness;
			uint32_t raidAAOffenseEnhancement;
			uint32_t raidAAManaEnhancement;
			uint32_t raidAAHealthEnhancement;
			uint32_t raidAAHealthRegeneration;
			uint32_t raidAAFindPathToPC;
			uint32_t raidAAHealthOfTargetsTarget;
			uint32_t raidAA14;
			uint32_t raidAA15;
		};
		uint32_t ranks[MAX_RAID_LEADERSHIP_AA_ARRAY];
	};
};

struct LeadershipAA_Struct {
	union {
		struct {
			GroupLeadershipAA_Struct group;
			RaidLeadershipAA_Struct raid;
		};
		uint32_t ranks[MAX_LEADERSHIP_AA_ARRAY];
	};
};

/**
* A bind point.
* Size: 20 Octets
*/
struct BindStruct {
	/*000*/ uint32_t zoneId;
	/*004*/ float x;
	/*008*/ float y;
	/*012*/ float z;
	/*016*/ float heading;
	/*020*/
};


// Player Profile - Variable Length as of Oct 12 2012 patch
struct PlayerProfile_Struct
{
	/*00000*/ uint32_t checksum;				//
	/*00004*/ uint32_t checksum_size;			// Value = ( Packet Size - 9 )
	/*00008*/ uint8_t checksum_byte;			//
	/*00009*/ uint8_t unknown_rof1[3];		//
	/*00012*/ uint32_t unknown_rof2;			//
	/*00016*/ uint8_t  gender;				// Player Gender - 0 Male, 1 Female
	/*00017*/ uint32_t  race;					// Player race
	/*00021*/ uint8_t  class_;				// Player class
	/*00022*/ uint8_t   level;				// Level of player
	/*00023*/ uint8_t   level1;				// Level of player (again?)
	/*00024*/ uint32_t bind_count;	// Seen 5
	/*00028*/ BindStruct binds[5];			// Bind points (primary is first) 5 fields = 100 bytes
	/*00128*/ uint32_t  deity;				// deity
	/*00132*/ uint32_t unknown_rof3;					// Maybe Drakkin Heritage?
	/*00136*/ uint32_t unknown4_count;		// Seen 10
	/*00140*/ uint32_t unknown_rof4[10];	// Seen all 0s
	/*00180*/ uint32_t equip_count;	// Seen 22
	union
	{
		struct
		{
			/*00184*/ EquipStruct equip_helmet; // Equiptment: Helmet visual
			/*00204*/ EquipStruct equip_chest; // Equiptment: Chest visual
			/*00224*/ EquipStruct equip_arms; // Equiptment: Arms visual
			/*00244*/ EquipStruct equip_bracers; // Equiptment: Wrist visual
			/*00264*/ EquipStruct equip_hands; // Equiptment: Hands visual
			/*00284*/ EquipStruct equip_legs; // Equiptment: Legs visual
			/*00304*/ EquipStruct equip_feet; // Equiptment: Boots visual
			/*00324*/ EquipStruct equip_primary; // Equiptment: Main visual
			/*00344*/ EquipStruct equip_secondary; // Equiptment: Off visual
			// Below slots are just guesses, but all 0s anyway...
			/*00364*/ EquipStruct equip_charm; // Equiptment: Non-visual
			/*00384*/ EquipStruct equip_ear1; // Equiptment: Non-visual
			/*00404*/ EquipStruct equip_ear2; // Equiptment: Non-visual
			/*00424*/ EquipStruct equip_face; // Equiptment: Non-visual
			/*00444*/ EquipStruct equip_neck; // Equiptment: Non-visual
			/*00464*/ EquipStruct equip_shoulder; // Equiptment: Non-visual
			/*00484*/ EquipStruct equip_bracer2; // Equiptment: Non-visual
			/*00504*/ EquipStruct equip_range; // Equiptment: Non-visual
			/*00524*/ EquipStruct equip_ring1; // Equiptment: Non-visual
			/*00544*/ EquipStruct equip_ring2; // Equiptment: Non-visual
			/*00564*/ EquipStruct equip_waist; // Equiptment: Non-visual
			/*00584*/ EquipStruct equip_powersource; // Equiptment: Non-visual
			/*00604*/ EquipStruct equip_ammo; // Equiptment: Non-visual
		} equip;
		/*00184*/ EquipStruct equipment[22];
	};
	/*00624*/ uint32_t equip2_count;			// Seen 9
	/*00628*/ EquipStruct equipment2[9];	// Appears to be Visible slots, but all 0s
	/*00808*/ uint32_t tint_count;			// Seen 9
	/*00812*/ Color_Struct item_tint[9];	// RR GG BB 00
	/*00848*/ uint32_t tint_count2;			// Seen 9
	/*00852*/ Color_Struct item_tint2[9];	// RR GG BB 00
	/*00888*/ uint8_t   haircolor;			// Player hair color
	/*00889*/ uint8_t   beardcolor;			// Player beard color
	/*00890*/ uint32_t unknown_rof5;			//
	/*00894*/ uint8_t   eyecolor1;			// Player left eye color
	/*00895*/ uint8_t   eyecolor2;			// Player right eye color
	/*00896*/ uint8_t   hairstyle;			// Player hair style
	/*00897*/ uint8_t   beard;				// Player beard type
	/*00898*/ uint8_t   face;					// Player face
	/*00899*/ uint32_t drakkin_heritage;		//
	/*00903*/ uint32_t drakkin_tattoo;		//
	/*00907*/ uint32_t drakkin_details;		//
	/*00911*/ uint8_t unknown_rof6;			//
	/*00912*/ int8_t unknown_rof7;			// seen -1
	/*00913*/ uint8_t unknown_rof8;			//
	/*00914*/ uint8_t unknown_rof9;			//
	/*00915*/ uint8_t unknown_rof10;			// Seen 1 or 0 (on a female?)
	/*00916*/ float height;					// Seen 7.0 (barb), 5.0 (woodelf), 5.5 (halfelf)
	/*00920*/ float unknown_rof11;			// Seen 3.0
	/*00924*/ float unknown_rof12;			// Seen 2.5
	/*00928*/ float unknown_rof13;			// Seen 5.5
	/*00932*/ uint32_t primary;				// Seen 10528
	/*00936*/ uint32_t secondary;				// Seen 10006
	/*00940*/ uint32_t  points;				// Unspent Practice points - RELOCATED???
	/*00944*/ uint32_t  mana;					// Current mana
	/*00948*/ uint32_t  cur_hp;				// Current HP without +HP equipment
	/*00952*/ uint32_t  STR;					// Strength - 6e 00 00 00 - 110
	/*00956*/ uint32_t  STA;					// Stamina - 73 00 00 00 - 115
	/*00960*/ uint32_t  CHA;					// Charisma - 37 00 00 00 - 55
	/*00964*/ uint32_t  DEX;					// Dexterity - 50 00 00 00 - 80
	/*00968*/ uint32_t  INT;					// Intelligence - 3c 00 00 00 - 60
	/*00972*/ uint32_t  AGI;					// Agility - 5f 00 00 00 - 95
	/*00976*/ uint32_t  WIS;					// Wisdom - 46 00 00 00 - 70
	/*00980*/ uint32_t unknown_rof14[7];				// Probably base resists?
	/*01008*/ uint32_t aa_count;						// Seen 300
	/*01012*/ AA_Array  aa_array[MAX_PP_AA_ARRAY];	// [300] 3600 bytes - AAs 12 bytes each
	/*04612*/ uint32_t skill_count;					// Seen 100
	/*04616*/ uint32_t skills[MAX_PP_SKILL];			// [100] 400 bytes - List of skills
	/*05016*/ uint32_t unknown15_count;				// Seen 25
	/*05020*/ uint32_t unknown_rof15[25];				// Most are 255 or 0
	/*05120*/ uint32_t discipline_count;				// Seen 200
	/*05124*/ Disciplines_Struct  disciplines;		// [200] 800 bytes Known disciplines
	/*05924*/ uint32_t timestamp_count;				// Seen 20
	/*05928*/ uint32_t timestamps[20];				// Unknown Unix Timestamps - maybe recast related?
	/*06008*/ uint32_t recast_count;					// Seen 20
	/*06012*/ uint32_t recastTimers[MAX_RECAST_TYPES];// [20] 80 bytes - Timers (UNIX Time of last use)
	/*06092*/ uint32_t timestamp2_count;				// Seen 100
	/*06096*/ uint32_t timestamps2[100];				// Unknown Unix Timestamps - maybe Skill related?
	/*06496*/ uint32_t spell_book_count;				// Seen 720
	/*06500*/ uint32_t spell_book[MAX_PP_SPELLBOOK];	// List of the Spells in spellbook 720 = 90 pages [2880 bytes]
	/*09380*/ uint32_t mem_spell_count;				// Seen 16
	/*09384*/ int32_t mem_spells[MAX_PP_MEMSPELL];	// [16] List of spells memorized - First 12 are set or -1 and last 4 are 0s
	/*09448*/ uint32_t unknown16_count;				// Seen 13
	/*09452*/ uint32_t unknown_rof16[13];				// Possibly spell or buff related
	/*09504*/ uint8_t unknown_rof17;					// Seen 0 or 8
	/*09505*/ uint32_t buff_count;					// Seen 42
	/*09509*/ SpellBuff_Struct buffs[BUFF_COUNT];	// [42] 3360 bytes - Buffs currently on the player (42 Max) - (Each Size 80)
	/*12869*/ uint32_t platinum;				// Platinum Pieces on player
	/*12873*/ uint32_t gold;					// Gold Pieces on player
	/*12877*/ uint32_t silver;				// Silver Pieces on player
	/*12881*/ uint32_t copper;				// Copper Pieces on player
	/*12885*/ uint32_t platinum_cursor;		// Platinum Pieces on cursor
	/*12889*/ uint32_t gold_cursor;			// Gold Pieces on cursor
	/*12893*/ uint32_t silver_cursor;			// Silver Pieces on cursor
	/*12897*/ uint32_t copper_cursor;			// Copper Pieces on cursor
	/*12901*/ uint32_t intoxication;			// Alcohol level (in ticks till sober?) - Position Guessed
	/*12905*/ uint32_t toxicity;				// Potion Toxicity (15=too toxic, each potion adds 3) - Position Guessed
	/*12909*/ uint32_t unknown_rof19;			//
	/*12913*/ uint32_t thirst_level;			// Drink (ticks till next drink) - Position Guessed
	/*12917*/ uint32_t hunger_level;			// Food (ticks till next eat) - Position Guessed
	/*12921*/ uint32_t aapoints_spent;		// Number of spent AA points
	/*12925*/ uint32_t aapoint_count;			// Seen 5 - Unsure what this is exactly
	/*12929*/ uint32_t aapoints_assigned;		// Number of Assigned AA points - Seen 206 (total of the 4 fields below)
	/*12933*/ uint32_t aa_spent_general;		// Seen 63
	/*12937*/ uint32_t aa_spent_archetype;	// Seen 40
	/*12941*/ uint32_t aa_spent_class;		// Seen 103
	/*12945*/ uint32_t aa_spent_special;		// Seen 0
	/*12949*/ uint32_t aapoints;				// Unspent AA points - Seen 1
	/*12953*/ uint16_t unknown_rof20;			//
	/*12955*/ uint32_t bandolier_count;		// Seen 20
	/*12959*/ Bandolier_Struct bandoliers[BANDOLIERS_SIZE]; // [20] 740 bytes (Variable Name Sizes) - bandolier contents
	/*13699*/ uint32_t potionbelt_count;		// Seen 5
	/*13703*/ PotionBelt_Struct potionbelt;	// [5] 45 bytes potion belt - (Variable Name Sizes)
	/*13748*/ int32_t unknown_rof21;			// Seen -1
	/*13752*/ int32_t hp_total;				// Guessed - Seen 20 on level 1 new mage
	/*13756*/ int32_t endurance_total;		// Guessed - Seen 20 on level 1 new mage
	/*13760*/ int32_t mana_total;			// Guessed - Only seen on casters so far - Matches above field if caster
	/*13764*/ uint32_t unknown_rof22[12];		// Same for all seen PPs - 48 bytes:
	/*
	19 00 00 00 19 00 00 00 19 00 00 00 0f 00 00 00
	0f 00 00 00 0f 00 00 00 0f 00 00 00 1f 85 eb 3e
	33 33 33 3f 08 00 00 00 02 00 00 00 01 00 00 00
	*/
	/*13812*/ uint32_t unknown_rof23;			// Seen 5, 19, and 20 in examples
	/*13816*/ uint32_t unknown_rof24[4];		//
	/*13832*/ uint32_t unknown_rof25[2];		// Seen random numbers from 0 to 2165037
	/*13840*/ uint32_t unknown_rof26;			// Seen 106
	//END SUB-STRUCT used for shrouding.
	/*13844*/ uint32_t name_str_len;			// Seen 64
	/*13848*/ char   name[64];				// Name of player - 19960 for Live 1180 difference
	/*13912*/ uint32_t last_name_str_len;		// Seen 32
	/*13916*/ char   last_name[32];			// Last name of player
	/*13948*/ uint32_t birthday;				// character birthday
	/*13952*/ uint32_t account_startdate;		// Date the Account was started
	/*13956*/ uint32_t lastlogin;				// character last save time
	/*13960*/ uint32_t timePlayedMin;			// time character played
	/*13964*/ uint32_t timeentitledonaccount;
	/*13968*/ uint32_t expansions;			// Bitmask for expansions ff 7f 00 00 - SoD
	/*13972*/ uint32_t language_count;		// Seen 32
	/*13976*/ uint8_t languages[MAX_PP_LANGUAGE];	// [32] 32 bytes - List of languages
	/*14008*/ uint16_t zone_id;				// see zones.h
	/*14010*/ uint16_t zoneInstance;			// Instance id
	/*14012*/ float  y;                 	// Players y position (NOT positive about this switch)
	/*14016*/ float  x;                 	// Players x position
	/*14020*/ float  z;                 	// Players z position
	/*14024*/ float  heading;           	// Players heading
	/*14028*/ uint32_t air_remaining;			// Air supply (seconds)
	/*14032*/ int32_t unknown_rof28;			// Seen -1
	/*14036*/ uint8_t unknown_rof29[10];		//
	/*14046*/ uint32_t unknown_rof30;			// Random large number or 0
	/*14050*/ uint32_t unknown_rof31;			//
	/*14054*/ uint32_t unknown32_count;		// Seen 5
	/*14058*/ uint8_t unknown_rof32[29];		//
	/*14087*/ uint32_t unknown33_count;		// Seen 32 for melee/hybrid and 21 for druid, 34 for mage
	/*14091*/ uint32_t unknown_rof33[64];		// Struct contains 2 ints, so double 32 count (Variable Sized)
	// Position Varies after this point - Really starts varying at Bandolier names, but if no names set it starts here
	/*00000*/ int32_t unknown_rof34;			// Seen -1
	/*00000*/ int32_t unknown_rof35;			// Seen -1
	/*00000*/ uint8_t unknown_rof36[18];		//
	/*00000*/ uint32_t unknown37_count;		// Seen 5
	/*00000*/ int32_t unknown_rof37[10];		// Alternates -1 and 0 - Struct contains 2 ints
	/*00000*/ uint32_t unknown38_count;		// Seen 10
	/*00000*/ int32_t unknown_rof38[20];		// Alternates -1 and 0 - Struct contains 2 ints
	/*00000*/ uint8_t unknown_rof39[137];		//
	/*00000*/ float unknown_rof40;			// Seen 1.0
	/*00000*/ uint32_t unknown_rof41[9];		//
	/*00000*/ uint32_t unknown_rof42;			// Seen 0 or 1
	/*00000*/ uint32_t unknown_string1_count;	// Seen 64
	/*00000*/ char unknown_string1[64];		//
	/*00000*/ uint8_t unknown_rof43[30];		//
	/*00000*/ uint32_t unknown_string2_count;	// Seen 64
	/*00000*/ char unknown_string2[64];		//
	/*00000*/ uint32_t unknown_string3_count;	// Seen 64
	/*00000*/ char unknown_string3[64];		//
	/*00000*/ uint32_t unknown_rof44;			// Seen 0 or 50
	/*00000*/ uint8_t unknown_rof45[663];		//
	/*00000*/ uint32_t char_id;				// Guessed based on char creation date and values
	/*00000*/ uint8_t unknown_rof46;			// Seen 0 or 1
	/*00000*/ uint32_t unknown_rof47;			// Seen 6
	/*00000*/ uint32_t unknown_rof48[13];		// Seen all 0s or some mix of ints and float?
	/*00000*/ uint32_t unknown_rof49;			// Seen 64
	/*00000*/ uint8_t unknown_rof50[256];		// Seen mostly 0s, but one example had a 2 in the middle
	/*00000*/ uint32_t unknown_rof51;			// Seen 100 or 0
	/*00000*/ uint8_t unknown_rof52[82];		//
	/*00000*/ uint32_t unknown_rof53;			// Seen 50

	uint8_t unknown_rof54[1325];	// Unknown Section

	// Bottom of Struct:
	/*00000*/ uint8_t  groupAutoconsent;		// 0=off, 1=on
	/*00000*/ uint8_t  raidAutoconsent;		// 0=off, 1=on
	/*00000*/ uint8_t  guildAutoconsent;		// 0=off, 1=on
	/*00000*/ uint8_t unknown_rof55;			// Seen 1
	/*00000*/ uint32_t level3;				// SoF looks at the level here to determine how many leadership AA you can bank.
	/*00000*/ uint32_t showhelm;				// 0=no, 1=yes
	/*00000*/ uint32_t RestTimer;
	/*00000*/ uint8_t unknown_rof56;
	/*00000*/ uint32_t unknown_rof57;			// Seen 49
	/*00000*/ uint8_t  unknown_rof58[1045];	// Seen all 0s

	/*
	///////////////////// - Haven't identified the below fields in the PP yet
	uint8_t   pvp;					// 1=pvp, 0=not pvp
	uint8_t   anon;					// 2=roleplay, 1=anon, 0=not anon
	uint8_t   gm;					// 0=no, 1=yes (guessing!)
	uint32_t   guild_id;				// guildid
	uint8_t    guildrank;			// 0=member, 1=officer, 2=guildleader -1=no guild
	uint32_t  guildbanker;
	uint32_t available_slots;
	uint32_t  endurance;			// Current endurance
	uint32_t  spellSlotRefresh[MAX_PP_MEMSPELL]; // Refresh time (millis) - 4 bytes Each * 16 = 64 bytes
	uint32_t  abilitySlotRefresh;
	///////////////////////

	uint32_t  platinum_bank;		// Platinum Pieces in Bank
	uint32_t  gold_bank;			// Gold Pieces in Bank
	uint32_t  silver_bank;			// Silver Pieces in Bank
	uint32_t  copper_bank;			// Copper Pieces in Bank
	uint32_t  platinum_shared;		// Shared platinum pieces

	uint32_t  autosplit;			// 0 = off, 1 = on

	char      groupMembers[MAX_GROUP_MEMBERS][64];// 384 all the members in group, including self
	char      groupLeader[64];	// Leader of the group ?
	uint32_t  entityid;

	uint32_t  leadAAActive;			// 0 = leader AA off, 1 = leader AA on
	int32_t  ldon_points_guk;		// Earned GUK points
	int32_t  ldon_points_mir;		// Earned MIR points
	int32_t  ldon_points_mmc;		// Earned MMC points
	int32_t  ldon_points_ruj;		// Earned RUJ points
	int32_t  ldon_points_tak;		// Earned TAK points
	int32_t  ldon_points_available;// Available LDON points
	float  tribute_time_remaining;// Time remaining on tribute (millisecs)
	uint32_t  career_tribute_points;// Total favor points for this char
	uint32_t  tribute_points;		// Current tribute points
	uint32_t  tribute_active;		// 0 = off, 1=on
	Tribute_Struct tributes[MAX_PLAYER_TRIBUTES]; // [40] Current tribute loadout
	double group_leadership_exp;	// Current group lead exp points
	double raid_leadership_exp;	// Current raid lead AA exp points
	uint32_t  group_leadership_points; // Unspent group lead AA points
	uint32_t  raid_leadership_points;  // Unspent raid lead AA points
	LeadershipAA_Struct leader_abilities; // [128]Leader AA ranks 19332

	uint32_t  PVPKills;
	uint32_t  PVPDeaths;
	uint32_t  PVPCurrentPoints;
	uint32_t  PVPCareerPoints;
	uint32_t  PVPBestKillStreak;
	uint32_t  PVPWorstDeathStreak;
	uint32_t  PVPCurrentKillStreak;
	PVPStatsEntry_Struct PVPLastKill;		// size 88
	PVPStatsEntry_Struct PVPLastDeath;	// size 88
	uint32_t  PVPNumberOfKillsInLast24Hours;
	PVPStatsEntry_Struct PVPRecentKills[50];	// size 4400 - 88 each
	uint32_t expAA;					// Exp earned in current AA point
	uint32_t currentRadCrystals;	// Current count of radiant crystals
	uint32_t careerRadCrystals;		// Total count of radiant crystals ever
	uint32_t currentEbonCrystals;	// Current count of ebon crystals
	uint32_t careerEbonCrystals;	// Total count of ebon crystals ever
	*/

};

/*
** Client Target Struct
** Length: 2 Bytes
** OpCode: 6221
*/
struct ClientTarget_Struct {
	/*000*/	uint32_t	new_target;			// Target ID
};

/*
** Target Rejection Struct
** Length: 12 Bytes
** OpCode: OP_TargetReject
*/
struct TargetReject_Struct {
	/*00*/	uint8_t	unknown00[12];
};

struct PetCommand_Struct {
	/*00*/ uint32_t	command;
	/*04*/ uint32_t	target;
	/*08*/ uint32_t	unknown08;
};

/*
** Delete Spawn
** Length: 5 Bytes
** OpCode: OP_DeleteSpawn
*/
struct DeleteSpawn_Struct
{
	/*00*/ uint32_t spawn_id;		// Spawn ID to delete
	/*04*/ uint8_t unknown04;		// Seen 1
	/*05*/
};

/*
** Channel Message received or sent
** Length: 144 Bytes + Variable Length + 1
** OpCode: OP_ChannelMessage
**
*/
struct ChannelMessage_Struct
{
	/*000*/	char	targetname[64];		// Tell recipient
	/*064*/	char	sender[64];			// The senders name (len might be wrong)
	/*128*/	uint32_t	language;			// Language
	/*132*/	uint32_t	chan_num;			// Channel
	/*136*/	uint32_t	cm_unknown4[2];		// ***Placeholder
	/*144*/	uint32_t	skill_in_language;	// The players skill in this language? might be wrong
	/*148*/	char	message[1];			// Variable length message
};

/*
** Special Message
** Length: 4 Bytes + Variable Text Length + 1
** OpCode: OP_SpecialMesg
**
*/
/*
Theres something wrong with this... example live packet:
Server->Client: [ Opcode: OP_SpecialMesg (0x0fab) Size: 244 ]
0: 01 02 00 0A 00 00 00 09 - 05 00 00 42 61 72 73 74  | ...........Barst
16: 72 65 20 53 6F 6E 67 77 - 65 61 76 65 72 00 7C F9  | re Songweaver.|.
32: FF FF 84 FF FF FF 03 00 - 00 00 47 72 65 65 74 69  | ..........Greeti

*/
struct SpecialMesg_Struct
{
	/*00*/	char	header[3];				// 04 04 00 <-- for #emote style msg
	/*03*/	uint32_t	msg_type;				// Color of text (see MT_*** below)
	/*07*/	uint32_t	target_spawn_id;		// Who is it being said to?
	/*11*/	char	sayer[1];				// Who is the source of the info - Was 1
	/*12*/	uint8_t	unknown12[12];
	/*24*/	char	message[128];				// What is being said? - was 128
};

/*
** When somebody changes what they're wearing
**      or give a pet a weapon (model changes)
** Length: 19 Bytes
*/
struct WearChange_Struct{
	/*000*/ uint16_t spawn_id;
	/*002*/ uint32_t material;
	/*006*/ uint32_t unknown06;
	/*010*/ uint32_t elite_material;	// 1 for Drakkin Elite Material
	/*014*/ uint32_t hero_forge_model; // New to VoA
	/*018*/ uint32_t unknown18; // New to RoF
	/*022*/ Color_Struct color;
	/*026*/ uint8_t wear_slot_id;
	/*027*/
};

/*
** Type:   Bind Wound Structure
** Length: 8 Bytes
*/
//Fixed for 7-14-04 patch
struct BindWound_Struct
{
	/*000*/	uint16_t	to;			// TargetID
	/*002*/	uint16_t	unknown2;		// ***Placeholder
	/*004*/	uint16_t	type;
	/*006*/	uint16_t	unknown6;
};


/*
** Type:   Zone Change Request (before hand)
** Length: 88 bytes
** OpCode: a320
*/

struct ZoneChange_Struct {
	/*000*/	char	char_name[64];     // Character Name
	/*064*/	uint16_t	zoneID;
	/*066*/	uint16_t	instanceID;
	/*068*/	uint32_t  Unknown068;
	/*072*/	uint32_t  Unknown072;
	/*076*/	float	y;
	/*080*/	float	x;
	/*084*/	float	z;
	/*088*/	uint32_t	zone_reason;	//0x0A == death, I think
	/*092*/	int32_t	success;		// =0 client->server, =1 server->client, -X=specific error
	/*096*/ uint32_t	Unknown096;	// Not sure the extra 4 bytes goes here or earlier in the struct.
	/*100*/
};

struct RequestClientZoneChange_Struct {
	/*000*/	uint16_t	zone_id;
	/*002*/	uint16_t	instance_id;
	/*004*/	uint32_t	unknown004;
	/*008*/	float	y;
	/*012*/	float	x;
	/*016*/	float	z;
	/*020*/	float	heading;
	/*024*/	uint32_t	type;	//unknown... values
	/*032*/	uint8_t	unknown032[144];
	/*172*/	uint32_t	unknown172;
	/*176*/
};

struct Animation_Struct {
	/*00*/	uint16_t spawnid;
	/*02*/	uint8_t action;
	/*03*/	uint8_t speed;
	/*04*/
};

// this is what causes the caster to animate and the target to
// get the particle effects around them when a spell is cast
// also causes a buff icon
struct Action_Struct
{
	/*00*/	uint16_t target;			// id of target
	/*02*/	uint16_t source;			// id of caster
	/*04*/	uint16_t level;			// level of caster - Seen 0
	/*06*/  uint32_t unknown06;
	/*10*/	float instrument_mod;
	/*14*/  uint32_t bard_focus_id;      // seen 0
	/*18*/  float knockback_angle;  //seems to go from 0-512 then it rolls over again
	/*22*/  uint32_t unknown22;
	/*26*/  uint8_t type;
	/*27*/  uint32_t damage;
	/*31*/  uint16_t unknown31;
	/*33*/	uint32_t spell;			// spell id being cast
	/*37*/	uint8_t level2;			// level of caster again? Or maybe the castee
	/*38*/	uint8_t effect_flag;		// if this is 4, the effect is valid: or if two are sent at the same time?
	/*39*/
};

// Starting with 2/21/2006, OP_Actions seem to come in pairs, duplicating
// themselves, with the second one with slightly more information. Maybe this
// has to do with buff blocking??
struct ActionAlt_Struct
{
	/*00*/	uint16_t target;			// id of target
	/*02*/	uint16_t source;			// id of caster
	/*04*/	uint16_t level;			// level of caster - Seen 0
	/*06*/  uint32_t unknown06;
	/*10*/	float instrument_mod;
	/*14*/  uint32_t bard_focus_id;      // seen 0
	/*18*/  float knockback_angle;  //seems to go from 0-512 then it rolls over again
	/*22*/  uint32_t unknown22;
	/*26*/  uint8_t type;
	/*27*/  uint32_t damage;
	/*31*/  uint16_t unknown31;
	/*33*/	uint32_t spell;			// spell id being cast
	/*37*/	uint8_t level2;			// level of caster again? Or maybe the castee
	/*38*/	uint8_t effect_flag;		// if this is 4, the effect is valid: or if two are sent at the same time?
	/*39*/	uint32_t unknown39;		// New field to Underfoot - Seen 14
	/*43*/	uint8_t unknown43;			// New field to Underfoot - Seen 0
	/*44*/	uint8_t unknown44;			// New field to Underfoot - Seen 17
	/*45*/	uint8_t unknown45;			// New field to Underfoot - Seen 0
	/*46*/	int32_t unknown46;		// New field to Underfoot - Seen -1
	/*50*/	uint32_t unknown50;		// New field to Underfoot - Seen 0
	/*54*/	uint16_t unknown54;		// New field to Underfoot - Seen 0
	/*56*/
};

// this is what prints the You have been struck. and the regular
// melee messages like You try to pierce, etc.  It's basically the melee
// and spell damage message
struct CombatDamage_Struct
{
	/* 00 */	uint16_t	target;
	/* 02 */	uint16_t	source;
	/* 04 */	uint8_t	type;			//slashing, etc.  231 (0xE7) for spells
	/* 05 */	uint32_t	spellid;
	/* 09 */	int32_t	damage;
	/* 13 */	float	force;		// cd cc cc 3d
	/* 17 */	float	meleepush_xy;		// see above notes in Action_Struct
	/* 21 */	float	meleepush_z;
	/* 25 */	uint8_t	unknown25[5];	// was [9]
	/* 30 */
};


/*
** Consider Struct
** Length: 20 Bytes
*/
struct Consider_Struct{
	/*000*/ uint32_t	playerid;               // PlayerID
	/*004*/ uint32_t	targetid;               // TargetID
	/*008*/ uint32_t	faction;                // Faction
	/*012*/ uint32_t	level;					// Level
	/*016*/ uint8_t	pvpcon;					// Pvp con flag 0/1
	/*017*/ uint8_t	unknown017[3];			//
	/*020*/
};

/*
** Spawn Death Blow
** Length: 32 Bytes
** OpCode: 0114
*/
struct Death_Struct
{
	/*000*/	uint32_t	spawn_id;
	/*004*/	uint32_t	killer_id;
	/*008*/	uint32_t	corpseid;	// was corpseid
	/*012*/	uint32_t	attack_skill;	// was type
	/*016*/	uint32_t	spell_id;
	/*020*/ uint32_t	bindzoneid;	//bindzoneid?
	/*024*/	uint32_t	damage;
	/*028*/	uint32_t	unknown028;
};

struct BecomeCorpse_Struct {
	uint32_t	spawn_id;
	float y;
	float x;
	float z;
};

struct ZonePlayerToBind_Struct {
	/*000*/	uint16_t	bind_zone_id;
	/*002*/	uint16_t	bind_instance_id;
	/*004*/	float	x;
	/*008*/	float	y;
	/*012*/	float	z;
	/*016*/	float	heading;
	/*020*/	char	zone_name[1];  // Or "Bind Location"
	/*000*/	uint8_t	unknown021;	// Seen 1 - Maybe 0 would be to force a rezone and 1 is just respawn
	/*000*/	uint32_t	unknown022;	// Seen 32 or 59
	/*000*/	uint32_t	unknown023;	// Seen 0
	/*000*/	uint32_t	unknown024;	// Seen 21 or 43
};

struct ZonePlayerToBindHeader_Struct
{
	/*000*/	uint16_t	bind_zone_id;
	/*002*/	uint16_t	bind_instance_id;
	/*004*/	float	x;
	/*008*/	float	y;
	/*012*/	float	z;
	/*016*/	float	heading;
	/*020*/	char	zone_name[1];  // Or "Bind Location"
};

struct ZonePlayerToBindFooter_Struct
{
	/*000*/	uint8_t	unknown021;	// Seen 1 - Maybe 0 would be to force a rezone and 1 is just respawn
	/*000*/	uint32_t	unknown022;	// Seen 32 or 59
	/*000*/	uint32_t	unknown023;	// Seen 0
	/*000*/	uint32_t	unknown024;	// Seen 21 or 43
};

typedef struct {
	/*000*/	uint32_t	bind_number;		// Number of this bind in the iteration
	/*004*/	uint32_t	bind_zone_id;		// ID of the zone for this bind point or resurect point
	/*008*/	float	x;					// X loc for this bind point
	/*012*/	float	y;					// Y loc for this bind point
	/*016*/	float	z;					// Z loc for this bind point
	/*020*/	float	heading;			// Heading for this bind point
	/*024*/	char	bind_zone_name[1];	// Or "Bind Location" or "Resurrect"
	/*000*/	uint8_t	validity;		// 0 = valid choice, 1 = not a valid choice at this time (resurrection)
} RespawnOptions_Struct;

struct RespawnWindow_Struct {
	/*000*/	uint32_t	unknown000;		// Seen 0
	/*004*/	uint32_t	time_remaining;	// Total time before respawn in milliseconds
	/*008*/	uint32_t	unknown008;		// Seen 0
	/*012*/	uint32_t	total_binds;	// Total Bind Point Options? - Seen 2
	/*016*/ RespawnOptions_Struct bind_points;
	// First bind point is "Bind Location" and the last one is "Ressurect"
};


/*
** Spawn position update - Size: 22
**	Struct sent from server->client to update position of
**	another spawn's position update in zone (whether NPC or PC)
**
*/
struct PlayerPositionUpdateServer_Struct
{
	/*0000*/ uint16_t	spawn_id;
	/*0002*/ uint16_t	spawnId2;
	/*0004*/ signed	padding0004 : 12;
	signed	y_pos : 19;           // y coord
	unsigned padding : 1;
	/*0008*/ signed	delta_x : 13;      // change in x
	signed	delta_heading : 10;// change in heading
	signed	padding0008 : 9;
	/*0012*/ signed	delta_y : 13;      // change in y
	signed	z_pos : 19;           // z coord
	/*0016*/ signed	x_pos : 19;           // x coord
	signed	animation : 10;   // animation
	signed	padding0016 : 3;
	/*0020*/ unsigned heading : 12;     // heading
	signed	delta_z : 13;      // change in z
	signed	padding0020 : 7;
	/*0024*/
};


/*
** Player position update - Size: 40
**	Struct sent from client->server to update
**	player position on server
**
*/
struct PlayerPositionUpdateClient_Struct
{
	/*0000*/ uint16_t		sequence;			// increments one each packet - Verified
	/*0002*/ uint16_t		spawn_id;			// Player's spawn id
	/*0004*/ uint8_t		unknown0004[6];		// ***Placeholder
	/*0010*/ float		delta_y;			// Change in y
	/*0014*/ float		x_pos;				// x coord (2nd loc value)
	/*0018*/ float		y_pos;				// y coord (1st loc value)
	/*0022*/ signed		delta_heading : 10;	// change in heading
	unsigned	animation : 10;		// ***Placeholder
	unsigned	padding0024 : 12;		// animation
	/*0026*/ float		delta_z;			// Change in z
	/*0030*/ float		delta_x;			// Change in x
	/*0034*/ float		z_pos;				// z coord (3rd loc value)
	/*0038*/ unsigned	heading : 12;			// Directional heading
	unsigned	padding0040 : 10;		// ***Placeholder
	unsigned	padding0041 : 10;		// ***Placeholder
	/*0042*/
};

/*
** Spawn HP Update
** Length: 10 Bytes
** OpCode: OP_HPUpdate
*/
struct SpawnHPUpdate_Struct
{
	/*00*/ int16_t	spawn_id;
	/*02*/ uint32_t	cur_hp;
	/*06*/ int32_t	max_hp;
	/*10*/
};

/*
** SendExpZonein
** Length: 152 Bytes
** OpCode: OP_SendExpZonein
*/
struct SendExpZonein_Struct
{
	/*0000*/ uint16_t spawn_id;          // ID of the spawn
	/*0002*/ uint16_t type;              // Values associated with the type
	/*0004*/ uint32_t parameter;         // Type of data sent
	/*0008*/ uint32_t exp;                    // Current experience ratio from 0 to 330
	/*0012*/ uint32_t	expAA;
	/*0016*/ uint8_t	unknown0016[4];
	/*0020*/ char	name[64];
	/*0084*/ char	last_name[64];
	/*00148*/ uint32_t	unknown132;
	/*00152*/
};

/*
** SendExpZonein
** Length: 0 Bytes
** OpCode: OP_SendExpZonein
*/
//struct SendExpZonein_Struct {};

struct SpawnHPUpdate_Struct2
{
	/*01*/ int16_t	spawn_id;
	/*00*/ uint8_t	hp;
};
/*
** Stamina
** Length: 8 Bytes
** OpCode: 5721
*/
struct Stamina_Struct {
	/*00*/ uint32_t food;                     // (low more hungry 127-0)
	/*02*/ uint32_t water;                    // (low more thirsty 127-0)
};

/*
** Level Update
** Length: 12 Bytes
*/
struct LevelUpdate_Struct
{
	/*00*/ uint32_t level;                  // New level
	/*04*/ uint32_t level_old;              // Old level
	/*08*/ uint32_t exp;                    // Current Experience
};

/*
** Experience Update
** Length: 14 Bytes
** OpCode: 9921
*/
struct ExpUpdate_Struct
{
	/*0000*/ uint32_t exp;                    // Current experience ratio from 0 to 330
	/*0004*/ uint32_t aaxp; // @BP ??
};

/*
** Item Packet Struct - Works on a variety of opcodes
** Packet Types: See ItemPacketType enum
**
*/
enum ItemPacketType
{
	ItemPacketViewLink = 0x00,
	ItemPacketTradeView = 0x65,
	ItemPacketLoot = 0x66,
	ItemPacketTrade = 0x67,
	ItemPacketCharInventory = 0x69,
	ItemPacketSummonItem = 0x6A,
	ItemPacketTributeItem = 0x6C,
	ItemPacketMerchant = 0x64,
	ItemPacketWorldContainer = 0x6B
};
struct ItemPacket_Struct
{
	/*00*/	ItemPacketType	PacketType;
	/*04*/	char			SerializedItem[1]; //was 1
	/*xx*/
};

struct BulkItemPacket_Struct
{
	/*00*/	char			SerializedItem[1];
	/*xx*/
};

struct Consume_Struct
{
	/*000*/ ItemSlotStruct	slot;
	/*012*/ uint32_t	auto_consumed;	// 0xffffffff when auto eating e7030000 when right click
	/*016*/ uint32_t	type;			// 0x01=Food 0x02=Water
	/*020*/ uint32_t	c_unknown1;		// Seen 2
	/*024*/
};

struct ItemNamePacket_Struct {
	/*000*/	uint32_t item_id;
	/*004*/	uint32_t unkown004;
	/*008*/ char name[64];
	/*072*/
};

// Length: 16
struct ItemProperties_Struct_Old {

	/*000*/ uint8_t	unknown01[2];
	/*002*/ uint8_t	charges;
	/*003*/ uint8_t	unknown02[13];
	/*016*/
};

// Length: 8
struct ItemProperties_Struct {

	/*000*/ uint8_t	unknown01[4];
	/*004*/ uint8_t	charges;
	/*005*/ uint8_t	unknown02[3];
	/*008*/
};

struct DeleteItem_Struct {
	/*0000*/ ItemSlotStruct	from_slot;
	/*0012*/ ItemSlotStruct	to_slot;
	/*0024*/ uint32_t			number_in_stack;
	/*0028*/
};

struct MoveItem_Struct {
	/*0000*/ ItemSlotStruct	from_slot;
	/*0012*/ ItemSlotStruct	to_slot;
	/*0024*/ uint32_t			number_in_stack;
	/*0028*/
};

//
// from_slot/to_slot
// -1 - destroy
//  0 - cursor
//  1 - inventory
//  2 - bank
//  3 - trade
//  4 - shared bank
//
// cointype
// 0 - copeer
// 1 - silver
// 2 - gold
// 3 - platinum
//
static const uint32_t COINTYPE_PP = 3;
static const uint32_t COINTYPE_GP = 2;
static const uint32_t COINTYPE_SP = 1;
static const uint32_t COINTYPE_CP = 0;

struct MoveCoin_Struct
{
	int32_t from_slot;
	int32_t to_slot;
	int32_t cointype1;
	int32_t cointype2;
	int32_t	amount;
};
struct TradeCoin_Struct{
	uint32_t	trader;
	uint8_t	slot;
	uint16_t	unknown5;
	uint8_t	unknown7;
	uint32_t	amount;
};
struct TradeMoneyUpdate_Struct{
	uint32_t	trader;
	uint32_t	type;
	uint32_t	amount;
};
/*
** Surname struct
** Size: 100 bytes
*/
struct Surname_Struct
{
	/*0000*/	char name[64];
	/*0064*/	uint32_t unknown0064;
	/*0068*/	char lastname[32];
	/*0100*/
};

struct GuildsListEntry_Struct {
	char name[64];
};

struct GuildsList_Struct {
	uint8_t head[64]; // First on guild list seems to be empty...
	GuildsListEntry_Struct Guilds[MAX_NUMBER_GUILDS];
};

struct GuildUpdate_Struct {
	uint32_t	guildID;
	GuildsListEntry_Struct entry;
};

/*
** Money Loot
** Length: 22 Bytes
** OpCode: 5020
*/
struct moneyOnCorpseStruct {
	/*0000*/ uint8_t	response;		// 0 = someone else is, 1 = OK, 2 = not at this time
	/*0001*/ uint8_t	unknown1;		// = 0x5a
	/*0002*/ uint8_t	unknown2;		// = 0x40
	/*0003*/ uint8_t	unknown3;		// = 0
	/*0004*/ uint32_t	platinum;		// Platinum Pieces
	/*0008*/ uint32_t	gold;			// Gold Pieces

	/*0012*/ uint32_t	silver;			// Silver Pieces
	/*0016*/ uint32_t	copper;			// Copper Pieces
};

struct LootingItem_Struct {
	/*000*/	uint32_t	lootee;
	/*004*/	uint32_t	looter;
	/*008*/	uint16_t	slot_id;
	/*010*/	uint16_t	unknown10;
	/*012*/	uint32_t	auto_loot;
	/*016*/	uint32_t	unknown16;
	/*020*/
};

struct GuildManageStatus_Struct{
	uint32_t	guildid;
	uint32_t	oldrank;
	uint32_t	newrank;
	char	name[64];
};
// Guild invite, remove
struct GuildJoin_Struct{
	/*000*/	uint32_t	guild_id;
	/*004*/	uint32_t	unknown04;
	/*008*/	uint32_t	level;
	/*012*/	uint32_t	class_;
	/*016*/	uint32_t	rank;//0 member, 1 officer, 2 leader
	/*020*/	uint32_t	zoneid;
	/*024*/	uint32_t	unknown24;
	/*028*/	char	name[64];
	/*092*/
};
struct GuildInviteAccept_Struct {
	char inviter[64];
	char newmember[64];
	uint32_t response;
	uint32_t guildeqid;
};
struct GuildManageRemove_Struct {
	uint32_t guildeqid;
	char member[64];
};
struct GuildCommand_Struct {
	/*000*/	char othername[64];
	/*064*/	char myname[64];
	/*128*/	uint16_t guildeqid;
	/*130*/	uint8_t unknown[2];		// for guildinvite all 0's, for remove 0=0x56, 2=0x02
	/*132*/	uint32_t officer;
	/*136*/	uint32_t unknown136;		// New in RoF
	/*140*/
};

// Opcode OP_GMZoneRequest
// Size = 88 bytes
struct GMZoneRequest_Struct {
	/*0000*/	char	charname[64];
	/*0064*/	uint32_t	zone_id;
	/*0068*/	float	x;
	/*0072*/	float	y;
	/*0076*/	float	z;
	/*0080*/	char	unknown0080[4];
	/*0084*/	uint32_t	success;		// 0 if command failed, 1 if succeeded?
	/*0088*/
	//	/*072*/	int8_t	success;		// =0 client->server, =1 server->client, -X=specific error
	//	/*073*/	uint8_t	unknown0073[3]; // =0 ok, =ffffff error
};

struct GMSummon_Struct {
	/*  0*/	char    charname[64];
	/* 30*/	char    gmname[64];
	/* 60*/ uint32_t	success;
	/* 61*/	uint32_t	zoneID;
	/*92*/	int32_t  y;
	/*96*/	int32_t  x;
	/*100*/ int32_t  z;
	/*104*/	uint32_t unknown2; // E0 E0 56 00
};

struct GMGoto_Struct { // x,y is swapped as compared to summon and makes sense as own packet
	/*  0*/	char    charname[64];

	/* 64*/	char    gmname[64];
	/* 128*/ uint32_t	success;
	/* 132*/	uint32_t	zoneID;

	/*136*/	int32_t  y;
	/*140*/	int32_t  x;
	/*144*/ int32_t  z;
	/*148*/	uint32_t unknown2; // E0 E0 56 00
};

struct GMLastName_Struct {
	/*000*/	char name[64];
	/*064*/	char gmname[64];
	/*128*/	char lastname[64];
	/*192*/	uint16_t unknown[4];	// 0x00, 0x00, 0x01, 0x00 = Update the clients
	/*200*/	uint32_t unknown200[8];
	/*232*/
};

struct OnLevelMessage_Struct {
	/*0000*/	uint32_t  Title_Count;
	/*0000*/	char    Title[128];
	/*0000*/	uint32_t  Text_Count;
	/*0000*/	char    Text[4096];
	/*0000*/	uint32_t  ButtonName0_Count;
	/*0000*/	char	ButtonName0[25];	// If Buttons = 1, these two are the text for the left and right buttons respectively
	/*0000*/	uint32_t  ButtonName1_Count;
	/*0000*/	char	ButtonName1[25];
	/*0000*/	uint8_t	Buttons;
	/*0000*/	uint8_t	Unknown4275;	// Something to do with audio controls
	/*0000*/	uint32_t  Duration;
	/*0000*/	uint32_t  PopupID;	// If none zero, a response packet with 00 00 00 00 <PopupID> is returned on clicking the left button
	/*0000*/	uint32_t  NegativeID;	// If none zero, a response packet with 01 00 00 00 <NegativeID> is returned on clicking the right button
	/*0000*/	uint32_t  Unknown4288;
	/*0000*/	uint8_t	Unknown4276;
	/*0000*/	uint8_t	Unknown4277;
	/*0000*/
};

//Combat Abilities
struct CombatAbility_Struct {
	uint32_t m_target;		//the ID of the target mob
	uint32_t m_atk;
	uint32_t m_skill;
};

//Instill Doubt
struct Instill_Doubt_Struct {
	uint8_t i_id;
	uint8_t ia_unknown;
	uint8_t ib_unknown;
	uint8_t ic_unknown;
	uint8_t i_atk;

	uint8_t id_unknown;
	uint8_t ie_unknown;
	uint8_t if_unknown;
	uint8_t i_type;
	uint8_t ig_unknown;
	uint8_t ih_unknown;
	uint8_t ii_unknown;
};

struct GiveItem_Struct {
	uint16_t to_entity;
	int16_t to_equipSlot;
	uint16_t from_entity;
	int16_t from_equipSlot;
};

struct RandomReq_Struct {
	uint32_t low;
	uint32_t high;
};

/* 9/23/03 reply to /random command */
struct RandomReply_Struct {
	/* 00 */	uint32_t low;
	/* 04 */	uint32_t high;
	/* 08 */	uint32_t result;
	/* 12 */	char name[64];
	/* 76 */
};

/*
** LFG_Appearance_Struct
** Packet sent to clients to notify when someone in zone toggles LFG flag
** Size: 8 bytes
** Used in: OP_LFGAppearance
**
*/
struct LFG_Appearance_Struct
{
	/*0000*/ uint32_t spawn_id;		// ID of the client
	/*0004*/ uint8_t lfg;				// 1=LFG, 0=Not LFG
	/*0005*/ char unknown0005[3];	//
	/*0008*/
};


// EverQuest Time Information:
// 72 minutes per EQ Day
// 3 minutes per EQ Hour
// 6 seconds per EQ Tick (2 minutes EQ Time)
// 3 seconds per EQ Minute

struct TimeOfDay_Struct {
	uint8_t	hour;
	uint8_t	minute;
	uint8_t	day;
	uint8_t	month;
	uint16_t	year;
	/*0006*/ uint16_t unknown0016;            // Placeholder
	/*0008*/
};

// Darvik: shopkeeper structs
struct Merchant_Click_Struct {
	/*000*/ uint32_t	npcid;			// Merchant NPC's entity id
	/*004*/ uint32_t	playerid;
	/*008*/ uint32_t	command;		// 1=open, 0=cancel/close
	/*012*/ float	rate;			// cost multiplier, dosent work anymore
	/*016*/ int32_t	unknown01;		// Seen 3 from Server or -1 from Client
	/*020*/ int32_t	unknown02;		// Seen 2592000 from Server or -1 from Client
	/*024*/
};
/*
Unknowns:
0 is e7 from 01 to // MAYBE SLOT IN PURCHASE
1 is 03
2 is 00
3 is 00
4 is ??
5 is ??
6 is 00 from a0 to
7 is 00 from 3f to */
/*
0 is F6 to 01
1 is CE CE
4A 4A
00 00
00 E0
00 CB
00 90
00 3F
*/

struct Merchant_Sell_Struct {
	/*000*/ uint32_t npcid;		// Merchant NPC's entity id
	/*004*/ uint32_t playerid;	// Player's entity id
	/*008*/ uint32_t itemslot;	// Merchant Slot / Item Instance ID
	/*012*/ uint32_t unknown12;
	/*016*/ uint32_t quantity;	// Already sold
	/*020*/ uint32_t unknown20;
	/*024*/ uint32_t price;
	/*028*/ uint32_t unknown28;	// Normally 0, but seen 84 c5 63 00 as well
	/*032*/
};

struct Merchant_Purchase_Struct {
	/*000*/	uint32_t	npcid;			// Merchant NPC's entity id
	/*004*/	MainInvItemSlotStruct	itemslot;
	/*012*/	uint32_t	quantity;
	/*016*/	uint32_t	price;
	/*020*/
};

struct Merchant_DelItem_Struct{
	/*000*/	uint32_t	npcid;			// Merchant NPC's entity id
	/*004*/	uint32_t	playerid;		// Player's entity id
	/*008*/	uint32_t	itemslot;
};

struct AltCurrencyDefinition_Struct {
	uint32_t id;
	uint32_t item_id;
};

//One packet i didn't include here is the alt currency merchant window.
//it works much like the adventure merchant window
//it is formated like: dbstringid|1|dbstringid|count
//ex for a blank crowns window you would send:
//999999|1|999999|0
//any items come after in much the same way adventure merchant items do except there is no theme included

//Server -> Client
//Populates the initial Alternate Currency Window
struct AltCurrencyPopulateEntry_Struct
{
	/*000*/ uint32_t currency_number;		// corresponds to a dbstr id as well, the string matches what shows up in the "alternate currency" tab.
	/*004*/ uint32_t unknown00;			// always 1
	/*008*/ uint32_t currency_number2;	// always same as currency number
	/*012*/ uint32_t item_id;				// appears to be the item id
	/*016*/ uint32_t item_icon;			// actual icon
	/*020*/ uint32_t stack_size;			// most are set to 1000, the stack size for the item; should match db i think or there will be problems.
	/*024*/ uint8_t  display;				// If set to 0, will not display by default.
	/*025*/
};

struct AltCurrencyPopulate_Struct {
	/*000*/ uint32_t opcode;	// 8 for populate
	/*004*/ uint32_t count;	// number of entries
	/*008*/ AltCurrencyPopulateEntry_Struct entries[1];
};

//Server -> Client
//Updates the value of a specific Alternate Currency
struct AltCurrencyUpdate_Struct {
	/*000*/ uint32_t opcode; //7 for update
	/*004*/ char name[64]; //name of client (who knows why just do it)
	/*068*/ uint32_t currency_number; //matches currency_number from populate entry
	/*072*/ uint32_t unknown072; //always 1
	/*076*/ uint32_t amount; //new amount
	/*080*/ uint32_t unknown080; //seen 0
	/*084*/ uint32_t unknown084; //seen 0
};

//Client -> Server
//When an item is selected while the alt currency merchant window is open
struct AltCurrencySelectItem_Struct {
	/*000*/ uint32_t merchant_entity_id;
	/*004*/ MainInvItemSlotStruct slot_id;
	/*008*/ uint32_t unknown008;
	/*012*/ uint32_t unknown012;
	/*016*/ uint32_t unknown016;
	/*020*/ uint32_t unknown020;
	/*024*/ uint32_t unknown024;
	/*028*/ uint32_t unknown028;
	/*032*/ uint32_t unknown032;
	/*036*/ uint32_t unknown036;
	/*040*/ uint32_t unknown040;
	/*044*/ uint32_t unknown044;
	/*048*/ uint32_t unknown048;
	/*052*/ uint32_t unknown052;
	/*056*/ uint32_t unknown056;
	/*060*/ uint32_t unknown060;
	/*064*/ uint32_t unknown064;
	/*068*/ uint32_t unknown068;
	/*072*/ uint32_t unknown072;
	/*076*/ uint32_t unknown076;
};

//Server -> Client
//As setup it makes it so that item can't be sold to the merchant.
//eg: "I will give you no doubloons for a cloth cap."
//Probably also sends amounts somewhere
struct AltCurrencySelectItemReply_Struct {
	/*000*/ uint32_t unknown000;
	/*004*/ uint8_t  unknown004; //0xff
	/*005*/ uint8_t  unknown005; //0xff
	/*006*/ uint8_t  unknown006; //0xff
	/*007*/ uint8_t  unknown007; //0xff
	/*008*/ char   item_name[64];
	/*072*/ uint32_t unknown074;
	/*076*/ uint32_t cost;
	/*080*/ uint32_t unknown080;
	/*084*/ uint32_t unknown084;
};

//Client -> Server
//Requests purchase of a specific item from the vendor
struct AltCurrencyPurchaseItem_Struct {
	/*000*/ uint32_t merchant_entity_id;
	/*004*/ uint32_t item_id;
	/*008*/ uint32_t unknown008; //1
};

//Client -> Server
//Reclaims / Create currency button pushed.
struct AltCurrencyReclaim_Struct {
	/*000*/ uint32_t currency_id;
	/*004*/ uint32_t unknown004;
	/*008*/ uint32_t count;
	/*012*/ uint32_t reclaim_flag; //1 = this is reclaim
};

struct AltCurrencySellItem_Struct {
	/*000*/ uint32_t merchant_entity_id;
	/*004*/ MainInvItemSlotStruct slot_id;
	/*008*/ uint32_t charges;
	/*012*/ uint32_t cost;
};

struct Adventure_Purchase_Struct {
	/*000*/	uint32_t	some_flag;	//set to 1 generally...
	/*004*/	uint32_t	npcid;
	/*008*/	uint32_t	itemid;
	/*012*/	uint32_t	variable;
};

struct Adventure_Sell_Struct {
	/*000*/	uint32_t	unknown000;	//0x01 - Stack Size/Charges?
	/*004*/	uint32_t	npcid;
	/*008*/ MainInvItemSlotStruct slot;
	/*016*/	uint32_t	charges;
	/*020*/	uint32_t	sell_price;
	/*024*/
};

struct AdventurePoints_Update_Struct {
	/*000*/	uint32_t				ldon_available_points;		// Total available points
	/*004*/ uint8_t				unkown_apu004[20];
	/*024*/	uint32_t				ldon_guk_points;		// Earned Deepest Guk points
	/*028*/	uint32_t				ldon_mirugal_points;		// Earned Mirugal' Mebagerie points
	/*032*/	uint32_t				ldon_mistmoore_points;		// Earned Mismoore Catacombs Points
	/*036*/	uint32_t				ldon_rujarkian_points;		// Earned Rujarkian Hills points
	/*040*/	uint32_t				ldon_takish_points;		// Earned Takish points
	/*044*/	uint8_t				unknown_apu042[216];
};


struct AdventureFinish_Struct{
	uint32_t win_lose;//Cofruben: 00 is a lose,01 is win.
	uint32_t points;
};
//OP_AdventureRequest
struct AdventureRequest_Struct{
	uint32_t risk;//1 normal,2 hard.
	uint32_t entity_id;
};
struct AdventureRequestResponse_Struct{
	uint32_t unknown000;
	char text[2048];
	uint32_t timetoenter;
	uint32_t timeleft;
	uint32_t risk;
	float x;
	float y;
	float z;
	uint32_t showcompass;
	uint32_t unknown2080;
};

//this is mostly right but something is off that causes the client to crash sometimes
//I don't really care enough about the feature to work on it anymore though.
struct AdventureLeaderboardEntry_Struct
{
	/*004*/ char name[64];
	/*008*/ uint32_t success;
	/*012*/ uint32_t failure;
	/*016*/
};

struct AdventureLeaderboard_Struct
{
	/*000*/ uint32_t unknown000;
	/*004*/ uint32_t unknown004;
	/*008*/ uint32_t success;
	/*012*/ uint32_t failure;
	/*016*/ uint32_t our_rank;
	/*020*/
};

/*struct Item_Shop_Struct {
uint16_t merchantid;
uint8_t itemtype;
Item_Struct item;
uint8_t iss_unknown001[6];
};*/

struct Illusion_Struct { // Was size: 336
	/*000*/ uint32_t spawnid;
	/*004*/ char charname[64];
	/*068*/ uint16_t race;
	/*070*/ char unknown006[2];		// Weird green name
	/*072*/ uint8_t gender;
	/*073*/ uint8_t texture;
	/*074*/ uint8_t unknown074;
	/*075*/ uint8_t unknown075;
	/*076*/ uint8_t helmtexture;
	/*077*/ uint8_t unknown077;
	/*078*/ uint8_t unknown078;
	/*079*/ uint8_t unknown079;
	/*080*/ uint32_t face;
	/*084*/ uint8_t hairstyle;		// Some Races don't change Hair Style Properly in SoF
	/*085*/ uint8_t haircolor;
	/*086*/ uint8_t beard;
	/*087*/ uint8_t beardcolor;
	/*088*/ float size;
	/*092*/ uint8_t unknown092[148];
	/*240*/ uint32_t unknown240;		// Removes armor?
	/*244*/ uint32_t drakkin_heritage;
	/*248*/ uint32_t drakkin_tattoo;
	/*252*/ uint32_t drakkin_details;
	/*256*/ uint8_t unknown256[60];	// This and below are new to RoF
	/*316*/ int32_t unknown316;		// Seen -1
	/*320*/ uint8_t unknown320[16];
	/*336*/
};

struct ZonePoint_Entry { //32 octets
	/*0000*/	uint32_t	iterator;
	/*0004*/	float	y;
	/*0008*/	float	x;
	/*0012*/	float	z;
	/*0016*/	float	heading;
	/*0020*/	uint16_t	zoneid;
	/*0022*/	uint16_t	zoneinstance; // LDoN instance
	/*0024*/	uint32_t  unknown024;
	/*0028*/	uint32_t	unknown028;
	/*0032*/
};

struct ZonePoints {
	/*0000*/	uint32_t	count;
	/*0004*/	struct	ZonePoint_Entry zpe[1]; // Always add one extra to the end after all zonepoints
	//*0xxx*/    uint8_t     unknown0xxx[24]; //New from SEQ
};

struct SkillUpdate_Struct {
	/*00*/	uint32_t skillId;
	/*04*/	uint32_t value;
	/*08*/	uint8_t unknown08;	// Seen 1
	/*09*/	uint8_t unknown09;	// Seen 80
	/*10*/	uint8_t unknown10;	// Seen 136
	/*11*/	uint8_t unknown11;	// Seen 54
	/*12*/
};

struct ZoneUnavail_Struct {
	//This actually varies, but...
	char zonename[16];
	int16_t unknown[4];
};

struct GroupInvite_Struct {
	/*0000*/	char	invitee_name[64];
	/*0064*/	char	inviter_name[64];
	/*0128*/	uint32_t	unknown0128;
	/*0132*/	uint32_t	unknown0132;
	/*0136*/	uint32_t	unknown0136;
	/*0140*/	uint32_t	unknown0140;
	/*0144*/	uint32_t	unknown0144;
	/*0148*/
};

struct GroupGeneric_Struct {
	/*0000*/	char	name1[64];
	/*0064*/	char	name2[64];
	/*0128*/	uint32_t	unknown0128;
	/*0132*/	uint32_t	unknown0132;
	/*0136*/	uint32_t	unknown0136;
	/*0140*/	uint32_t	unknown0140;
	/*0144*/	uint32_t	unknown0144;
	/*0148*/
};

struct GroupCancel_Struct {
	/*000*/	char	name1[64];
	/*064*/	char	name2[64];
	/*128*/	uint8_t	unknown128[20];
	/*148*/	uint32_t	toggle;
	/*152*/
};

struct GroupUpdate_Struct {
	/*0000*/	uint32_t	action;
	/*0004*/	char	yourname[64];
	/*0068*/	char	membername[5][64];
	/*0388*/	char	leadersname[64];
	/*0452*/
};

struct GroupUpdate2_Struct {
	/*0000*/	uint32_t	action;
	/*0004*/	char	yourname[64];
	/*0068*/	char	membername[5][64];
	/*0388*/	char	leadersname[64];
	/*0452*/	GroupLeadershipAA_Struct leader_aas;
	/*0516*/	uint8_t	unknown[252];	// Titanium uses [188] here
	/*0768*/
};

struct GroupUpdate_Struct_Live {	// New for Live
	/*0000*/	uint32_t	groupid;		// Guess - Matches unknown0136 from GroupFollow_Struct
	/*0004*/	uint32_t	totalmembers;	// Guess
	/*0000*/	//uint32_t	leadersname[1];	// Group Leader Name Null Terminated
	/*0008*/	//GroupMembers_Struct groupmembers;
};

struct GroupMembers_Struct {	// New for Live
	/*0000*/	uint32_t	membernumber;	// Guess - number of member in the group (0 to 5?)
	/*0000*/	//char	membername[1];	// Member Name Null Terminated
	/*0000*/	uint8_t	unknown001[3];	// Seen 0
	/*0000*/	uint32_t	memberlevel;	// Guess
	/*0000*/	uint8_t	unknown002[11];	// Seen 0
};

struct GroupJoin_Struct_Live {	// New for Live
	/*0000*/	uint32_t	unknown0000;	// Matches unknown0136 from GroupFollow_Struct
	/*0004*/	uint32_t	action;
	/*0008*/	uint8_t	unknown0008[5];	// Seen 0
	/*0013*/	//char	membername[1];	// Null Terminated?
	/*0000*/	uint8_t	unknown0013[3];	// Seen 0
	/*0000*/	uint32_t	unknown0016;	// Matches unknown0132 from GroupFollow_Struct
	/*0000*/	uint8_t	unknown0020[11];	// Seen 0
};

struct GroupJoin_Struct {
	/*000*/	char	unknown000[64];
	/*064*/	char	membername[64];
	/*128*/	uint8_t	unknown128[20];	// Leadership AA ?
	/*148*/
};

struct GroupFollow_Struct { // Live Follow Struct
	/*0000*/	char	name1[64];	// inviter
	/*0064*/	char	name2[64];	// invitee
	/*0128*/	uint32_t	unknown0128;	// Seen 0
	/*0132*/	uint32_t	unknown0132;	// Group ID or member level?
	/*0136*/	uint32_t	unknown0136;	// Maybe Voice Chat Channel or Group ID?
	/*0140*/	uint32_t	unknown0140;	// Seen 0
	/*0144*/	uint32_t	unknown0144;	// Seen 0
	/*0148*/	uint32_t	unknown0148;
	/*0152*/
};

struct InspectBuffs_Struct {
	/*000*/ uint32_t spell_id[BUFF_COUNT];
	/*168*/ int32_t tics_remaining[BUFF_COUNT];
};

struct LFG_Struct {
	/*000*/	uint32_t unknown000;
	/*004*/	uint32_t value; // 0x00 = off 0x01 = on
	/*008*/	uint32_t unknown008;
	/*012*/	uint32_t unknown012;
	/*016*/	char	name[64];
};

struct FaceChange_Struct {
	/*000*/	uint8_t	haircolor;
	/*001*/	uint8_t	beardcolor;
	/*002*/	uint8_t	eyecolor1;
	/*003*/	uint8_t	eyecolor2;
	/*004*/	uint8_t	hairstyle;
	/*005*/	uint8_t	beard;
	/*006*/	uint8_t	face;
	/*007*/ uint8_t	unknown007;
	/*008*/ uint32_t	drakkin_heritage;
	/*012*/ uint32_t	drakkin_tattoo;
	/*016*/ uint32_t	drakkin_details;
	/*020*/ uint32_t	unknown020;
	/*024*/
};
//there are only 10 faces for barbs changing woad just
//increase the face value by ten so if there were 8 woad
//designs then there would be 80 barb faces

/*
** Trade request from one client to another
** Used to initiate a trade
** Size: 8 bytes
** Used in: OP_TradeRequest
*/
struct TradeRequest_Struct {
	/*00*/	uint32_t to_mob_id;
	/*04*/	uint32_t from_mob_id;
	/*08*/
};

struct TradeAccept_Struct {
	/*00*/	uint32_t from_mob_id;
	/*04*/	uint32_t unknown4;		//seems to be garbage
	/*08*/
};

/*
** Cancel Trade struct
** Sent when a player cancels a trade
** Size: 8 bytes
** Used In: OP_CancelTrade
**
*/
struct CancelTrade_Struct {
	/*00*/	uint32_t fromid;
	/*04*/	uint32_t action;
	/*08*/
};

struct PetitionUpdate_Struct {
	uint32_t petnumber;    // Petition Number
	uint32_t color;		// 0x00 = green, 0x01 = yellow, 0x02 = red
	uint32_t status;
	time_t senttime;    // 4 has to be 0x1F
	char accountid[32];
	char gmsenttoo[64];
	int32_t quetotal;
	char charname[64];
};

struct Petition_Struct {
	uint32_t petnumber;
	uint32_t urgency;
	char accountid[32];
	char lastgm[32];
	uint32_t	zone;
	//char zone[32];
	char charname[64];
	uint32_t charlevel;
	uint32_t charclass;
	uint32_t charrace;
	uint32_t unknown;
	//time_t senttime; // Time?
	uint32_t checkouts;
	uint32_t unavail;
	//uint8_t unknown5[4];
	time_t senttime;
	uint32_t unknown2;
	char petitiontext[1024];
	char gmtext[1024];
};


struct Who_All_Struct { // 156 length total
	/*000*/	char	whom[64];
	/*088*/	uint8_t	unknown088[64];
	/*064*/	uint32_t	wrace;		// FF FF = no race
	/*068*/	uint32_t	wclass;		// FF FF = no class
	/*072*/	uint32_t	lvllow;		// FF FF = no numbers
	/*076*/	uint32_t	lvlhigh;	// FF FF = no numbers
	/*080*/	uint32_t	gmlookup;	// FF FF = not doing /who all gm
	/*084*/	uint32_t	guildid;	// Also used for Buyer/Trader/LFG
	/*152*/	uint32_t	type;		// 0 = /who 3 = /who all
	/*156*/
};

struct Stun_Struct { // 8 bytes total
	/*000*/	uint32_t	duration; // Duration of stun
	/*004*/	uint8_t	unknown004; // seen 0
	/*005*/	uint8_t	unknown005; // seen 163
	/*006*/	uint8_t	unknown006; // seen 67
	/*007*/	uint8_t	unknown007; // seen 0
	/*008*/
};

struct AugmentItem_Struct {
	/*00*/	uint32_t	dest_inst_id;			// The unique serial number for the item instance that is being augmented
	/*04*/	uint32_t	container_index;				// Seen 0
	/*08*/	ItemSlotStruct container_slot;	// Slot of the item being augmented
	/*20*/	uint32_t	augment_index;				// Seen 0
	/*24*/	ItemSlotStruct augment_slot;	// Slot of the distiller to use (if one applies)
	/*36*/	int32_t	augment_action;			// Guessed - 0 = augment, 1 = remove with distiller, 3 = delete aug
	/*36*/	//int32_t	augment_slot;
	/*40*/
};

// OP_Emote
struct Emote_Struct {
	/*0000*/	uint32_t unknown01;
	/*0004*/	char message[1024]; // was 1024
	/*1028*/
};

// Inspect
struct Inspect_Struct {
	uint32_t TargetID;
	uint32_t PlayerID;
};

//OP_InspectAnswer - Size: 1860
struct InspectResponse_Struct{
	/*000*/	uint32_t TargetID;
	/*004*/	uint32_t playerid;
	/*008*/	char itemnames[23][64];
	/*1480*/uint32_t itemicons[23];
	/*1572*/char text[288];	// Max number of chars in Inspect Window appears to be 254
	/*1860*/
};

//OP_SetDataRate
struct SetDataRate_Struct {
	float newdatarate;
};

//OP_SetServerFilter
struct SetServerFilter_Struct {
	uint32_t filters[35];		//see enum eqFilterType [31]
};

//Op_SetServerFilterAck
struct SetServerFilterAck_Struct {
	uint8_t blank[8];
};
struct IncreaseStat_Struct{
	/*0000*/	uint8_t	unknown0;
	/*0001*/	uint8_t	str;
	/*0002*/	uint8_t	sta;
	/*0003*/	uint8_t	agi;
	/*0004*/	uint8_t	dex;
	/*0005*/	uint8_t	int_;
	/*0006*/	uint8_t	wis;
	/*0007*/	uint8_t	cha;
	/*0008*/	uint8_t	fire;
	/*0009*/	uint8_t	cold;
	/*0010*/	uint8_t	magic;
	/*0011*/	uint8_t	poison;
	/*0012*/	uint8_t	disease;
	/*0013*/	char	unknown13[116];
	/*0129*/	uint8_t	str2;
	/*0130*/	uint8_t	sta2;
	/*0131*/	uint8_t	agi2;
	/*0132*/	uint8_t	dex2;
	/*0133*/	uint8_t	int_2;
	/*0134*/	uint8_t	wis2;
	/*0135*/	uint8_t	cha2;
	/*0136*/	uint8_t	fire2;
	/*0137*/	uint8_t	cold2;
	/*0138*/	uint8_t	magic2;
	/*0139*/	uint8_t	poison2;
	/*0140*/	uint8_t	disease2;
};

struct GMName_Struct {
	char oldname[64];
	char gmname[64];
	char newname[64];
	uint8_t badname;
	uint8_t unknown[3];
};

struct GMDelCorpse_Struct {
	char corpsename[64];
	char gmname[64];
	uint8_t unknown;
};

struct GMKick_Struct {
	char name[64];
	char gmname[64];
	uint8_t unknown;
};


struct GMKill_Struct {
	char name[64];
	char gmname[64];
	uint8_t unknown;
};


struct GMEmoteZone_Struct {
	char text[512];
};

// The BookText_Struct is not used in  SoF and later clients.
// The BookRequest_Struct is used instead for both request and reply.
//
struct BookText_Struct {
	uint8_t window;	// where to display the text (0xFF means new window)
	uint8_t type;             //type: 0=scroll, 1=book, 2=item info.. prolly
	char booktext[1]; // Variable Length - was 1
};
// This is the request to read a book.
// This is just a "text file" on the server
// or in our case, the 'name' column in our books table.
struct BookRequest_Struct {
	/*0000*/	uint32_t window;		// where to display the text (0xFFFFFFFF means new window).
	/*0004*/	uint16_t invslot;		// Is the slot, but the RoF conversion causes it to fail.  Turned to 0 since it isnt required anyway.
	/*0008*/	uint32_t unknown006;	// Seen FFFFFFFF
	/*0010*/	uint16_t unknown008;	// seen 0000
	/*0012*/	uint32_t type;		// 0 = Scroll, 1 = Book, 2 = Item Info. Possibly others
	/*0016*/	uint32_t unknown0012;
	/*0020*/	uint16_t unknown0016;
	/*0022*/	char txtfile[8194];
};

/*
** Object/Ground Spawn struct
** Used for Forges, Ovens, ground spawns, items dropped to ground, etc
** Size: Variable
** OpCodes: OP_CreateObject
**
*/
struct Object_Struct {
	/*00*/	uint32_t	object_count;		// Iteration count in the object list
	/*00*/	char	object_name[1];		// Name of object, usually something like IT63_ACTORDEF
	/*00*/	uint16_t	zone_id;			// Redudant, but: Zone the object appears in
	/*00*/	uint16_t	zone_instance;		//
	/*00*/	uint32_t	drop_id;			// Unique object id for zone
	/*00*/	uint32_t	unknown024;			// 53 9e f9 7e - same for all objects in the zone?
	/*00*/	float	heading;			// heading
	/*00*/	float	unknown032[2];		// 00 00 00 00 00 00 00 00
	/*00*/	float	size;				// Size - default 1
	/*00*/	float	z;					// z coord
	/*00*/	float	x;					// x coord
	/*00*/	float	y;					// y coord
	/*00*/	int32_t	object_type;		// Type of object, not directly translated to OP_OpenObject
};
// object_type - 01 = generic drop, 02 = armor, 19 = weapon
// 0xff seems to be indicative of the tradeskill/openable items that end up returning the old style item type in the OP_OpenObject

/*
** Click Object Struct
** Client clicking on zone object (forge, groundspawn, etc)
** Size: 8 bytes
** Last Updated: Oct-17-2003
**
*/
struct ClickObject_Struct {
	/*00*/	uint32_t drop_id;		// Appears to use the Object Count field now
	/*04*/	uint32_t player_id;
	/*08*/
};

struct Shielding_Struct {
	uint32_t target_id;
};

/*
** Click Object Acknowledgement Struct
** Response to client clicking on a World Container (ie, forge)
**
*/
struct ClickObjectAction_Struct {
	/*00*/  //uint32_t player_id;	// Appears to have been removed
	/*00*/	uint32_t	drop_id;	// Appears to use the object_count field now
	/*04*/	int32_t	unknown04;	// Seen -1
	/*08*/	int32_t	unknown08;	// Seen -1
	/*08*/	//uint32_t open;		// 1=opening, 0=closing - Removed?
	/*12*/	uint32_t	type;		// See object.h, "Object Types"
	/*16*/	uint32_t	unknown16;	//
	/*20*/	uint32_t	icon;		// Icon to display for tradeskill containers
	/*24*/	uint32_t	unknown24;	//
	/*28*/	char	object_name[64]; // Object name to display
	/*92*/
};

/*
** This is different now, mostly unknown
**
*/
struct CloseContainer_Struct {
	/*00*/	uint32_t	player_id;	// Entity Id of player who clicked object
	/*04*/	uint32_t	drop_id;	// Zone-specified unique object identifier
	/*08*/	uint32_t	open;		// 1=opening, 0=closing
	/*12*/	uint32_t	unknown12[12];
};

/*
** Generic Door Struct
** Length: 52 Octets
** Used in:
**    cDoorSpawnsStruct(f721)
**
*/
struct Door_Struct
{
	/*0000*/ char    name[32];            // Filename of Door // Was 10char long before... added the 6 in the next unknown to it: Daeken M. BlackBlade
	/*0032*/ float   yPos;               // y loc
	/*0036*/ float   xPos;               // x loc
	/*0040*/ float   zPos;               // z loc
	/*0044*/ float	 heading;
	/*0048*/ uint32_t   incline;	// rotates the whole door
	/*0052*/ uint32_t   size;			// 100 is normal, smaller number = smaller model
	/*0054*/ uint8_t    unknown0054[4]; // 00 00 00 00
	/*0060*/ uint8_t   doorId;             // door's id #
	/*0061*/ uint8_t   opentype;
	/*0062*/ uint8_t  state_at_spawn;
	/*0063*/ uint8_t  invert_state;	// if this is 1, the door is normally open
	/*0064*/ uint32_t  door_param; // normally ff ff ff ff (-1)
	/*0068*/ uint32_t	unknown0068; // 00 00 00 00
	/*0072*/ uint32_t	unknown0072; // 00 00 00 00
	/*0076*/ uint8_t	unknown0076[4]; // New for RoF
	/*0080*/ uint8_t	unknown0080; // seen 1 or 0
	/*0081*/ uint8_t	unknown0081; // seen 1 (always?)
	/*0082*/ uint8_t	unknown0082; // seen 0 (always?)
	/*0083*/ uint8_t	unknown0083; // seen 1 (always?)
	/*0084*/ uint8_t	unknown0084; // seen 0 (always?)
	/*0085*/ uint8_t	unknown0085; // seen 1 or 0 or rarely 2C or 90 or ED or 2D or A1
	/*0086*/ uint8_t  unknown0086; // seen 0 or rarely FF or FE or 10 or 5A or 82
	/*0087*/ uint8_t  unknown0087; // seen 0 or rarely 02 or 7C
	/*0088*/ uint8_t  unknown0088[8]; // mostly 0s, the last 3 bytes are something tho
	/*0096*/
};

struct DoorSpawns_Struct {
	struct Door_Struct doors[1];
};

/*
OP Code: 	Op_ClickDoor
Size:		16
*/
struct ClickDoor_Struct {
	/*000*/	uint8_t	doorid;
	/*001*/	uint8_t	unknown001;		// This may be some type of action setting
	/*002*/	uint8_t	unknown002;		// This is sometimes set after a lever is closed
	/*003*/	uint8_t	unknown003;		// Seen 0
	/*004*/	uint8_t	picklockskill;
	/*005*/	uint8_t	unknown005[3];
	/*008*/ uint32_t	item_id;
	/*012*/ uint16_t	player_id;
	/*014*/ uint8_t	unknown014[2];
	/*016*/
};

struct MoveDoor_Struct {
	uint8_t	doorid;
	uint8_t	action;
};


struct BecomeNPC_Struct {
	uint32_t id;
	int32_t maxlevel;
};

struct Underworld_Struct {
	float speed;
	float y;
	float x;
	float z;
};

struct Resurrect_Struct
{
	/*000*/	uint32_t	unknown000;
	/*004*/	uint16_t	zone_id;
	/*006*/	uint16_t	instance_id;
	/*008*/	float	y;
	/*012*/	float	x;
	/*016*/	float	z;
	/*020*/	uint32_t	unknown020;
	/*024*/	char	your_name[64];
	/*088*/	uint32_t	unknown088;
	/*092*/	char	rezzer_name[64];
	/*156*/	uint32_t	spellid;
	/*160*/	char	corpse_name[64];
	/*224*/	uint32_t	action;
	/*228*/	uint32_t	unknown228;
	/*232*/
};

struct SetRunMode_Struct {
	uint8_t mode;                    //01=run  00=walk
	uint8_t unknown[3];
};

// EnvDamage is EnvDamage2 without a few bytes at the end.
// Size: 37 bytes
struct EnvDamage2_Struct {
	/*0000*/	uint32_t id;
	/*0004*/	uint16_t unknown4;
	/*0006*/	uint32_t damage;
	/*0010*/	float unknown10;	// New to Underfoot - Seen 1
	/*0014*/	uint8_t unknown14[12];
	/*0026*/	uint8_t dmgtype;		// FA = Lava; FC = Falling
	/*0027*/	uint8_t unknown27[4];
	/*0031*/	uint16_t unknown31;	// New to Underfoot - Seen 66
	/*0033*/	uint16_t constant;		// Always FFFF
	/*0035*/	uint16_t unknown35;
	/*0037*/
};

//Bazaar Stuff

enum {
	BazaarTrader_StartTraderMode = 1,
	BazaarTrader_EndTraderMode = 2,
	BazaarTrader_UpdatePrice = 3,
	BazaarTrader_EndTransaction = 4,
	BazaarSearchResults = 7,
	BazaarWelcome = 9,
	BazaarBuyItem = 10,
	BazaarTrader_ShowItems = 11,
	BazaarSearchDone = 12,
	BazaarTrader_CustomerBrowsing = 13,
	BazaarInspectItem = 18,
	BazaarSearchDone2 = 19,
	BazaarTrader_StartTraderMode2 = 22
};

enum {
	BazaarPriceChange_Fail = 0,
	BazaarPriceChange_UpdatePrice = 1,
	BazaarPriceChange_RemoveItem = 2,
	BazaarPriceChange_AddItem = 3
};

struct BazaarWindowStart_Struct {
	uint8_t   Action;
	uint8_t   Unknown001;
	uint16_t  Unknown002;
};


struct BazaarWelcome_Struct {
	BazaarWindowStart_Struct Beginning;
	uint32_t  Traders;
	uint32_t  Items;
	uint8_t   Unknown012[8];
};

struct BazaarSearch_Struct {
	BazaarWindowStart_Struct Beginning;
	uint32_t	TraderID;
	uint32_t	Class_;
	uint32_t	Race;
	uint32_t	ItemStat;
	uint32_t	Slot;
	uint32_t	Type;
	char	Name[64];
	uint32_t	MinPrice;
	uint32_t	MaxPrice;
	uint32_t	Minlevel;
	uint32_t	MaxLlevel;
};
struct BazaarInspect_Struct{
	uint32_t ItemID;
	uint32_t Unknown004;
	char Name[64];
};

struct NewBazaarInspect_Struct {
	/*000*/	BazaarWindowStart_Struct Beginning;
	/*004*/	char Name[64];
	/*068*/	uint32_t Unknown068;
	/*072*/	int32_t SerialNumber;
	/*076*/	uint32_t Unknown076;
	/*080*/	uint32_t SellerID;
	/*084*/	uint32_t Unknown084;
};

struct BazaarReturnDone_Struct{
	uint32_t Type;
	uint32_t TraderID;
	uint32_t Unknown008;
	uint32_t Unknown012;
	uint32_t Unknown016;
};

struct BazaarSearchResults_Struct {
	/*000*/	BazaarWindowStart_Struct Beginning;
	/*004*/	uint32_t	SellerID;
	/*008*/	char	SellerName[64];
	/*072*/	uint32_t	NumItems;
	/*076*/	uint32_t	ItemID;
	/*080*/	uint32_t	SerialNumber;
	/*084*/	uint32_t	Unknown084;
	/*088*/	char	ItemName[64];
	/*152*/	uint32_t	Cost;
	/*156*/	uint32_t	ItemStat;
	/*160*/
};

struct ServerSideFilters_Struct {
	uint8_t	clientattackfilters; // 0) No, 1) All (players) but self, 2) All (players) but group
	uint8_t	npcattackfilters;	 // 0) No, 1) Ignore NPC misses (all), 2) Ignore NPC Misses + Attacks (all but self), 3) Ignores NPC Misses + Attacks (all but group)
	uint8_t	clientcastfilters;	 // 0) No, 1) Ignore PC Casts (all), 2) Ignore PC Casts (not directed towards self)
	uint8_t	npccastfilters;		 // 0) No, 1) Ignore NPC Casts (all), 2) Ignore NPC Casts (not directed towards self)
};

/*
** Client requesting item statistics
** Size: 52 bytes
** Used In: OP_ItemLinkClick
** Last Updated: 01/03/2012
**
*/
struct	ItemViewRequest_Struct {
	/*000*/	uint32_t	item_id;
	/*004*/	uint32_t	augments[6];
	/*028*/ uint32_t	link_hash;
	/*032*/	uint32_t	unknown028;	//seems to always be 4 on SoF client
	/*036*/	char	unknown032[12];	//probably includes loregroup & evolving info. see Client::MakeItemLink() in zone/inventory.cpp:469
	/*048*/	uint16_t	icon;
	/*050*/	char	unknown046[2];
	/*052*/
};

/*
*  Client to server packet
*/
struct PickPocket_Struct {
	// Size 18
	uint32_t to;
	uint32_t from;
	uint16_t myskill;
	uint8_t type; // -1 you are being picked, 0 failed , 1 = plat, 2 = gold, 3 = silver, 4 = copper, 5 = item
	uint8_t unknown1; // 0 for response, unknown for input
	uint32_t coin;
	uint8_t lastsix[2];
};
/*
* Server to client packet
*/

struct sPickPocket_Struct {
	// Size 28 = coin/fail
	uint32_t to;
	uint32_t from;
	uint32_t myskill;
	uint32_t type;
	uint32_t coin;
	char itemname[64];
};


struct LogServer_Struct {
	// Op_Code OP_LOGSERVER
	/*000*/	uint32_t	unknown000;
	/*004*/	uint8_t	enable_pvp;
	/*005*/	uint8_t	unknown005;
	/*006*/	uint8_t	unknown006;
	/*007*/	uint8_t	unknown007;
	/*008*/	uint8_t	enable_FV;
	/*009*/	uint8_t	unknown009;
	/*010*/	uint8_t	unknown010;
	/*011*/	uint8_t	unknown011;
	/*012*/	uint32_t	unknown012;	// htonl(1) on live
	/*016*/	uint32_t	unknown016;	// htonl(1) on live
	/*020*/	uint8_t	unknown020[12];
	/*032*/ uint32_t	unknown032;
	/*036*/	char	worldshortname[32];
	/*068*/	uint8_t	unknown068[181];
	/*249*/ uint8_t	unknown249[27];
	/*276*/	float	unknown276[7];
	/*304*/	uint8_t	unknown304[256];
	/*560*/

	/* 	Currently lost
	uint8_t	enablevoicemacros;
	uint8_t	enablemail;
	*/
};

struct ApproveWorld_Struct {
	// Size 544
	// Op_Code OP_ApproveWorld
	uint8_t unknown544[544];
};

struct ClientError_Struct
{
	/*00001*/	char	type;
	/*00001*/	char	unknown0001[69];
	/*00069*/	char	character_name[64];
	/*00134*/	char	unknown134[192];
	/*00133*/	char	message[31994];
	/*32136*/
};

struct MobHealth
{
	/*0000*/	uint8_t	hp; //health percent
	/*0001*/	uint16_t	id;//mobs id
};

struct Track_Struct {
	uint32_t entityid;
	float distance;
	// Fields for SoD and later
	uint8_t level;
	uint8_t is_npc;
	char name[64];
	uint8_t is_merc;
};

struct Tracking_Struct {
	uint16_t entry_count;
	Track_Struct Entrys[1];
};

struct TrackTarget_Struct
{
	uint32_t	EntityID;
};

/*
** ZoneServerInfo_Struct
** Zone server information
** Size: 130 bytes
** Used In: OP_ZoneServerInfo
**
*/
struct ZoneServerInfo_Struct
{
	/*0000*/	char	ip[128];
	/*0128*/	uint16_t	port;
};

struct WhoAllPlayer{
	uint32_t	formatstring;
	uint32_t	pidstring;
	int32_t	unknown64;		// Seen -1
	char*	name;
	uint32_t	rankstring;
	char*	guild;
	uint32_t	unknown80[2];
	uint32_t	zonestring;
	uint32_t	zone;
	uint32_t	class_;
	uint32_t	level;
	uint32_t	race;
	char*	account;
	uint32_t	unknown100;
};

struct WhoAllReturnStruct {
	uint32_t	id;
	uint32_t	playerineqstring;
	char	line[27];
	uint8_t	unknown35;			// 0A
	uint32_t	unknown36;			// Seen 208243456
	uint32_t	playersinzonestring;
	uint32_t	unknown52;			// Same as playercount?
	uint32_t	unknown44[2];		// 0s
	uint32_t	unknown56;			// Same as playercount?
	uint32_t	playercount;		// Player Count in the who list
	struct WhoAllPlayer player[1];
};

// The following four structs are the WhoAllPlayer struct above broken down
// for use in World ClientList::SendFriendsWho to accomodate the user of variable
// length strings within the struct above.

struct	WhoAllPlayerPart1 {
	uint32_t	FormatMSGID;
	uint32_t	Unknown04;
	uint32_t	Unknown08;
	char	Name[1];
};

struct	WhoAllPlayerPart2 {
	uint32_t	RankMSGID;
	char	Guild[1];
};

struct	WhoAllPlayerPart3 {
	uint32_t	Unknown80[2];
	uint32_t	ZoneMSGID;
	uint32_t	Zone;
	uint32_t	Class_;
	uint32_t	Level;
	uint32_t	Race;
	char	Account[1];
};

struct	WhoAllPlayerPart4 {
	uint32_t	Unknown100;
};

struct TraderItemSerial_Struct {
	char	SerialNumber[17];
	uint8_t	Unknown18;
};

struct Trader_Struct {
	/*0000*/	uint32_t	Code;
	/*0004*/	TraderItemSerial_Struct	items[200];
	/*3604*/	uint32_t	ItemCost[200];
	/*4404*/
};

struct ClickTrader_Struct {
	/*0000*/	uint32_t	Code;
	/*0004*/	TraderItemSerial_Struct	items[200];
	/*3604*/	uint32_t	ItemCost[200];
	/*4404*/
};

struct GetItems_Struct {
	uint32_t	items[200];
};

struct BecomeTrader_Struct {
	uint32_t id;
	uint32_t code;
};

struct Trader_ShowItems_Struct {
	/*000*/	uint32_t Code;
	/*004*/	char   SerialNumber[17];
	/*021*/	uint8_t  Unknown21;
	/*022*/	uint16_t TraderID;
	/*026*/	uint32_t Stacksize;
	/*030*/	uint32_t Price;
	/*032*/
};

struct TraderStatus_Struct {
	/*000*/	uint32_t Code;
	/*004*/	uint32_t Uknown04;
	/*008*/	uint32_t Uknown08;
	/*012*/
};

struct TraderBuy_Struct {
	/*000*/ uint32_t   Action;
	/*004*/	uint32_t	Unknown004;
	/*008*/ uint32_t   Price;
	/*012*/	uint32_t	Unknown008;	// Probably high order bits of a 64 bit price.
	/*016*/ uint32_t   TraderID;
	/*020*/ char    ItemName[64];
	/*084*/ uint32_t   Unknown076;
	/*088*/ uint32_t   ItemID;
	/*092*/ uint32_t   AlreadySold;
	/*096*/ uint32_t   Quantity;
	/*100*/ uint32_t   Unknown092;
	/*104*/
};

struct TraderItemUpdate_Struct{
	uint32_t unknown0;
	uint32_t traderid;
	uint8_t  fromslot;
	uint8_t  toslot; //7?
	uint16_t charges;
};

struct MoneyUpdate_Struct{
	int32_t platinum;
	int32_t gold;
	int32_t silver;
	int32_t copper;
};

//struct MoneyUpdate_Struct
//{
//*0000*/ uint32_t spawn_id;            // ***Placeholder
//*0004*/ uint32_t cointype;           // Coin Type
//*0008*/ uint32_t amount;             // Amount
//*0012*/
//};


struct TraderDelItem_Struct{
	uint32_t slotid;
	uint32_t quantity;
	uint32_t unknown;
};

struct TraderClick_Struct{
	uint32_t traderid;
	uint32_t unknown4[2];
	uint32_t approval;
};

struct FormattedMessage_Struct{
	uint32_t	unknown0;
	uint32_t	string_id;
	uint32_t	type;
	char	message[1];
	//*0???*/ uint8_t  unknown0[8];         // ***Placeholder
};
struct SimpleMessage_Struct{
	uint32_t	string_id;
	uint32_t	color;
	uint32_t	unknown8;
};

// Size: 52 + strings
// Other than the strings, all of this packet is network byte order (reverse from normal)
struct GuildMemberEntry_Struct {
	char	name[1];			// variable length
	uint32_t	level;
	uint32_t	banker;				// 1=yes, 0=no
	uint32_t	class_;
	uint32_t	rank;
	uint32_t	time_last_on;
	uint32_t	tribute_enable;
	uint32_t	unknown01;			// Seen 0
	uint32_t	total_tribute;		// total guild tribute donated, network byte order
	uint32_t	last_tribute;		// unix timestamp
	uint32_t	unknown_one;		// unknown, set to 1
	char	public_note[1];		// variable length.
	uint16_t	zoneinstance;		// Seen 0s or -1 in RoF
	uint16_t	zone_id;			// Seen 0s or -1 in RoF
	uint32_t	unknown_one2;		// unknown, set to 1
	uint32_t	unknown04;			// Seen 0
};

//just for display purposes, this is not actually used in the message encoding other than for size.
struct GuildMembers_Struct {
	char	player_name[1];		// variable length.
	uint32_t	guildid;			// Was unknown02 - network byte order
	uint32_t	count;				// network byte order
	GuildMemberEntry_Struct member[1];
};

struct GuildMOTD_Struct{
	/*0000*/	uint32_t	unknown0;
	/*0004*/	char	name[64];
	/*0068*/	char	setby_name[64];
	/*0132*/	uint32_t	unknown132;
	/*0136*/	char	motd[1]; //was 512
};

struct GuildURL_Struct{
	/*0000*/	uint32_t	unknown0;	//index? seen server send 0 w/ the Guild URL, followed by 1 with nothing.
	/*0004*/	uint32_t	unknown4;
	/*0008*/	uint32_t	unknown8;	//seen 7
	/*0012*/	char	setby_name[64];
	/*0076*/	uint32_t	unknown132;	//seen 0xc7de
	/*0136*/	char	url[4040];
};

struct GuildStatus_Struct
{
	/*000*/	char	Name[64];
	/*064*/	uint8_t	Unknown064[76];
};

struct GuildMemberUpdate_Struct {
	/*00*/	uint32_t	GuildID;
	/*04*/	char	MemberName[64];
	/*68*/	uint16_t	ZoneID;
	/*70*/	uint16_t	InstanceID;	//speculated
	/*72*/	uint32_t	LastSeen;	//unix timestamp
	/*76*/	uint32_t	Unknown76;
	/*80*/
};

struct GuildMemberLevelUpdate_Struct {
	/*00*/	uint32_t guild_id;
	/*04*/	char	member_name[64];
	/*68*/	uint32_t	level;	//not sure
};

struct GuildUpdate_PublicNote {
	uint32_t	unknown0;
	char	name[64];
	char	target[64];
	char	note[100]; //we are cutting this off at 100, actually around 252
};

struct GuildDemoteStruct {
	/*000*/	char	name[64];
	/*064*/	char	target[64];
	/*128*/	uint32_t	rank;			// New in RoF
	/*132*/
};

struct GuildRemoveStruct {
	/*000*/	char	target[64];
	/*064*/	char	name[64];
	/*128*/	uint32_t	GuildID;		// Was unknown128
	/*132*/	uint32_t	leaderstatus;
	/*136*/	uint32_t	unknown136;		// New in RoF
	/*140*/
};

struct GuildMakeLeader {
	char	name[64];
	char	target[64];
};

// Server -> Client
// Update a guild members rank and banker status
struct GuildSetRank_Struct
{
	/*00*/	uint32_t	GuildID;	// Was Unknown00
	/*04*/	uint32_t	Rank;
	/*08*/	char	MemberName[64];
	/*72*/	uint32_t	Banker;
	/*76*/	uint32_t	Unknown76;	// Seen 1 - Maybe Banker?
	/*80*/
};

struct BugStruct{
	/*0000*/	char	chartype[64];
	/*0064*/	char	name[96];
	/*0160*/	char	ui[128];
	/*0288*/	float	x;
	/*0292*/	float	y;
	/*0296*/	float	z;
	/*0300*/	float	heading;
	/*0304*/	uint32_t	unknown304;
	/*0308*/	uint32_t	type;
	/*0312*/	char	unknown312[2144];
	/*2456*/	char	bug[1024];
	/*3480*/	char	placeholder[2];
	/*3482*/	char	system_info[4098];
};
struct Make_Pet_Struct { //Simple struct for getting pet info
	uint8_t level;
	uint8_t class_;
	uint16_t race;
	uint8_t texture;
	uint8_t pettype;
	float size;
	uint8_t type;
	uint32_t min_dmg;
	uint32_t max_dmg;
};
struct Ground_Spawn{
	float max_x;
	float max_y;
	float min_x;
	float min_y;
	float max_z;
	float heading;
	char name[16];
	uint32_t item;
	uint32_t max_allowed;
	uint32_t respawntimer;
};
struct Ground_Spawns {
	struct Ground_Spawn spawn[50]; //Assigned max number to allow
};
struct PetitionBug_Struct{
	uint32_t	petition_number;
	uint32_t	unknown4;
	char	accountname[64];
	uint32_t	zoneid;
	char	name[64];
	uint32_t	level;
	uint32_t	class_;
	uint32_t	race;
	uint32_t	unknown152[3];
	uint32_t	time;
	uint32_t	unknown168;
	char	text[1028];
};

struct DyeStruct
{
	union
	{
		struct
		{
			struct Color_Struct head;
			struct Color_Struct chest;
			struct Color_Struct arms;
			struct Color_Struct wrists;
			struct Color_Struct hands;
			struct Color_Struct legs;
			struct Color_Struct feet;
			struct Color_Struct primary;	// you can't actually dye this
			struct Color_Struct secondary;	// or this
		}
		dyes;
		struct Color_Struct dye[9];
	};
};

struct ApproveZone_Struct {
	char	name[64];
	uint32_t	zoneid;
	uint32_t	approve;
};
struct ZoneInSendName_Struct {
	uint32_t	unknown0;
	char	name[64];
	char	name2[64];
	uint32_t	unknown132;
};
struct ZoneInSendName_Struct2 {
	uint32_t	unknown0;
	char	name[64];
	uint32_t	unknown68[145];
};

struct StartTribute_Struct {
	uint32_t	client_id;
	uint32_t	tribute_master_id;
	uint32_t	response;
};

struct TributeLevel_Struct {
	uint32_t	level;	//backwards byte order!
	uint32_t	tribute_item_id;	//backwards byte order!
	uint32_t	cost;	//backwards byte order!
};

struct TributeAbility_Struct {
	/*000*/	uint32_t	tribute_id;	//backwards byte order!
	/*004*/	uint32_t	tier_count;	//backwards byte order!
	/*008*/	TributeLevel_Struct tiers[MAX_TRIBUTE_TIERS];
	/*128*/	uint32_t	unknown128;	// New to RoF
	/*132*/	char	name[1];
};

struct GuildTributeAbility_Struct {
	uint32_t	guild_id;
	TributeAbility_Struct ability;
};

struct SelectTributeReq_Struct {
	uint32_t	client_id;	//? maybe action ID?
	uint32_t	tribute_id;
	uint32_t	unknown8;	//seen E3 00 00 00
};

struct SelectTributeReply_Struct {
	uint32_t	client_id;	//echoed from request.
	uint32_t	tribute_id;
	char	desc[1];
};

struct TributeInfo_Struct {
	uint32_t	active;		//0 == inactive, 1 == active
	uint32_t	tributes[MAX_PLAYER_TRIBUTES];	//-1 == NONE
	uint32_t	tiers[MAX_PLAYER_TRIBUTES];		//all 00's
	uint32_t	tribute_master_id;
};

struct TributeItem_Struct
{
	/*00*/	ItemSlotStruct	slot;
	/*12*/	uint32_t	quantity;
	/*16*/	uint32_t	tribute_master_id;
	/*20*/	int32_t	tribute_points;
	/*24*/
};

struct TributePoint_Struct {
	int32_t   tribute_points;
	uint32_t   unknown04;
	int32_t   career_tribute_points;
	uint32_t   unknown12;
};

struct TributeMoney_Struct {
	uint32_t   platinum;
	uint32_t   tribute_master_id;
	int32_t   tribute_points;
};


struct Split_Struct
{
	uint32_t	platinum;
	uint32_t	gold;
	uint32_t	silver;
	uint32_t	copper;
};


/*
** New Combine Struct
** Client requesting to perform a tradeskill combine
** Size: 24 bytes
** Used In: OP_TradeSkillCombine
** Last Updated: 01-05-2013
*/
struct NewCombine_Struct {
	/*00*/	ItemSlotStruct container_slot;
	/*12*/	ItemSlotStruct guildtribute_slot;	// Slot type is 8? (MapGuildTribute = 8)
	/*24*/
};


//client requesting favorite recipies
struct TradeskillFavorites_Struct {
	uint32_t object_type;
	uint32_t some_id;
	uint32_t favorite_recipes[500];
};

//search request
struct RecipesSearch_Struct {
	uint32_t object_type;	//same as in favorites
	uint32_t some_id;			//same as in favorites
	uint32_t mintrivial;
	uint32_t maxtrivial;
	char query[56];
	uint32_t unknown4;	//is set to 00 03 00 00
	uint32_t unknown5; //is set to 4C DD 12 00
	/*80*/
};

//one sent for each item, from server in reply to favorites or search
struct RecipeReply_Struct {
	uint32_t object_type;
	uint32_t some_id;	 //same as in favorites
	uint32_t component_count;
	uint32_t recipe_id;
	uint32_t trivial;
	char recipe_name[64];
	/*84*/
};

//received and sent back as an ACK with different reply_code
struct RecipeAutoCombine_Struct {
	/*00*/	uint32_t object_type;
	/*04*/	uint32_t some_id;
	/*08*/	ItemSlotStruct container_slot;		//echoed in reply - Was uint32_t unknown1
	/*20*/	ItemSlotStruct unknown_slot;		//echoed in reply
	/*32*/	uint32_t recipe_id;
	/*36*/	uint32_t reply_code;
	/*40*/
};

struct LevelAppearance_Struct { //Sends a little graphic on level up
	uint32_t	spawn_id;
	uint32_t	parm1;
	uint32_t	value1a;
	uint32_t	value1b;
	uint32_t	parm2;
	uint32_t	value2a;
	uint32_t	value2b;
	uint32_t	parm3;
	uint32_t	value3a;
	uint32_t	value3b;
	uint32_t	parm4;
	uint32_t	value4a;
	uint32_t	value4b;
	uint32_t	parm5;
	uint32_t	value5a;
	uint32_t	value5b;
	/*64*/
};
struct MerchantList{
	uint32_t	id;
	uint32_t	slot;
	uint32_t	item;
};
struct TempMerchantList{
	uint32_t	npcid;
	uint32_t	slot;
	uint32_t	item;
	uint32_t	charges; //charges/quantity
	uint32_t	origslot;
};


struct FindPerson_Point {
	float y;
	float x;
	float z;
};

struct FindPersonRequest_Struct {
	/*00*/	uint32_t	unknown00;
	/*04*/	uint32_t	npc_id;
	/*08*/	uint32_t	unknown08;
	/*12*/	uint32_t	unknown12;
	/*16*/	FindPerson_Point client_pos;
	/*28*/	uint32_t	unknown28;
	/*32*/	uint32_t	unknown32;
	/*36*/	uint32_t	unknown36;
};

//variable length packet of points
struct FindPersonResult_Struct {
	FindPerson_Point dest;
	FindPerson_Point path[1];	//last element must be the same as dest
};

struct MobRename_Struct {
	/*000*/	char	old_name[64];
	/*064*/	char	old_name_again[64];	//not sure what the difference is
	/*128*/	char	new_name[64];
	/*192*/	uint32_t	unknown192;		//set to 0
	/*196*/	uint32_t	unknown196;		//set to 1
	/*200*/
};

struct PlayMP3_Struct {
	char filename[1];
};

//this is for custom title display in the skill window
struct TitleEntry_Struct {
	uint32_t	skill_id;
	uint32_t	skill_value;
	char	title[1];
};

struct Titles_Struct {
	uint32_t	title_count;
	TitleEntry_Struct titles[1];
};

//this is for title selection by the client
struct TitleListEntry_Struct {
	uint32_t	unknown0;	//title ID
	char prefix[1];		//variable length, null terminated
	char postfix[1];		//variable length, null terminated
};

struct TitleList_Struct {
	uint32_t title_count;
	TitleListEntry_Struct titles[1];	//list of title structs
	//uint32_t unknown_ending; seen 0x7265, 0
};

struct SetTitle_Struct {
	uint32_t	is_suffix;	//guessed: 0 = prefix, 1 = suffix
	uint32_t	title_id;
};

struct SetTitleReply_Struct {
	uint32_t	is_suffix;	//guessed: 0 = prefix, 1 = suffix
	char	title[32];
	uint32_t	entity_id;
};


#if 0
// Old struct not used by Task System implementation but left for reference
struct TaskDescription_Struct {
	/*000*/	uint32_t	activity_count;		//not right.
	/*004*/	uint32_t	taskid;
	/*008*/	uint8_t	unk;
	/*009*/	uint32_t	id3;
	/*013*/	uint32_t	unknown13;
	/*017*/	char	name[1];	//variable length, 0 terminated
	/*018*/	uint32_t	unknown18;
	/*022*/	uint32_t	unknown22;
	/*026*/	uint32_t	unknown26;
	/*030*/	char	desc[1];	//variable length, 0 terminated
	/*031*/	uint32_t	reward_count;   //not sure
	/*035*/	uint8_t	unknown31;
	/*036*/	uint32_t	unknown31;
	/*040*/	uint32_t	unknown35;
	/*044*/	uint16_t	unknown39;
	/*046*/	char	reward_link[1];	//variable length, 0 terminated
	/*047*/	uint32_t	unknown43;  //maybe crystal count?
	/*051*/
};
#endif

struct TaskMemberList_Struct {
	/*00*/  uint32_t  gopher_id;
	/*04*/  uint32_t  unknown04;
	/*08*/  uint32_t  member_count;   //1 less than the number of members
	/*12*/  char	list_pointer[1];
	/*	list is of the form:
	char member_name[1]	//null terminated string
	uint8_t   task_leader	//boolean flag
	*/
};

#if 0
// Struct not used by Task System implentation but left for reference (current for RoF)
struct TaskActivity_Struct {
	/*000*/	uint32_t	TaskSequenceNumber;
	/*004*/	uint32_t	unknown2;
	/*008*/	uint32_t	TaskID;
	/*012*/	uint32_t	ActivityID;
	/*016*/	uint32_t	unknown3;
	/*020*/	uint32_t	ActivityType;
	/*024*/	uint32_t	Optional;
	/*028*/	uint8_t	unknown5;
	/*032*/	char	Text1[1];			// Variable length - Null terminated
	/*000*/	uint32_t	Text2Len;			// Lenth of the following string
	/*000*/	char	Text2[1];			// Variable length - not Null terminated
	/*000*/	uint32_t	GoalCount;
	/*000*/	uint32_t	String1Len;			// Lenth of the following string - Seen 2
	/*000*/	char	String1[1];			// Numeric String - Seen "-1" - not Null terminated
	/*000*/	uint32_t	String2Len;			// Lenth of the following string - Seen 2
	/*000*/	char	String2[1];			// Numeric String - Seen "-1" - not Null terminated
	/*000*/	char	ZoneIDString1[1];	// Numeric String - Seen "398" - Null terminated
	/*000*/	uint32_t	unknown7;			// Seen 0
	/*000*/	char 	Text3[1];			// Variable length - Null terminated
	/*000*/	uint32_t	DoneCount;
	/*000*/	uint8_t	unknown9;			// Seen 1
	/*000*/	char	ZoneIDString2[1];	// Numeric String - Seen "398" - Null terminated
};

struct TaskHistoryEntry_Struct {
	uint32_t	task_id;
	char	name[1];
	uint32_t	completed_time;
};
struct TaskHistory_Struct {
	uint32_t completed_count;
	TaskHistoryEntry_Struct entries[1];
};
#endif

struct AcceptNewTask_Struct {
	uint32_t  unknown00;
	uint32_t	task_id;		//set to 0 for 'decline'
	uint32_t	task_master_id;	//entity ID
};

//was all 0's from client, server replied with same op, all 0's
struct CancelTask_Struct {
	uint32_t SequenceNumber;
	uint32_t unknown4; // Only seen 0x00000002
};

#if 0
// old struct, not used by Task System implementation but left for reference.
struct AvaliableTask_Struct {
	uint32_t	task_index;		//no idea, seen 0x1
	uint32_t	task_master_id;	//entity ID
	uint32_t	task_id;
	uint32_t	unknown012;
	uint32_t	activity_count;	//not sure, seen 2
	char desc[1];	//variable length, 0 terminated
	uint32_t	reward_platinum;//not sure on these
	uint32_t	reward_gold;
	uint32_t	reward_silver;
	uint32_t	reward_copper;
	char some_name[1];	//variable length, 0 terminated
	uint8_t	unknown1;
	uint32_t	unknown2;	//0xFFFFFFFF
	uint32_t	unknown3;	//0xFFFFFFFF
	uint32_t	unknown4;	//seen 0x16
	uint8_t	unknown5;
};
#endif


// Many of the Task System packets contain variable length strings, as well as variable numbers
// of records, hence splitting them into multiple structs (header, middle, trailer) etc.
//
struct AvailableTaskHeader_Struct {
	uint32_t	TaskCount;
	uint32_t	unknown1;
	uint32_t	TaskGiver;
};

struct AvailableTaskData1_Struct {
	uint32_t	TaskID;
	uint32_t	unknown1;
	uint32_t	TimeLimit;
	uint32_t	unknown2;
};

struct AvailableTaskData2_Struct {
	uint32_t	unknown1, unknown2, unknown3, unknown4;
};

struct AvailableTaskTrailer_Struct {
	uint32_t	ItemCount;
	uint32_t	unknown1, unknown2;
	uint32_t	StartZone;
};

struct TaskDescriptionHeader_Struct {
	uint32_t	SequenceNumber; // The order the tasks appear in the journal. 0 for first task, 1 for second, etc.
	uint32_t	TaskID;
	uint32_t	unknown2;
	uint32_t	unknown3;
	uint8_t	unknown4;
};

struct TaskDescriptionData1_Struct {
	uint32_t	Duration;
	uint32_t	unknown2;
	uint32_t	StartTime;
};

struct TaskDescriptionData2_Struct {
	uint32_t	RewardCount; // ??
	uint32_t	unknown1;
	uint32_t	unknown2;
	uint16_t	unknown3;
	//uint8_t	unknown4;
};

struct TaskDescriptionTrailer_Struct {
	//uint16_t  unknown1; // 0x0012
	uint32_t	Points;
};

struct TaskActivityHeader_Struct {
	uint32_t	TaskSequenceNumber;
	uint32_t	unknown2; // Seen 0x00000002
	uint32_t	TaskID;
	uint32_t	ActivityID;
	uint32_t	unknown3;
	uint32_t	ActivityType;
	uint32_t	Optional;
	uint32_t	unknown5;
};

struct TaskActivityData1_Struct {
	uint32_t	GoalCount;
	uint32_t	unknown1; // 0xffffffff
	uint32_t	unknown2; // 0xffffffff
	uint32_t	ZoneID; // seen 0x36
	uint32_t  unknown3;
};

struct TaskActivityTrailer_Struct {
	uint32_t	DoneCount;
	uint32_t	unknown1; // Seen 1
};

// The Short_Struct is sent for tasks that are hidden and act as a placeholder
struct TaskActivityShort_Struct {
	uint32_t	TaskSequenceNumber;
	uint32_t	unknown2; // Seen 0x00000002
	uint32_t	TaskID;
	uint32_t	ActivityID;
	uint32_t	unknown3;
	uint32_t	ActivityType; // 0xffffffff for the short packet
	uint32_t  unknown4;
};

struct TaskActivityComplete_Struct {
	uint32_t	TaskIndex;
	uint32_t	unknown2; // 0x00000002
	uint32_t	unknown3;
	uint32_t	ActivityID;
	uint32_t	unknown4; // 0x00000001
	uint32_t	unknown5; // 0x00000001
};

#if 0
// This is a dupe of the CancelTask struct
struct TaskComplete_Struct {
	uint32_t	unknown00; // 0x00000000
	uint32_t	unknown04; // 0x00000002
};
#endif

struct TaskHistoryRequest_Struct {
	uint32_t	TaskIndex; // This is the sequence the task was sent in the Completed Tasks packet.
};

struct TaskHistoryReplyHeader_Struct {
	uint32_t	TaskID;
	uint32_t	ActivityCount;
};

struct TaskHistoryReplyData1_Struct {
	uint32_t	ActivityType;
};

struct TaskHistoryReplyData2_Struct {
	uint32_t  GoalCount;
	uint32_t	unknown04; // 0xffffffff
	uint32_t	unknown08; // 0xffffffff
	uint32_t	ZoneID;
	uint32_t	unknown16;
};

struct BankerChange_Struct {
	/*00*/	uint32_t	platinum;
	/*04*/	uint32_t	gold;
	/*08*/	uint32_t	silver;
	/*12*/	uint32_t	copper;
	/*16*/	uint32_t	platinum_bank;
	/*20*/	uint32_t	gold_bank;
	/*24*/	uint32_t	silver_bank;
	/*28*/	uint32_t	copper_bank;
	/*32*/
};

struct LeadershipExpUpdate_Struct {
	/*00*/	double	group_leadership_exp;
	/*08*/	uint32_t	group_leadership_points;
	/*12*/	uint32_t	Unknown12;
	/*16*/	double	raid_leadership_exp;
	/*24*/	uint32_t	raid_leadership_points;
};

struct UpdateLeadershipAA_Struct {
	/*00*/	uint32_t	ability_id;
	/*04*/	uint32_t	new_rank;
	/*08*/	uint32_t	unknown08;
	/*12*/
};

/**
* Leadership AA update
* Length: 32 Octets
* OpCode: LeadExpUpdate
*/
struct leadExpUpdateStruct {
	/*0000*/ uint32_t unknown0000;          // All zeroes?
	/*0004*/ uint32_t group_leadership_exp;         // Group leadership exp value
	/*0008*/ uint32_t group_leadership_points;   // Unspent group points
	/*0012*/ uint32_t unknown0012;          // Type?
	/*0016*/ uint32_t unknown0016;          // All zeroes?
	/*0020*/ uint32_t raid_leadership_exp;          // Raid leadership exp value
	/*0024*/ uint32_t raid_leadership_points;    // Unspent raid points
	/*0028*/ uint32_t unknown0028;
};

struct RaidGeneral_Struct {
	/*00*/	uint32_t		action;
	/*04*/	char		player_name[64];
	/*68*/	uint32_t		unknown68;
	/*72*/	char		leader_name[64];
	/*136*/	uint32_t		parameter;
};

struct RaidAddMember_Struct {
	/*000*/ RaidGeneral_Struct raidGen; //param = (group num-1); 0xFFFFFFFF = no group
	/*136*/ uint8_t _class;
	/*137*/	uint8_t level;
	/*138*/	uint8_t isGroupLeader;
	/*139*/	uint8_t flags[5]; //no idea if these are needed...
};

struct RaidMOTD_Struct {
	/*000*/ RaidGeneral_Struct general; // leader_name and action only used
	/*140*/ char motd[1]; // max size 1024, but reply is variable
};

struct RaidLeadershipUpdate_Struct {
	/*000*/	uint32_t action;
	/*004*/	char player_name[64];
	/*068*/	uint32_t Unknown068;
	/*072*/	char leader_name[64];
	/*136*/	GroupLeadershipAA_Struct group; //unneeded
	/*200*/	RaidLeadershipAA_Struct raid;
	/*264*/	char Unknown264[128];
};

struct RaidAdd_Struct {
	/*000*/	uint32_t		action;	//=0
	/*004*/	char		player_name[64];	//should both be the player's name
	/*068*/	char		leader_name[64];
	/*132*/	uint8_t		_class;
	/*133*/	uint8_t		level;
	/*134*/	uint8_t		has_group;
	/*135*/	uint8_t		unknown135;	//seems to be 0x42 or 0
};

struct RaidCreate_Struct {
	/*00*/	uint32_t		action;	//=8
	/*04*/	char		leader_name[64];
	/*68*/	uint32_t		leader_id;
};

struct RaidMemberInfo_Struct {
	/*00*/	uint8_t		group_number;
	/*01*/	char		member_name[1];		//dyanmic length, null terminated '\0'
	/*00*/	uint8_t		unknown00;
	/*01*/	uint8_t		_class;
	/*02*/	uint8_t		level;
	/*03*/	uint8_t		is_raid_leader;
	/*04*/	uint8_t		is_group_leader;
	/*05*/	uint8_t		main_tank;		//not sure
	/*06*/	uint8_t		unknown06[5];	//prolly more flags
};

struct RaidDetails_Struct {
	/*000*/	uint32_t		action;	//=6,20
	/*004*/	char		leader_name[64];
	/*068*/	uint32_t		unknown68[4];
	/*084*/	LeadershipAA_Struct abilities;	//ranks in backwards byte order
	/*128*/	uint8_t		unknown128[142];
	/*354*/	uint32_t		leader_id;
};

struct RaidMembers_Struct {
	/*000*/	RaidDetails_Struct		details;
	/*358*/	uint32_t					member_count;		//including leader
	/*362*/	RaidMemberInfo_Struct	members[1];
	/*...*/	RaidMemberInfo_Struct	empty;	//seem to have an extra member with a 0 length name on the end
};

struct DynamicWall_Struct {
	/*00*/  char	name[32];
	/*32*/  float   y;
	/*36*/  float   x;
	/*40*/  float   z;
	/*44*/  uint32_t  something;
	/*48*/  uint32_t  unknown48;  //0
	/*52*/  uint32_t  one_hundred;	//0x64
	/*56*/  uint32_t  unknown56;  //0
	/*60*/  uint32_t  something2;
	/*64*/  int32_t  unknown64;  //-1
	/*68*/  uint32_t  unknown68;  //0
	/*72*/  uint32_t  unknown72;  //0
	/*76*/  uint32_t  unknown76;  //0x100
	/*80*/
};

// Bandolier actions
enum
{
	bandolierCreate = 0,
	bandolierRemove,
	bandolierSet
};

struct BandolierCreate_Struct
{
	/*00*/	uint32_t Action;		//0 for create
	/*04*/	uint8_t Number;
	/*05*/	char Name[32];
	/*37*/	uint16_t Unknown37;	//seen 0x93FD
	/*39*/	uint8_t Unknown39;	//0
};

struct BandolierDelete_Struct
{
	/*00*/	uint32_t Action;
	/*04*/	uint8_t Number;
	/*05*/	uint8_t Unknown05[35];
};

struct BandolierSet_Struct
{
	/*00*/	uint32_t Action;
	/*04*/	uint8_t Number;
	/*05*/	uint8_t Unknown05[35];
};

struct Arrow_Struct {
	/*000*/	float	src_y;
	/*004*/	float	src_x;
	/*008*/	float	src_z;
	/*012*/	uint8_t	unknown012[12];
	/*024*/	float	velocity;		//4 is normal, 20 is quite fast
	/*028*/	float	launch_angle;	//0-450ish, not sure the units, 140ish is straight
	/*032*/	float	tilt;		//on the order of 125
	/*036*/	uint8_t	unknown036[8];
	/*044*/	float	arc;
	/*048*/	uint32_t	source_id;
	/*052*/	uint32_t	target_id;	//entity ID
	/*056*/	uint32_t	item_id;
	/*060*/	uint32_t	unknown060;
	/*064*/	uint32_t	unknown064;
	/*068*/	uint8_t	unknown068;
	/*069*/	uint8_t	unknown069;
	/*070*/	uint8_t	unknown070;
	/*071*/	uint8_t	item_type;
	/*072*/	uint8_t	skill;
	/*073*/	uint8_t	unknown073[16];
	/*089*/	char	model_name[27];
	/*116*/
};

//made a bunch of trivial structs for stuff for opcode finder to use
struct Consent_Struct {
	char name[1];	//always at least a null - was 1
};

struct AdventureMerchant_Struct {
	uint32_t	unknown_flag;		//seems to be 1
	uint32_t	entity_id;
};

// OP_Save - Size: 484
struct Save_Struct {
	/*000*/	uint8_t	unknown00[192];
	/*192*/	uint8_t	unknown0192[176];
	/*368*/	uint8_t	unknown0368[116];
	/*484*/
};

struct GMToggle_Struct {
	uint8_t unknown0[64];
	uint32_t toggle;
};

struct ColoredText_Struct {
	uint32_t color;
	char msg[1]; //was 1
	/*0???*/ uint8_t  paddingXXX[3];          // always 0's
};

struct UseAA_Struct {
	uint32_t begin;
	uint32_t ability;
	uint32_t end;
};

struct AA_Ability {
	/*00*/	uint32_t skill_id;
	/*04*/	uint32_t base1;
	/*08*/	uint32_t base2;
	/*12*/	uint32_t slot;
	/*16*/
};

struct SendAA_Struct {
	/*0000*/	uint32_t id;
	/*0004*/	uint8_t unknown004;		// uint32_t unknown004; set to 1.
	/*0005*/	int32_t hotkey_sid;
	/*0009*/	int32_t hotkey_sid2;
	/*0013*/	uint32_t title_sid;
	/*0017*/	uint32_t desc_sid;
	/*0021*/	uint32_t class_type;
	/*0025*/	uint32_t cost;
	/*0029*/	uint32_t seq;
	/*0033*/	uint32_t current_level; //1s, MQ2 calls this AARankRequired
	/*0037*/	uint32_t prereq_skill_count;	// mutliple prereqs at least 1, even no prereqs
	/*0041*/	uint32_t prereq_skill;		//is < 0, abs() is category #
	/*0045*/	uint32_t prereq_minpoints_count;	// mutliple prereqs at least 1, even no prereqs
	/*0049*/	uint32_t prereq_minpoints; //min points in the prereq
	/*0053*/	uint32_t type;
	/*0057*/	uint32_t spellid;
	/*0061*/	uint32_t unknown057;	// Introduced during HoT - Seen 1 - Maybe account status or enable/disable AA?
	/*0065*/	uint32_t spell_type;
	/*0069*/	uint32_t spell_refresh;
	/*0073*/	uint16_t classes;
	/*0075*/	uint16_t berserker; //seems to be 1 if its a berserker ability
	/*0077*/	uint32_t max_level;
	/*0081*/	uint32_t last_id;
	/*0085*/	uint32_t next_id;
	/*0089*/	uint32_t cost2;
	/*0093*/	uint8_t unknown93;
	/*0094*/	uint8_t grant_only; // VetAAs, progression, etc
	/*0095*/	uint8_t unknown95; // 1 for skill cap increase AAs, Mystical Attuning, and RNG attack inc, doesn't seem to matter though
	/*0096*/	uint32_t expendable_charges; // max charges of the AA
	/*0100*/	uint32_t aa_expansion;
	/*0104*/	uint32_t special_category;
	/*0108*/	uint8_t shroud;
	/*0109*/	uint8_t unknown109;
	/*0110*/	uint8_t layonhands; // 1 for lay on hands -- doesn't seem to matter?
	/*0111*/	uint8_t unknown111;
	/*0112*/	uint32_t total_abilities;
	/*0116*/	AA_Ability abilities[1];
};

struct AA_List {
	SendAA_Struct* aa[1];
};

struct AA_Action {
	/*00*/	uint32_t	action;
	/*04*/	uint32_t	ability;
	/*08*/	uint32_t	unknown08;
	/*12*/	uint32_t	exp_value;
	/*16*/
};

struct AAExpUpdate_Struct {
	/*00*/	uint32_t unknown00;	//seems to be a value from AA_Action.ability
	/*04*/	uint32_t aapoints_unspent;
	/*08*/	uint8_t aaxp_percent;	//% of exp that goes to AAs
	/*09*/	uint8_t unknown09[3];	//live doesn't always zero these, so they arnt part of aaxp_percent
	/*12*/
};

struct AltAdvStats_Struct {
	/*000*/  uint32_t experience;
	/*004*/  uint16_t unspent;
	/*006*/  uint16_t	unknown006;
	/*008*/  uint8_t	percentage;
	/*009*/  uint8_t	unknown009[3];
	/*012*/
};

struct PlayerAA_Struct {						// Is this still used?
	AA_Array aa_list[MAX_PP_AA_ARRAY];
};

struct AATable_Struct {
	/*00*/ uint32_t aa_spent;				// Total AAs Spent
	/*04*/ uint32_t aapoints_assigned;	// Number of Assigned AA points - Seen 206 (total of the 4 fields below)
	/*08*/ uint32_t aa_spent_general;		// Seen 63
	/*12*/ uint32_t aa_spent_archetype;	// Seen 40
	/*16*/ uint32_t aa_spent_class;		// Seen 103
	/*20*/ uint32_t aa_spent_special;		// Seen 0
	/*24*/ AA_Array aa_list[MAX_PP_AA_ARRAY];
};

struct Weather_Struct {
	uint32_t	val1;	//generall 0x000000FF
	uint32_t	type;	//0x31=rain, 0x02=snow(i think), 0 = normal
	uint32_t	mode;
};

struct ZoneInUnknown_Struct {
	uint32_t	val1;
	uint32_t	val2;
	uint32_t	val3;
};

struct MobHealth_Struct {
	uint16_t entity_id;
	uint8_t hp;
};

struct AnnoyingZoneUnknown_Struct {
	uint32_t	entity_id;
	uint32_t	value;		//always 4
};

struct LoadSpellSet_Struct {
	uint8_t	spell[12];	// 0xFFFFFFFF if no action, slot number if to unmem starting at 0
	uint32_t	unknown;	//Seen 12 - Maybe a gem count?
};

struct BlockedBuffs_Struct
{
	/*000*/ int32_t SpellID[BLOCKED_BUFF_COUNT];
	/*120*/ uint32_t Count;
	/*124*/ uint8_t Pet;
	/*125*/ uint8_t Initialise;
	/*126*/ uint16_t Flags;
};

//Size 24 Bytes
struct WorldObfuscator_Struct {
	/*000*/ uint32_t var1;
	/*004*/ uint32_t Unknown1;
	/*008*/ uint32_t Unknown2;
	/*012*/ uint32_t Unknown3;
	/*016*/ uint32_t var2;
	/*020*/ uint32_t Unknown4;
	/*024*/
};

struct ExpansionInfo_Struct {
	/*000*/	char	Unknown000[64];
	/*064*/	uint32_t	Expansions;
};

struct ApplyPoison_Struct {
	MainInvItemSlotStruct inventorySlot;
	uint32_t success;
};

struct ItemVerifyRequest_Struct {
	/*000*/	ItemSlotStruct slot;
	/*012*/	uint32_t	target;		// Target Entity ID
	/*016*/
};

struct ItemVerifyReply_Struct {
	/*000*/	ItemSlotStruct slot;
	/*012*/	uint32_t	spell;		// Spell ID to cast if different than item effect
	/*016*/	uint32_t	target;		// Target Entity ID
	/*020*/
};


struct RoFSlotStruct
{
	uint8_t	Bank;
	uint16_t	MainSlot;
	uint16_t	SubSlot;
};

struct ItemSerializationHeader
{
	/*000*/	char unknown000[17];	// New for HoT. Looks like a string.
	/*017*/	uint32_t stacksize;
	/*021*/	uint32_t unknown004;
	/*025*/	uint8_t  slot_type;	// 0 = normal, 1 = bank, 2 = shared bank, 9 = merchant, 20 = ?
	/*026*/	uint16_t main_slot;
	/*028*/ uint16_t sub_slot;
	/*030*/ uint16_t unknown013;	// 0xffff
	/*032*/	uint32_t price;
	/*036*/	uint32_t merchant_slot; //1 if not a merchant item
	/*040*/	uint32_t scaled_value; //0
	/*044*/	uint32_t instance_id; //unique instance id if not merchant item, else is merchant slot
	/*048*/	uint32_t unknown028; //0
	/*052*/	uint32_t last_cast_time;	// Unix Time from PP of last cast for this recast type if recast delay > 0
	/*056*/	uint32_t charges; //Total Charges an item has (-1 for unlimited)
	/*060*/	uint32_t inst_nodrop;	// 1 if the item is no drop (attuned items)
	/*064*/	uint32_t unknown044;	// 0
	/*068*/	uint32_t unknown048;	// 0
	/*072*/	uint32_t unknown052;	// 0
	uint8_t isEvolving;
};

struct EvolvingItem {
	uint8_t unknown001;
	uint8_t unknown002;
	uint8_t unknown003;
	uint8_t unknown004;
	int32_t evoLevel;
	double progress;
	uint8_t Activated;
	int32_t evomaxlevel;
	uint8_t unknown005[4];
};

struct ItemSerializationHeaderFinish
{
	/*079*/	uint32_t ornamentIcon;
	/*083*/	int32_t unknowna1;	// 0xffffffff
	/*087*/	uint32_t ornamentHeroModel;	// 0
	/*091*/	uint8_t unknown063;	// 0
	/*092*/	uint32_t unknowna3;	// 0
	/*096*/	int32_t unknowna4;	// 0xffffffff
	/*100*/	uint32_t unknowna5;	// 0
	/*104*/	uint8_t ItemClass; //0, 1, or 2
	/*105*/
};

struct ItemBodyStruct
{
	uint32_t id;
	int32_t weight;	// Seen an item on Live with -0.1 weight
	uint8_t norent;
	uint8_t nodrop;
	uint8_t attune;
	uint8_t size;
	uint32_t slots;
	uint32_t price;
	uint32_t icon;
	uint8_t unknown1;
	uint8_t unknown2;
	uint32_t BenefitFlag;
	uint8_t tradeskills;
	int8_t CR;
	int8_t DR;
	int8_t PR;
	int8_t MR;
	int8_t FR;
	int8_t SVCorruption;
	int8_t AStr;
	int8_t ASta;
	int8_t AAgi;
	int8_t ADex;
	int8_t ACha;
	int8_t AInt;
	int8_t AWis;
	int32_t HP;
	int32_t Mana;
	uint32_t Endur;
	int32_t AC;
	int32_t regen;
	int32_t mana_regen;
	int32_t end_regen;
	uint32_t Classes;
	uint32_t Races;
	uint32_t Deity;
	int32_t SkillModValue;
	int32_t SkillModMax;		// Max skill point modification
	int32_t SkillModType;
	uint32_t SkillModExtra;	// Adds a "+value" after the mod percentage
	uint32_t BaneDmgRace;
	uint32_t BaneDmgBody;
	uint32_t BaneDmgRaceAmt;
	int32_t BaneDmgAmt;
	uint8_t Magic;
	int32_t CastTime_;
	uint32_t ReqLevel;
	uint32_t RecLevel;
	uint32_t RecSkill;
	uint32_t BardType;
	int32_t BardValue;
	uint8_t Light;
	uint8_t Delay;
	uint8_t ElemDmgType;
	uint8_t ElemDmgAmt;
	uint8_t Range;
	uint32_t Damage;
	uint32_t Color;
	uint32_t Prestige;	// New to March 21 2012 client
	uint8_t ItemType;
	uint32_t Material;
	uint32_t MaterialUnknown1;
	uint32_t EliteMaterial;
	uint32_t HerosForgeModel;		// New to March 21 2012 client
	uint32_t MaterialUnknown2;	// New to December 10th 2012 client - NEW
	float  SellRate;
	int32_t CombatEffects;
	int32_t Shielding;
	int32_t StunResist;
	int32_t StrikeThrough;
	int32_t ExtraDmgSkill;
	int32_t ExtraDmgAmt;
	int32_t SpellShield;
	int32_t Avoidance;
	int32_t Accuracy;
	uint32_t CharmFileID;
	uint32_t FactionMod1;
	int32_t FactionAmt1;
	uint32_t FactionMod2;
	int32_t FactionAmt2;
	uint32_t FactionMod3;
	int32_t FactionAmt3;
	uint32_t FactionMod4;
	int32_t FactionAmt4;
};

struct AugSlotStruct
{
	uint32_t type;
	uint8_t visible;
	uint8_t unknown;
};

struct ItemSecondaryBodyStruct
{
	uint32_t augtype;
	// swapped augrestrict and augdistiller positions
	// (this swap does show the proper augment restrictions in Item Information window now)
	// unsure what the purpose of augdistiller is at this time 3/17/2014
	uint32_t augdistiller;	// New to December 10th 2012 client - NEW
	uint32_t augrestrict;
	AugSlotStruct augslots[6];

	uint32_t ldonpoint_type;
	uint32_t ldontheme;
	uint32_t ldonprice;
	uint32_t ldonsellbackrate;
	uint32_t ldonsold;

	uint8_t bagtype;
	uint8_t bagslots;
	uint8_t bagsize;
	uint8_t wreduction;

	uint8_t book;
	uint8_t booktype;
	//int32_t filename; filename is either 0xffffffff/0x00000000 or the null term string ex: CREWizardNote\0
};

struct ItemTertiaryBodyStruct
{
	int32_t loregroup;
	uint8_t artifact;
	uint8_t summonedflag;
	uint32_t favor;
	uint8_t fvnodrop;
	int32_t dotshield;
	int32_t atk;
	int32_t haste;
	int32_t damage_shield;
	uint32_t guildfavor;
	uint32_t augdistil;
	int32_t unknown3;	// 0xffffffff
	uint32_t unknown4;
	uint8_t no_pet;
	uint8_t unknown5;

	uint8_t potion_belt_enabled;
	uint32_t potion_belt_slots;

	uint32_t stacksize;
	uint8_t no_transfer;
	uint16_t expendablearrow;

	uint32_t unknown8;
	uint32_t unknown9;
	uint32_t unknown10;
	uint32_t unknown11;
	uint8_t unknown12;
	uint8_t unknown13;
	uint8_t unknown14;
};

struct ClickEffectStruct
{
	int32_t effect;
	uint8_t level2;
	uint32_t type;
	uint8_t level;
	int32_t max_charges;
	int32_t cast_time;
	uint32_t recast;
	int32_t recast_type;
	uint32_t clickunk5;
	//uint8_t effect_string;
	//int32_t clickunk7;
};

struct ProcEffectStruct
{
	uint32_t effect;
	uint8_t level2;
	uint32_t type;
	uint8_t level;
	uint32_t unknown1; // poison?
	uint32_t unknown2;
	uint32_t unknown3;
	uint32_t unknown4;
	uint32_t procrate;
	//uint8_t effect_string;
	//uint32_t unknown5;
};

struct WornEffectStruct //worn, focus and scroll effect
{
	uint32_t effect;
	uint8_t level2;
	uint32_t type;
	uint8_t level;
	uint32_t unknown1;
	uint32_t unknown2;
	uint32_t unknown3;
	uint32_t unknown4;
	uint32_t unknown5;
	//uint8_t effect_string;
	//uint32_t unknown6;
};

struct ItemQuaternaryBodyStruct
{
	uint32_t scriptfileid;
	uint8_t quest_item;
	uint32_t Power; // Enables "Power" percentage field used by Power Sources
	uint32_t Purity;
	uint8_t  unknown16;	// RoF
	uint32_t BackstabDmg;
	uint32_t DSMitigation;
	int32_t HeroicStr;
	int32_t HeroicInt;
	int32_t HeroicWis;
	int32_t HeroicAgi;
	int32_t HeroicDex;
	int32_t HeroicSta;
	int32_t HeroicCha;
	int32_t HeroicMR;
	int32_t HeroicFR;
	int32_t HeroicCR;
	int32_t HeroicDR;
	int32_t HeroicPR;
	int32_t HeroicSVCorrup;
	int32_t HealAmt;
	int32_t SpellDmg;
	int32_t clairvoyance;
	uint8_t unknown18;	//Power Source Capacity or evolve filename?
	uint32_t evolve_string; // Some String, but being evolution related is just a guess
	uint8_t unknown19;
	uint32_t unknown20;	// Bard Stuff?
	//uint32_t unknown21;
	uint8_t unknown22;
	uint32_t unknown23;
	uint32_t unknown24;
	uint32_t unknown25;
	float unknown26;
	float unknown27;
	uint32_t unknown_RoF6;	// 0 New to March 21 2012 client
	uint32_t unknown28;	// 0xffffffff
	uint16_t unknown29;
	uint32_t unknown30;	// 0xffffffff
	uint16_t unknown31;
	uint32_t unknown32;
	float  unknown33;
	uint32_t unknown34;
	uint32_t unknown35;
	uint32_t unknown36;
	uint32_t unknown37;
	uint32_t unknown_RoF7;
	uint32_t unknown_RoF8;
	uint8_t unknown38;	// 0
	uint8_t unknown39;	// 1
	uint32_t subitem_count;
};

struct AugmentInfo_Struct
{
	/*000*/ uint32_t	itemid;			// id of the solvent needed
	/*004*/ uint32_t	window;			// window to display the information in
	/*008*/ char	augment_info[64];	// total packet length 76, all the rest were always 00
	/*072*/ uint32_t	unknown072;
};

struct VeteranRewardItem
{
	/*000*/	uint32_t name_length;
	/*004*/	//char item_name[1]; // THIS IS NOT NULL TERMED
	/*???*/	uint32_t item_id;
	/*???*/	uint32_t charges;
};

struct VeteranRewardEntry
{
	/*000*/	uint32_t claim_id; // guessed
	/*004*/	uint32_t avaliable_count;
	/*008*/	uint32_t claim_count;
	/*012*/	char enabled;
	/*013*/	//VeteranRewardItem items[1];
};

struct VeteranReward
{
	/*000*/	uint32_t claim_count;
	/*004*/	//VeteranRewardEntry entries[1];
};

struct VeteranClaim
{
	/*000*/	char name[68]; //name + other data
	/*068*/	uint32_t claim_id;
	/*072*/	uint32_t unknown072;
	/*076*/	uint32_t action;
};

struct ExpeditionEntryHeader_Struct
{
	/*000*/ uint32_t unknown000;
	/*000*/ uint32_t number_of_entries;
};

struct ExpeditionJoinPrompt_Struct
{
	/*000*/ uint32_t clientid;
	/*004*/ uint32_t unknown004;
	/*008*/ char player_name[64];
	/*072*/ char expedition_name[64];
};

struct ExpeditionExpireWarning
{
	/*000*/ uint32_t clientid;
	/*004*/ uint32_t unknown004;
	/*008*/ uint32_t minutes_remaining;
};

struct ExpeditionInfo_Struct
{
	/*000*/ uint32_t clientid;
	/*004*/ uint32_t unknown004;
	/*008*/ uint32_t unknown008;
	/*012*/ uint32_t max_players;
	/*016*/ char expedition_name[128];
	/*142*/ char leader_name[64];
};

struct ExpeditionCompassEntry_Struct
{
	/*000*/ float unknown000; //seen *((uint32_t*)) = 1584791871
	/*004*/ uint32_t enabled; //guess
	/*008*/ uint32_t unknown008; //seen 1019
	/*012*/ float y;
	/*016*/ float x;
	/*020*/ float z;
};

struct ExpeditionCompass_Struct
{
	/*000*/ uint32_t clientid;
	/*004*/ uint32_t count;
	/*008*/ ExpeditionCompassEntry_Struct entries[1];
};

struct MaxCharacters_Struct
{
	/*000*/ uint32_t max_chars;	// Seen 4 on Silver Account (4 chars max)
	/*004*/ uint32_t unknown004;	// Seen 0
	/*008*/ uint32_t unknown008;	// Seen 0
};

// Used by MercenaryListEntry_Struct
struct MercenaryStance_Struct {
	/*0000*/ uint32_t StanceIndex; // Index of this stance (sometimes reverse reverse order - 3, 2, 1, 0 for 4 stances etc)
	/*0004*/ uint32_t Stance; // From dbstr_us.txt - 1^24^Passive^0, 2^24^Balanced^0, etc
};
// Used by MercenaryMerchantList_Struct
struct MercenaryListEntry_Struct {
	/*0000*/ uint32_t MercID; // ID unique to each type of mercenary (probably a DB id)
	/*0004*/ uint32_t MercType; // From dbstr_us.txt - Apprentice (330000100), Journeyman (330000200), Master (330000300)
	/*0008*/ uint32_t MercSubType; // From dbstr_us.txt - 330020105^23^Race: Guktan<br>Type: Healer<br>Confidence: High<br>Proficiency: Apprentice, Tier V...
	/*0012*/ uint32_t PurchaseCost; // Purchase Cost (in gold)
	/*0016*/ uint32_t UpkeepCost; // Upkeep Cost (in gold)
	/*0020*/ uint32_t Status; // Required Account Status (Free = 0, Silver = 1, Gold = 2) at merchants - Seen 0 (suspended) or 1 (unsuspended) on hired mercs ?
	/*0024*/ uint32_t AltCurrencyCost; // Alternate Currency Purchase Cost? (all seen costs show N/A Bayle Mark) - Seen 0
	/*0028*/ uint32_t AltCurrencyUpkeep; // Alternate Currency Upkeep Cost? (all seen costs show 1 Bayle Mark) - Seen 1
	/*0032*/ uint32_t AltCurrencyType; // Alternate Currency Type? - 19^17^Bayle Mark^0 - Seen 19
	/*0036*/ uint8_t MercUnk01; // Unknown (always see 0)
	/*0037*/ int32_t TimeLeft; // Unknown (always see -1 at merchant) - Seen 900000 (15 minutes in ms for newly hired merc)
	/*0041*/ uint32_t MerchantSlot; // Merchant Slot? Increments, but not always by 1 - May be for Merc Window Options (Seen 5, 36, 1 for active mercs)?
	/*0045*/ uint32_t MercUnk02; // Unknown (normally see 1, but sometimes 2 or 0)
	/*0049*/ uint32_t StanceCount; // Iterations of MercenaryStance_Struct - Normally 2 to 4 seen
	/*0053*/ int32_t MercUnk03; // Unknown (always 0 at merchant) - Seen on active merc: 93 a4 03 77, b8 ed 2f 26, 88 d5 8b c3, and 93 a4 ad 77
	/*0057*/ uint8_t MercUnk04; // Seen 1
	/*0058*/ char MercName[1]; // Null Terminated Mercenary Name (00 at merchants)
	/*0000*/ MercenaryStance_Struct Stances[1]; // Count Varies - From dbstr_us.txt - 1^24^Passive^0, 2^24^Balanced^0, etc
};

// Sent by the server when browsing the Mercenary Merchant
struct MercenaryMerchantList_Struct {
	/*0000*/ uint32_t MercTypeCount; // Number of Merc Types to follow
	/*0004*/ uint32_t MercTypes[1]; // Count varies, but hard set to 3 max for now - From dbstr_us.txt - Apprentice (330000100), Journeyman (330000200), Master (330000300)
	/*0016*/ uint32_t MercCount; // Number of MercenaryInfo_Struct to follow
	/*0020*/ MercenaryListEntry_Struct Mercs[1]; // Data for individual mercenaries in the Merchant List
};

// OP_MercenaryDataRequest
// Right clicking merchant - shop request
struct MercenaryMerchantShopRequest_Struct {
	/*0000*/ uint32_t MercMerchantID; // Entity ID of the Mercenary Merchant
	/*0004*/
};

// Used by MercenaryDataUpdate_Struct
struct MercenaryData_Struct {
	/*0000*/ uint32_t MercID; // ID unique to each type of mercenary (probably a DB id) - (if 1, do not send MercenaryData_Struct - No merc hired)
	/*0004*/ uint32_t MercType; // From dbstr_us.txt - Apprentice (330000100), Journeyman (330000200), Master (330000300)
	/*0008*/ uint32_t MercSubType; // From dbstr_us.txt - 330020105^23^Race: Guktan<br>Type: Healer<br>Confidence: High<br>Proficiency: Apprentice, Tier V...
	/*0012*/ uint32_t PurchaseCost; // Purchase Cost (in gold)
	/*0016*/ uint32_t UpkeepCost; // Upkeep Cost (in gold)
	/*0020*/ uint32_t Status; // Required Account Status (Free = 0, Silver = 1, Gold = 2) at merchants - Seen 0 (suspended) or 1 (unsuspended) on hired mercs ?
	/*0024*/ uint32_t AltCurrencyCost; // Alternate Currency Purchase Cost? (all seen costs show N/A Bayle Mark) - Seen 0
	/*0028*/ uint32_t AltCurrencyUpkeep; // Alternate Currency Upkeep Cost? (all seen costs show 1 Bayle Mark) - Seen 1
	/*0032*/ uint32_t AltCurrencyType; // Alternate Currency Type? - 19^17^Bayle Mark^0 - Seen 19
	/*0036*/ uint8_t MercUnk01; // Unknown (always see 0)
	/*0037*/ int32_t TimeLeft; // Unknown (always see -1 at merchant) - Seen 900000 (15 minutes in ms for newly hired merc)
	/*0041*/ uint32_t MerchantSlot; // Merchant Slot? Increments, but not always by 1 - May be for Merc Window Options (Seen 5, 36, 1 for active mercs)?
	/*0045*/ uint32_t MercUnk02; // Unknown (normally see 1, but sometimes 2 or 0)
	/*0049*/ uint32_t StanceCount; // Iterations of MercenaryStance_Struct - Normally 2 to 4 seen
	/*0053*/ int32_t MercUnk03; // Unknown (always 0 at merchant) - Seen on active merc: 93 a4 03 77, b8 ed 2f 26, 88 d5 8b c3, and 93 a4 ad 77
	/*0057*/ uint8_t MercUnk04; // Seen 1
	/*0058*/ char MercName[1]; // Null Terminated Mercenary Name (00 at merchants)
	/*0000*/ MercenaryStance_Struct Stances[1]; // Count Varies, but hard set to 2 for now - From dbstr_us.txt - 1^24^Passive^0, 2^24^Balanced^0, etc (1 to 9 as of April 2012)
	/*0000*/ uint32_t MercUnk05; // Seen 1 - Extra Merc Data field that differs from MercenaryListEntry_Struct
	// MercUnk05 may be a field that is at the end of the packet only, even if multiple mercs are listed (haven't seen examples of multiple mercs owned at once)
};

// Should be named OP_MercenaryDataResponse, but the current opcode using that name should be renamed first
// Size varies if mercenary is hired or if browsing Mercenary Merchant
// This may also be the response for Client->Server 0x0327 (size 0) packet On Live as of April 2 2012
struct MercenaryDataUpdate_Struct {
	/*0000*/ int32_t MercStatus; // Seen 0 with merc and -1 with no merc hired
	/*0004*/ uint32_t MercCount; // Seen 1 with 1 merc hired and 0 with no merc hired
	/*0008*/ MercenaryData_Struct MercData[1]; // Data for individual mercenaries in the Merchant List
};

// Size 12 and sent on Zone-In if no mercenary is currently hired and when merc is dismissed
// (Same packet as MercAssign_Struct?)
struct NoMercenaryHired_Struct {
	/*0000*/ int32_t MercStatus; // Seen -1 with no merc hired
	/*0004*/ uint32_t MercCount; // Seen 0 with no merc hired
	/*0008*/ uint32_t MercID; // Seen 1 when no merc is hired - ID unique to each type of mercenary
	/*0012*/
};

// OP_MercenaryAssign (Same packet as NoMercenaryHired_Struct?)
// Not actually Merc related - This is actually a weapon equp packet
struct MercenaryAssign_Struct {
	/*0000*/ uint32_t MercEntityID; // Seen 0 (no merc spawned) or 615843841 and 22779137
	/*0004*/ uint32_t MercUnk01; //
	/*0008*/ uint32_t MercUnk02; //
	/*0012*/
};

// OP_MercenaryTimer
// Sent on Zone-In, or after Dismissing, Suspending, or Unsuspending Mercs
struct MercenaryStatus_Struct {
	/*0000*/ uint32_t MercEntityID; // Seen 0 (no merc spawned) or 615843841 and 22779137
	/*0004*/ uint32_t UpdateInterval; // Seen 900000 - Matches from 0x6537 packet (15 minutes in ms?)
	/*0008*/ uint32_t MercUnk01; // Seen 180000 - 3 minutes in milleseconds? Maybe next update interval?
	/*0012*/ uint32_t MercState; // Seen 5 (normal) or 1 (suspended)
	/*0016*/ uint32_t SuspendedTime; // Seen 0 (not suspended) or c9 c2 64 4f (suspended on Sat Mar 17 11:58:49 2012) - Unix Timestamp
	/*0020*/
};

// Sent from the client when using the Mercenary Window
struct MercenaryCommand_Struct {
	/*0000*/ uint32_t MercCommand; // Seen 0 (zone in with no merc or suspended), 1 (dismiss merc), 5 (normal state), 36 (zone in with merc)
	/*0004*/ int32_t Option; // Seen -1 (zone in with no merc), 0 (setting to passive stance), 1 (normal or setting to balanced stance)
	/*0008*/
};

// Requesting to suspend or unsuspend merc
struct SuspendMercenary_Struct {
	/*0000*/ uint8_t SuspendMerc; // Seen 30 (48) for suspending or unsuspending
	/*0001*/
};

// Response to suspend merc with timestamp
struct SuspendMercenaryResponse_Struct {
	/*0000*/ uint32_t SuspendTime; // Unix Timestamp - Seen a9 11 78 4f
	/*0004*/
};

// Sent by client when requesting to view Mercenary info or Hire a Mercenary
struct MercenaryMerchantRequest_Struct {
	/*0000*/ uint32_t MercID; // Seen 399 and 400 for merc ID
	/*0004*/ uint32_t MercUnk01; // Seen 1
	/*0008*/ uint32_t MercMerchantID; // Entity ID for Mercenary Merchant
	/*0012*/ uint32_t MercUnk02; // Seen 65302016 (00 6e e4 03) - (probably actually individual uint8_t fields), but seen as DWORD in Seeds client.
	/*0016*/
};

// Sent by Server in response to requesting to view Mercenary info or Hire a Mercenary
struct MercenaryMerchantResponse_Struct {
	/*0000*/ uint32_t ResponseType;
	/*0004*/
};

}

#endif//_EQNET_STRUCTS_ROF_H_
