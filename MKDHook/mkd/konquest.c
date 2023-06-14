#include "konquest.h"
#include "..\scripthook.h"

int get_monk()
{
	int p_konquest_data = *(int*)(0x5D6F40);
	int obj = *(int*)(p_konquest_data + 248);
	if (*(int*)(obj + 4) != *(int*)(p_konquest_data + 252))
		obj = 0;
	return obj;
}

void konquest_hide_hud()
{
	((void(*)())0x2F8260)();
}

int load_hero_model(int ptr)
{
	return ((int(*)(int))0x303A90)(ptr);
}

void add_npc(int npc)
{
	((void(*)(int))0x334930)(npc);
}

void set_monk_position(int ptr, float x, float y, float z)
{
	((void(*)(int, float, float, float))0x2FEDA0)(ptr, x, y, z);
}
