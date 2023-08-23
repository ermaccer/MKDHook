#include "drahmin.h"

// uppercut & flies
struct scan_action_dual scan_drahmin_1 = {
	0,
	0x3000019,
	11,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	4613,
	0x3000019,
	27,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,

};

// clock
struct scan_action scan_drahmin_2 = {
	0,
	0x3000023,
	13,
	MOVE_FORWARD,
	MOVE_FORWARD,
	-1,
	0,
	0
};

// groundpound
struct scan_action scan_drahmin_4 = {
	16987,
	0x300001E,
	26,
	MOVE_BACKWARDS,
	MOVE_DOWN,
	-1,
	0,
	0
};

struct mk_file_entry drahmin_entry_table[DRAHMIN_FILES] = {
	{"drahmin.ssf"	,0, 4},

	{"drahmin.sec",0, 1},
	{"drahmin_ap.sec",0, 1},
	{"sh_drahmin.sec",0, 1},
	{"drahmin.mko",0, 3},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"drahmin_fx.mko",0,3},
	{"dhunggar.mko",0, 3},
	{"style_dhunggar.sec",0,1},
	{"wrestling.mko",0, 3},
	{"style_wrestling.sec",0,1},
	{"iron_club.mko",0, 3},
	{"style_iron_club.sec",0,1},
	{"drahmin_anims.sec",0, 2},
	{"fat_anims_backpull.sec",0,2},
	{"dhunggar_anims.sec",0, 2},
	{"wrestling_anims.sec",0, 2},
	{"iron_club_anims.sec",0,2},
	{"pz_scorpion_anims.sec",0,2},
};

// I:\ps2dvd\art\drahmin.ssf
struct mk_toc_entry drahmin_file_table[DRAHMIN_FILES + 1] = {
		{&drahmin_entry_table[0]	,0,0 },

		{&drahmin_entry_table[1]	,0,	   489984 },	// drahmin.sec
		{&drahmin_entry_table[2]	,0,    489984 },	// drahmin_ap.sec
		{&drahmin_entry_table[3]	,0,    333952 },	// sh_drahmin.sec
		{&drahmin_entry_table[4]	,0,    24608  },	// drahmin.mko
		{&drahmin_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&drahmin_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&drahmin_entry_table[7]	,0,    8032   },	// drahmin_fx.mko
		{&drahmin_entry_table[8] 	,0,	   11808  },	// dhunggar.mko
		{&drahmin_entry_table[9]	,0,    10112  },	// style_dhunggar.sec
		{&drahmin_entry_table[10]	,0,	   11776  },	// wrestling.mko
		{&drahmin_entry_table[11]	,0,    10112  },	// style_wrestling.sec
		{&drahmin_entry_table[12]	,0,	   12416  },	// iron_club.mko
		{&drahmin_entry_table[13]	,0,	   10112  },	// style_iron_club.sec
		{&drahmin_entry_table[14]	,0,	   128164 },	// drahmin_anims.sec
		{&drahmin_entry_table[15]	,0,	   100864 },	// fat_anims_backpull.sec
		{&drahmin_entry_table[16]	,0,	   193536 },	// dhunggar_anims.sec 
		{&drahmin_entry_table[17]	,0,	   176052 },	// wrestling_anims.sec
		{&drahmin_entry_table[18]	,0,	   145032 },	// iron_club_anims.sec
		{&drahmin_entry_table[19]	,0,	   88320  },	// pz_scorpion_anims.sec

		{0,0,0}
};

struct mk_file_entry drahmin_alt_entry_table[DRAHMIN_FILES] = {
	{"drahmin_alt.ssf"	,0, 4},

	{"drahmin_alt.sec",0, 1},
	{"drahmin_alt_ap.sec",0, 1},
	{"sh_drahmin.sec",0, 1},
	{"drahmin.mko",0, 3},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"drahmin_fx.mko",0,3},
	{"dhunggar.mko",0, 3},
	{"style_dhunggar.sec",0,1},
	{"wrestling.mko",0, 3},
	{"style_wrestling.sec",0,1},
	{"iron_club.mko",0, 3},
	{"style_iron_club.sec",0,1},
	{"drahmin_alt_anims.sec",0, 2},
	{"fat_anims_backpull.sec",0,2},
	{"dhunggar_anims.sec",0, 2},
	{"wrestling_anims.sec",0, 2},
	{"iron_club_anims.sec",0,2},
	{"pz_scorpion_anims.sec",0,2},
};

// I:\ps2dvd\art\drahmin_alt.ssf
struct mk_toc_entry drahmin_alt_file_table[DRAHMIN_FILES + 1] = {
		{&drahmin_alt_entry_table[0]	,0,0 },

		{&drahmin_alt_entry_table[1]	,0,	   543744 },	// drahmin_alt.sec
		{&drahmin_alt_entry_table[2]	,0,    543744 },	// drahmin_alt_ap.sec
		{&drahmin_alt_entry_table[3]	,0,    333952 },	// sh_drahmin.sec
		{&drahmin_alt_entry_table[4]	,0,    24608  },	// drahmin.mko
		{&drahmin_alt_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&drahmin_alt_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&drahmin_alt_entry_table[7]	,0,    8032   },	// drahmin_fx.mko
		{&drahmin_alt_entry_table[8] 	,0,	   11808  },	// dhunggar.mko
		{&drahmin_alt_entry_table[9]	,0,    10112  },	// style_dhunggar.sec
		{&drahmin_alt_entry_table[10]	,0,	   11776  },	// wrestling.mko
		{&drahmin_alt_entry_table[11]	,0,    10112  },	// style_wrestling.sec
		{&drahmin_alt_entry_table[12]	,0,	   12416  },	// iron_club.mko
		{&drahmin_alt_entry_table[13]	,0,	   10112  },	// style_iron_club.sec
		{&drahmin_alt_entry_table[14]	,0,	   128164 },	// drahmin_alt_anims.sec
		{&drahmin_alt_entry_table[15]	,0,	   100864 },	// fat_anims_backpull.sec
		{&drahmin_alt_entry_table[16]	,0,	   193536 },	// dhunggar_anims.sec 
		{&drahmin_alt_entry_table[17]	,0,	   176052 },	// wrestling_anims.sec
		{&drahmin_alt_entry_table[18]	,0,	   145032 },	// iron_club_anims.sec
		{&drahmin_alt_entry_table[19]	,0,	   88320  },	// pz_scorpion_anims.sec

		{0,0,0}
};


void init_drahmin_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < DRAHMIN_FILES; i++)
	{
		drahmin_entry_table[i].belong = &drahmin_file_table[0];
	}


	for (int i = 1; i < DRAHMIN_FILES; i++)
	{
		drahmin_file_table[i].previousSize = baseSize;
		baseSize += (drahmin_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;
	for (int i = 0; i < DRAHMIN_FILES; i++)
	{
		drahmin_alt_entry_table[i].belong = &drahmin_alt_file_table[0];
	}


	for (int i = 1; i < DRAHMIN_FILES; i++)
	{
		drahmin_alt_file_table[i].previousSize = baseSize;
		baseSize += (drahmin_alt_file_table[i].size + 2048 - 1) & -2048;
	}


}
