#pragma once
#include "..\toc.h"

#define DKP_FILES 37

extern struct mk_file_entry dkp_entry_table[DKP_FILES];
extern struct mk_toc_entry dkp_file_table[DKP_FILES + 1];

void init_dkp_toc();