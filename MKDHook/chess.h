#pragma once

#include "build_config.h"
#include "toc.h"

#define CHESS_FILES 45
#define CHESS_PIECES 34

extern struct mk_file_entry chess_entry_table[CHESS_FILES];
extern struct mk_toc_entry  chess_file_table[CHESS_FILES + 1];

void init_chess_hook();

void load_new_chess();