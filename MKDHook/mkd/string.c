#include "string.h"

char* get_string_by_id(int id)
{
	return ((char*(*)(int))0x219CE0)(id);
}

int string_left_xy(int id, int font, char* text, int x, int y, int unk)
{
	return ((int(*)(int, int, char*, int, int, int))0x175A20)(id, font, text, x, y, unk);
}

int string_right_xy(int id, int font, char* text, int x, int y, int unk)
{
	return ((int(*)(int, int, char*, int, int, int))0x1759A0)(id, font, text, x, y, unk);
}

void update_string_obj(int string, int font, char* newText)
{
	((void(*)(int, int, char*))0x1754C0)(string, font, newText);
}

void pfx_2d_obj_set_alpha_by_id(int id, int alpha)
{
	((void(*)(int, int))0x18B370)(id, alpha);
}

void pfx_2d_obj_set_alpha(int obj, int alpha)
{
	*(char*)(obj + 184) = alpha;
}

void pfx_2d_obj_set_rgb(int obj, int r, int g, int b)
{
	*(char*)(obj + 172) = r;
	*(char*)(obj + 176) = g;
	*(char*)(obj + 180) = b;

}

void pfx_2d_obj_set_size(int obj, float x, float y)
{
	*(float*)(obj + 64) = x;
	*(float*)(obj + 84) = y;
}

void pfx_2d_obj_set_pos(int obj, int x, int y)
{
	*(int*)(obj + 40) = x;
	*(int*)(obj + 44) = y;
}
