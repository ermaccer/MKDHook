	#pragma once
#include "mkdeception.h"
#include "character.h"
#include "sound.h"

#define SELECT_SCREEN_SWAP_SOUND 7024
#define SELECT_SCREEN_ALT_PAL_SOUND 7020


enum ECurrentSelect {
	Select_Default,
	Select_UMKD,
	Select_NPC,
};
extern select_screen_entry pSelectTableNew[27];

void init_mkdhook_vars();

void process_swap_select_screen();
void swap_select_screen();

void restore_select_screen();
void hook_render();

void process_mkdhook();