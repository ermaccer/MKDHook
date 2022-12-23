#include "mkda_mokap.h"

struct mk_file_entry mkda_mokap_entry_table[MKDA_MOKAP_FILES] = {
	{"mkda_mokap.ssf"	,0, 4},
	{"mkda_mokap.sec"	,0, 1},
	{"mkda_mokap_ap.sec"	,0, 1},
	{"sh_mkda_mokap.sec"	,0, 1},
	{"mkda_mokap.mko"	,0, 3},
	{"blood_fx.mko"	,0	,3},
	{"fight_fx.mko"	,0	,3},
	{"karate.mko"	,0	,3},
	{"style_karate.sec"	,0,1 },
	{"jeetkunedo.mko"	,0, 3},
	{"style_jeet_kun_do.sec",0,1 },
	{"nunchaku.mko"	,0, 3},
	{"style_nunchaku.sec", 0,1 },
	{"mokap_anims.sec"	,0, 2},
	{"pz_jax_anims.sec"	,0, 2},
	{"karate_anims.sec"	,0, 2},
	{"jeetkunedo_anims.sec"	,0, 2},
	{"nunchaku_anims.sec"	,0, 2},

};

struct mk_toc_entry mkda_mokap_file_table[MKDA_MOKAP_FILES + 1] = {
		{&mkda_mokap_entry_table[0]	,0,0 },
		{&mkda_mokap_entry_table[1]	,0,	   649728},
		{&mkda_mokap_entry_table[2]	,0,	   649728},
		{&mkda_mokap_entry_table[3]	,0,	   233088},
		{&mkda_mokap_entry_table[4]	,0,	   2604},
		{&mkda_mokap_entry_table[5]	,0,	   21368},
		{&mkda_mokap_entry_table[6]	,0,	   10164},
		{&mkda_mokap_entry_table[7]	,0,	   16004},
		{&mkda_mokap_entry_table[8]	,0,	   10112},
		{&mkda_mokap_entry_table[9]	,0,	   11692},
		{&mkda_mokap_entry_table[10]	,0,10112},
		{&mkda_mokap_entry_table[11]	,0,15372},
		{&mkda_mokap_entry_table[12]	,0,10112},
		{&mkda_mokap_entry_table[13]	,0,21120},
		{&mkda_mokap_entry_table[14]	,0,52352},
		{&mkda_mokap_entry_table[15]	,0,170496},
		{&mkda_mokap_entry_table[16]	,0,189312},
		{&mkda_mokap_entry_table[17]	,0,222208},
		{0,0,0}
};


void init_mkda_mokap_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < MKDA_MOKAP_FILES; i++)
	{
		mkda_mokap_entry_table[i].belong = &mkda_mokap_file_table[0];
	}


	for (int i = 1; i < MKDA_MOKAP_FILES; i++)
	{
		mkda_mokap_file_table[i].previousSize = baseSize;
		baseSize += (mkda_mokap_file_table[i].size + 2048 - 1) & -2048;
	}
}
