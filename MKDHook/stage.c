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
};

struct stage_select_entry pStageSelectNormal[] = {
	{0	, "BEETLE LAIR"	,"BGS_BEETLE"	, 6	},
	{19	, "SLAUGHTERHOUSE"	,"BGS_SLAUGHTER"	, 7	},
	{18	, "SKY TEMPLE"	,"BGS_SKYTEMPLE"	, 7	},
	{21	, "YIN YANG ISLAND"	,"BGS_YINYANG"	, 1	},
	{17	, "CHAMBER OF ARTIFACTS"	,"BGS_REDDRAGON"	, 6	},
	{14	, "NETHERSHIP INTERIOR"	,"BGS_NETHERBELLY"	, 2	},
	{8	, "HELL'S FOUNDRY"	,"BGS_FOUNDRY"	, 3	},
	{6	, "FALLING CLIFFS"	,"BGS_CLIFF"	, 1	},
	{12	, "GOLDEN DESERT"	,"BGS_LOSTWARRIORS"	, 3	},
	{2	, "DARK PRISON"	,"BGS_PRISON"	, 3	},
	{13	, "LOWER MINES"	,"BGS_MINES"	, 3	},
	{5	, "DRAGON MOUNTAIN"	,"BGS_DRAGON"	, 2	},
	{9	, "LIU KANG'S TOMB"	,"BGS_KANGTOMB"	, 4	},
	{1	, "COURTYARD"	,"BGS_COURTYARD"	, 0	},
	{16	, "PORTAL"	,"BGS_PORTAL"	, 0	},
	{20	, "THE PIT"	,"BGS_THEPIT"	, 1	},
	{3	, "DEAD POOL"	,"BGS_DEADPOOL"	, 1	},
	{7	, "QUAN CHI'S FORTRESS"	,"BGS_FORTRESS"	, 1	},
	{10	, "KUATAN PALACE"	,"BGS_KUATAN"	, 1	},
	{11	, "LIVING FOREST"	,"BGS_FOREST"	, 0	},
	{4	, "DRAGON KING'S TEMPLE"	,"BGS_DKA"	, 1	},
	{15	, "NEXUS ARENA"	,"BGS_NEXUS"	, 1	},
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
	short selectSize = sizeof(pStageSelectNormal) / sizeof(pStageSelectNormal[0]);
	patchShort(0x191EAC, selectSize);
	patchShort(0x192D7C, selectSize);
	patchShort(0x192E50, selectSize);
	patchShort(0x193180, selectSize);

	int val = 0;
	int output = 0;

	// stage selection
	val = (int)&pStageSelectNormal[0];

	output = li(a0, val);
	patchInt(0x191E24, output);

	output = li(a0, val);
	patchInt(0x191EB4, output);

	output = li(a0, val);
	patchInt(0x191F44, output);

	output = li(a1, val);
	patchInt(0x192D84, output);

	output = li(s2, val);
	patchInt(0x192E58, output);

	output = li(s2, val);
	patchInt(0x193188, output);
}
void init_stage_hook()
{
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
	int stage_addr = 0x4FBFA0;
	*(int*)(stage_addr) = (int)&katakombs_file_table[0];
	*(int*)(stage_addr + 4) = (int)&script_name[0];
	*(int*)(stage_addr + 4 + 4) = 0x24;
	*(int*)(stage_addr + 4 + 4 + 4) = 1;

	//*(int*)(0x4FBFA0) = (int)0x4FBFA0;
	//*(int*)(0x4FC1B0 + 4) = (int)&script_name[0];
}