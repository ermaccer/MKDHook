#pragma once
#include "..\toc.h"

#define KATAKOMBS_FILES 4

extern struct mk_file_entry katakombs_entry_table[KATAKOMBS_FILES];
extern struct mk_toc_entry katakombs_file_table[KATAKOMBS_FILES + 1];

void init_katakombs_toc();