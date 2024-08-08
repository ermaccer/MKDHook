#pragma once
#include "..\toc.h"
#include "..\moves.h"

#define SCORPION_FILES 21

extern struct mk_file_entry scorpion2_entry_table[SCORPION_FILES];
extern struct mk_toc_entry scorpion2_file_table[SCORPION_FILES + 1];

extern struct scan_action scan_scorpion_2;
extern struct scan_action_dual scan_scorpion_3;



void init_scorpion_toc();
