#pragma once

#define PLAYER1_OBJ   0x8D929AC
#define PLAYER2_OBJ   0x8D92A18

extern int(*is_char_locked)(int id, int param);
extern int(*load_hero_model)(int ptr);

extern int(*pressed_button)(int player, int id);
extern void (*game_printf)(char* format, ...);
extern void(*render)();
extern void(*refresh_screen)();
extern int(*string_left_xy)(int id, int font, char* text, int y, int x, int unk);
extern void(*mko_clear)();
extern void(*mko_push)(int script, int command_id);
extern void(*mko_run)(int script);
extern int(*mko_get_function_id)(int script, char* name);
extern void(*mko_player_call)();

int get_game_state();
int get_game_tick();

void call_script(char* func);


enum game_state {
	STATE_0,
	STATE_1,
	STATE_2,
	STATE_ATTRACT,
	STATE_SELECT,
	STATE_5,
	STATE_6,
	STATE_GAME,
	STATE_8,
	STATE_MENU,

};

enum characters
{
	SCORPION,
	BARAKA,
	NOOB,
	SUBZERO,
	MILEENA,
	NIGHTWOLF,
	ERMAC,
	ASHRAH,
	SINDEL,
	LI_MEI,
	BORAICHO,
	HOTARU,
	KENSHI,
	SMOKE,
	HAVIK,
	TANYA,
	LIU_KANG,
	GHOST,
	KIRA,
	KABAL,
	KOBRA,
	JADE,
	DAIROU,
	RAIDEN,
	DARRIUS,
	SHUJINKO,
	SHUJINKO_13,
	NOOBSMOKE,
	MONSTER,
	ONAGA,
	MKDA_JAX,
	MKDA_RAIDEN,
	MKDA_QUAN_CHI,
	MKDA_KUNG_LAO,
	MKDA_CAGE,
	MKDA_SONYA,
	MKDA_NITARA,
	MKDA_SHANG_TSUNG,
	MKDA_FROST,
	MKDA_KITANA,
	MKDA_DRAHMIN,
	RANDOM
};

struct ladder_entry
{
	int background;
	int backgroundLocked;
	int character;
	int characterLocked;
};


void MKDeception_Init();
