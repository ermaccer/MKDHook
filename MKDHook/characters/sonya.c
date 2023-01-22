#include "sonya.h"

// kiss of death
struct scan_action scan_sonya_1 = {
	16933,
	0x3000019,
	20,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

// armed forces
struct scan_action scan_sonya_2 = {
	16924,
	0x3000019,
	17,
	MOVE_DOWN,
	MOVE_FORWARD,
	-1,
	0,
	0
};

// flying boots
struct scan_action scan_sonya_3 = {
	12801,
	0x3000019,
	23,
	MOVE_FORWARD,
	MOVE_FORWARD,
	-1,
	0,
	0,
};

struct mk_file_entry sonya_entry_table[SONYA_FILES] = {
	{"sonya.ssf"	,0, 4},
	{"kira.sec"	,0, 1},
	{"kira_ap.sec"	,0, 1},
	{"kira.mko"	,0, 3},
	{"blood_fx.mko"	,0	,3},
	{"fight_fx.mko"	,0	,3},
	{"kira_fx.mko"	,0	,3},
	{"sh_kira.sec"	,0, 1},
	{"kenpo.mko"	,0, 3},
	{"style_kenpo.sec",0,1 },
	{"taekwondo.mko"	,0, 3},
	{"style_taekwondo.sec",0,1 },
	{"kali.mko"	,0, 3},
	{"style_kali.sec", 0,1 },
	{"kenpo_anims.sec"	,0, 2},
	{"taekwondo_anims.sec"	,0, 2},
	{"kali_anims.sec"	,0, 2},
	{"kira_anims.sec"	,0, 2},
	{"fat_anims_kira_1.sec"	,0, 2},
	{"fat_anims_kira_2.sec"	,0, 2},
	{"pz_mileena_anims.sec"	,0, 2},
};

// I:\ps2dvd\art\sonya.ssf
struct mk_toc_entry sonya_file_table[SONYA_FILES + 1] = {
		{&sonya_entry_table[0]	,0,0 },

		{&sonya_entry_table[1]	,0,461056}, // kira.sec
		{&sonya_entry_table[2]	,0,461056}, // kira_ap.sec
		{&sonya_entry_table[3]	,0,42048}, // kira.mko
		{&sonya_entry_table[4]	,0,21368}, // blood_fx.mko
		{&sonya_entry_table[5]	,0,10164}, // fight_fx.mko
		{&sonya_entry_table[6]	,0,8860}, // kira_fx.mko
		{&sonya_entry_table[7]	,0,237952 }, // sh_kira.sec

		{&sonya_entry_table[8]	,0,15716  }, // kenpo.mko
		{&sonya_entry_table[9]	,0,10112  }, // style_kenpo.sec
		{&sonya_entry_table[10]	,0,17500  }, // taekwondo.mko
		{&sonya_entry_table[11]	,0,10112  }, // style_taekwondo.sec
		{&sonya_entry_table[12]	,0,18756  }, // kali.mko
		{&sonya_entry_table[13]	,0,10112  }, // style_kali.sec

		{&sonya_entry_table[14]	,0,163712 }, // kenpo_anims.sec
		{&sonya_entry_table[15]	,0,166656 }, // taekwondo_anims.sec
		{&sonya_entry_table[16]	,0,189312 }, // kali_anims.sec
		{&sonya_entry_table[17]	,0,156280 }, // kira_anims.sec

		{&sonya_entry_table[18]	,0,120192 }, // fat_anims_kira_1.sec
		{&sonya_entry_table[19]	,0,106596  }, // fat_anims_kira_2.sec

		{&sonya_entry_table[20]	,0,63104  }, // pz_mileena_anims.sec

		{0,0,0}
};


struct mk_file_entry sonya_alt_entry_table[SONYA_FILES] = {
	{"sonya_alt.ssf"	,0, 4},
	{"kira_alt.sec"	,0, 1},
	{"kira_alt_ap.sec"	,0, 1},
	{"kira.mko"	,0, 3},
	{"blood_fx.mko"	,0	,3},
	{"fight_fx.mko"	,0	,3},
	{"kira_fx.mko"	,0	,3},
	{"sh_kira.sec"	,0, 1},
	{"kenpo.mko"	,0, 3},
	{"style_kenpo.sec",0,1 },
	{"taekwondo.mko"	,0, 3},
	{"style_taekwondo.sec",0,1 },
	{"kali.mko"	,0, 3},
	{"style_kali.sec", 0,1 },
	{"kenpo_anims.sec"	,0, 2},
	{"taekwondo_anims.sec"	,0, 2},
	{"kali_anims.sec"	,0, 2},
	{"kira_alt_anims.sec"	,0, 2},
	{"fat_anims_kira_1.sec"	,0, 2},
	{"fat_anims_kira_2.sec"	,0, 2},
	{"pz_mileena_anims.sec"	,0, 2},
};

// I:\ps2dvd\art\sonya_alt.ssf
struct mk_toc_entry sonya_alt_file_table[SONYA_FILES + 1] = {
		{&sonya_alt_entry_table[0]	,0,0 },

		{&sonya_alt_entry_table[1]	,0,496128}, // kira_alt.sec
		{&sonya_alt_entry_table[2]	,0,496128}, // kira_alt_ap.sec
		{&sonya_alt_entry_table[3]	,0,42048}, // kira.mko
		{&sonya_alt_entry_table[4]	,0,21368}, // blood_fx.mko
		{&sonya_alt_entry_table[5]	,0,10164}, // fight_fx.mko
		{&sonya_alt_entry_table[6]	,0,8860}, // kira_fx.mko
		{&sonya_alt_entry_table[7]	,0,237952 }, // sh_kira.sec

		{&sonya_alt_entry_table[8]	,0,15716  }, // kenpo.mko
		{&sonya_alt_entry_table[9]	,0,10112  }, // style_kenpo.sec
		{&sonya_alt_entry_table[10]	,0,17500  }, // taekwondo.mko
		{&sonya_alt_entry_table[11]	,0,10112  }, // style_taekwondo.sec
		{&sonya_alt_entry_table[12]	,0,18756  }, // kali.mko
		{&sonya_alt_entry_table[13]	,0,10112  }, // style_kali.sec

		{&sonya_alt_entry_table[14]	,0,163712 }, // kenpo_anims.sec
		{&sonya_alt_entry_table[15]	,0,166656 }, // taekwondo_anims.sec
		{&sonya_alt_entry_table[16]	,0,189312 }, // kali_anims.sec
		{&sonya_alt_entry_table[17]	,0,156280 }, // kira_alt_anims.sec

		{&sonya_alt_entry_table[18]	,0,120192 }, // fat_anims_kira_1.sec
		{&sonya_alt_entry_table[19]	,0,106596  }, // fat_anims_kira_2.sec

		{&sonya_alt_entry_table[20]	,0,63104  }, // pz_mileena_anims.sec

		{0,0,0}
};


void init_sonya_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < SONYA_FILES; i++)
	{
		sonya_entry_table[i].belong = &sonya_file_table[0];
	}


	for (int i = 1; i < SONYA_FILES; i++)
	{
		sonya_file_table[i].previousSize = baseSize;
		baseSize += (sonya_file_table[i].size + 2048 - 1) & -2048;
	}

	// alt

	baseSize = 2048;
	for (int i = 0; i < SONYA_FILES; i++)
	{
		sonya_alt_entry_table[i].belong = &sonya_alt_file_table[0];
	}


	for (int i = 1; i < SONYA_FILES; i++)
	{
		sonya_alt_file_table[i].previousSize = baseSize;
		baseSize += (sonya_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}
