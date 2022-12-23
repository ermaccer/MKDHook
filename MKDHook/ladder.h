#pragma once

struct ladder_entry
{
	int background;
	int backgroundLocked;
	int character;
	int characterLocked;
};


void init_ladder_hook();

int hook_get_one_tower(int max);
void make_custom_tower();
int is_in_my_ladder(int id);
int is_map_in_my_ladder(int id);