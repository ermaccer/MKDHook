#pragma once
#include "..\toc.h"

#define DRAGONKING_FILES 13

extern struct mk_file_entry  dragonking_entry_table[DRAGONKING_FILES];
extern struct mk_toc_entry dragonking_file_table[DRAGONKING_FILES + 1];


void hook_xfer_to_intro(int obj, int proc);
void hook_wait_for_intro();


void init_dragonking_toc();
void init_dragonking_patches();