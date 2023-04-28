#include "shaokahn.h"
#include "..\mkdeception.h"

// force field & fireball & taunt
struct scan_action_triple scan_sk_1 = {
	4613,
	0x3000019,
	12,
	MOVE_DOWN,
	MOVE_FORWARD,
	// forcefield
	16984,
	0x3000019,
	16,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	// taunt
	0,
	0x3000019,
	24,
	MOVE_DOWN,
	MOVE_UP,
	-1,
};

// charge
struct scan_action_dual_fatality scan_sk_2 = {
	16982,
	0x3000019,
	17,
	MOVE_FORWARD,
	MOVE_FORWARD,
	
	// fatality one
	2.0f,
	0x1000032,
	DO_FATALITY_ONE,
	MOVE_DOWN,
	MOVE_UP,
	MOVE_UP,
	MOVE_FORWARD,
	// fatality two
	2.0f,
	0x1000032,
	DO_FATALITY_TWO,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	MOVE_DOWN,
	MOVE_FORWARD,
	-1
};

// knee
struct scan_action scan_sk_3 = {
	16983,
	0x300001E,
	19,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};

// hk
struct scan_suicide scan_sk_suicide = {
	// fatality two
	2.0f,
	0x1000032,
	DO_HARAKIRI,
	MOVE_DOWN,
	MOVE_UP,
	MOVE_UP,
	MOVE_DOWN,
	-1
};

struct mk_file_entry sk_entry_table[SK_FILES] = {
	{"shaokahn.ssf"	,0, 4},

	{"shaokahn.sec",0, 1},
	{"shaokahn_ap.sec",0, 1},
	{"shaokahn.mko",0, 3},
	{"sh_shaokahn.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"shaokahn_fx.mko",0,3},
	{"shk_1.mko",0, 3},
	{"style_shk_1.sec",0,1},
	{"shk_2.mko",0, 3},
	{"style_shk_2.sec",0,1},
	{"shk_ham.mko",0, 3},
	{"style_shk_ham.sec",0,1},
	{"shaokahn_anims.sec",0, 2},
	{"fat_anims_shaokhan_golf.sec",0,2},
	{"fat_anims_shaokhan_homerun.sec",0,2},
	{"shk_1_anims.sec",0, 2},
	{"shk_2_anims.sec",0, 2},
	{"shk_ham_anims.sec",0,2},
	{"pz_shaokahn_anims.sec",0,2},
};

// I:\ps2dvd\art\shaokahn.ssf
struct mk_toc_entry sk_file_table[SK_FILES + 1] = {
		{&sk_entry_table[0]	,0,0 },

		{&sk_entry_table[1]	,0,	   470144 },	// shaokahn.sec
		{&sk_entry_table[2]	,0,    470144 },	// shaokahn_ap.sec
		{&sk_entry_table[3]	,0,    48512  },	// shaokahn.mko
		{&sk_entry_table[4]	,0,    321920 },	// sh_shaokahn.sec
		{&sk_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&sk_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&sk_entry_table[7]	,0,    12352  },	// shaokahn_fx.mko
		{&sk_entry_table[8] ,0,	   10560  },	// shk_1.mko
		{&sk_entry_table[9]	,0,    10112   },	// style_shk_1.sec
		{&sk_entry_table[10],0,	   12320  },	// shk_2.mko
		{&sk_entry_table[11],0,    10112   },	// style_shk_2.sec
		{&sk_entry_table[12],0,	   10688  },	// shk_ham.mko
		{&sk_entry_table[13],0,	   10112   },	// style_shk_ham.sec
		{&sk_entry_table[14],0,	   142080 },	// shaokahn_anims.sec
		{&sk_entry_table[15],0,	   95232  },	// fat_anims_shaokhan_golf.sec
		{&sk_entry_table[16],0,	   82560  },	// fat_anims_shaokhan_homerun.sec
		{&sk_entry_table[17],0,	   157484 },	// shk_1_anims.sec
		{&sk_entry_table[18],0,	   123392 },	// shk_2_anims.sec
		{&sk_entry_table[19],0,	   153472 },	// shk_ham_anims.sec
		{&sk_entry_table[20],0,	   52352  },	// pz_shaokahn_anims.sec

