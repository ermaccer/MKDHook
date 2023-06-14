#include "core.h"
#include "..\ps2mem.h"
void _printf(char* format, ...)
{
	((void(*)(const char*, ...))0x1E7CF0)(format);
}

void _sprintf(char* dest, char* format, ...)
{
	((void(*)(const char*, ...))0x1E9660)(format);
}

int _strcmp(char* str1, char* str2)
{
	return ((int(*)(char*, char*))0x1E9CA8)(str1, str2);
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

void set_game_mode(int mode)
{
	patchInt(0x5D629C, mode);
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
	patchFloat(0x5D628C, speed);
}

int get_character_id(int plr)
{
	player_info* plr1 = (player_info*)PLAYER1_INFO;
	player_info* plr2 = (player_info*)PLAYER2_INFO;
	if (plr == 0) return plr1->characterID;
	if (plr == 1) return plr2->characterID;
	return -1;
}

void delete_player(int id)
{
	((void(*)(int))0x131DF0)(id);
}

void set_fatality_available(int status)
{
	patchInt(0x5D64FC, status);
}

int load_background(int id)
{
	return ((int(*)(int))0x15A620)(id);
}

void load_ssf(struct mk_toc_entry* table)
{
	((void(*)(struct mk_toc_entry*))0x267090)(table);

}

void load_art_section_by_name(int slot, char* name)
{
	((int(*)(int, char*))0x1A4250)(slot, name);
}

void load_art_section(int slot, int ptr)
{
	((int(*)(int, int))0x1A44D0)(slot, ptr);
}

void add_art_section_by_name_async(int slot, char* name)
{
	((int(*)(int, char*))0x1A4BB0)(slot, name);
}

int load_named_model_from_slot(int slot, char* name, int id, int unk)
{
	return ((int(*)(int, char*, int, int))0x36DFF0)(slot, name, id, unk);
}

int load_named_model_for_player(char* name, int plr, int id, int unk)
{
	return ((int(*)(char*, int, int, int))0x36C730)(name, plr, id, unk);
}

void unload_section_slot(int slot)
{
	((void(*)(int))0x1A5150)(slot);
}

void wait_for_slot_load(int slot)
{
	((void(*)(int))0x1A4830)(slot);
}

int create_mkproc_hand_anim(int id, void* pFunc, int* result)
{
	return ((int(*)(int, void*, int*))0x166540)(id, pFunc, result);
}

int create_mkproc_generic_nostack(int id, int a2, void* pFunc, int unk, int* result)
{
	return ((int(*)(int, int, void*, int, int*))0x12C4C0)(id, a2, pFunc, unk, result);
}

void mk_insert_no_own(int obj, int proc)
{
	((void(*)(int, int))0x12E220)(obj, proc);
}
