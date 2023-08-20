#pragma once
// UMKD DRAHMIN
#include "..\toc.h"
#include "..\moves.h"


#define DRAHMIN_FILES 20


extern struct mk_file_entry drahmin_entry_table[DRAHMIN_FILES];
extern struct mk_toc_entry drahmin_file_table[DRAHMIN_FILES + 1];

extern struct mk_file_entry drahmin_alt_entry_table[DRAHMIN_FILES];
extern struct mk_toc_entry drahmin_alt_file_table[DRAHMIN_FILES + 1];

extern struct scan_action_dual scan_drahmin_1;
extern struct scan_action scan_drahmin_2;
extern struct scan_action scan_drahmin_4;
void init_drahmin_toc();
