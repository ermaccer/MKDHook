#include "kitana.h"


// fan lift
struct scan_action scan_kitana_1 = {
	4621,
	0x300001E,
	6,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};

// pretty kick
struct scan_action scan_kitana_3 = {
	0,
	0x3000019,
	9,
	MOVE_UP,
	-1,
	0,
	0,
	0
};


struct mk_file_entry kitana_entry_table[KITANA_FILES] = {
	{"kitana.ssf"	,0, 4},
	{"kitana.sec",0, 1},
	{"kitana_ap.sec",0, 1},
	{"sh_kitana.sec",0, 1},
	{"kitana.mko",0, 3},
	{"blood_fx.mko",0,3},
	{"fight_fx.mko",0,3},
	{"bagua.mko",0, 3},
	{"style_bagua.sec",0,1},
	{"eagleclaw.mko",0, 3},
	{"style_eagle_claw.sec",0,1},
	{"steelfan.mko",0, 3},
	{"style_steel_fan.sec",0,1},
	{"kitana_anims.sec",0, 2},
	{"pz_jax_anims.sec",0,2},
	{"bagua_anims.sec",0, 2},
	{"eagleclaw_anims.sec",0, 2},
	{"steelfan_anims.sec",0,2},

};

// I:\ps2dvd\art\kitana.ssf
struct mk_toc_entry kitana_file_table[KITANA_FILES + 1] = {
		{&kitana_entry_table[0]	,0,0 },
		{&kitana_entry_table[1]	,0,   679424},
		{&kitana_entry_table[2]	,0,    641152},
		{&kitana_entry_table[3]	,0,    235648},

		{&kitana_entry_table[4]	,0,    11552},

		{&kitana_entry_table[5]	,0,    21368},
		{&kitana_entry_table[6]	,0,    10164},

		{&kitana_entry_table[7]	,0,    13484},
		{&kitana_entry_table[8]	,0,	   6016},
		{&kitana_entry_table[9]	,0,    10560},
		{&kitana_entry_table[10],0,	   10112},
		{&kitana_entry_table[11],0,    9280},
		{&kitana_entry_table[12],0,	   10112},
		{&kitana_entry_table[13]	,0,58624},
		{&kitana_entry_table[14]	,0,52352},

		{&kitana_entry_table[15]	,0,179840},
		{&kitana_entry_table[16]	,0,166016},
		{&kitana_entry_table[17]	,0,247424},
		{0,0,0}
};



void init_kitana_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < KITANA_FILES; i++)
	{
		kitana_entry_table[i].belong = &kitana_file_table[0];
	}


	for (int i = 1; i < KITANA_FILES; i++)
	{
		kitana_file_table[i].previousSize = baseSize;
		baseSize += (kitana_file_table[i].size + 2048 - 1) & -2048;
	}
}
