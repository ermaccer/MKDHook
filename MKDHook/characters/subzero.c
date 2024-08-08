#include "subzero.h"
#include "..\mkdeception.h"
#include "..\ps2mem.h"
#include "..\mips.h"
#include "..\scripthook.h"

struct scan_action scan_subzero_4 = {
	4628,
	0x300001E,
	23,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};

struct mk_file_entry subzero2_entry_table[SUBZERO_FILES] = {
	{"subzero2.ssf"	,0, 4},

	{"subzero.sec",0, 1},
	{"subzero_ap.sec",0, 1},
	{"sh_subzero.sec",0, 1},
	{"subzero.mko",0, 3},
	{"subzero_fx.mko",0,3},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"shotokan.mko",0, 3},
	{"style_shotokan.sec",0,1},
	{"dragons.mko",0, 3},
	{"style_dragons.sec",0,1},
	{"koriblade.mko",0, 3},
	{"style_koriblade.sec",0,1},
	{"subzero_anims.sec",0, 2},
	{"fat_anims_subzero.sec",0,2},
	{"fat_anims_subzero2.sec",0,2},
	{"shotokan_anims.sec",0, 2},
	{"dragons_anims.sec",0, 2},
	{"koriblade_anims.sec",0,2},
	{"pz_subzero_anims.sec",0,2},
};

// I:\ps2dvd\art\subzero2.ssf
struct mk_toc_entry subzero2_file_table[SUBZERO_FILES + 1] = {
		{&subzero2_entry_table[0]	,0,0 },

		{&subzero2_entry_table[1]	,0,	   508672 },	// subzero.sec
		{&subzero2_entry_table[2]	,0,    508672 },	// subzero_ap.sec
		{&subzero2_entry_table[3]	,0,    667008 },	// sh_subzero.sec
		{&subzero2_entry_table[4]	,0,    61088  },	// subzero.mko
		{&subzero2_entry_table[5]	,0,    20784  },	// subzero_fx.mko
		{&subzero2_entry_table[6]	,0,    10164  },	// fight_fx.mko
		{&subzero2_entry_table[7]	,0,    21368  },	// blood_fx.mko
		{&subzero2_entry_table[8] 	,0,	   13972  },	// shotokan.mko
		{&subzero2_entry_table[9]	,0,    10112  },	// style_shotokan.sec
		{&subzero2_entry_table[10]	,0,	   15072  },	// dragons.mko
		{&subzero2_entry_table[11]	,0,    6016   },	// style_dragons.sec
		{&subzero2_entry_table[12]	,0,	   10676  },	// koriblade.mko
		{&subzero2_entry_table[13]	,0,	   10112  },	// style_koriblade.sec
		{&subzero2_entry_table[14]	,0,	   144384 },	// subzero_anims.sec
		{&subzero2_entry_table[15]	,0,	   78208  },	// fat_anims_subzero.sec
		{&subzero2_entry_table[16]	,0,	   102912 },	// fat_anims_subzero2.sec
		{&subzero2_entry_table[17]	,0,	   127872 },	// shotokan_anims.sec
		{&subzero2_entry_table[18]	,0,	   150784 },	// dragons_anims.sec
		{&subzero2_entry_table[19]	,0,	   183168 },	// koriblade_anims.sec
		{&subzero2_entry_table[20]	,0,	   47488  },	// pz_subzero_anims.sec

		{0,0,0}
};

struct mk_file_entry subzero2_alt_entry_table[SUBZERO_FILES] = {
	{"subzero2_alt.ssf"	,0, 4},

	{"subzero_alt.sec",0, 1},
	{"subzero_alt_ap.sec",0, 1},
	{"sh_subzero.sec",0, 1},
	{"subzero.mko",0, 3},
	{"subzero_fx.mko",0,3},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"shotokan.mko",0, 3},
	{"style_shotokan.sec",0,1},
	{"dragons.mko",0, 3},
	{"style_dragons.sec",0,1},
	{"koriblade.mko",0, 3},
	{"style_koriblade.sec",0,1},
	{"subzero_alt_anims.sec",0, 2},
	{"fat_anims_subzero.sec",0,2},
	{"fat_anims_subzero2.sec",0,2},
	{"shotokan_anims.sec",0, 2},
	{"dragons_anims.sec",0, 2},
	{"koriblade_anims.sec",0,2},
	{"pz_subzero_anims.sec",0,2},
};

// I:\ps2dvd\art\subzero2_alt.ssf
struct mk_toc_entry subzero2_alt_file_table[SUBZERO_FILES + 1] = {
		{&subzero2_alt_entry_table[0]	,0,0 },

		{&subzero2_alt_entry_table[1]	,0,	   624128 },	// subzero_alt.sec
		{&subzero2_alt_entry_table[2]	,0,    624128 },	// subzero_alt_ap.sec
		{&subzero2_alt_entry_table[3]	,0,    667008 },	// sh_subzero.sec
		{&subzero2_alt_entry_table[4]	,0,    61088  },	// subzero.mko
		{&subzero2_alt_entry_table[5]	,0,    20784  },	// subzero_fx.mko
		{&subzero2_alt_entry_table[6]	,0,    10164  },	// fight_fx.mko
		{&subzero2_alt_entry_table[7]	,0,    21368  },	// blood_fx.mko
		{&subzero2_alt_entry_table[8] 	,0,	   13972  },	// shotokan.mko
		{&subzero2_alt_entry_table[9]	,0,    10112  },	// style_shotokan.sec
		{&subzero2_alt_entry_table[10]	,0,	   15072  },	// dragons.mko
		{&subzero2_alt_entry_table[11]	,0,    6016   },	// style_dragons.sec
		{&subzero2_alt_entry_table[12]	,0,	   10676  },	// koriblade.mko
		{&subzero2_alt_entry_table[13]	,0,	   10112  },	// style_koriblade.sec
		{&subzero2_alt_entry_table[14]	,0,	   144384 },	// subzero_alt_anims.sec
		{&subzero2_alt_entry_table[15]	,0,	   78208  },	// fat_anims_subzero.sec
		{&subzero2_alt_entry_table[16]	,0,	   102912 },	// fat_anims_subzero2.sec
		{&subzero2_alt_entry_table[17]	,0,	   127872 },	// shotokan_anims.sec
		{&subzero2_alt_entry_table[18]	,0,	   150784 },	// dragons_anims.sec
		{&subzero2_alt_entry_table[19]	,0,	   183168 },	// koriblade_anims.sec
		{&subzero2_alt_entry_table[20]	,0,	   47488  },	// pz_subzero_anims.sec

		{0,0,0}
};



void fat_sz_start_iceblock()
{
	static float blockSize = 0.8f;

	patchShort(0x267E4C, *(short*)((int)&blockSize + 2));
	patchShort(0x267E54, *(short*)((int)&blockSize));

	((void(*)())0x22E820)();
}

void init_subzero_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < SUBZERO_FILES; i++)
	{
		subzero2_entry_table[i].belong = &subzero2_file_table[0];
	}


	for (int i = 1; i < SUBZERO_FILES; i++)
	{
		subzero2_file_table[i].previousSize = baseSize;
		baseSize += (subzero2_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;
	for (int i = 0; i < SUBZERO_FILES; i++)
	{
		subzero2_alt_entry_table[i].belong = &subzero2_alt_file_table[0];
	}


	for (int i = 1; i < SUBZERO_FILES; i++)
	{
		subzero2_alt_file_table[i].previousSize = baseSize;
		baseSize += (subzero2_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}
