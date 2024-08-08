#pragma once
#include "..\toc.h"
#include "..\moves.h"

#define SUBZERO_FILES 21

extern struct mk_file_entry subzero2_entry_table[SUBZERO_FILES];
extern struct mk_toc_entry subzero2_file_table[SUBZERO_FILES + 1];

extern struct mk_file_entry subzero2_alt_entry_table[SUBZERO_FILES];
extern struct mk_toc_entry subzero2_alt_file_table[SUBZERO_FILES + 1];

extern struct scan_action scan_subzero_4;


void fat_sz_start_iceblock();
void init_subzero_toc();
