#pragma once
// UMKD SHANG TSUNG
#include "..\toc.h"
#include "..\moves.h"
#include "..\mkdeception.h"



#define SHANG_FILES 21
#define SHANG_BALLS_PROC_ID 20527

#define SHANG_BALL_LEFT 0
#define SHANG_BALL_RIGHT 1
#define SHANG_BALL_EXPLOSION 2
#define SHANG_TOTAL_EMITTERS 3

#define SHANG_FX_LEFT_TRAIL 0
#define SHANG_FX_LEFT 1
#define SHANG_FX_RIGHT_TRAIL 2
#define SHANG_FX_RIGHT 3
#define SHANG_FX_EXPLOSION 4
#define SHANG_TOTAL_FX 5

extern struct mk_file_entry shang_entry_table[SHANG_FILES];
extern struct mk_toc_entry shang_file_table[SHANG_FILES + 1];

extern struct mk_file_entry shang_alt_entry_table[SHANG_FILES];
extern struct mk_toc_entry shang_alt_file_table[SHANG_FILES + 1];

extern struct scan_action scan_shang_1;
extern struct scan_action_dual scan_shang_2;
extern struct scan_action scan_shang_3;

extern int shang_emitter_particle_handle[2][SHANG_TOTAL_EMITTERS];
extern int shang_emitter_fx_handle[2][SHANG_TOTAL_FX];
extern int shang_balls_exploded[2];
extern int shang_balls_script_set[2];
extern float shang_balls_distance[2][2];

void init_shang_toc();


int shangtsung_make_new_balls(int plrID);
void shangtsung_check_for_balls(int plrID);
void shangtsung_balls_set_on_fire(int plrID);
void p_shangtsung_update_ball(int obj, int plrObj, float speed, float angle);
float p_shangtsung_balls_proc();
void start_shangtsung_balls(int plrID, int type);
void shang_explode_ball(int plrID);
int p_shangtsung_are_balls_touching(int plrID, int obj, int obj2);
void p_shangtsung_explode_balls(int plrID, int obj, int obj2, int hit);



void shangtsung_reset_event();
void reset_shangtsung_emitters(int plrID);