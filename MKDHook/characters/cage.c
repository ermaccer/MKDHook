#include "cage.h"

// forceball
struct scan_action scan_cage_1 = {
	0,
	0x3000023,
	16,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

// split uppercut
struct scan_action scan_cage_3 = {
	0,
	0x3000023,
	21,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};

// shadow kick
struct scan_action scan_cage_4 = {
	0,
	0x3000023,
	23,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};

struct mk_file_entry cage_entry_table[CAGE_FILES] = {
	{"cage.ssf"	,0, 4},

	{"cage.sec",0, 1},
	{"cage_ap.sec",0, 1},
	{"cage.mko",0, 3},
	{"sh_cage.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"cage_fx.mko",0,3},
	{"shorin_ryu.mko",0, 3},
	{"style_shorin_ryu.sec",0,1},
	{"jeetkunedo.mko",0, 3},
	{"style_jeet_kun_do.sec",0,1},
	{"nunchaku.mko",0, 3},
	{"style_nunchaku.sec",0,1},
	{"cage_anims.sec",0, 2},
	{"shorin_ryu_anims.sec",0, 2},
	{"jeetkunedo_anims.sec",0, 2},
	{"nunchaku_anims.sec",0,2},
	{"pz_jax_anims.sec",0,2},
};

// I:\ps2dvd\art\cage.ssf
struct mk_toc_entry cage_file_table[CAGE_FILES + 1] = {
		{&cage_entry_table[0]	,0,0 },

		{&cage_entry_table[1]	,0,	   547072 },	// cage.sec        
		{&cage_entry_table[2]	,0,    596224 },	// cage_ap.sec     
		{&cage_entry_table[3]	,0,    43200  },	// cage.mko        
		{&cage_entry_table[4]	,0,    262400 },	// sh_cage.sec     
		{&cage_entry_table[5]	,0,    10164  },	// fight_fx.mko       
		{&cage_entry_table[6]	,0,    21368  },	// blood_fx.mko       
		{&cage_entry_table[7]	,0,    11424  },	// cage_fx.mko     
		{&cage_entry_table[8] 	,0,	   15552  },	// shorin_ryu.mko       
		{&cage_entry_table[9]	,0,    10112  },	// style_shorin_ryu.sec 
		{&cage_entry_table[10]	,0,	   14592  },	// jeetkunedo.mko           
		{&cage_entry_table[11]	,0,    10112  },	// style_jeet_kun_do.sec    
		{&cage_entry_table[12]	,0,	   15392  },	// nunchaku.mko        
		{&cage_entry_table[13]	,0,	   10112  },	// style_nunchaku.sec    
		{&cage_entry_table[14]	,0,	   62336  },	// cage_anims.sec  
		{&cage_entry_table[15]	,0,	   183424 },	// shorin_ryu_anims.sec
		{&cage_entry_table[16]	,0,	   195328 },	// jeetkunedo_anims.sec     
		{&cage_entry_table[17]	,0,	   222208 },	// nunchaku_anims.sec    
		{&cage_entry_table[18]	,0,	   53120  },	// pz_noob_anims.sec  

		{0,0,0}
};

struct mk_file_entry cage_alt_entry_table[CAGE_FILES] = {
	{"cage_alt.ssf"	,0, 4},

	{"cage_alt.sec",0, 1},
	{"cage_alt_ap.sec",0, 1},
	{"cage.mko",0, 3},
	{"sh_cage.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"cage_fx.mko",0,3},
	{"shorin_ryu.mko",0, 3},
	{"style_shorin_ryu.sec",0,1},
	{"jeetkunedo.mko",0, 3},
	{"style_jeet_kun_do.sec",0,1},
	{"nunchaku.mko",0, 3},
	{"style_nunchaku.sec",0,1},
	{"cage_alt_anims.sec",0, 2},
	{"shorin_ryu_anims.sec",0, 2},
	{"jeetkunedo_anims.sec",0, 2},
	{"nunchaku_anims.sec",0,2},
	{"pz_jax_anims.sec",0,2},
};

// I:\ps2dvd\art\cage_alt.ssf
struct mk_toc_entry cage_alt_file_table[CAGE_FILES + 1] = {
		{&cage_alt_entry_table[0]	,0,0 },

		{&cage_alt_entry_table[1]	,0,	   492160 },	// cage_alt.sec        
		{&cage_alt_entry_table[2]	,0,    492160 },	// cage_alt_ap.sec     
		{&cage_alt_entry_table[3]	,0,    43200  },	// cage.mko        
		{&cage_alt_entry_table[4]	,0,    262400 },	// sh_cage.sec     
		{&cage_alt_entry_table[5]	,0,    10164  },	// fight_fx.mko       
		{&cage_alt_entry_table[6]	,0,    21368  },	// blood_fx.mko       
		{&cage_alt_entry_table[7]	,0,    11424  },	// cage_fx.mko     
		{&cage_alt_entry_table[8] 	,0,	   15552  },	// shorin_ryu.mko       
		{&cage_alt_entry_table[9]	,0,    10112  },	// style_shorin_ryu.sec 
		{&cage_alt_entry_table[10]	,0,	   14592  },	// jeetkunedo.mko           
		{&cage_alt_entry_table[11]	,0,    10112  },	// style_jeet_kun_do.sec    
		{&cage_alt_entry_table[12]	,0,	   15392  },	// nunchaku.mko        
		{&cage_alt_entry_table[13]	,0,	   10112  },	// style_nunchaku.sec    
		{&cage_alt_entry_table[14]	,0,	   62336  },	// cage_alt_anims.sec  
		{&cage_alt_entry_table[15]	,0,	   183424 },	// shorin_ryu_anims.sec
		{&cage_alt_entry_table[16]	,0,	   195328 },	// jeetkunedo_anims.sec     
		{&cage_alt_entry_table[17]	,0,	   222208 },	// nunchaku_anims.sec    
		{&cage_alt_entry_table[18]	,0,	   53120  },	// pz_noob_anims.sec  

		{0,0,0}
};

void init_cage_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < CAGE_FILES; i++)
	{
		cage_entry_table[i].belong = &cage_file_table[0];
	}


	for (int i = 1; i < CAGE_FILES; i++)
	{
		cage_file_table[i].previousSize = baseSize;
		baseSize += (cage_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;
	for (int i = 0; i < CAGE_FILES; i++)
	{
		cage_alt_entry_table[i].belong = &cage_alt_file_table[0];
	}


	for (int i = 1; i < CAGE_FILES; i++)
	{
		cage_alt_file_table[i].previousSize = baseSize;
		baseSize += (cage_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}
