#pragma once
#include "build_config.h"

#define TOTAL_REACTIONS 314 + EXTRA_REACTIONS
// mku added 17 new reactions

#define UMKD_REACTIONS 1
#define EXTRA_REACTIONS 17 + UMKD_REACTIONS




enum eReactionType {
	TYPE_FUNCTION_CALL = 1, // custom function
	TYPE_2,
	TYPE_SCRIPT_FUNCTION = 3, // player script reaction
	TYPE_REACTIONS_FUNCTION = 4, // this is from misc_anims//shared_reactions.mko
	TYPE_TRANSFER = 5,
};
typedef struct{
	int type;
	int arg;
	int field8;
	int field12;
	int field16;
}reaction_table_entry;



extern reaction_table_entry reaction_table[TOTAL_REACTIONS];

extern int onaga_remap_table[TOTAL_REACTIONS];

void init_reactions_hook();
#ifndef PS2_BUILD
void dump_reactions_table();
void dump_onaga_remap_table();
#endif