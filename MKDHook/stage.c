#include "toc.h"
#include "stage.h"
#include "mkdeception.h"
#include <stdio.h>
#include "ps2mem.h"
#include "mips.h"


struct mk_file_entry katakombs_entry_table[] = {
	{"katakombs.ssf"	,0, 4},
	{"katakombs.sec"	,0, 1},
	{"katakombs.mko"	,0, 3},
	{"katakombs_fx.mko"	,0, 3},
};

struct mk_toc_entry katakombs_file_table[] = {
		{&katakombs_entry_table[0]	,0,0 },
		{&katakombs_entry_table[1]	,0,2983296},
		{&katakombs_entry_table[2]	,0,2264},
		{&katakombs_entry_table[3]	,0,1576},
		{0,0,0}
};


struct stage_info_entry pStageTable[] = {
	{0x5A3770	, "beetlelair.mko"	, 18	,1,},
	{0x5A3D90	, "courtyard.mko"	, 28	,9,},
	{0x5A4220	, "darkprison.mko"	, 36	,1,},
	{0x5A4450	, "deadpool.mko"	, 32	,9,},
	{0x5A44D0	, "dka.mko"	, 38	,1,},
	{0x5A45C0	, "dragonmountain.mko"	, 26	,1,},
	{0x5A3370	, "fallingcliff.mko"	, 27	,1,},
	{0x5A50B0	, "fortress.mko"	, 34	,1,},
	{0x5A3460	, "hellsfoundry.mko"	, 25	,1,},
	{0x5A5180	, "kangtomb.mko"	, 19	,1,},
	{0x5A3550	, "kuatanpalace.mko"	, 35	,1,},
	{0x5A55C0	, "livingforest.mko"	, 39	,9,},
	{0x5A5690	, "lostwarriors.mko"	, 22	,1,},
	{0x5A5750	, "lower_mines.mko"	, 33	,1,},
	{0x5A5810	, "netherbelly.mko"	, 23	,1,},
	{0x5A5F00	, "nexus_arena.mko"	, 40	,1,},
	{0x5A6920	, "portal.mko"	, 29	,9,},
	{0x5A3660	, "reddragon.mko"	, 21	,1,},
	{0x5A6AB0	, "skytemple.mko"	, 24	,1,},
	{0x5A6C10	, "slaughterhouse.mko"	, 20	,1,},
	{0x5A6CF0	, "thepit.mko"	, 30	,9,},
	{0x5A6DA0	, "yinyang.mko"	, 31	,1,},
	{0x5A5520	, "ladder.mko"	, 0	,32,},
	{0x5A69B0	, "pz_ladder.mko"	, 0	,32,},
	{0x5A53E0	, "krypt.mko"	, 0	,16,},
	{0x5A4790	, "earth_1.mko"	, 0	,4,},
	{0x5A4790	, "earth_1.mko"	, 0	,4,},
	{0x5A4B10	, "earth_2.mko"	, 0	,4,},
	{0x5A5AC0	, "netherrealm_1.mko"	, 0	,4,},
	{0x5A3B40	, "chaosrealm_1.mko"	, 0	,4,},
	{0x5A6730	, "outworld_1.mko"	, 0	,4,},
	{0x5A6380	, "orderrealm_1.mko"	, 0	,4,},
	{0x5A4ED0	, "edenia_1.mko"	, 0	,4,},
	{0x5A5DC0	, "nexus_1.mko"	, 0	,4,},
	{0x5A60C0	, "nexus_nis.mko"	, 0	,0,},
	// new
	{(int)&katakombs_file_table[0]	, "katakombs.mko"	, 0	,0,},
};

