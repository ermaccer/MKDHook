#include "reiko.h"

// tele throw & shurikens
struct scan_action_dual scan_reiko_1 = {
	16902,
	0x3000019,
	13,
	MOVE_DOWN,
	MOVE_UP,
	16944,
	0x3000019,
	16,
	MOVE_DOWN,
	MOVE_FORWARD,
};



// spin kick
struct scan_action scan_reiko_4 = {
	16902,
	0x3000019,
	20,
	MOVE_BACKWARDS,
	MOVE_DOWN,
	-1,
	0,
	0
};

// circling teleport
struct scan_action scan_reiko_3 = {
	16902,
	0x3000019,
	8,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};



struct mk_file_entry reiko_entry_table[REIKO_FILES] = {
	{"reiko.ssf"	,0, 4},

	{"reiko.sec",0, 1},
	{"reiko_ap.sec",0, 1},
	{"reiko.mko",0, 3},
	{"sh_reiko.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"reiko_fx.mko",0,3},
	{"mian.mko",0, 3},
	{"style_mian.sec",0,1},
	{"silate.mko",0, 3},
	{"style_silate.sec",0,1},
	{"club.mko",0, 3},
	{"style_club.sec",0,1},
	{"reiko_anims.sec",0, 2},
	{"mian_anims.sec",0, 2},
	{"silate_anims.sec",0, 2},
	{"club_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\reiko.ssf
struct mk_toc_entry reiko_file_table[REIKO_FILES + 1] = {
		{&reiko_entry_table[0]	,0,0 },

		{&reiko_entry_table[1]		,0,		453248 },	// reiko.sec             
		{&reiko_entry_table[2]		,0,		453248 },	// reiko_ap.sec        
		{&reiko_entry_table[3]		,0,		19648  },	// reiko.mko   
		{&reiko_entry_table[4]		,0,		362496 },	// sh_reiko.sec           
		{&reiko_entry_table[5]		,0,		10164  },	// fight_fx.mko         
		{&reiko_entry_table[6]		,0,		21368  },	// blood_fx.mko         
		{&reiko_entry_table[7]		,0,		14336  },	// reiko_fx.mko          
		{&reiko_entry_table[8]		,0,		16064  },	// mian.mko         
		{&reiko_entry_table[9]		,0,		10112  },	// style_mian.sec   
		{&reiko_entry_table[10]		,0,		15648  },	// silate.mko        
		{&reiko_entry_table[11]		,0,		10112  },	// style_silate.sec  
		{&reiko_entry_table[12]		,0,		12000  },	// club.mko        
		{&reiko_entry_table[13]		,0,		10112  },	// style_club.sec  
		{&reiko_entry_table[14]		,0,		135936 },	// reiko_anims.sec       
		{&reiko_entry_table[15]		,0,		173696 },	// mian_anims.sec   
		{&reiko_entry_table[16]		,0,		175616 },	// silate_anims.sec  
		{&reiko_entry_table[17]		,0,		170112 },	// club_anims.sec  
		{&reiko_entry_table[18]		,0,		53120  },	// pz_noob_anims.sec

		{0,0,0}
};

struct mk_file_entry reiko_alt_entry_table[REIKO_FILES] = {
	{"reiko_alt.ssf"	,0, 4},

	{"reiko_alt.sec",0, 1},
	{"reiko_alt_ap.sec",0, 1},
	{"reiko.mko",0, 3},
	{"sh_reiko.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"reiko_fx.mko",0,3},
	{"mian.mko",0, 3},
	{"style_mian.sec",0,1},
	{"silate.mko",0, 3},
	{"style_silate.sec",0,1},
	{"club.mko",0, 3},
	{"style_club.sec",0,1},
	{"reiko_alt_anims.sec",0, 2},
	{"mian_anims.sec",0, 2},
	{"silate_anims.sec",0, 2},
	{"club_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\reiko_alt.ssf
struct mk_toc_entry reiko_alt_file_table[REIKO_FILES + 1] = {
		{&reiko_alt_entry_table[0]	,0,0 },

		{&reiko_alt_entry_table[1]		,0,		445568 },	// reiko_alt.sec             
		{&reiko_alt_entry_table[2]		,0,		445568 },	// reiko_alt_ap.sec        
		{&reiko_alt_entry_table[3]		,0,		19648  },	// reiko.mko   
		{&reiko_alt_entry_table[4]		,0,		362496 },	// sh_reiko.sec           
		{&reiko_alt_entry_table[5]		,0,		10164  },	// fight_fx.mko         
		{&reiko_alt_entry_table[6]		,0,		21368  },	// blood_fx.mko         
		{&reiko_alt_entry_table[7]		,0,		14124  },	// reiko_fx.mko          
		{&reiko_alt_entry_table[8]		,0,		16064  },	// mian.mko         
		{&reiko_alt_entry_table[9]		,0,		10112  },	// style_mian.sec   
		{&reiko_alt_entry_table[10]		,0,		15648   },	// silate.mko        
		{&reiko_alt_entry_table[11]		,0,		10112  },	// style_silate.sec  
		{&reiko_alt_entry_table[12]		,0,		12000  },	// club.mko        
		{&reiko_alt_entry_table[13]		,0,		10112  },	// style_club.sec  
		{&reiko_alt_entry_table[14]		,0,		135936 },	// reiko_alt_anims.sec       
		{&reiko_alt_entry_table[15]		,0,		173696 },	// mian_anims.sec   
		{&reiko_alt_entry_table[16]		,0,		175616 },	// silate_anims.sec  
		{&reiko_alt_entry_table[17]		,0,		170112 },	// club_anims.sec  
		{&reiko_alt_entry_table[18]		,0,		53120  },	// pz_noob_anims.sec

		{0,0,0}
};



void init_reiko_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < REIKO_FILES; i++)
	{
		reiko_entry_table[i].belong = &reiko_file_table[0];
	}


	for (int i = 1; i < REIKO_FILES; i++)
	{
		reiko_file_table[i].previousSize = baseSize;
		baseSize += (reiko_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;
	for (int i = 0; i < REIKO_FILES; i++)
	{
		reiko_alt_entry_table[i].belong = &reiko_alt_file_table[0];
	}


	for (int i = 1; i < REIKO_FILES; i++)
	{
		reiko_alt_file_table[i].previousSize = baseSize;
		baseSize += (reiko_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}


const char func_reiko_teleport[176] = {
	0xf0, 0xff, 0xbd, 0x27, 0x80, 0x3f, 0x02, 0x3c, 0x00, 0x00, 0xbf,
	0xff, 0x00, 0x28, 0x82, 0x44, 0x30, 0x98, 0x83, 0x8f, 0x2c, 0x98,
	0x84, 0x8f, 0xa0, 0x00, 0x61, 0xc4, 0xa0, 0x00, 0x65, 0x24, 0xa0,
	0x00, 0x84, 0xc4, 0xa8, 0x00, 0x83, 0xc4, 0xa8, 0x00, 0x60, 0xc4,
	0x81, 0x08, 0x04, 0x46, 0x41, 0x00, 0x03, 0x46, 0x1a, 0x08, 0x01,
	0x46, 0x1c, 0x10, 0x02, 0x46, 0x56, 0x29, 0x00, 0x46, 0x02, 0x10,
	//          v -2.0 -> -0.6 ish, losing precision due to 2 bytes missing
	0x05, 0x46, 0x19, 0xbf, 0x04, 0x3c, 0x5e, 0x00, 0x02, 0x3c, 0x02,
	0x00, 0x03, 0x24, 0x82, 0x08, 0x05, 0x46, 0x00, 0x08, 0x84, 0x44,
	0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x46, 0x00, 0x00, 0x04,
	0x46, 0x00, 0x00, 0xa0, 0xe4, 0x42, 0x10, 0x01, 0x46, 0x30, 0x98,
	0x84, 0x8f, 0x00, 0x08, 0x03, 0x46, 0xa8, 0x00, 0x80, 0xe4, 0x68,
	0x43, 0x42, 0x8c, 0x04, 0x00, 0x43, 0x10, 0x00, 0x00, 0x00, 0x00,
	0x2c, 0x98, 0x82, 0x8f, 0x40, 0xf6, 0x09, 0x0c, 0xa0, 0x00, 0x44,
	0x24, 0x4c, 0xcb, 0x07, 0x0c, 0x00, 0x00, 0x00, 0x00, 0xd8, 0x56,
	0x05, 0x0c, 0x34, 0x98, 0x84, 0x8f, 0x00, 0x00, 0xbf, 0xdf, 0x08,
	0x00, 0xe0, 0x03, 0x10, 0x00, 0xbd, 0x27, 0x00, 0x00, 0x00, 0x00
};


void reiko_teleport()
{
	((void(*)())(int)&func_reiko_teleport[0])();
}
