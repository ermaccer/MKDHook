#pragma once
#include "..\toc.h"
#include "..\moves.h"

#define ERMAC_FILES 22

extern struct mk_file_entry ermac2_entry_table[ERMAC_FILES];
extern struct mk_toc_entry ermac2_file_table[ERMAC_FILES + 1];

extern struct scan_action scan_ermac_2;


void init_ermac_toc();