struct stage_select_entry pStageSelectNormal[] = {
	{BGS_BEETLELAIR	, "BEETLE LAIR"	,"BGS_BEETLE"	, 6	},
	{BGS_SLAUGHTERHOUSE	, "SLAUGHTERHOUSE"	,"BGS_SLAUGHTER"	, 7	},
	{BGS_SKYTEMPLE	, "SKY TEMPLE"	,"BGS_SKYTEMPLE"	, 7	},
	{BGS_YINYANG	, "YIN YANG ISLAND"	,"BGS_YINYANG"	, 1	},
	{BGS_REDDRAGON	, "CHAMBER OF ARTIFACTS"	,"BGS_REDDRAGON"	, 6	},
	{BGS_NETHERBELLY	, "NETHERSHIP INTERIOR"	,"BGS_NETHERBELLY"	, 2	},
	{BGS_HELLSFOUNDRY	, "HELL'S FOUNDRY"	,"BGS_FOUNDRY"	, 3	},
	{BGS_FALLINGCLIFF	, "FALLING CLIFFS"	,"BGS_CLIFF"	, 1	},
	{BGS_LOSTWARRIORS	, "GOLDEN DESERT"	,"BGS_LOSTWARRIORS"	, 3	},
	{BGS_DARKPRISON	, "DARK PRISON"	,"BGS_PRISON"	, 3	},
	{BGS_LOWERMINES	, "LOWER MINES"	,"BGS_MINES"	, 3	},
	{BGS_DRAGONMOUNTAIN	, "DRAGON MOUNTAIN"	,"BGS_DRAGON"	, 2	},
	{BGS_KANGTOMB	, "LIU KANG'S TOMB"	,"BGS_KANGTOMB"	, 4	},
	{BGS_COURTYARD	, "COURTYARD"	,"BGS_COURTYARD"	, 0	},
	{BGS_PORTAL	, "PORTAL"	,"BGS_PORTAL"	, 0	},
	{BGS_THEPIT	, "THE PIT"	,"BGS_THEPIT"	, 1	},
	{BGS_DEADPOOL	, "DEAD POOL"	,"BGS_DEADPOOL"	, 1	},
	{BGS_FORTRESS	, "QUAN CHI'S FORTRESS"	,"BGS_FORTRESS"	, 1	},
	{BGS_KUATANPALACE	, "KUATAN PALACE"	,"BGS_KUATAN"	, 1	},
	{BGS_LIVINGFOREST	, "LIVING FOREST"	,"BGS_FOREST"	, 0	},
	{BGS_DKA	, "DRAGON KING'S TEMPLE"	,"BGS_DKA"	, 1	},
	{BGS_NEXUS_ARENA	, "NEXUS ARENA"	,"BGS_NEXUS"	, 1	},
	// NEW
	{BGS_KATAKOMBS,	"KATAKOMBS", "NULL"	, 0},
	{BGS_EARTH_1,	"EARTHREALM", "NULL"	, 0},
	{BGS_NETHERREALM,	"NETHERREALM", "NULL"	, 0	},
	{BGS_CHAOSREALM,"CHAOSRREALM"	, "NULL"	, 0	},
	{BGS_OUTWORLD,"ORDERREALM"	, "NULL"	, 0	},
	{BGS_ORDERREALM	,"OUTWORLD", "NULL"	, 0	},
	{BGS_EDENIA,	"EDENIA", "NULL"	, 0	},
};


