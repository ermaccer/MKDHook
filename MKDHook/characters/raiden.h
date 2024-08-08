#pragma once
#include "..\toc.h"
#include "..\moves.h"

#define RAIDEN_FILES 21

extern struct mk_file_entry raiden2_entry_table[RAIDEN_FILES];
extern struct mk_toc_entry raiden2_file_table[RAIDEN_FILES + 1];


void init_raiden_toc();
