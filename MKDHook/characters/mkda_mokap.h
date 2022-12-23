#pragma once
#include "..\toc.h"

#define MKDA_MOKAP_FILES 18

extern struct mk_file_entry mkda_mokap_entry_table[MKDA_MOKAP_FILES];
extern struct mk_toc_entry mkda_mokap_file_table[MKDA_MOKAP_FILES + 1];

void init_mkda_mokap_toc();