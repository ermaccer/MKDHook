#pragma once
// UMKD RAIN
#include "..\toc.h"
#include "..\moves.h"


#define RAIN_FILES 19


extern struct mk_file_entry rain_entry_table[RAIN_FILES];
extern struct mk_toc_entry rain_file_table[RAIN_FILES + 1];

extern struct mk_file_entry rain_alt_entry_table[RAIN_FILES];
extern struct mk_toc_entry rain_alt_file_table[RAIN_FILES + 1];


extern struct scan_action_dual scan_rain_1;
extern struct scan_action scan_rain_2;
extern struct scan_action scan_rain_3;

void init_rain_toc();
