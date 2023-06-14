#pragma once
#include "build_config.h"
#include "toc.h"

#define LADDER_FILES 4


extern struct mk_file_entry ladder_entry_table[LADDER_FILES];
extern struct mk_toc_entry  ladder_file_table[LADDER_FILES + 1];

struct ladder_entry
{
	int background;
	int backgroundLocked;
	int character;
	int characterLocked;
};

typedef struct
{
	int stageID;
	char* image;
	int field8;
	int field12;
} ladder_stage_entry;

typedef struct {
	int id;
	char* name;
}ladder_model_entry;

void init_ladder_hook();

int hook_get_one_tower(int max);
void make_custom_tower();
int is_in_my_ladder(int id);
int is_map_in_my_ladder(int id);

// game funcs

int get_current_ladder_pos();
