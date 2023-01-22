#pragma once
#include "mkdeception.h"

#define SELECT_SCREEN_SWAP_SOUND 7024
#define SELECT_SCREEN_ALT_PAL_SOUND 7020

enum ECurrentSelect {
	Select_Default,
	Select_UMKD,
	Select_NPC,
};
extern int sound;

void init_mkdhook_vars();

void process_swap_select_screen();
void swap_select_screen();

void restore_select_screen();
void hook_render();

void process_mkdhook();