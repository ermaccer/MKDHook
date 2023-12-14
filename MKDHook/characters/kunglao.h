#pragma once
// UMKD KUNGLAO
#include "..\toc.h"
#include "..\moves.h"


#define KUNGLAO_FILES 19


extern struct mk_file_entry kunglao_entry_table[KUNGLAO_FILES];
extern struct mk_toc_entry kunglao_file_table[KUNGLAO_FILES + 1];

extern struct mk_file_entry kunglao_alt_entry_table[KUNGLAO_FILES];
extern struct mk_toc_entry kunglao_alt_file_table[KUNGLAO_FILES + 1];

extern struct scan_action scan_kunglao_1;
extern struct scan_action scan_kunglao_3;
extern struct scan_action scan_kunglao_4;

void init_kunglao_toc();
void kunglao_fatality_hide_hat(int id, int object);
