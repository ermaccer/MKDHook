#pragma once
// MKU FROST
#include "..\toc.h"
#include "..\moves.h"


#define FROST_FILES 21

extern struct mk_file_entry frost_entry_table[FROST_FILES];
extern struct mk_toc_entry frost_file_table[FROST_FILES + 1];


extern struct mk_file_entry frost_alt_entry_table[FROST_FILES];
extern struct mk_toc_entry frost_alt_file_table[FROST_FILES + 1];

extern struct scan_fatality scan_frost_1;
extern struct scan_action scan_frost_3;
extern struct scan_action scan_frost_4;

void init_frost_toc();

void fat_frost_start_iceblock();
void fat_frost_start_icechunks();