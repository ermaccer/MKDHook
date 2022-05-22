#include "mkdeception.h"

int(*is_char_locked)(int id, int param);
int(*load_hero_model)(int ptr);

int(*pressed_button)(int player, int id);
void (*game_printf)(char* format, ...);
void(*render)();
void(*refresh_screen)();

int(*string_left_xy)(int id, int font, char* text, int y, int x, int unk);
void(*mko_clear)();
void(*mko_push)(int script, int command_id);
void(*mko_run)(int script);
int(*mko_get_function_id)(int script, char* name);
void(*mko_player_call)();

int get_game_state()
{
	return *(int*)0x626BD4;
}

int get_game_tick()
{
	int* gp = (int*)0x5EA000;
	return (*(gp + 5));
}

void call_script(char* name)
{
	int id = 0;

	int script = *(int*)(0x5F5968);

	id = mko_get_function_id(script, name);
	//*(int*)0x59FFB0 = script;
	//*(int*)0x59FFB4 = id;

	*(int*)(0x5EA9E0 + 40) = id;
	//game_printf("SCRIPT ID: %d\n", id);
	// 
	//*(int*)(*(&dword_5EA5F8 + 250) + 40) = id;
	//mko_clear();
	//mko_push(script, id);
	//mko_run(script);
}

void MKDeception_Init()
{
	load_hero_model = (void*)0x303A90;
	render = (void*)0x127110;
	pressed_button = (void*)0x16B7C0;
	refresh_screen = (void*)0x35BBE0;
	is_char_locked = (void*)0x1933C0;
	game_printf = (void*)0x1E9330;
	string_left_xy = (void*)0x176620;

	mko_clear = (void*)0x21B5A0;
	mko_push = (void*)0x21C0B0;
	mko_run = (void*)0x21C290;
	mko_get_function_id = (void*)0x21BAF0;
	mko_player_call = (void*)0x2118C0;
}
