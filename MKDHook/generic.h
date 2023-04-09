// generic hooks or patches
#include "characters/character_list.h"
#include "character.h"
#include "mkdeception.h"
#include "sound.h"

void init_generic();

void patch_freeze_reaction();
void patch_freeze_sound();

float hook_plyr_start_proc();
void  hook_delete_player(int id);