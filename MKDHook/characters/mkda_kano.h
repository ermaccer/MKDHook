#pragma once
#include "..\toc.h"

#define MKDA_KANO_FILES 18

extern struct mk_file_entry mkda_kano_entry_table[MKDA_KANO_FILES];
extern struct mk_toc_entry mkda_kano_file_table[MKDA_KANO_FILES + 1];

void init_mkda_kano_toc();