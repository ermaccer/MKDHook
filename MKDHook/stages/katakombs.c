#include "katakombs.h"


struct mk_file_entry katakombs_entry_table[KATAKOMBS_FILES] = {
	{"katakombs.ssf"	,0, 4},

	{"katakombs.sec"	,0, 1},
	{"katakombs.mko"	,0, 3},
	{"katakombs_fx.mko"	,0, 3},
};

struct mk_toc_entry katakombs_file_table[KATAKOMBS_FILES + 1] = {
		{&katakombs_entry_table[0]	,0,0 },

		{&katakombs_entry_table[1]	,0,2983296},
		{&katakombs_entry_table[2]	,0,2176},
		{&katakombs_entry_table[3]	,0,1576},

		{0,0,0}
};



void init_katakombs_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < KATAKOMBS_FILES; i++)
	{
		katakombs_entry_table[i].belong = &katakombs_file_table[0];
	}


	for (int i = 1; i < KATAKOMBS_FILES; i++)
	{
		katakombs_file_table[i].previousSize = baseSize;
		baseSize += (katakombs_file_table[i].size + 2048 - 1) & -2048;
	}


}
