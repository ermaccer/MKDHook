#pragma once
// UMKD REIKO
#include "..\toc.h"
#include "..\moves.h"

#define REIKO_FILES 19

extern struct mk_file_entry reiko_entry_table[REIKO_FILES];
extern struct mk_toc_entry reiko_file_table[REIKO_FILES + 1];

extern struct mk_file_entry reiko_alt_entry_table[REIKO_FILES];
extern struct mk_toc_entry reiko_alt_file_table[REIKO_FILES + 1];

extern struct scan_action_dual scan_reiko_1;
extern struct scan_action scan_reiko_3;
extern struct scan_action scan_reiko_4;

void init_reiko_toc();
void reiko_teleport();