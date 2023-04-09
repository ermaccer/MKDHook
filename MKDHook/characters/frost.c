#include "frost.h"
#include "..\mkdeception.h"
#include "..\ps2mem.h"
#include "..\mips.h"
#include "..\scripthook.h"

// freeze kick
struct scan_fatality scan_frost_1 = {
	2.0f,
	0x1000032,
	DO_FATALITY_ONE,
	MOVE_FORWARD,
	MOVE_BACKWARDS,
	MOVE_UP,
	MOVE_DOWN,
	-1,
};


// ground freeze
struct scan_action scan_frost_3 = {
	4613,
	0x3000019,
	10,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

// slide
struct scan_action scan_frost_4 = {
	4626,
	0x3000019,
	24,
	MOVE_DOWN,
	MOVE_FORWARD,
	-1,
	0,
	0
};



struct mk_file_entry frost_entry_table[FROST_FILES] = {
	{"frost.ssf"	,0, 4},

	{"frost.sec",0, 1},
	{"frost_ap.sec",0, 1},
	{"frost.mko",0, 3},
	{"sh_frost.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"frost_fx.mko",0,3},
	{"tongbei.mko",0, 3},
	{"style_tongbei.sec",0,1},
	{"yuanyang.mko",0, 3},
	{"style_yuan_yang.sec",0,1},
	{"daggers.mko",0, 3},
	{"style_daggers.sec",0,1},
	{"frost_anims.sec",0, 2},
	{"tongbei_anims.sec",0,2},
	{"yuanyang_anims.sec",0,2},
	{"daggers_anims.sec",0, 2},
	{"fat_anims_subzero2.sec",0, 2},
	{"fat_anims_frost1.sec",0,2},
	{"pz_jax_anims.sec",0,2},
};

// I:\ps2dvd\art\frost.ssf
struct mk_toc_entry frost_file_table[FROST_FILES + 1] = {
		{&frost_entry_table[0]	,0,0 },

		{&frost_entry_table[1]	,0,	   492032 },	// frost.sec
		{&frost_entry_table[2]	,0,    492032 },	// frost_ap.sec
		{&frost_entry_table[3]	,0,    34624  },	// frost.mko
		{&frost_entry_table[4]	,0,    654720 },	// sh_frost.sec
		{&frost_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&frost_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&frost_entry_table[7]	,0,    23904  },	// frost_fx.mko
		{&frost_entry_table[8]  ,0,	   14112  },	// tongbei.mko
		{&frost_entry_table[9]	,0,    10112   },	// style_tongbei.sec
		{&frost_entry_table[10] ,0,	   12128  },	// yuanyang.mko
		{&frost_entry_table[11] ,0,    10112   },	// style_yuan_yang.sec
		{&frost_entry_table[12] ,0,	   11104  },	// daggers.mko
		{&frost_entry_table[13] ,0,	   10112   },	// style_daggers.sec
		{&frost_entry_table[14] ,0,	   58112  },	// frost_anims.sec
		{&frost_entry_table[15] ,0,	   151808 },	// tongbei_anims.sec
		{&frost_entry_table[16] ,0,	   167680 },	// yuanyang_anims.sec
		{&frost_entry_table[17] ,0,	   217344 },	// daggers_anims.sec
		{&frost_entry_table[18] ,0,	   112000 },	// fat_anims_subzero2.sec
		{&frost_entry_table[19] ,0,	   51328  },	// fat_anims_frost1.sec
		{&frost_entry_table[20] ,0,	   52352  },	// pz_jax_anims.sec


		{0,0,0}
};


struct mk_file_entry frost_alt_entry_table[FROST_FILES] = {
	{"frost_alt.ssf"	,0, 4},

	{"frost_alt.sec",0, 1},
	{"frost_alt_ap.sec",0, 1},
	{"frost.mko",0, 3},
	{"sh_frost.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"frost_fx.mko",0,3},
	{"tongbei.mko",0, 3},
	{"style_tongbei.sec",0,1},
	{"yuanyang.mko",0, 3},
	{"style_yuan_yang.sec",0,1},
	{"daggers.mko",0, 3},
	{"style_daggers.sec",0,1},
	{"frost_alt_anims.sec",0, 2},
	{"tongbei_anims.sec",0,2},
	{"yuanyang_anims.sec",0,2},
	{"daggers_anims.sec",0, 2},
	{"fat_anims_subzero2.sec",0, 2},
	{"fat_anims_frost1.sec",0,2},
	{"pz_jax_anims.sec",0,2},
};

// I:\ps2dvd\art\frost_alt.ssf
struct mk_toc_entry frost_alt_file_table[FROST_FILES + 1] = {
		{&frost_alt_entry_table[0]	,0,0 },

		{&frost_alt_entry_table[1]	,0,	   485120 },	// frost_alt.sec
		{&frost_alt_entry_table[2]	,0,    485120 },	// frost_alt_ap.sec
		{&frost_alt_entry_table[3]	,0,    34624  },	// frost.mko
		{&frost_alt_entry_table[4]	,0,    654720 },	// sh_frost.sec
		{&frost_alt_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&frost_alt_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&frost_alt_entry_table[7]	,0,    23904  },	// frost_fx.mko
		{&frost_alt_entry_table[8]  ,0,	   14112  },	// tongbei.mko
		{&frost_alt_entry_table[9]	,0,    10112   },	// style_tongbei.sec
		{&frost_alt_entry_table[10] ,0,	   12128  },	// yuanyang.mko
		{&frost_alt_entry_table[11] ,0,    10112   },	// style_yuan_yang.sec
		{&frost_alt_entry_table[12] ,0,	   11104  },	// daggers.mko
		{&frost_alt_entry_table[13] ,0,	   10112   },	// style_daggers.sec
		{&frost_alt_entry_table[14] ,0,	   58112  },	// frost_alt_anims.sec
		{&frost_alt_entry_table[15] ,0,	   151808 },	// tongbei_anims.sec
		{&frost_alt_entry_table[16] ,0,	   167680 },	// yuanyang_anims.sec
		{&frost_alt_entry_table[17] ,0,	   217344 },	// daggers_anims.sec
		{&frost_alt_entry_table[18] ,0,	   112000 },	// fat_anims_subzero2.sec
		{&frost_alt_entry_table[19] ,0,	   51328  },	// fat_anims_frost1.sec
		{&frost_alt_entry_table[20] ,0,	   52352  },	// pz_jax_anims.sec


		{0,0,0}
};



void init_frost_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < FROST_FILES; i++)
	{
		frost_entry_table[i].belong = &frost_file_table[0];
	}


	for (int i = 1; i < FROST_FILES; i++)
	{
		frost_file_table[i].previousSize = baseSize;
		baseSize += (frost_file_table[i].size + 2048 - 1) & -2048;
	}

	// alt

	baseSize = 2048;
	for (int i = 0; i < FROST_FILES; i++)
	{
		frost_alt_entry_table[i].belong = &frost_alt_file_table[0];
	}


	for (int i = 1; i < FROST_FILES; i++)
	{
		frost_alt_file_table[i].previousSize = baseSize;
		baseSize += (frost_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}

// PSP values
// $f12 - 1.8
// $f13 - 0.17500 - actually too fast and iceblock doesnt grow long enough to match the animation

void fat_frost_start_iceblock()
{
	static float blockSize = 1.8f;
	static float blockRate = 0.175f;

	patchShort(0x267E4C, *(short*)((int)&blockSize + 2));
	patchShort(0x267E54, *(short*)((int)&blockSize));

	((void(*)())0x22E820)();
}


void fat_frost_start_icechunks()
{
	call_script_function(1490);
}
