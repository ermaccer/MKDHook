#include "sareena.h"

// skull toss & bash
struct scan_action_dual scan_sareena_1 = {
	16944,
	0x3000019,
	17,
	MOVE_DOWN,
	MOVE_FORWARD,
	4630,
	0x300001E,
	22,
	MOVE_FORWARD,
	MOVE_FORWARD,
	-1
};


// cartwheel kick
struct scan_action scan_sareena_4 = {
	4630,
	0x300001E,
	19,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};


struct mk_file_entry sareena_entry_table[SAREENA_FILES] = {
	{"sareena.ssf"	,0, 4},

	{"sareena.sec",0, 1},
	{"sareena_ap.sec",0, 1},
	{"sh_sareena.sec",0, 1},
	{"sareena.mko",0, 3},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"sareena_fx.mko",0,3},
	{"bajiquan.mko",0, 3},
	{"style_baji_quan.sec",0,1},
	{"yuanyang.mko",0, 3},
	{"style_yuan_yang.sec",0,1},
	{"demon_sword.mko",0, 3},
	{"style_demon_sword.sec",0,1},
	{"sareena_anims.sec",0, 2},
	{"baji_quan_anims.sec",0, 2},
	{"yuanyang_anims.sec",0, 2},
	{"demon_sword_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\sareena.ssf
struct mk_toc_entry sareena_file_table[SAREENA_FILES + 1] = {
		{&sareena_entry_table[0]	,0,0 },

		{&sareena_entry_table[1]	,0,	   585856 },	// sareena.sec
		{&sareena_entry_table[2]	,0,    585856 },	// sareena_ap.sec
		{&sareena_entry_table[3]	,0,    291200 },	// sh_sareena.sec
		{&sareena_entry_table[4]	,0,    28736  },	// sareena.mko
		{&sareena_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&sareena_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&sareena_entry_table[7]	,0,    8192   },	// sareena_fx.mko
		{&sareena_entry_table[8] 	,0,	   14144  },	// bajiquan.mko
		{&sareena_entry_table[9]	,0,    10112  },	// style_baji_quan.sec
		{&sareena_entry_table[10]	,0,	   12096  },	// yuanyang.mko
		{&sareena_entry_table[11]	,0,    10112  },	// style_yuan_yang.sec
		{&sareena_entry_table[12]	,0,	   15136  },	// demon_sword.mko
		{&sareena_entry_table[13]	,0,	   10112  },	// style_demon_sword.sec
		{&sareena_entry_table[14]	,0,	   65204  },	// sareena_anims.sec
		{&sareena_entry_table[15]	,0,	   149536 },	// baji_quan_anims.sec
		{&sareena_entry_table[16]	,0,	   167680 },	// yuanyang_anims.sec
		{&sareena_entry_table[17]	,0,	   194304 },	// demon_sword_anims.sec
		{&sareena_entry_table[18]	,0,	   53120  },	// pz_noob_anims.sec

		{0,0,0}
};

struct mk_file_entry sareena_alt_entry_table[SAREENA_FILES] = {
	{"sareena_alt.ssf"	,0, 4},

	{"sareena_alt.sec",0, 1},
	{"sareena_alt_ap.sec",0, 1},
	{"sh_sareena.sec",0, 1},
	{"sareena.mko",0, 3},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"sareena_fx.mko",0,3},
	{"bajiquan.mko",0, 3},
	{"style_baji_quan.sec",0,1},
	{"yuanyang.mko",0, 3},
	{"style_yuan_yang.sec",0,1},
	{"demon_sword.mko",0, 3},
	{"style_demon_sword.sec",0,1},
	{"sareena_alt_anims.sec",0, 2},
	{"baji_quan_anims.sec",0, 2},
	{"yuanyang_anims.sec",0, 2},
	{"demon_sword_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\sareena_alt.ssf
struct mk_toc_entry sareena_alt_file_table[SAREENA_FILES + 1] = {
		{&sareena_alt_entry_table[0]	,0,0 },

		{&sareena_alt_entry_table[1]	,0,	   574592 },	// sareena_alt.sec
		{&sareena_alt_entry_table[2]	,0,    525440 },	// sareena_alt_ap.sec
		{&sareena_alt_entry_table[3]	,0,    291200 },	// sh_sareena.sec
		{&sareena_alt_entry_table[4]	,0,    28736  },	// sareena.mko
		{&sareena_alt_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&sareena_alt_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&sareena_alt_entry_table[7]	,0,    8200   },	// sareena_fx.mko
		{&sareena_alt_entry_table[8] 	,0,	   14144  },	// bajiquan.mko
		{&sareena_alt_entry_table[9]	,0,    10112  },	// style_baji_quan.sec
		{&sareena_alt_entry_table[10]	,0,	   12096  },	// yuanyang.mko
		{&sareena_alt_entry_table[11]	,0,    10112  },	// style_yuan_yang.sec
		{&sareena_alt_entry_table[12]	,0,	   15136  },	// demon_sword.mko
		{&sareena_alt_entry_table[13]	,0,	   10112  },	// style_demon_sword.sec
		{&sareena_alt_entry_table[14]	,0,	   65204  },	// sareena_alt_anims.sec
		{&sareena_alt_entry_table[15]	,0,	   149536 },	// baji_quan_anims.sec
		{&sareena_alt_entry_table[16]	,0,	   167680 },	// yuanyang_anims.sec
		{&sareena_alt_entry_table[17]	,0,	   194304 },	// demon_sword_anims.sec
		{&sareena_alt_entry_table[18]	,0,	   53120  },	// pz_noob_anims.sec

		{0,0,0}
};


void init_sareena_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < SAREENA_FILES; i++)
	{
		sareena_entry_table[i].belong = &sareena_file_table[0];
	}


	for (int i = 1; i < SAREENA_FILES; i++)
	{
		sareena_file_table[i].previousSize = baseSize;
		baseSize += (sareena_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;
	for (int i = 0; i < SAREENA_FILES; i++)
	{
		sareena_alt_entry_table[i].belong = &sareena_alt_file_table[0];
	}


	for (int i = 1; i < SAREENA_FILES; i++)
	{
		sareena_alt_file_table[i].previousSize = baseSize;
		baseSize += (sareena_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}
