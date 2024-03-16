#include "teststage.h"

struct mk_file_entry teststage_entry_table[TESTSTAGE_FILES] = {
	{"teststage.ssf"	,0, 4},
	{"teststage.sec"	,0, 1},
	{"teststage.mko"	,0, 3},
};

struct mk_toc_entry teststage_file_table[TESTSTAGE_FILES + 1] = {
		{&teststage_entry_table[0]	,0,0 },
		{&teststage_entry_table[1]	,0,1047552},
		{&teststage_entry_table[2]	,0,1344},
		{0,0,0}
};


void init_teststage_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < TESTSTAGE_FILES; i++)
	{
		teststage_entry_table[i].belong = &teststage_file_table[0];
	}

	for (int i = 1; i < TESTSTAGE_FILES; i++)
	{
		teststage_file_table[i].previousSize = baseSize;
		baseSize += (teststage_file_table[i].size + 2048 - 1) & -2048;
	}
}