#include "dragonking.h"
#include "..\mkdeception.h"
#include "..\ladder.h"
#include "..\ps2mem.h"
#include "..\mips.h"



struct mk_file_entry dragonking_entry_table[DRAGONKING_FILES] = {
	{"dragonking.ssf"	,0, 4},

	{"dragonking.sec",0, 1},
	{"dragonking_ap.sec",0, 1},
	{"dragonking.mko",0, 3},
	{"sh_dragonking.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"dragonking_fx.mko",0,3},
	{"dragon_king.mko",0, 3},
	{"style_dragon_king.sec",0,1},
	{"dragonking_anims.sec",0, 2},
	{"dragon_king_anims.sec",0, 2},
	{"pz_dragonking_anims.sec",0, 2},

};


// I:\ps2dvd\art\dragonking.ssf
struct mk_toc_entry dragonking_file_table[DRAGONKING_FILES + 1] = {
		{&dragonking_entry_table[0]	,0,0 },

		{&dragonking_entry_table[1]		,0,	   488576 },	// dragonking.sec
		{&dragonking_entry_table[2]		,0,    488576 },	// dragonking_ap.sec
		{&dragonking_entry_table[3]		,0,    57056  },	// dragonking.mko
		{&dragonking_entry_table[4]		,0,    210816 },	// sh_dragonking.sec
		{&dragonking_entry_table[5]		,0,    10164  },	// fight_fx.mko
		{&dragonking_entry_table[6]		,0,    21368  },	// blood_fx.mko
		{&dragonking_entry_table[7]		,0,    20176  },	// dragonking_fx.mko
		{&dragonking_entry_table[8] 	,0,	   9064   },	// dragon_king.mko
		{&dragonking_entry_table[9]		,0,    6016   },	// style_dragon_king.sec
		{&dragonking_entry_table[10]	,0,	   187136 },	// dragonking_anims.sec
		{&dragonking_entry_table[11]	,0,    131968 },	// dragon_king_anims.sec
		{&dragonking_entry_table[12]	,0,	   62080  },	// pz_dragonking_anims.sec

		{0,0,0}
};



void hook_xfer_to_intro(int obj, int proc)
{
	if (get_current_ladder_pos() == 7)
		xfer_proc(obj, proc);
}

void hook_wait_for_intro()
{
	if (get_current_ladder_pos() == 7)
		((void(*)())0x241860)();
}

void init_dragonking_toc()
{
	init_dragonking_patches();

	int baseSize = 2048;
	for (int i = 0; i < DRAGONKING_FILES; i++)
	{
		dragonking_entry_table[i].belong = &dragonking_file_table[0];
	}


	for (int i = 1; i < DRAGONKING_FILES; i++)
	{
		dragonking_file_table[i].previousSize = baseSize;
		baseSize += (dragonking_file_table[i].size + 2048 - 1) & -2048;
	}

}

void init_dragonking_patches()
{
	makeJal(0x170F18, hook_xfer_to_intro);
	makeJal(0x170F48, hook_xfer_to_intro);
	makeJal(0x170F20, hook_wait_for_intro);
}
