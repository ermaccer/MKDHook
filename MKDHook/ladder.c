#include "ladder.h"
#include "mkdeception.h"
#include "stage.h"
#include "ps2mem.h"
#include "character.h"
#include "mips.h"

struct mk_file_entry ladder_entry_table[LADDER_FILES] = {
	{"ladder.ssf"	,0, 4},

	{"ladder.sec",0, 1},
	{"ladder.mko",0, 3},
	{"arcade_ladder_anims.sec",0,2},
};

// I:\ps2dvd\art\ladder.ssf
struct mk_toc_entry ladder_file_table[LADDER_FILES + 1] = {
		{&ladder_entry_table[0]	,0,0 },

		{&ladder_entry_table[1]	,0,	   5217408 },	// ladder.sec
		{&ladder_entry_table[2]	,0,    6688 },		// ladder.mko
		{&ladder_entry_table[3]	,0,    47360  },	// arcade_ladder_anims.sec

		{0,0,0}
};


struct ladder_entry my_ladder[8] = { 0 };

short sub_bosses[] = {
	NOOBSMOKE
};

short characters[] = {
	SCORPION,
	BARAKA,
	SUBZERO,
	MILEENA,
	NIGHTWOLF,
	ERMAC,
	ASHRAH,
	SINDEL,
	LI_MEI,
	BORAICHO,
	HOTARU,
	KENSHI,
	HAVIK,
	TANYA,
	LIU_KANG,
	KIRA,
	KABAL,
	KOBRA,
	JADE,
	DAIROU,
	RAIDEN,
	DARRIUS,
	SHUJINKO,
	SONYA,
	KITANA,
	JAX,
	FROST,
	BLAZE,
	SHAO_KAHN,
	GORO
};

short backgrounds[] = {
	BGS_BEETLELAIR,
	BGS_COURTYARD,
	BGS_DARKPRISON,
	BGS_DEADPOOL,
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
	BGS_KATAKOMBS
};

ladder_model_entry ladder_models[] = {
	{NOOBSMOKE, "NOOBSMOKE"},
	{DARRIUS, "CASSIUS"},
	{RAIDEN, "RAIDEN"},
	{DAIROU, "DAIROU"},
	{JADE, "JADE"},
	{KOBRA, "KOBRA"},
	{KABAL, "KABAL"},
	{KIRA, "KIRA"},
	{LIU_KANG, "LIUKANG"},
	{TANYA, "TANYA"},
	{HAVIK, "SKAB"},
	{HOTARU, "HOTARU"},
	{MILEENA, "MILEENA"},
	{NIGHTWOLF, "NIGHTWOLF"},
	{BORAICHO, "BORAICHO"},
	{BARAKA, "BARAKA"},
	{SCORPION, "SCORPION"},
	{SUBZERO, "SUBZERO"},
	{ERMAC, "ERMAC"},
	{KENSHI, "KENSHI"},
	{SINDEL, "SINDEL"},
	{ASHRAH, "ASHRAH"},
	{LI_MEI, "LIMEI"},
	{SHUJINKO, "SHUJINKO"},
	{JAX, "JAX"},
	{FROST, "FROST"},
	{BLAZE, "BLAZE"},
	{KITANA, "KITANA"},
	{SHAO_KAHN, "SHAOK"},
	{SONYA, "SONYA"},
	{GORO, "GORO"},
	{-1, ""},
};

ladder_stage_entry ladder_stages[] = {
	{BGS_BEETLELAIR, "LADDER_BEETLELAIR", 0x140, 0x21},
	{BGS_COURTYARD, "LADDER_COURTYARD", 0x140, 0x21},
	{BGS_DARKPRISON, "LADDER_DARKPRISON", 0x140, 0x21},
	{BGS_DEADPOOL, "LADDER_DEADPOOL", 0x140, 0x21},
	{BGS_DKA, "LADDER_DKA", 0x140, 0x49},
	{BGS_DRAGONMOUNTAIN, "LADDER_DRAGONMOUNTAIN", 0x140, 0x49},
	{BGS_FALLINGCLIFF, "LADDER_FALLINGCLIFF", 0x140, 0x21},
	{BGS_FORTRESS, "LADDER_FORTRESS", 0x140, 0x49},
	{BGS_HELLSFOUNDRY, "LADDER_HELLSFOUNDRY", 0x140, 0x21},
	{BGS_KANGTOMB, "LADDER_KANGTOMB", 0x140, 0x49},
	{BGS_KUATANPALACE, "LADDER_KUATANPALACE", 0x140, 0x21},
	{BGS_LIVINGFOREST, "LADDER_LIVINGFOREST", 0x140, 0x21},
	{BGS_LOSTWARRIORS, "LADDER_LOSTWARRIORS", 0x140, 0x21},
	{BGS_LOWERMINES, "LADDER_LOWER_MINES", 0x140, 0x21},
	{BGS_NETHERBELLY, "LADDER_NETHERBELLY", 0x140, 0x49},
	{BGS_NEXUS_ARENA, "LADDER_NEXUS", 0x140, 0x21},
	{BGS_PORTAL, "LADDER_PORTAL", 0x140, 0x21},
	{BGS_REDDRAGON, "LADDER_REDDRAGON", 0x140, 0x49},
	{BGS_SKYTEMPLE, "LADDER_SKYTEMPLE", 0x140, 0x21},
	{BGS_SLAUGHTERHOUSE, "LADDER_SLAUGHTERHOUSE", 0x140, 0x49},
	{BGS_THEPIT, "LADDER_THEPIT", 0x140, 0x21},
	{BGS_YINYANG, "LADDER_YINYANG", 0x140, 0x49},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{BGS_KATAKOMBS, "LADDER_KATAKOMBS", 0x140, 0x49}, // 35

};

