#pragma once
#include "mkdeception.h"

extern player_info* cached_info;

void init_practice_hook();

void display_pratice_damage(player_info* info);

void practice_sprintf_hook(char* dst, char* fmt, int damageValue);
char* practice_get_hit_level_name(int lvl);