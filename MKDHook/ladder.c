#include "ladder.h"
#include "mkdeception.h"
#include "stage.h"
#include "ps2mem.h"
#include "character.h"
#include "mips.h"
#include "scripthook.h"
#include ".\misc\konquest_npc.h"

struct mk_file_entry ladder_entry_table[LADDER_FILES] = {
	{"ladder.ssf"	,0, 4},

	{"ladder.sec",0, 1},
	{"ladder.mko",0, 3},
	{"arcade_ladder_anims.sec",0,2},
};

// I:\ps2dvd\art\ladder.ssf
struct mk_toc_entry ladder_file_table[LADDER_FILES + 1] = {
		{&ladder_entry_table[0]	,0,0 },

		{&ladder_entry_table[1]	,0,	   1935360},	// ladder.sec
		{&ladder_entry_table[2]	,0,    6688 },		// ladder.mko
		{&ladder_entry_table[3]	,0,    47360},	// arcade_ladder_anims.sec

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
	GORO,
	DRAHMIN,
	SAREENA,
	QUAN_CHI,
	SHANG_TSUNG,
	KUNG_LAO,
	CAGE,
	SEKTOR,
	RAIN,
	NITARA,
	TREMOR,
	CYRAX,
	REIKO
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
	BGS_KATAKOMBS,
	BGS_ACIDBATH
};

ladder_model_entry ladder_models[] = {
	{NOOBSMOKE, "kon_noob.sec"},
	{DARRIUS, "kon_darrius.sec"},
	{RAIDEN, "kon_raidenmk6.sec"},
	{DAIROU, "kon_dairou.sec"},
	{JADE, "kon_jade.sec"},
	{KOBRA, "kon_kobra.sec"},
	{KABAL, "kon_kabal.sec"},
	{KIRA, "kon_kira.sec"},
	{LIU_KANG, "kon_kang_dead.sec"},
	{TANYA, "kon_tanya.sec"},
	{HAVIK, "kon_havik.sec"},
	{HOTARU, "kon_hotaru.sec"},
	{MILEENA, "kon_mileena.sec"},
	{NIGHTWOLF, "kon_nightwolf.sec"},
	{BORAICHO, "kon_boraicho.sec"},
	{BARAKA, "kon_baraka.sec"},
	{SCORPION, "kon_scorpion.sec"},
	{SUBZERO, "kon_subzero.sec"},
	{ERMAC, "kon_ermac.sec"},
	{KENSHI, "kon_kenshi.sec"},
	{SINDEL, "kon_sindel.sec"},
	{ASHRAH, "kon_ashrah.sec"},
	{LI_MEI, "kon_limei.sec"},
	{SHUJINKO, "SHUJINKO"},
	{JAX, "kon_jax.sec"},
	{FROST, "kon_frost.sec"},
	{BLAZE, "kon_blaze.sec"},
	{KITANA, "kon_kitana.sec"},
	{SHAO_KAHN, "kon_shaok.sec"},
	{SONYA, "kon_sonya.sec"},
	{GORO, "kon_goro.sec"},
	{DRAHMIN, "kon_drahmin.sec"},
	{SAREENA, "kon_sareena.sec"},
	{QUAN_CHI,"kon_quanchi.sec"},
	{SHANG_TSUNG, "kon_shangmk5.sec"},
	{KUNG_LAO, "kon_kunglao.sec"},
	{CAGE, "kon_cage.sec"},
	{SEKTOR, "kon_sektor.sec"},
	{RAIN, "kon_rain.sec"},
	{NITARA, "kon_nitara.sec"},
	{TREMOR, "kon_tremor.sec"},
	{CYRAX, "kon_cyrax.sec"},
	{REIKO, "kon_reiko.sec"},
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
	{BGS_ACIDBATH, "LADDER_ACIDBATH", 0x140, 0x49}, // 36

};

void init_ladder_hook()
{
	makeJal(0x3E7CF8, hook_get_one_tower);
	makeJal(0x3E82A8, ladder_load_npcs);
	makeJal(0x3E9038, load_ladder_model);



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


	

	static int newLadderLayout[] = {
		0x6D,	LADDER_MAIN_BUFFER,		// main ladder buffer + smoke
		0x6E,	LADDER_CHAR_BUFFER,		// ladder secs 
		0xFFFFFFFF, 0
	};


	patchInt(0x5852B4, LADDER_MAIN_BUFFER + LADDER_CHAR_BUFFER);
	patchInt(0x5852B0, (int)&newLadderLayout[0]);
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

void ladder_load_npcs()
{
	load_background_hook(BGS_LADDER);
	load_new_kon_npc();
}

int load_ladder_model(int slot, char* name, int id, int unk)
{
	int obj = 0;

	if (name)
	{
		if (name[0] == 'k' && name[1] == 'o' && name[2] == 'n')
		{
			int sec = find_section_by_name(name);
			int newSlot = 0x18006E;

			if (sec)
			{
				add_art_section(newSlot, sec);
				obj = load_named_model_from_slot(newSlot, "NPC", 0xC022, 0);
			}
		}
		else
			obj = load_named_model_from_slot(slot, name, 0xC022, 0);
	}

	return obj;
}

int get_current_ladder_pos()
{
	return *(int*)0x5D72D4;
}
