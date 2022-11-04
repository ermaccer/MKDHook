#pragma once

struct stage_info_entry
{
	int file_table;
	char* scriptName;
	int stringID;
	int unk2;
};

struct stage_select_entry {
	int id;
	char* name;
	char* previewImage;
	int unk;
};
// stage hooks

enum backgrounds {
	BGS_BEETLELAIR,
	BGS_COURTYARD,
	BGS_DARKPRISON,
	BGS_DEADPOOL,
	BGS_DKA,
	BGS_DRAGONMOUNTAIN,
	BGS_FALLINGCLIFF,
	BGS_FORTRESS,
	BGS_HELLSFOUNDRY,
	BGS_KANGTOMB,
	BGS_KUATANPALACE,
	BGS_LIVINGFOREST,
	BGS_LOSTWARRIORS,
	BGS_LOWERMINES,
	BGS_NETHERBELLY,
	BGS_NEXUS_ARENA,
	BGS_PORTAL,
	BGS_REDDRAGON,
	BGS_SKYTEMPLE,
	BGS_SLAUGHTERHOUSE,
	BGS_THEPIT,
	BGS_YINYANG,
	BGS_LADDER,
	BGS_PZ_LADDER,
	BGS_KRYPT,
	BGS_EARTH_1,
	BGS_EARTH_1_2,
	BGS_EARTH_2,
	BGS_NETHERREALM,
	BGS_CHAOSREALM,
	BGS_OUTWORLD,
	BGS_ORDERREALM,
	BGS_EDENIA,
	BGS_NEXUS,
	BGS_NEXUS_NIS,
	// new

	TOTAL_BACKGROUNDS
};

// from mkuhook
void dump_stage_table(unsigned int addr);
void dump_select_stable(unsigned int addr);
void patch_stage_data();

void init_stage_hook();

char* get_arena_name();