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
#define P2_PROC_DATA   0x5D6398
#define PLAYER2_OBJ    0x5D639C
#define PLAYER_OBJ     0x5D63A0


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
	MODE_PRACTICE,
	MODE_4,
	MODE_PUZZLE,
	MODE_KONQUEST,
	MODE_7,
	MODE_8,
	MODE_CHESS,
	MODE_FRONTEND = 13,
};



void _printf(char* format, ...);
void _sprintf(char* dest, char* format, ...);
void render();
void pause(int status);
void init_fatality_world();
int randu(int max);
int get_game_state();
int get_game_mode();
int get_game_tick();
void xfer_proc(int obj, int proc);

void set_game_speed(float speed);

int get_character_id(int plr);


// loaders
int load_background(int id);
void load_ssf(struct mk_toc_entry* table);