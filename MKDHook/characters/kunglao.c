#include "kunglao.h"
#include "..\mkd\object.h"
#include "..\scripthook.h"

// hat throw
struct scan_action scan_kunglao_1 = {
	4617,
	0x3000019,
	6,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};

// spin
struct scan_action scan_kunglao_3 = {
	0,
	0x3000019,
	19,
	MOVE_DOWN,
	MOVE_FORWARD,
	-1,
	0,
	0
};


// air rotate kick
struct scan_action scan_kunglao_4 = {
	0,
	0x3000019,
	5,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

struct mk_file_entry kunglao_entry_table[KUNGLAO_FILES] = {
	{"kunglao.ssf"	,0, 4},

	{"kunglao.sec",0, 1},
	{"kunglao_ap.sec",0, 1},
	{"kunglao.mko",0, 3},
	{"sh_kunglao.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"kunglao_fx.mko",0,3},
	{"mantis.mko",0, 3},
	{"style_mantis.sec",0,1},
	{"shaolin_fist.mko",0, 3},
	{"style_shaolin_fist.sec",0,1},
	{"broadsword.mko",0, 3},
	{"style_broadsword.sec",0,1},
	{"kunglao_anims.sec",0, 2},
	{"mantis_anims.sec",0, 2},
	{"shaolin_fist_anims.sec",0, 2},
	{"broadsword_anims.sec",0,2},
	{"pz_jax_anims.sec",0,2},
};

// I:\ps2dvd\art\kunglao.ssf
struct mk_toc_entry kunglao_file_table[KUNGLAO_FILES + 1] = {
		{&kunglao_entry_table[0]	,0,0 },

		{&kunglao_entry_table[1]	,0,	   471424 },	// kunglao.sec        
		{&kunglao_entry_table[2]	,0,    471424 },	// kunglao_ap.sec     
		{&kunglao_entry_table[3]	,0,    29664  },	// kunglao.mko        
		{&kunglao_entry_table[4]	,0,    274816 },	// sh_kunglao.sec     
		{&kunglao_entry_table[5]	,0,    10164  },	// fight_fx.mko       
		{&kunglao_entry_table[6]	,0,    21368  },	// blood_fx.mko       
		{&kunglao_entry_table[7]	,0,    7008   },	// kunglao_fx.mko     
		{&kunglao_entry_table[8] 	,0,	   15248  },	// mantis.mko       
		{&kunglao_entry_table[9]	,0,    10112  },	// style_mantis.sec 
		{&kunglao_entry_table[10]	,0,	   15776  },	// shaolin_fist.mko           
		{&kunglao_entry_table[11]	,0,    10112  },	// style_shaolin_fist.sec     
		{&kunglao_entry_table[12]	,0,	   16064  },	// broadsword.mko        
		{&kunglao_entry_table[13]	,0,	   10112  },	// style_broadsword.sec    
		{&kunglao_entry_table[14]	,0,	   77440  },	// kunglao_anims.sec  
		{&kunglao_entry_table[15]	,0,	   179584 },	// mantis_anims.sec 
		{&kunglao_entry_table[16]	,0,	   161536 },	// shaolin_fist_anims.sec     
		{&kunglao_entry_table[17]	,0,	   209664 },	// broadsword_anims.sec    
		{&kunglao_entry_table[18]	,0,	   52352  },	// pz_jax_anims.sec   

		{0,0,0}
};

struct mk_file_entry kunglao_alt_entry_table[KUNGLAO_FILES] = {
	{"kunglao_alt.ssf"	,0, 4},

	{"kunglao_alt.sec",0, 1},
	{"kunglao_alt_ap.sec",0, 1},
	{"kunglao.mko",0, 3},
	{"sh_kunglao.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"kunglao_fx.mko",0,3},
	{"mantis.mko",0, 3},
	{"style_mantis.sec",0,1},
	{"shaolin_fist.mko",0, 3},
	{"style_shaolin_fist.sec",0,1},
	{"broadsword.mko",0, 3},
	{"style_broadsword.sec",0,1},
	{"kunglao_alt_anims.sec",0, 2},
	{"mantis_anims.sec",0, 2},
	{"shaolin_fist_anims.sec",0, 2},
	{"broadsword_anims.sec",0,2},
	{"pz_jax_anims.sec",0,2},
};

// I:\ps2dvd\art\kunglao_alt.ssf
struct mk_toc_entry kunglao_alt_file_table[KUNGLAO_FILES + 1] = {
		{&kunglao_alt_entry_table[0]	,0,0 },

		{&kunglao_alt_entry_table[1]	,0,	   524032 },	// kunglao_alt.sec        
		{&kunglao_alt_entry_table[2]	,0,    524032 },	// kunglao_alt_ap.sec     
		{&kunglao_alt_entry_table[3]	,0,    29664  },	// kunglao.mko        
		{&kunglao_alt_entry_table[4]	,0,    274816 },	// sh_kunglao.sec     
		{&kunglao_alt_entry_table[5]	,0,    10164  },	// fight_fx.mko       
		{&kunglao_alt_entry_table[6]	,0,    21368  },	// blood_fx.mko       
		{&kunglao_alt_entry_table[7]	,0,    7008   },	// kunglao_fx.mko     
		{&kunglao_alt_entry_table[8] 	,0,	   15248  },	// mantis.mko       
		{&kunglao_alt_entry_table[9]	,0,    10112  },	// style_mantis.sec 
		{&kunglao_alt_entry_table[10]	,0,	   15776  },	// shaolin_fist.mko           
		{&kunglao_alt_entry_table[11]	,0,    10112  },	// style_shaolin_fist.sec     
		{&kunglao_alt_entry_table[12]	,0,	   16064  },	// broadsword.mko        
		{&kunglao_alt_entry_table[13]	,0,	   10112  },	// style_broadsword.sec    
		{&kunglao_alt_entry_table[14]	,0,	   77440  },	// kunglao_alt_anims.sec  
		{&kunglao_alt_entry_table[15]	,0,	   179584 },	// mantis_anims.sec 
		{&kunglao_alt_entry_table[16]	,0,	   161536 },	// shaolin_fist_anims.sec     
		{&kunglao_alt_entry_table[17]	,0,	   209664 },	// broadsword_anims.sec    
		{&kunglao_alt_entry_table[18]	,0,	   52352  },	// pz_jax_anims.sec   

		{0,0,0}
};


void init_kunglao_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < KUNGLAO_FILES; i++)
	{
		kunglao_entry_table[i].belong = &kunglao_file_table[0];
	}


	for (int i = 1; i < KUNGLAO_FILES; i++)
	{
		kunglao_file_table[i].previousSize = baseSize;
		baseSize += (kunglao_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;

	for (int i = 0; i < KUNGLAO_FILES; i++)
	{
		kunglao_alt_entry_table[i].belong = &kunglao_alt_file_table[0];
	}


	for (int i = 1; i < KUNGLAO_FILES; i++)
	{
		kunglao_alt_file_table[i].previousSize = baseSize;
		baseSize += (kunglao_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}

void kunglao_fatality_hide_hat(int id, int object)
{
	collapse_bone(object, 58, 0);
}
