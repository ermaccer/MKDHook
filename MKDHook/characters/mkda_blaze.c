#include "mkda_blaze.h"

struct mk_file_entry mkda_blaze_entry_table[MKDA_BLAZE_FILES] = {
	{"mkda_blaze.ssf"	,0, 4},
	{"mkda_blaze.sec"	,0, 1},
	{"mkda_blaze_ap.sec"	,0, 1},
	{"sh_mkda_blaze.sec"	,0, 1},
	{"mkda_blaze.mko"	,0, 3},
	{"blood_fx.mko"	,0	,3},
	{"fight_fx.mko"	,0	,3},
	{"karate.mko"	,0	,3},
	{"style_karate.sec"	,0,1 },
	{"jeetkunedo.mko"	,0, 3},
	{"style_jeet_kun_do.sec",0,1 },
	{"nunchaku.mko"	,0, 3},
	{"style_nunchaku.sec", 0,1 },
	{"blaze_anims.sec"	,0, 2},
	{"pz_jax_anims.sec"	,0, 2},
	{"karate_anims.sec"	,0, 2},
	{"jeetkunedo_anims.sec"	,0, 2},
	{"nunchaku_anims.sec"	,0, 2},

};

struct mk_toc_entry mkda_blaze_file_table[MKDA_BLAZE_FILES + 1] = {
		{&mkda_blaze_entry_table[0]	,0,0 },
		{&mkda_blaze_entry_table[1]	,0,	   351616},
		{&mkda_blaze_entry_table[2]	,0,	   351616},
		{&mkda_blaze_entry_table[3]	,0,	   233088},
		{&mkda_blaze_entry_table[4]	,0,	   2556},
		{&mkda_blaze_entry_table[5]	,0,	   21368},
		{&mkda_blaze_entry_table[6]	,0,	   10164},
		{&mkda_blaze_entry_table[7]	,0,	   16004},
		{&mkda_blaze_entry_table[8]	,0,	   10112},
		{&mkda_blaze_entry_table[9]	,0,	   11692},
		{&mkda_blaze_entry_table[10]	,0,10112},
		{&mkda_blaze_entry_table[11]	,0,15372},
		{&mkda_blaze_entry_table[12]	,0,10112},
		{&mkda_blaze_entry_table[13]	,0,21760},
		{&mkda_blaze_entry_table[14]	,0,52352},
		{&mkda_blaze_entry_table[15]	,0,170496},
		{&mkda_blaze_entry_table[16]	,0,189312},
		{&mkda_blaze_entry_table[17]	,0,222208},
		{0,0,0}
};


void init_mkda_blaze_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < MKDA_BLAZE_FILES; i++)
	{
		mkda_blaze_entry_table[i].belong = &mkda_blaze_file_table[0];
	}


	for (int i = 1; i < MKDA_BLAZE_FILES; i++)
	{
		mkda_blaze_file_table[i].previousSize = baseSize;
		baseSize += (mkda_blaze_file_table[i].size + 2048 - 1) & -2048;
	}
}
