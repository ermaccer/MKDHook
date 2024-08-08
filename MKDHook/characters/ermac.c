#include "ermac.h"

struct scan_action scan_ermac_2 = {
	0,
	0x300000F,
	25,
	MOVE_FORWARD,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

struct mk_file_entry ermac2_entry_table[ERMAC_FILES] = {
	{"ermac2.ssf"	,0, 4},

	{"ermac.sec",0, 1},
	{"ermac_ap.sec",0, 1},
	{"sh_ermac.sec",0, 1},
	{"ermac.mko",0, 3},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"ermac_fx.mko",0,3},
	{"magic_glow_green_fx.mko",0,3},
	{"huachuan.mko",0, 3},
	{"style_hua_chuan.sec",0,1},
	{"choyleefut.mko",0, 3},
	{"style_choy_lee_fut.sec",0,1},
	{"axe.mko",0, 3},
	{"style_axe.sec",0,1},
	{"ermac_anims.sec",0, 2},
	{"fat_anims_kenshi2.sec",0,2},
	{"fat_anims_crunch.sec",0,2},
	{"huachuan_anims.sec",0, 2},
	{"choyleefut_anims.sec",0, 2},
	{"axe_anims.sec",0,2},
	{"pz_ermac_anims.sec",0,2},
};

// I:\ps2dvd\art\ermac2.ssf
struct mk_toc_entry ermac2_file_table[ERMAC_FILES + 1] = {
		{&ermac2_entry_table[0]	,0,0 },

		{&ermac2_entry_table[1]		,0,	   591744 },	// ermac.sec
		{&ermac2_entry_table[2]		,0,    591744 },	// ermac_ap.sec
		{&ermac2_entry_table[3]		,0,    370560 },	// sh_ermac.sec
		{&ermac2_entry_table[4]		,0,    64480  },	// ermac.mko
		{&ermac2_entry_table[5]		,0,    10164  },	// fight_fx.mko
		{&ermac2_entry_table[6]		,0,    21368  },	// blood_fx.mko
		{&ermac2_entry_table[7]		,0,    14124  },	// ermac_fx.mko
		{&ermac2_entry_table[8]		,0,    1292   },	// magic_glow_green_fx.mko
		{&ermac2_entry_table[9] 	,0,	   10552  },	// huachuan.mko
		{&ermac2_entry_table[10]	,0,    10112  },	// style_hua_chuan.sec
		{&ermac2_entry_table[11]	,0,	   12528  },	// choyleefut.mko
		{&ermac2_entry_table[12]	,0,    10112  },	// style_choy_lee_fut.sec
		{&ermac2_entry_table[13]	,0,	   11928  },	// axe.mko
		{&ermac2_entry_table[14]	,0,	   6016   },	// style_axe.sec
		{&ermac2_entry_table[15]	,0,	   177920 },	// ermac_anims.sec
		{&ermac2_entry_table[16]	,0,	   94336  },	// fat_anims_kenshi2.sec
		{&ermac2_entry_table[17]	,0,	   78464  },	// fat_anims_crunch.sec
		{&ermac2_entry_table[18]	,0,	   134272 },	// huachuan_anims.sec
		{&ermac2_entry_table[19]	,0,	   166656 },	// choyleefut_anims.sec
		{&ermac2_entry_table[20]	,0,	   170112 },	// axe_anims.sec
		{&ermac2_entry_table[21]	,0,	   54912  },	// pz_ermac_anims.sec

		{0,0,0}
};

void init_ermac_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < ERMAC_FILES; i++)
	{
		ermac2_entry_table[i].belong = &ermac2_file_table[0];
	}


	for (int i = 1; i < ERMAC_FILES; i++)
	{
		ermac2_file_table[i].previousSize = baseSize;
		baseSize += (ermac2_file_table[i].size + 2048 - 1) & -2048;
	}

}

