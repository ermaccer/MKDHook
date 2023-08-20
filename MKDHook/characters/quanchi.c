#include "quanchi.h"


// skull toss
struct scan_action scan_quan_1 = {
	4616,
	0x3000019,
	17,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

// floor kick
struct scan_action scan_quan_4 = {
	0,
	0x3000019,
	22,
	MOVE_BACKWARDS,
	MOVE_DOWN,
	-1,
	0,
	0
};

// tele kick
struct scan_action scan_quan_3 = {
	16985 ,
	0x3000019,
	19,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

struct mk_file_entry quan_entry_table[QUAN_FILES] = {
	{"quanchi.ssf"	,0, 4},

	{"quan.sec",0, 1},
	{"quan_ap.sec",0, 1},
	{"sh_quan.sec",0, 1},
	{"quan.mko",0, 3},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"quan_fx.mko",0,3},
	{"tang_soo_do.mko",0, 3},
	{"style_tang_soo_do.sec",0,1},
	{"escrima.mko",0, 3},
	{"style_escrima.sec",0,1},
	{"broadswords.mko",0, 3},
	{"style_broadswords.sec",0,1},
	{"quan_anims.sec",0, 2},
	{"fat_anims_legrip_1.sec",0, 2},
	{"tang_soo_do_anims.sec",0, 2},
	{"escrima_anims.sec",0, 2},
	{"broadswords_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\quanchi.ssf
struct mk_toc_entry quan_file_table[QUAN_FILES + 1] = {
		{&quan_entry_table[0]	,0,0 },

		{&quan_entry_table[1]	,0,	   440832 },	// quan.sec              
		{&quan_entry_table[2]	,0,    440832 },	// quan_ap.sec           
		{&quan_entry_table[3]	,0,    300800 },	// sh_quan.sec           
		{&quan_entry_table[4]	,0,    27136  },	// quan.mko              
		{&quan_entry_table[5]	,0,    10164  },	// fight_fx.mko          
		{&quan_entry_table[6]	,0,    21368  },	// blood_fx.mko          
		{&quan_entry_table[7]	,0,    8160   },	// quan_fx.mko           
		{&quan_entry_table[8] 	,0,	   17056  },	// tang_soo_do.mko       
		{&quan_entry_table[9]	,0,    10112  },	// style_tang_soo_do.sec 
		{&quan_entry_table[10]	,0,	   14080  },	// escrima.mko           
		{&quan_entry_table[11]	,0,    10112  },	// style_escrima.sec     
		{&quan_entry_table[12]	,0,	   13888  },	// broadswords.mko             
		{&quan_entry_table[13]	,0,	   10112  },	// style_broadswords.sec
		{&quan_entry_table[14]	,0,	   139528 },	// quan_anims.sec        
		{&quan_entry_table[15]	,0,	   92544  },	// fat_anims_legrip_1.sec
		{&quan_entry_table[16]	,0,	   152704 },	// tang_soo_do_anims.sec 
		{&quan_entry_table[17]	,0,	   158080 },	// escrima_anims.sec     
		{&quan_entry_table[18]	,0,	   172984 },	// broadswords_anims.sec       
		{&quan_entry_table[19]	,0,	   53120  },	// pz_noob_anims.sec     

		{0,0,0}
};

struct mk_file_entry quan_alt_entry_table[QUAN_FILES] = {
	{"quanchi_alt.ssf"	,0, 4},

	{"quan_alt.sec",0, 1},
	{"quan_alt_ap.sec",0, 1},
	{"sh_quan.sec",0, 1},
	{"quan.mko",0, 3},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"quan_fx.mko",0,3},
	{"tang_soo_do.mko",0, 3},
	{"style_tang_soo_do.sec",0,1},
	{"escrima.mko",0, 3},
	{"style_escrima.sec",0,1},
	{"broadswords.mko",0, 3},
	{"style_broadswords.sec",0,1},
	{"quan_alt_anims.sec",0, 2},
	{"fat_anims_legrip_1.sec",0, 2},
	{"tang_soo_do_anims.sec",0, 2},
	{"escrima_anims.sec",0, 2},
	{"broadswords_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\quanchi_alt.ssf
struct mk_toc_entry quan_alt_file_table[QUAN_FILES + 1] = {
		{&quan_alt_entry_table[0]	,0,0 },

		{&quan_alt_entry_table[1]	,0,	   454016 },	// quan_alt.sec              
		{&quan_alt_entry_table[2]	,0,    454016 },	// quan_alt_ap.sec           
		{&quan_alt_entry_table[3]	,0,    300800 },	// sh_quan.sec           
		{&quan_alt_entry_table[4]	,0,    27136  },	// quan.mko              
		{&quan_alt_entry_table[5]	,0,    10164  },	// fight_fx.mko          
		{&quan_alt_entry_table[6]	,0,    21368  },	// blood_fx.mko          
		{&quan_alt_entry_table[7]	,0,    8160   },	// quan_fx.mko           
		{&quan_alt_entry_table[8] 	,0,	   17056  },	// tang_soo_do.mko       
		{&quan_alt_entry_table[9]	,0,    10112  },	// style_tang_soo_do.sec 
		{&quan_alt_entry_table[10]	,0,	   14080  },	// escrima.mko           
		{&quan_alt_entry_table[11]	,0,    10112  },	// style_escrima.sec     
		{&quan_alt_entry_table[12]	,0,	   13888  },	// broadswords.mko             
		{&quan_alt_entry_table[13]	,0,	   10112  },	// style_broadswords.sec
		{&quan_alt_entry_table[14]	,0,	   139528 },	// quan_alt_anims.sec        
		{&quan_alt_entry_table[15]	,0,	   92544  },	// fat_anims_legrip_1.sec
		{&quan_alt_entry_table[16]	,0,	   152704 },	// tang_soo_do_anims.sec 
		{&quan_alt_entry_table[17]	,0,	   158080 },	// escrima_anims.sec     
		{&quan_alt_entry_table[18]	,0,	   172984 },	// broadswords_anims.sec       
		{&quan_alt_entry_table[19]	,0,	   53120  },	// pz_noob_anims.sec     

		{0,0,0}
};

void init_quan_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < QUAN_FILES; i++)
	{
		quan_entry_table[i].belong = &quan_file_table[0];
	}


	for (int i = 1; i < QUAN_FILES; i++)
	{
		quan_file_table[i].previousSize = baseSize;
		baseSize += (quan_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;
	for (int i = 0; i < QUAN_FILES; i++)
	{
		quan_alt_entry_table[i].belong = &quan_alt_file_table[0];
	}


	for (int i = 1; i < QUAN_FILES; i++)
	{
		quan_alt_file_table[i].previousSize = baseSize;
		baseSize += (quan_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}
