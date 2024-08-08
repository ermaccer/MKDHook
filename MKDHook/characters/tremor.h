#pragma once
// UMKD TREMOR
#include "..\toc.h"
#include "..\moves.h"

#define TREMOR_FILES 19

extern struct mk_file_entry tremor_entry_table[TREMOR_FILES];
extern struct mk_toc_entry tremor_file_table[TREMOR_FILES + 1];


extern struct scan_action scan_tremor_2;
extern struct scan_action scan_tremor_3;
extern struct scan_action scan_tremor_4;

void init_tremor_toc();