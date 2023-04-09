#pragma once
#include "..\toc.h"

#define FATANIMS_FILES 52 + 1


extern struct mk_file_entry fatalityanims_entry_table[FATANIMS_FILES];
extern struct mk_toc_entry  fatalityanims_file_table[FATANIMS_FILES + 1];


void init_fatanims_toc();
void init_fatanims_hook();

void load_new_fatanims();