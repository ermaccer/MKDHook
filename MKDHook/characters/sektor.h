#pragma once
// UMKD SEKTOR
#include "..\toc.h"
#include "..\moves.h"
#include "..\mkdeception.h"

#define SEKTOR_FILES 19
#define SEKTOR_CHEST_STATUS_DEFAULT 0
#define SEKTOR_CHEST_STATUS_START_OPENING 1
#define SEKTOR_CHEST_STATUS_START_CLOSING 2
#define SEKTOR_CHEST_STATUS_FORCE_CLOSE 3
#define SEKTOR_CHEST_LEFT_BONE_ID 59
#define SEKTOR_CHEST_RIGHT_BONE_ID 58

#define SEKTOR_CHEST_OPEN_MAX 14
#define SEKTOR_CHEST_CLOSE_MAX -12

extern int sektor_chest_status[2];
extern int sektor_chest_angle[2];

extern struct mk_file_entry sektor_entry_table[SEKTOR_FILES];
extern struct mk_toc_entry sektor_file_table[SEKTOR_FILES + 1];

extern struct mk_file_entry sektor_alt_entry_table[SEKTOR_FILES];
extern struct mk_toc_entry sektor_alt_file_table[SEKTOR_FILES + 1];

extern struct scan_action scan_sektor_1;
extern struct scan_action scan_sektor_3;
extern struct scan_action scan_sektor_4;

void init_sektor_toc();

void sektor_set_chest_status(int id, int status);
void sektor_update_chest_piece(bone_data* bone, int id, int right, int isAlt);
void sektor_update_chest(int id, int object, int flags);
void sektor_reset_event();