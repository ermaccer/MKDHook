#pragma once
#include "plr_info.h"
#include "..\toc.h"

typedef struct {
	float x, y, z;
}CVector;

#define PLAYER1_INFO   0x5E43F4 
#define PLAYER2_INFO   0x5E4460
#define PLAYER_DATA    0x5D63A4 
#define MISSION_INFO   0x642C08
#define P2_PLAYER_DATA   0x5D6398
#define PLAYER2_OBJ    0x5D639C
#define PLAYER_OBJ     0x5D63A0
#define CUR_BGND	   0x5E4368

enum game_state {
	STATE_0,
	STATE_1,
	STATE_2,
	STATE_ATTRACT,
	STATE_SELECT,
	STATE_LADDER,
	STATE_6,
	STATE_GAME,
	STATE_8,
	STATE_MENU,
	STATE_10,
	STATE_KRYPT,
	STATE_KONQUEST = 19
};


enum game_mode {
	MODE_ARCADE,
	MODE_VERSUS,
	MODE_2,
	MODE_3,
	MODE_PRACTICE,
	MODE_PUZZLE,
	MODE_KONQUEST,
	MODE_7,
	MODE_8,
	MODE_CHESS,
	MODE_FRONTEND = 13,
};



void _printf(char* format, ...);
void _sprintf(char* dest, char* format, ...);
int _strcmp(char* str1, char* str2);
void render();
void pause(int status);
void init_fatality_world();
int randu(int max);
int get_game_state();
int get_game_mode();
void set_game_mode(int mode);
int get_game_tick();
void xfer_proc(int obj, int proc);

void set_game_speed(float speed);

int get_character_id(int plr);

void delete_player(int id);

void set_fatality_available(int status);

// loaders
int load_background(int id);
void load_ssf(struct mk_toc_entry* table);
void load_art_section_by_name(int slot, char* name);
void load_art_section(int slot, int ptr);
void add_art_section_by_name_async(int slot, char* name);
int load_named_model_from_slot(int slot, char* name, int id, int unk);
int load_named_model_for_player(char* name, int plr, int id, int unk);
void unload_section_slot(int slot);
void wait_for_slot_load(int slot);
int find_section_by_name(char* name);
void add_art_section(int slot, int section);
// procs

int create_mkproc_hand_anim(int id, void* pFunc, int* result);
int create_mkproc_generic_nostack(int id, int a2, void* pFunc, int unk, int* result);


void mk_insert_no_own(int obj, int proc);


typedef struct {
	char* modelName;
	int* bones;
	int boneID;
	float flt_one;
	char pad[24];
	float flt_two;
	int field40;
	char* trailName;
	int* trailBones;
	int trailUnk;
	int* trailAnchors;
	int* trailTails;
	int field64;
	int field68;
	float flt_three;
	int field76;
	int field80;
	float flt_four;
	int someID;
	int field92;
	float flt_five;
	float flt_six;
	int unk;
}weapon_mdl_description;