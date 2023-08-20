#pragma once
// UMKD SAREENA
#include "..\toc.h"
#include "..\moves.h"


#define SAREENA_FILES 19


extern struct mk_file_entry sareena_entry_table[SAREENA_FILES];
extern struct mk_toc_entry sareena_file_table[SAREENA_FILES + 1];

extern struct mk_file_entry sareena_alt_entry_table[SAREENA_FILES];
extern struct mk_toc_entry sareena_alt_file_table[SAREENA_FILES + 1];


extern struct scan_action_dual scan_sareena_1;
extern struct scan_action scan_sareena_4;


void init_sareena_toc();
