#pragma once
#include "mkdeception.h"
#include "character.h"
#include "sound.h"
#include "build_config.h"

#define SELECT_SCREEN_SWAP_SOUND 7024
#define SELECT_SCREEN_ALT_PAL_SOUND 7020
#define SELECT_SCREEN_EXTRA_SOUND 7022
#define SELECT_SCREEN_ALT_PAL_FONT 5
#define SELECT_SCREEN_EXTRA_NUM 5

typedef struct {
	int swapCharacter;
	int sourceCharacter;
}swap_entry;

enum ECurrentSelect {
	Select_Default,
	Select_UMKD,
	Select_NPC,
};

extern swap_entry pSwapTable[SELECT_SCREEN_EXTRA_NUM];
extern select_screen_entry pSelectTableNew[24];
extern int pselect_extra_text[2];
extern int pselect_extra_costume_text[24];
extern int pselect_extra_costume_toggle[24];
extern int pselect_alternate_palette_toggle[2];
extern int pselect_toggle_timer[2];
extern int pselect_toggle_extra_timer[2];

extern int pselect_text_x[2];
extern int pselect_text_y[2];



void init_mkdhook_vars();

void process_swap_select_screen();
void swap_select_screen(int refresh);

void restore_select_screen();
void pselect_init_hook();
void pselect_start_text_proc();
void hook_render();
void process_mkdhook();
void set_slot_character_id(int slot, int id);
int  get_slot_character_id(int slot);
float p_select_new_text_proc();
void p_select_toggle_alternate_palette(player_info* info);
void p_select_process_toggle(int id);
void p_select_process_extra_toggle(int id, int slot);
void p_select_create_text();
void p_select_update_text(int id, int alpha);
int  is_extra_swap_allowed(int id);
int  find_extra_swap_entry(int id);
void set_extra_character_remap(int slot, int id);