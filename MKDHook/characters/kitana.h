#pragma once
// MKU KITANA
#include "..\toc.h"
#include "..\moves.h"


#define KITANA_FILES 18

extern struct mk_file_entry kitana_entry_table[KITANA_FILES];
extern struct mk_toc_entry kitana_file_table[KITANA_FILES + 1];

extern struct scan_action scan_kitana_1;
extern struct scan_action scan_kitana_3;

void init_kitana_toc();