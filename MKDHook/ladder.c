#include "ladder.h"
#include "mkdeception.h"
#include "stage.h"
#include "ps2mem.h"
#include "character.h"

struct ladder_entry my_ladder[8];

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
	SHAO_KAHN
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



void init_ladder_hook()
{
	makeJal(0x3E7CF8, hook_get_one_tower);
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
	

		_printf("Setting %d as %d on %d\n", i, fighter_id, background_id);
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
