#pragma once
// UMKD SONYA
#include "..\toc.h"
#include "..\moves.h"


#define SONYA_FILES 21

extern struct mk_file_entry sonya_entry_table[SONYA_FILES];
extern struct mk_toc_entry sonya_file_table[SONYA_FILES + 1];


extern struct mk_file_entry sonya_alt_entry_table[SONYA_FILES];
extern struct mk_toc_entry sonya_alt_file_table[SONYA_FILES + 1];

extern struct scan_action scan_sonya_1;
extern struct scan_action scan_sonya_2;
extern struct scan_action scan_sonya_3;


void init_sonya_toc();