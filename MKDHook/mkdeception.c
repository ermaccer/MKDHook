#include "mkdeception.h"

int(*is_bgnd_locked)(int id);
int(*is_char_locked)(int id, int param);
int(*load_hero_model)(int ptr);

int(*pressed_button)(int player, int id);
void (*game_printf)(char* format, ...);
void(*render)();
void(*refresh_screen)();
void(*impale_him)();
int(*string_left_xy)(int id, int font, char* text, int y, int x, int unk);
void(*mko_clear)();
void(*mko_push)(int script, int command_id);
void(*mko_run)(int script);
int(*mko_get_function_id)(int script, char* name);
void(*mko_player_call)();

void(*update_string)(int string, int font, char* newText);
void(*string_set_alpha)(int id, int alpha);
void(*pause)(int i);
int(*randu)(int max);
void(*set_cam_pos)(struct CVector* pos);
void(*set_cam_rot)(struct CVector* rot);
void(*set_cam_target)(struct CVector* rot);
void(*sever_limb)(int obj, int id, int unk, int unk2);
void(*get_bone_pos)(int obj, int id, struct CVector* pos);
void(*hide_limb)(int obj, int id, int unk);
void(*setup_fatality_scene)();
void(*split_in_half)(int obj);
void(*konquest_hide_hud)(int status);
int(*snd_req)(int id);
void(*music_proc)();
int(*get_stick)(int player, int which, float* x, float* y);
void(*update_camera)();
int(*load_background)(int id);
char* (*get_string)(int id);
int get_game_state()
{
	return *(int*)0x612E14;
}

int get_game_mode()
{
	return *(int*)(0x5D629C);
}

int get_game_tick()
{
	return *(int*)(0x5D62AC);
}

void xfer_proc(int proc, int function)
{
	*(int*)(proc + 244) = *(int*)(proc + 240);
	*(int*)(proc + 224) = function;
	*(int*)(proc + 12) = 0;
}

struct CQuat* get_bone_rot(int obj, int id)
{
	int skeleton;
	struct CQuat* v3; 
	struct CQuat* result; 

	skeleton = *(int*)(obj + 72);
	v3 = *(struct CQuat**)(skeleton + 4 * id);
	if (v3 || (v3 = *(struct CQuat**)(skeleton + 4 * *(int*)(obj + 80))) != 0)
		result = v3 + 13;
	else
		result = 0;
	return result;
}

void get_obj_matrix_right(int obj, struct CVector* mat)
{
	mat->x = *(float*)(*(int*)(obj + 36) + 0);
	mat->y = *(float*)(*(int*)(obj + 36) + 4);
	mat->z = *(float*)(*(int*)(obj + 36) + 8);
}

void get_matrix_right(int obj, struct CVector* mat)
{
	mat->x = *(float*)(*(int*)(obj + 36) + 0);
	mat->y = *(float*)(*(int*)(obj + 36) + 4);
	mat->z = *(float*)(*(int*)(obj + 36) + 8);
}

void get_matrix_forward(int obj, struct CVector* mat)
{
	mat->x = *(float*)(*(int*)(obj + 36) + 32 + 0);
	mat->y = *(float*)(*(int*)(obj + 36) + 32 + 4);
	mat->z = *(float*)(*(int*)(obj + 36) + 32 + 8);
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

void set_music(int id)
{
	*(int*)0x5D62EC = snd_req(id);
}


void MKDeception_Init()
{
	load_hero_model = (void*)0x303A90;
	render = (void*)0x127090; // usad
	pressed_button = (void*)0x16ACE0; // usad
	refresh_screen = (void*)0x357520; // usad
	is_char_locked = (void*)0x192580; // usad
	game_printf = (void*)0x1E7CF0; // usad
	string_left_xy = (void*)0x175A20; // usad

	mko_push = (void*)0x21A910; //usad
	mko_run = (void*)0x21A750; //usad
	mko_get_function_id = (void*)0x21A350; //usad

	impale_him = (void*)0x1FB3D0;

	update_string = (void*)0x1754C0; // usad
	string_set_alpha = (void*)0x18B370; // usad

	pause = (void*)0x18A330; //usad

	set_cam_pos = (void*)0x186FA0; //usad
	set_cam_rot  =(void*)0x186F50; // usad
	get_bone_pos = (void*)0x1388F0; // usad
	set_cam_target = (void*)0x186C90; // usad
	sever_limb= (void*)0x13C3C0; // usad
	setup_fatality_scene = (void*)0x25D250;
	split_in_half = (void*)0x3C0840;
	hide_limb = (void*)0x262A10;

	konquest_hide_hud = (void*)0x2F8260;

	is_bgnd_locked = (void*)0x13DF20;
	snd_req = (void*)0x12B2B0;
	randu = (void*)0x18D1D0;
	music_proc = (void*)0x129860;
	update_camera = (void*)0x1833C0;
	get_stick = (void*)0x16A8B0;

	load_background = (void*)0x15A620;

	get_string = (void*)0x219CE0;
}

int get_monk()
{
	int p_konquest_data = *(int*)(0x5D6F40);
	int obj = *(int*)(p_konquest_data + 248);
	if (*(int*)(obj + 4) != *(int*)(p_konquest_data + 252))
		obj = 0;
	return obj;
}
