#pragma once
#include "..\toc.h"
#include "..\moves.h"

// GC/MKU SHAOKAHN

#define SK_FILES 21

extern struct mk_file_entry sk_entry_table[SK_FILES];
extern struct mk_toc_entry sk_file_table[SK_FILES + 1];

extern struct mk_file_entry sk_alt_entry_table[SK_FILES];
extern struct mk_toc_entry sk_alt_file_table[SK_FILES + 1];

extern struct scan_action_triple scan_sk_1;
extern struct scan_action_dual_fatality scan_sk_2;
extern struct scan_action scan_sk_3;
extern struct scan_suicide scan_sk_suicide;

void init_sk_toc();

void get_taunts_performed();
void increment_taunts_performed();