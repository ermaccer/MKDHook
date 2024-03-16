#pragma once
// UMKD SELECT
#include "..\toc.h"


#define PSELECT_MAIN_BUFFER 7475840
#define PSELECT_P1_BUFFER 67584
#define PSELECT_P2_BUFFER 67584



#define PSELECT_FILES 43 + 1


extern struct mk_file_entry pselect_entry_table[PSELECT_FILES];
extern struct mk_toc_entry  pselect_file_table[PSELECT_FILES + 1];


void init_pselect_toc();
void init_pselect_hook();

void load_new_pselect();