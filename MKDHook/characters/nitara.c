#include "nitara.h"

// blood spit
struct scan_action scan_nitara_2 = {
	4629,
	0x3000019,
	16,
	MOVE_FORWARD,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

// escape
struct scan_action scan_nitara_3 = {
	17068,
	0x3000019,
	15,
	MOVE_FORWARD,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

// unicorn kick, duck kick
struct scan_action_dual scan_nitara_4 = {
	16934,
	0x3000019,
	8,
	MOVE_BACKWARDS,
	MOVE_DOWN,
	17037,
	0x3000019,
	13,
	MOVE_DOWN,
	MOVE_FORWARD,
	-1,
};



struct mk_file_entry nitara_entry_table[NITARA_FILES] = {
	{"nitara.ssf"	,0, 4},

	{"nitara.sec",0, 1},
	{"nitara_ap.sec",0, 1},
	{"nitara.mko",0, 3},
	{"sh_nitara.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"nitara_fx.mko",0,3},
	{"leopard.mko",0, 3},
	{"style_leopard.sec",0,1},
	{"fujowpai.mko",0, 3},
	{"style_fu_jow_pai.sec",0,1},
	{"kama.mko",0, 3},
	{"style_kama.sec",0,1},
	{"nitara_anims.sec",0, 2},
	{"leopard_anims.sec",0, 2},
	{"fujowpai_anims.sec",0, 2},
	{"kama_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\nitara.ssf
struct mk_toc_entry nitara_file_table[NITARA_FILES + 1] = {
		{&nitara_entry_table[0]	,0,0 },

		{&nitara_entry_table[1]		,0,	   525312 },	// nitara.sec             
		{&nitara_entry_table[2]		,0,    525312 },	// nitara_ap.sec        
		{&nitara_entry_table[3]		,0,    19072  },	// nitara.mko   
		{&nitara_entry_table[4]		,0,    258944 },	// sh_nitara.sec           
		{&nitara_entry_table[5]		,0,    10164  },	// fight_fx.mko         
		{&nitara_entry_table[6]		,0,    21368  },	// blood_fx.mko         
		{&nitara_entry_table[7]		,0,    13504  },	// nitara_fx.mko          
		{&nitara_entry_table[8] 	,0,	   10912  },	// leopard.mko         
		{&nitara_entry_table[9]		,0,    10112  },	// style_leopard.sec   
		{&nitara_entry_table[10]	,0,	   12288  },	// fujowpai.mko        
		{&nitara_entry_table[11]	,0,    10112  },	// style_fu_jow_pai.sec
		{&nitara_entry_table[12]	,0,	   12896  },	// kama.mko        
		{&nitara_entry_table[13]	,0,	   10112  },	// style_kama.sec  
		{&nitara_entry_table[14]	,0,	   81792  },	// nitara_anims.sec       
		{&nitara_entry_table[15]	,0,	   140928 },	// leopard_anims.sec   
		{&nitara_entry_table[16]	,0,	   155904 },	// fujowpai_anims.sec  
		{&nitara_entry_table[17]	,0,	   167552 },	// kama_anims.sec  
		{&nitara_entry_table[18]	,0,	   53120  },	// pz_noob_anims.sec    

		{0,0,0}
};


struct mk_file_entry nitara_alt_entry_table[NITARA_FILES] = {
	{"nitara_alt.ssf"	,0, 4},

	{"nitara_alt.sec",0, 1},
	{"nitara_alt_ap.sec",0, 1},
	{"nitara.mko",0, 3},
	{"sh_nitara.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"nitara_fx.mko",0,3},
	{"leopard.mko",0, 3},
	{"style_leopard.sec",0,1},
	{"fujowpai.mko",0, 3},
	{"style_fu_jow_pai.sec",0,1},
	{"kama.mko",0, 3},
	{"style_kama.sec",0,1},
	{"nitara_alt_anims.sec",0, 2},
	{"leopard_anims.sec",0, 2},
	{"fujowpai_anims.sec",0, 2},
	{"kama_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\nitara_alt.ssf
struct mk_toc_entry nitara_alt_file_table[NITARA_FILES + 1] = {
		{&nitara_alt_entry_table[0]	,0,0 },

		{&nitara_alt_entry_table[1]		,0,	   487552 },	// nitara_alt.sec             
		{&nitara_alt_entry_table[2]		,0,    487552 },	// nitara_alt_ap.sec        
		{&nitara_alt_entry_table[3]		,0,    19072  },	// nitara.mko   
		{&nitara_alt_entry_table[4]		,0,    258944 },	// sh_nitara.sec           
		{&nitara_alt_entry_table[5]		,0,    10164  },	// fight_fx.mko         
		{&nitara_alt_entry_table[6]		,0,    21368  },	// blood_fx.mko         
		{&nitara_alt_entry_table[7]		,0,    13504  },	// nitara_fx.mko          
		{&nitara_alt_entry_table[8] 	,0,	   10912  },	// leopard.mko         
		{&nitara_alt_entry_table[9]		,0,    10112  },	// style_leopard.sec   
		{&nitara_alt_entry_table[10]	,0,	   12288  },	// fujowpai.mko        
		{&nitara_alt_entry_table[11]	,0,    10112  },	// style_fu_jow_pai.sec
		{&nitara_alt_entry_table[12]	,0,	   12896  },	// kama.mko        
		{&nitara_alt_entry_table[13]	,0,	   10112  },	// style_kama.sec  
		{&nitara_alt_entry_table[14]	,0,	   81792  },	// nitara_alt_anims.sec       
		{&nitara_alt_entry_table[15]	,0,	   140928 },	// leopard_anims.sec   
		{&nitara_alt_entry_table[16]	,0,	   155904 },	// fujowpai_anims.sec  
		{&nitara_alt_entry_table[17]	,0,	   167552 },	// kama_anims.sec  
		{&nitara_alt_entry_table[18]	,0,	   53120  },	// pz_noob_anims.sec    

		{0,0,0}
};


void init_nitara_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < NITARA_FILES; i++)
	{
		nitara_entry_table[i].belong = &nitara_file_table[0];
	}


	for (int i = 1; i < NITARA_FILES; i++)
	{
		nitara_file_table[i].previousSize = baseSize;
		baseSize += (nitara_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;
	for (int i = 0; i < NITARA_FILES; i++)
	{
		nitara_alt_entry_table[i].belong = &nitara_alt_file_table[0];
	}


	for (int i = 1; i < NITARA_FILES; i++)
	{
		nitara_alt_file_table[i].previousSize = baseSize;
		baseSize += (nitara_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}
