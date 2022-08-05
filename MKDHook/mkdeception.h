#pragma once

#define PLAYER1_INFO   0x5F8184
#define PLAYER2_INFO   0x5F81F0

struct CVector
{
	float x, y, z;
};

struct CQuat
{
	float x, y, z, w;
};

// plr obj
// 20 - visible

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
extern void(*update_string)(int string, int font, char* newText);
extern void(*string_set_alpha)(int id, int alpha);
extern void(*pause)(int i);

extern void(*set_cam_pos)(struct CVector* pos);
extern void(*set_cam_rot)(struct CVector* rot);

extern void(*get_bone_pos)(int obj, int id, struct CVector* pos);

int get_game_state();
int get_game_tick();

struct CQuat* get_bone_rot(int obj, int id);
struct CVector  get_bone_rot_vec(struct CQuat base);
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


enum pad_button {
	PAD_L2,
	PAD_R2,
	PAD_L1,
	PAD_R1,
	PAD_TRIANGLE,
	PAD_CIRCLE,
	PAD_CROSS,
	PAD_SQUARE,
	PAD_SELECT,
	PAD_L3,
	PAD_R3,
	PAD_START,
	PAD_UP,
	PAD_RIGHT,
	PAD_DOWN,
	PAD_LEFT,
	PAD_ANY,
	PAD_L2R2,

};

struct ladder_entry
{
	int background;
	int backgroundLocked;
	int character;
	int characterLocked;
};


struct player_info
{
	int field_0;
	int field_4;
	int selected;
	float field_C;
	char field_10;
	char field_11;
	char field_12;
	char field_13;
	int flags;
	int field_18;
	char field_1C;
	char field_1D;
	char field_1E;
	char field_1F;
	char field_20;
	char field_21;
	char field_22;
	char field_23;
	char field_24;
	char field_25;
	char field_26;
	char field_27;
	char field_28;
	char field_29;
	char field_2A;
	char field_2B;
	char field_2C;
	char field_2D;
	char field_2E;
	char field_2F;
	char field_30;
	char field_31;
	char field_32;
	char field_33;
	char field_34;
	char field_35;
	char field_36;
	char field_37;
	char field_38;
	char field_39;
	char field_3A;
	char field_3B;
	char field_3C;
	char field_3D;
	char field_3E;
	char field_3F;
	int field_40;
	int winCount;
	int field_48;
	int field_4C;
	int field_50;
	int characterID;
	int field_58;
	int pObject;
	int field_60;
	int field_64;
	int field_68;
};



void MKDeception_Init();
