#include "core.h"

void _printf(char* format, ...)
{
	((void(*)(const char*, ...))0x1E7CF0)(format);
}

void render()
{
	((void(*)())0x127090)();
}

void pause(int status)
{
	((void(*)(int))0x18A330)(status);
}

void init_fatality_world()
{
	((void(*)())0x25D250)();
}

int randu(int max)
{
	return ((int(*)(int))0x18D1D0)(max);
}

int get_game_state()
{
	return *(int*)0x612E14;
}

int get_game_mode()
{
	return *(int*)0x5D629C;
}

int get_game_tick()
{
	return *(int*)0x5D62AC;
}

void set_game_speed(float speed)
{
	*(float*)0x5D628C = speed;
}

int load_background(int id)
{
	return ((int(*)(int))0x15A620)(id);
}

void load_ssf(struct mk_toc_entry* table)
{
	((void(*)(struct mk_toc_entry*))0x267090)(table);

}
