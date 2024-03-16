#pragma once
// UMKD NITARA
#include "..\toc.h"
#include "..\moves.h"


#define NITARA_FILES 19


extern struct mk_file_entry nitara_entry_table[NITARA_FILES];
extern struct mk_toc_entry nitara_file_table[NITARA_FILES + 1];

extern struct mk_file_entry nitara_alt_entry_table[NITARA_FILES];
extern struct mk_toc_entry nitara_alt_file_table[NITARA_FILES + 1];

extern struct scan_action scan_nitara_2;
extern struct scan_action scan_nitara_3;
extern struct scan_action_dual scan_nitara_4;

void init_nitara_toc();
