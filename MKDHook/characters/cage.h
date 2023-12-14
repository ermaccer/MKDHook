#pragma once
// UMKD CAGE
#include "..\toc.h"
#include "..\moves.h"


#define CAGE_FILES 19


extern struct mk_file_entry cage_entry_table[CAGE_FILES];
extern struct mk_toc_entry cage_file_table[CAGE_FILES + 1];

extern struct mk_file_entry cage_alt_entry_table[CAGE_FILES];
extern struct mk_toc_entry cage_alt_file_table[CAGE_FILES + 1];

extern struct scan_action scan_cage_1;
extern struct scan_action scan_cage_3;
extern struct scan_action scan_cage_4;

void init_cage_toc();