void init_ladder_hook()
{
	makeJal(0x3E7CF8, hook_get_one_tower);


	int val;
	val = (int)&ladder_models[0];
	patchInt(0x3E8FB8, lui(v1, HIWORD(val)));
	patchInt(0x3E8FC0, ori(v1, v1, LOWORD(val)));

	patchInt(0x3E8FCC, lui(a2, HIWORD(val)));
	patchInt(0x3E8FCC  + 4, ori(a2, a2, LOWORD(val)));

	val += 4;
	patchInt(0x3E8FF4, lui(v1, HIWORD(val)));
	patchInt(0x3E8FFC, ori(v1, v1, LOWORD(val)));


	val = (int)&ladder_stages[0];
	patchInt(0x3E8454, lui(v0, HIWORD(val)));
	patchInt(0x3E8454 + 4, ori(v0, v0, LOWORD(val)));

	val += 8;
	patchInt(0x3E7DB8, lui(a0, HIWORD(val)));
	patchInt(0x3E7DC0, ori(a0, a0, LOWORD(val)));
	
	val += 4;
	patchInt(0x3E7DBC, lui(v1, HIWORD(val)));
	patchInt(0x3E7DC4, ori(v1, v1, LOWORD(val)));


	int baseSize = 2048;
	for (int i = 0; i < LADDER_FILES; i++)
	{
		ladder_entry_table[i].belong = &ladder_file_table[0];
	}


	for (int i = 1; i < LADDER_FILES; i++)
	{
		ladder_file_table[i].previousSize = baseSize;
		baseSize += (ladder_file_table[i].size + 2048 - 1) & -2048;
	}

	// allocate more ram to ladder

	patchInt(0x5852B4, 5300000);
	patchInt(0x584FF4, 5300000);
}

int hook_get_one_tower(int max)
{
	make_custom_tower();
	return 0;
}

void make_custom_tower()
{
	int ladder_addr = 0x57E8A0;
	for (int i = 0; i < 8; i++)
	{
		int fighter_id = -1;
		int background_id = -1;
		int table_size = 0;
		// boss
		if (i == 7)
		{
			fighter_id = ONAGA;
			background_id = BGS_DKA;
		}
		else if (i == 6) // sub boss
		{
			table_size = sizeof(sub_bosses) / sizeof(sub_bosses[0]);
			fighter_id = sub_bosses[randu(table_size)];
		}
		else
		{
			table_size = sizeof(characters) / sizeof(characters[0]);
			fighter_id = characters[randu(table_size)];


			while (is_in_my_ladder(fighter_id))
				fighter_id = characters[randu(table_size)];
		}
		table_size = sizeof(backgrounds) / sizeof(backgrounds[0]);
		if (!(background_id == BGS_DKA))
		{
			background_id = backgrounds[randu(table_size)];

			while (is_map_in_my_ladder(background_id))
				background_id = backgrounds[randu(table_size)];
		}
	
#ifndef PS2_BUILD
		_printf("Setting %d as %d on %d\n", i, fighter_id, background_id);
#endif
		my_ladder[i].background = my_ladder[i].backgroundLocked = background_id;
		my_ladder[i].character = my_ladder[i].characterLocked = fighter_id;
}

	for (int i = 0; i < 8; i++)
	{
		int ladder_entry_addr = (ladder_addr + (sizeof(struct ladder_entry) * i));
		*(struct ladder_entry*)(ladder_entry_addr) = my_ladder[i];
	}
}

int is_in_my_ladder(int id)
{
	int result = 0;
	for (int i = 0; i < 8; i++)
	{
		if (my_ladder[i].character == id)
			result = 1;
	}

	return result;
}

int is_map_in_my_ladder(int id)
{
	int result = 0;
	for (int i = 0; i < 8; i++)
	{
		if (my_ladder[i].background == id)
			result = 1;
	}

	return result;
}

int get_current_ladder_pos()
{
	return *(int*)0x5D72D4;
}

