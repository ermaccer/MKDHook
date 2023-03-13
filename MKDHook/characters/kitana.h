#pragma once
// MKU KITANA
#include "..\toc.h"
#include "..\moves.h"

#define NUM_STRETCHBONES 14

typedef struct {
	int boneID;
	float x;
	float y;
	float z;
}kitana_bone_stretcher_entry;

#define KITANA_FILES 21

extern struct mk_file_entry kitana_entry_table[KITANA_FILES];
extern struct mk_toc_entry kitana_file_table[KITANA_FILES + 1];

extern struct mk_file_entry kitana_alt_entry_table[KITANA_FILES];
extern struct mk_toc_entry kitana_alt_file_table[KITANA_FILES + 1];

extern kitana_bone_stretcher_entry kitana_bone_stretchers[NUM_STRETCHBONES];

extern struct scan_action scan_kitana_1;
extern struct scan_fatality scan_kitana_2;
extern struct scan_action scan_kitana_3;

void init_kitana_toc();

void kitana_kod_stretcher(int object, float scale);
void kitana_fanlift_voice();