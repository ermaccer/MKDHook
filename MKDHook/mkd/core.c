#include "core.h"

void _printf(char* format, ...)
{
	((void(*)(const char*, ...))0x1E7CF0)(format);
}

void _sprintf(char* dest, char* format, ...)
{
	((void(*)(const char*, ...))0x1E9660)(format);
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

void xfer_proc(int obj, int proc)
{
	((void(*)(int, int))0x12D260)(obj, proc);
}

void set_game_speed(float speed)
{
	*(float*)0x5D628C = speed;
}

int get_character_id(int plr)
{
	player_info plr1 = *(player_info*)PLAYER1_INFO;
	player_info plr2 = *(player_info*)PLAYER2_INFO;
	if (plr == 0) return plr1.characterID;
	if (plr == 1) return plr2.characterID;
	return -1;
}

void delete_player(int id)
{
	((void(*)(int))0x131DF0)(id);
}

void set_fatality_available(int status)
{
	*(int*)0x5D64FC = status;
}

int load_background(int id)
{
	return ((int(*)(int))0x15A620)(id);
}

void load_ssf(struct mk_toc_entry* table)
{
	((void(*)(struct mk_toc_entry*))0x267090)(table);

}
