#pragma once

char* get_string_by_id(int id);

int string_left_xy(int id, int font, char* text, int x, int y, int unk);
int string_right_xy(int id, int font, char* text, int x, int y, int unk);
void update_string_obj(int string, int font, char* newText);
void pfx_2d_obj_set_alpha_by_id(int id, int alpha);

void pfx_2d_obj_set_alpha(int obj, int alpha);
void pfx_2d_obj_set_rgb(int obj, int r, int g, int b);
void pfx_2d_obj_set_size(int obj, float x, float y);
void pfx_2d_obj_set_pos(int obj, int x, int y);