#pragma once
#include "..\toc.h"

#define ACIDBATH_FILES 4

extern struct mk_file_entry acidbath_entry_table[ACIDBATH_FILES];
extern struct mk_toc_entry acidbath_file_table[ACIDBATH_FILES + 1];

void init_acidbath_toc();