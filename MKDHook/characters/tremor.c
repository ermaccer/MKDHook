#include "tremor.h"


// earthquake
struct scan_action scan_tremor_2 = {
	16902,
	0x3000019,
	8,
	MOVE_FORWARD,
	MOVE_DOWN,
	-1,
	0,
	0
};

// shoulder bash
struct scan_action scan_tremor_3 = {
	16902,
	0x3000019,
	13,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};

// rolling rock
struct scan_action scan_tremor_4 = {
	16902,
	0x3000019,
	16,
	MOVE_DOWN,
	MOVE_FORWARD,
	-1,
	0,
	0
};


struct mk_file_entry tremor_entry_table[TREMOR_FILES] = {
	{"tremor.ssf"	,0, 4},

	{"tremor.sec",0, 1},
	{"tremor_ap.sec",0, 1},
	{"tremor.mko",0, 3},
	{"sh_tremor.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"tremor_fx.mko",0,3},
	{"wrestling.mko",0, 3},
	{"style_wrestling.sec",0,1},
	{"sunbin.mko",0, 3},
	{"style_sun_bin.sec",0,1},
	{"rockarms.mko",0, 3},
	{"style_rockarms.sec",0,1},
	{"tremor_anims.sec",0, 2},
	{"wrestling_anims.sec",0, 2},
	{"sunbin_anims.sec",0, 2},
	{"rockarms_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\tremor.ssf
struct mk_toc_entry tremor_file_table[TREMOR_FILES + 1] = {
		{&tremor_entry_table[0]	,0,0 },

		{&tremor_entry_table[1]			,0,		591872  },	// tremor.sec             
		{&tremor_entry_table[2]			,0,		591872  },	// tremor_ap.sec        
		{&tremor_entry_table[3]			,0,		19968   },	// tremor.mko   
		{&tremor_entry_table[4]			,0,		311424  },	// sh_tremor.sec           
		{&tremor_entry_table[5]			,0,		10164   },	// fight_fx.mko         
		{&tremor_entry_table[6]			,0,		21368   },	// blood_fx.mko         
		{&tremor_entry_table[7]			,0,		14496   },	// tremor_fx.mko          
		{&tremor_entry_table[8]			,0,		11744   },	// wrestling.mko         
		{&tremor_entry_table[9]			,0,		10112   },	// style_wrestling.sec   
		{&tremor_entry_table[10]		,0,		13760   },	// sunbin.mko        
		{&tremor_entry_table[11]		,0,		10112   },	// style_sun_bin.sec  
		{&tremor_entry_table[12]		,0,		9696    },	// rockarms.mko        
		{&tremor_entry_table[13]		,0,		10112   },	// style_rockarms.sec  
		{&tremor_entry_table[14]		,0,		156544  },	// tremor_anims.sec       
		{&tremor_entry_table[15]		,0,		176052  },	// wrestling_anims.sec   
		{&tremor_entry_table[16]		,0,		134016  },	// sunbin_anims.sec  
		{&tremor_entry_table[17]		,0,		163840  },	// rockarms_anims.sec  
		{&tremor_entry_table[18]		,0,		53120   },	// pz_noob_anims.sec

		{0,0,0}
};

void init_tremor_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < TREMOR_FILES; i++)
	{
		tremor_entry_table[i].belong = &tremor_file_table[0];
	}


	for (int i = 1; i < TREMOR_FILES; i++)
	{
		tremor_file_table[i].previousSize = baseSize;
		baseSize += (tremor_file_table[i].size + 2048 - 1) & -2048;
	}
}