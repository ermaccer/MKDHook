#pragma once
#include "misc_anims.h"

struct  mk_toc_entry  misc_anims_file_table[MISC_ANIMS_FILES] = {
		{0	,0,SCRIPT_REACTIONS_SIZE },
		{0 	,0,35456}, // pselect
		{0	,0,919296}, // bg
};
void patch_misc_anims_toc()
{
	int baseSize = 2048;

	for (int i = 0; i < MISC_ANIMS_FILES; i++)
	{
		misc_anims_file_table[i].previousSize = baseSize;
		baseSize += (misc_anims_file_table[i].size + 2048 - 1) & -2048;
	}

	int patch_addr = 0x5A700C;

	*(int*)0x5A7010 = misc_anims_file_table[0].previousSize;
	*(int*)0x5A7014 = misc_anims_file_table[0].size;
	*(int*)0x5A701C = misc_anims_file_table[1].previousSize;
	*(int*)0x5A7020 = misc_anims_file_table[1].size;
	*(int*)0x5A7028 = misc_anims_file_table[2].previousSize;
	*(int*)0x5A702C = misc_anims_file_table[2].size;
}
