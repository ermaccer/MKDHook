#include "raiden.h"


struct mk_file_entry raiden2_entry_table[RAIDEN_FILES] = {
	{"raiden2.ssf"	,0, 4},

	{"raiden.sec",0, 1},
	{"raiden_ap.sec",0, 1},
	{"raiden.mko",0, 3},
	{"sh_raiden.sec",0, 1},
	{"blood_fx.mko",0,3},
	{"fight_fx.mko",0,3},
	{"raiden_fx.mko",0,3},
	{"nanchuan.mko",0, 3},
	{"style_nanchuan.sec",0,1},
	{"jujutsu.mko",0, 3},
	{"style_jujutsu.sec",0,1},
	{"staff.mko",0, 3},
	{"style_staff.sec",0,1},
	{"raiden_anims.sec",0, 2},
	{"fat_anims_raiden_1.sec",0,2},
	{"fat_anims_raiden_2.sec",0,2},
	{"nanchuan_anims.sec",0, 2},
	{"jujutsu_anims.sec",0, 2},
	{"staff_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\raiden2.ssf
struct mk_toc_entry raiden2_file_table[RAIDEN_FILES + 1] = {
		{&raiden2_entry_table[0]	,0,0 },

		{&raiden2_entry_table[1]	,0,	   449536 },	// raiden.sec
		{&raiden2_entry_table[2]	,0,    449536 },	// raiden_ap.sec
		{&raiden2_entry_table[3]	,0,    91872  },	// raiden.mko
		{&raiden2_entry_table[4]	,0,    482560 },	// sh_raiden.sec
		{&raiden2_entry_table[5]	,0,    21368  },	// blood_fx.mko
		{&raiden2_entry_table[6]	,0,    10164  },	// fight_fx.mko
		{&raiden2_entry_table[7]	,0,    20112  },	// raiden_fx.mko
		{&raiden2_entry_table[8] 	,0,	   13200  },	// nanchuan.mko
		{&raiden2_entry_table[9]	,0,    10112  },	// style_nanchuan.sec
		{&raiden2_entry_table[10]	,0,	   12380  },	// jujutsu.mko
		{&raiden2_entry_table[11]	,0,    10112  },	// style_jujutsu.sec
		{&raiden2_entry_table[12]	,0,	   11716  },	// staff.mko
		{&raiden2_entry_table[13]	,0,	   10112  },	// style_staff.sec
		{&raiden2_entry_table[14]	,0,	   165632 },	// raiden_anims.sec
		{&raiden2_entry_table[15]	,0,	   37504  },	// fat_anims_raiden_1.sec
		{&raiden2_entry_table[16]	,0,	   66944  },	// fat_anims_raiden_2.sec
		{&raiden2_entry_table[17]	,0,	   150784 },	// nanchuan_anims.sec
		{&raiden2_entry_table[18]	,0,	   147200 },	// jujutsu_anims.sec
		{&raiden2_entry_table[19]	,0,	   207616 },	// staff_anims.sec
		{&raiden2_entry_table[20]	,0,	   53120  },	// pz_noob_anims.sec

		{0,0,0}
};



void init_raiden_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < RAIDEN_FILES; i++)
	{
		raiden2_entry_table[i].belong = &raiden2_file_table[0];
	}


	for (int i = 1; i < RAIDEN_FILES; i++)
	{
		raiden2_file_table[i].previousSize = baseSize;
		baseSize += (raiden2_file_table[i].size + 2048 - 1) & -2048;
	}

}