		{0,0,0}
};

struct mk_file_entry sk_alt_entry_table[SK_FILES] = {
	{"shaokahn_alt.ssf"	,0, 4},

	{"shaokahn_alt.sec",0, 1},
	{"shaokahn_alt_ap.sec",0, 1},
	{"shaokahn.mko",0, 3},
	{"sh_shaokahn.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"shaokahn_fx.mko",0,3},
	{"shk_1.mko",0, 3},
	{"style_shk_1.sec",0,1},
	{"shk_2.mko",0, 3},
	{"style_shk_2.sec",0,1},
	{"shk_ham.mko",0, 3},
	{"style_shk_ham.sec",0,1},
	{"shaokahn_alt_anims.sec",0, 2},
	{"fat_anims_shaokhan_golf.sec",0,2},
	{"fat_anims_shaokhan_homerun.sec",0,2},
	{"shk_1_anims.sec",0, 2},
	{"shk_2_anims.sec",0, 2},
	{"shk_ham_anims.sec",0,2},
	{"pz_shaokahn_anims.sec",0,2},
};

// I:\ps2dvd\art\shaokahn_alt.ssf
struct mk_toc_entry sk_alt_file_table[SK_FILES + 1] = {
		{&sk_alt_entry_table[0]	,0,0 },

		{&sk_alt_entry_table[1]	,0,	   493696 },	// shaokahn_alt.sec
		{&sk_alt_entry_table[2]	,0,    493696 },	// shaokahn_alt_ap.sec
		{&sk_alt_entry_table[3]	,0,    48512  },	// shaokahn.mko
		{&sk_alt_entry_table[4]	,0,    321920 },	// sh_shaokahn.sec
		{&sk_alt_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&sk_alt_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&sk_alt_entry_table[7]	,0,    12352  },	// shaokahn_fx.mko
		{&sk_alt_entry_table[8] ,0,	   10560  },	// shk_1.mko
		{&sk_alt_entry_table[9]	,0,    10112   },	// style_shk_1.sec
		{&sk_alt_entry_table[10],0,	   12320  },	// shk_2.mko
		{&sk_alt_entry_table[11],0,    10112   },	// style_shk_2.sec
		{&sk_alt_entry_table[12],0,	   10688  },	// shk_ham.mko
		{&sk_alt_entry_table[13],0,	   10112   },	// style_shk_ham.sec
		{&sk_alt_entry_table[14],0,	   142080 },	// shaokahn_alt_anims.sec
		{&sk_alt_entry_table[15],0,	   95232  },	// fat_anims_shaokhan_golf.sec
		{&sk_alt_entry_table[16],0,	   82560  },	// fat_anims_shaokhan_homerun.sec
		{&sk_alt_entry_table[17],0,	   157484 },	// shk_1_anims.sec
		{&sk_alt_entry_table[18],0,	   123392 },	// shk_2_anims.sec
		{&sk_alt_entry_table[19],0,	   153472 },	// shk_ham_anims.sec
		{&sk_alt_entry_table[20],0,	   52352  },	// pz_shaokahn_anims.sec

		{0,0,0}
};



void init_sk_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < SK_FILES; i++)
	{
		sk_entry_table[i].belong = &sk_file_table[0];
	}


	for (int i = 1; i < SK_FILES; i++)
	{
		sk_file_table[i].previousSize = baseSize;
		baseSize += (sk_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;
	for (int i = 0; i < SK_FILES; i++)
	{
		sk_alt_entry_table[i].belong = &sk_alt_file_table[0];
	}


	for (int i = 1; i < SK_FILES; i++)
	{
		sk_alt_file_table[i].previousSize = baseSize;
		baseSize += (sk_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}

void get_taunts_performed()
{
	int args = *(int*)(CURRENT_ARGS);
	int result = randu(3);
	int* ac = (int*)ACTIVE_SCRIPT;
	ac[11] = result;
}

void increment_taunts_performed()
{
	// no need to implement this due to fact theres no taunt limit anymore
}
