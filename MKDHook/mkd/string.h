#pragma once

char* get_string_by_id(int id);

int string_left_xy(int id, int font, char* text, int x, int y, int unk);
void update_string_obj(int string, int font, char* newText);
void pfx_2d_obj_set_alpha_by_id(int id, int alpha);