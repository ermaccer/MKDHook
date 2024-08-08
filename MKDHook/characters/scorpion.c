#include "scorpion.h"


struct scan_action scan_scorpion_2 = {
	16907,
	0x3000019,
	9,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

struct scan_action_dual scan_scorpion_3 = {
	// move 1
	0,
	0x3000019,
	6,
	MOVE_FORWARD,
	MOVE_BACKWARDS,
	// move 2
	16915,
	0x3000019,
	11,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1
};

struct mk_file_entry scorpion2_entry_table[SCORPION_FILES] = {
	{"scorpion2.ssf"	,0, 4},

	{"scorpion.sec",0, 1},
	{"scorpion_ap.sec",0, 1},
	{"sh_scorpion.sec",0, 1},
	{"scorpion.mko",0, 3},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"scorpion_fx.mko",0,3},
	{"hapkido.mko",0, 3},
	{"style_hapkido.sec",0,1},
	{"moifah.mko",0, 3},
	{"style_moifah.sec",0,1},
	{"ninjasword.mko",0, 3},
	{"style_mugai_ryu.sec",0,1},
	{"scorpion_anims.sec",0, 2},
	{"fat_anims_spinerip.sec",0,2},
	{"fat_anims_scorpion.sec",0,2},
	{"hapkido_anims.sec",0, 2},
	{"moifah_anims.sec",0, 2},
	{"ninjasword_anims.sec",0,2},
	{"pz_scorpion_anims.sec",0,2},
};

// I:\ps2dvd\art\scorpion2.ssf
struct mk_toc_entry scorpion2_file_table[SCORPION_FILES + 1] = {
		{&scorpion2_entry_table[0]	,0,0 },

		{&scorpion2_entry_table[1]	,0,	   448768 },	// scorpion.sec
		{&scorpion2_entry_table[2]	,0,    448768 },	// scorpion_ap.sec
		{&scorpion2_entry_table[3]	,0,    306176 },	// sh_scorpion.sec
		{&scorpion2_entry_table[4]	,0,    43520  },	// scorpion.mko
		{&scorpion2_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&scorpion2_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&scorpion2_entry_table[7]	,0,    4724   },	// scorpion_fx.mko
		{&scorpion2_entry_table[8] 	,0,	   15616  },	// hapkido.mko
		{&scorpion2_entry_table[9]	,0,    10112  },	// style_hapkido.sec
		{&scorpion2_entry_table[10]	,0,	   15192  },	// moifah.mko
		{&scorpion2_entry_table[11]	,0,    10112  },	// style_moifah.sec
		{&scorpion2_entry_table[12]	,0,	   14160  },	// ninjasword.mko
		{&scorpion2_entry_table[13]	,0,	   10112  },	// style_mugai_ryu.sec
		{&scorpion2_entry_table[14]	,0,	   189568 },	// scorpion_anims.sec
		{&scorpion2_entry_table[15]	,0,	   65408  },	// fat_anims_spinerip.sec
		{&scorpion2_entry_table[16]	,0,	   113920 },	// fat_anims_scorpion.sec
		{&scorpion2_entry_table[17]	,0,	   182144 },	// hapkido_anims.sec
		{&scorpion2_entry_table[18]	,0,	   148224 },	// moifah_anims.sec
		{&scorpion2_entry_table[19]	,0,	   194560 },	// ninjasword_anims.sec
		{&scorpion2_entry_table[20]	,0,	   88320  },	// pz_scorpion_anims.sec

		{0,0,0}
};


void init_scorpion_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < SCORPION_FILES; i++)
	{
		scorpion2_entry_table[i].belong = &scorpion2_file_table[0];
	}


	for (int i = 1; i < SCORPION_FILES; i++)
	{
		scorpion2_file_table[i].previousSize = baseSize;
		baseSize += (scorpion2_file_table[i].size + 2048 - 1) & -2048;
	}

}
