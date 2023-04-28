#pragma once
// MKU BLAZE
#include "..\toc.h"
#include "..\moves.h"

#define BLAZE_FILES 19

extern struct mk_file_entry blaze_entry_table[BLAZE_FILES];
extern struct mk_toc_entry blaze_file_table[BLAZE_FILES + 1];

extern struct scan_action scan_blaze_1;
extern struct scan_action scan_blaze_2;
extern struct scan_action scan_blaze_3;

void init_blaze();
void init_blaze_toc();


void start_blaze_flaming_limbs(int id);
void reset_blaze_flaming_limbs(int id);

void blaze_reset_event();
void blaze_destroy_event(int id);

void blaze_fatality_watch();