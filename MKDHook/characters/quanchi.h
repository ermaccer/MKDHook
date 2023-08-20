#pragma once
// UMKD QUANCHI
#include "..\toc.h"
#include "..\moves.h"


#define QUAN_FILES 20


extern struct mk_file_entry quan_entry_table[QUAN_FILES];
extern struct mk_toc_entry quan_file_table[QUAN_FILES + 1];

extern struct mk_file_entry quan_alt_entry_table[QUAN_FILES];
extern struct mk_toc_entry quan_alt_file_table[QUAN_FILES + 1];


extern struct scan_action scan_quan_1;
extern struct scan_action scan_quan_3;
extern struct scan_action scan_quan_4;

void init_quan_toc();
