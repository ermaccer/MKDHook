#pragma once
#include "..\toc.h"

#define MKDA_BLAZE_FILES 18

extern struct mk_file_entry mkda_blaze_entry_table[MKDA_BLAZE_FILES];
extern struct mk_toc_entry mkda_blaze_file_table[MKDA_BLAZE_FILES + 1];

void init_mkda_blaze_toc();