char* script_name = "katakombs.mko";
void dump_stage_table(unsigned int addr)
{
	int stage_addr = 0x4FBFA0;
	game_printf("STAGE DATA\n");
	char msgBuffer[1256];
	for (int i = 0; i < 35; i++)
	{
		struct  stage_info_entry stage = *(struct stage_info_entry*)(stage_addr + (sizeof(struct stage_info_entry) * i));
		sprintf(msgBuffer, "{0x%X\t, \"%s\"\t, %d\t,%d,},\n",
			stage.file_table,
			stage.scriptName,
			stage.stringID,
			stage.unk2);
		game_printf(msgBuffer);
	}
}
void dump_select_stable(unsigned int addr)
{
	int stage_addr = 0x4FED30;
	char msgBuffer[1256];
	for (int i = 0; i < 22; i++)
	{
		struct  stage_select_entry stage = *(struct stage_select_entry*)(stage_addr + (sizeof(struct stage_select_entry) * i));
		sprintf(msgBuffer, "{%d\t, \"%s\"\t,\"%s\"\t, %d\t},\n",
			stage.id,
			stage.name,
			stage.previewImage,
			stage.unk);
		game_printf(msgBuffer);
	}
}
void patch_stage_data()
{
	int val = 0;
	// SELECT
	short selectSize = sizeof(pStageSelectNormal) / sizeof(pStageSelectNormal[0]);
	patchShort(0x191EAC, selectSize);
	patchShort(0x192D7C, selectSize);
	patchShort(0x192E50, selectSize);
	patchShort(0x193180, selectSize);
	patchShort(0x193070, selectSize);



	val = (int)&pStageSelectNormal[0];


	patchInt(0x191E10, lui(a0, HIWORD(val)));
	patchInt(0x191E24, ori(a0, a0, LOWORD(val)));

	patchInt(0x191EA0, lui(a0, HIWORD(val)));
	patchInt(0x191EB4, ori(a0, a0, LOWORD(val)));
	
	patchInt(0x191F30, lui(a0, HIWORD(val)));
	patchInt(0x191F44, ori(a0, a0, LOWORD(val)));


	patchInt(0x192D70, lui(a1, HIWORD(val)));
	patchInt(0x192D84, ori(a1, a1, LOWORD(val)));


	patchInt(0x192E4C, lui(s2, HIWORD(val)));
	patchInt(0x192E58, ori(s2, s2, LOWORD(val)));


	patchInt(0x193174, lui(s2, HIWORD(val)));
	patchInt(0x193188, ori(s2, s2, LOWORD(val)));

	// NAME
	val += 4;
	patchInt(0x19380C, lui(v0, HIWORD(val)));
	patchInt(0x19380C + 4, ori(v0, v0, LOWORD(val)));


	// STAGE DATA

	// toc
	for (int i = 0; i < 4; i++)
	{
		katakombs_entry_table[i].belong = &katakombs_file_table[0];
	}

	int baseSize = 2048;
	for (int i = 1; i < 4; i++)
	{
		katakombs_file_table[i].previousSize = baseSize;
		baseSize += (katakombs_file_table[i].size + 2048 - 1) & -2048;
	}

	// code
	patchShort(0x13DF28, TOTAL_BACKGROUNDS + 1);
	patchShort(0x16F098, TOTAL_BACKGROUNDS);
	patchShort(0x16F07C, TOTAL_BACKGROUNDS);
	patchShort(0x16F054, TOTAL_BACKGROUNDS);
	patchShort(0x129884, TOTAL_BACKGROUNDS);

	val = (int)&pStageTable[0];
	patchInt(0x15A668, lui(v0, HIWORD(val)));
	patchInt(0x15A670, ori(v0, v0, LOWORD(val)));

	// script
	val += 4;
	patchInt(0x15A680, lui(v0, HIWORD(val)));
	patchInt(0x15A680 + 4, ori(v0, v0, LOWORD(val)));

	// unk2
	val += 8;
	patchInt(0x15A76C, lui(v1, HIWORD(val)));
	patchInt(0x15A76C + 4, ori(v1, v1, LOWORD(val)));

	patchInt(0x15A7E8, lui(v1, HIWORD(val)));
	patchInt(0x15A818, ori(v1, v1, LOWORD(val)));

	// unk
	val -= 4;
	patchInt(0x3E7D94, lui(v0, HIWORD(val)));
	patchInt(0x3E7D94 + 4, ori(v0, v0, LOWORD(val)));

	// lock status

	makeJal(0x13DFE8, hook_bgnd_locked);
	makeJal(0x13E058, hook_bgnd_locked);
	makeJal(0x192EF8, hook_bgnd_locked);
	makeJal(0x3E7BD8, hook_bgnd_locked);
	makeJal(0x3E7C5C, hook_bgnd_locked);
	makeJal(0x3E7D5C, hook_bgnd_locked);
	makeJal(0x3E840C, hook_bgnd_locked);
	makeJal(0x3E857C, hook_bgnd_locked);

	// music

	//makeJal(0x16ED7C, play_kon_music);
	//makeJal(0x3C722C, play_kon_music);
	//makeJal(0x3F3638, play_kon_music);
}
int hook_bgnd_locked(int id)
{
	id = BGS_THEPIT;
	return is_bgnd_locked(id);;
}
void play_kon_music()
{
	int cur_bgnd = *(int*)0x5E4368;

	if (cur_bgnd >= BGS_EARTH_1 && cur_bgnd <= BGS_EDENIA)
	{
		int p_data= *(int*)(0x5E435C);
		int music = randu(24);
		set_music(6939);
	}
	else
		music_proc();
}
void init_stage_hook()
{

	int stage_addr = 0x4FBFA0;
	*(int*)(stage_addr) = (int)&katakombs_file_table[0];
	*(int*)(stage_addr + 4) = (int)&script_name[0];
	*(int*)(stage_addr + 4 + 4) = 0x24;
	*(int*)(stage_addr + 4 + 4 + 4) = 1;

	//*(int*)(0x4FBFA0) = (int)0x4FBFA0;
	//*(int*)(0x4FC1B0 + 4) = (int)&script_name[0];
}