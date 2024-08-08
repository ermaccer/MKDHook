#pragma once
#include "..\toc.h"

#define KON_NPC_FILES 65


extern struct mk_file_entry kon_npc_entry_table[KON_NPC_FILES];
extern struct mk_toc_entry  kon_npc_file_table[KON_NPC_FILES + 1];


void init_kon_npc_toc();
void init_kon_npc_hook();

void load_new_kon_npc();