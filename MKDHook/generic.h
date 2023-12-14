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
extern void obj_set_rotation_from_target(int obj, CVector* target);

void patch_weapon_grab(int data, int obj);
void patch_weapon_show(int data, int unk, int entry);
void patch_weapon_hide(int data, int unk, int entry);

void goro_grab_weapon(int data);
void goro_show_weapon(int data, int unk);
void goro_hide_weapon(int data, int unk);


int fatality_lock();
int death_traps_lock();

float hook_plyr_start_proc();
void  hook_delete_player(int id);

void update_characters();