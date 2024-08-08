// generic hooks or patches
#include "characters/character_list.h"
#include "character.h"
#include "mkdeception.h"
#include "sound.h"
#include "build_config.h"

void init_generic();

void patch_freeze_reaction();
void patch_freeze_sound();

extern void freeze_reaction_patch();
extern void freeze_reaction_patchP2();

extern void plyr_weapon_grab_direct(int data, int obj);

extern void cyrax_bomb_hack_check();

extern void eye_gore_check();
extern void eye_gore2_check();
extern void eye_gore3_check();

extern void scorpion_spear_launch_hack();
extern void scorpion_spear_victory_hack();

void scorpion_spear_detach_hack(int data, int obj);

void create_player_hook(int id, player_info* info);
void set_palettes_hook(player_info* info);


void patch_weapon_grab(int data, int obj);
void patch_weapon_show(int data, int unk, int entry);
void patch_weapon_hide(int data, int unk, int entry);
void patch_lightning_sound(int id);

void goro_grab_weapon(int data);
void goro_show_weapon(int data, int unk);
void goro_hide_weapon(int data, int unk);


int fatality_lock();
int death_traps_lock();

float hook_plyr_start_proc();
void  hook_delete_player(int id);
void  hook_reset_fight();

void update_character(player_info* info);
void update_characters();
