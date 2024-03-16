#include "rain.h"

// lightning strike
struct scan_action scan_rain_2 = {
	16977,
	0x3000019,
	8,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

// storm kick
struct scan_action scan_rain_3 = {
	0,
	0x3000019,
	13,
	MOVE_DOWN,
	MOVE_FORWARD,
	-1,
	0,
	0
};


// high burst, water ball
struct scan_action_dual scan_rain_1 = {
	4629,
	0x300001E,
	16,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	4629,
	0x300001E,
	20,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
};


struct mk_file_entry rain_entry_table[RAIN_FILES] = {
	{"rain.ssf"	,0, 4},

	{"rain.sec",0, 1},
	{"rain_ap.sec",0, 1},
	{"rain.mko",0, 3},
	{"sh_rain.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"rain_fx.mko",0,3},
	{"yue_chuan.mko",0, 3},
	{"style_yue_chuan.sec",0,1},
	{"nanchuan.mko",0, 3},
	{"style_nanchuan.sec",0,1},
	{"stormsword.mko",0, 3},
	{"style_stormsword.sec",0,1},
	{"rain_anims.sec",0, 2},
	{"yue_chuan_anims.sec",0, 2},
	{"nanchuan_anims.sec",0, 2},
	{"stormsword_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\rain.ssf
struct mk_toc_entry rain_file_table[RAIN_FILES + 1] = {
		{&rain_entry_table[0]	,0,0 },

		{&rain_entry_table[1]	,0,	   939648 },	// rain.sec             
		{&rain_entry_table[2]	,0,    939648 },	// rain_ap.sec        
		{&rain_entry_table[3]	,0,    26240  },	// rain.mko   
		{&rain_entry_table[4]	,0,    311552 },	// sh_rain.sec           
		{&rain_entry_table[5]	,0,    10164  },	// fight_fx.mko         
		{&rain_entry_table[6]	,0,    21368  },	// blood_fx.mko         
		{&rain_entry_table[7]	,0,    13696  },	// rain_fx.mko          
		{&rain_entry_table[8] 	,0,	   12480  },	// yue_chuan.mko         
		{&rain_entry_table[9]	,0,    10112  },	// style_yue_chuan.sec   
		{&rain_entry_table[10]	,0,	   13440  },	// nanchuan.mko        
		{&rain_entry_table[11]	,0,    10112  },	// style_nanchuan.sec  
		{&rain_entry_table[12]	,0,	   11584  },	// stormsword.mko        
		{&rain_entry_table[13]	,0,	   10112  },	// style_stormsword.sec  
		{&rain_entry_table[14]	,0,	   154752 },	// rain_anims.sec       
		{&rain_entry_table[15]	,0,	   132608 },	// yue_chuan_anims.sec   
		{&rain_entry_table[16]	,0,	   150784 },	// nanchuan_anims.sec  
		{&rain_entry_table[17]	,0,	   169344 },	// stormsword_anims.sec  
		{&rain_entry_table[18]	,0,	   53120  },	// pz_noob_anims.sec    

		{0,0,0}
};

struct mk_file_entry rain_alt_entry_table[RAIN_FILES] = {
	{"rain_alt.ssf"	,0, 4},

	{"rain_alt.sec",0, 1},
	{"rain_alt_ap.sec",0, 1},
	{"rain.mko",0, 3},
	{"sh_rain.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"rain_fx.mko",0,3},
	{"yue_chuan.mko",0, 3},
	{"style_yue_chuan.sec",0,1},
	{"nanchuan.mko",0, 3},
	{"style_nanchuan.sec",0,1},
	{"stormsword.mko",0, 3},
	{"style_stormsword.sec",0,1},
	{"rain_alt_anims.sec",0, 2},
	{"yue_chuan_anims.sec",0, 2},
	{"nanchuan_anims.sec",0, 2},
	{"stormsword_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\rain_alt.ssf
struct mk_toc_entry rain_alt_file_table[RAIN_FILES + 1] = {
		{&rain_alt_entry_table[0]	,0,0 },

		{&rain_alt_entry_table[1]	,0,	   843648 },	// rain_alt.sec             
		{&rain_alt_entry_table[2]	,0,    597888 },	// rain_alt_ap.sec        
		{&rain_alt_entry_table[3]	,0,    26240  },	// rain.mko   
		{&rain_alt_entry_table[4]	,0,    311552 },	// sh_rain.sec           
		{&rain_alt_entry_table[5]	,0,    10164  },	// fight_fx.mko         
		{&rain_alt_entry_table[6]	,0,    21368  },	// blood_fx.mko         
		{&rain_alt_entry_table[7]	,0,    13696  },	// rain_fx.mko          
		{&rain_alt_entry_table[8] 	,0,	   12480  },	// yue_chuan.mko         
		{&rain_alt_entry_table[9]	,0,    10112  },	// style_yue_chuan.sec   
		{&rain_alt_entry_table[10]	,0,	   13440  },	// nanchuan.mko        
		{&rain_alt_entry_table[11]	,0,    10112  },	// style_nanchuan.sec  
		{&rain_alt_entry_table[12]	,0,	   11584  },	// stormsword.mko        
		{&rain_alt_entry_table[13]	,0,	   10112  },	// style_stormsword.sec  
		{&rain_alt_entry_table[14]	,0,	   154752 },	// rain_alt_anims.sec       
		{&rain_alt_entry_table[15]	,0,	   132608 },	// yue_chuan_anims.sec   
		{&rain_alt_entry_table[16]	,0,	   150784 },	// nanchuan_anims.sec  
		{&rain_alt_entry_table[17]	,0,	   169344 },	// stormsword_anims.sec  
		{&rain_alt_entry_table[18]	,0,	   53120  },	// pz_noob_anims.sec    

		{0,0,0}
};

void init_rain_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < RAIN_FILES; i++)
	{
		rain_entry_table[i].belong = &rain_file_table[0];
	}


	for (int i = 1; i < RAIN_FILES; i++)
	{
		rain_file_table[i].previousSize = baseSize;
		baseSize += (rain_file_table[i].size + 2048 - 1) & -2048;
	}


	baseSize = 2048;
	for (int i = 0; i < RAIN_FILES; i++)
	{
		rain_alt_entry_table[i].belong = &rain_alt_file_table[0];
	}


	for (int i = 1; i < RAIN_FILES; i++)
	{
		rain_alt_file_table[i].previousSize = baseSize;
		baseSize += (rain_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}
