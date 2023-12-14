#include "acidbath.h"


struct mk_file_entry acidbath_entry_table[ACIDBATH_FILES] = {
	{"acidbath.ssf"	,0, 4},
	{"acidbath.sec"	,0, 1},
	{"acidbath.mko"	,0, 3},
};

struct mk_toc_entry acidbath_file_table[ACIDBATH_FILES + 1] = {
		{&acidbath_entry_table[0]	,0,0 },
		{&acidbath_entry_table[1]	,0,1636736},
		{&acidbath_entry_table[2]	,0,1344},
		{0,0,0}
};


void init_acidbath_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < ACIDBATH_FILES; i++)
	{
		acidbath_entry_table[i].belong = &acidbath_file_table[0];
	}

	
	for (int i = 1; i < ACIDBATH_FILES; i++)
	{
		acidbath_file_table[i].previousSize = baseSize;
		baseSize += (acidbath_file_table[i].size + 2048 - 1) & -2048;
	}
}
