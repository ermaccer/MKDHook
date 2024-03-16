#pragma once
#include "..\toc.h"

#define TESTSTAGE_FILES 3

extern struct mk_file_entry teststage_entry_table[TESTSTAGE_FILES];
extern struct mk_toc_entry teststage_file_table[TESTSTAGE_FILES + 1];

void init_teststage_toc();