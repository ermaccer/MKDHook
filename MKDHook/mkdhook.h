#pragma once
#include "mkdeception.h"
//#define KONQUEST_FP

int hook_character_lock_status(int id, int param);

void hook_new_select_table(int status);
void restore_select_screen();
void hook_render();
int test_print(int id, int font, char* text, int y, int x, int unk);

void process_mkdhook();