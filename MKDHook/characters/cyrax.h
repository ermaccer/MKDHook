#pragma once
// UMKD CYRAX
#include "..\toc.h"
#include "..\moves.h"
#include "..\mkdeception.h"

#define CYRAX_FILES 19

#define CYRAX_BOMB_EXPLODE_TIME 15
#define CYRAX_BOMB_REACTION_ID 349
#define CYRAX_BOMB_SOUND_ID 7588
#define CYRAX_CUTTER_BLADE_BONE_ID 4
#define CYRAX_CUTTER_BLADE_SPEED 2000
#define CYRAX_CUTTER_SCALE_SPEED 0.07f

#define CYRAX_CUTTER_STATUS_HIDE 1
#define CYRAX_CUTTER_STATUS_START 2
#define CYRAX_CUTTER_STATUS_END 3
#define CYRAX_CUTTER_STATUS_ADJUST 4

extern struct mk_file_entry cyrax_entry_table[CYRAX_FILES];
extern struct mk_toc_entry cyrax_file_table[CYRAX_FILES + 1];

extern struct mk_file_entry cyrax_alt_entry_table[CYRAX_FILES];
extern struct mk_toc_entry cyrax_alt_file_table[CYRAX_FILES + 1];

extern struct scan_action_dual scan_cyrax_1;
extern struct scan_action scan_cyrax_3;
extern struct scan_action scan_cyrax_4;

extern int cyrax_emitter_fx_handle[2];
extern int cyrax_cutter_status[2];
extern int cyrax_bomb_emitter[2];
extern int cyrax_last_bomb_player;

void init_cyrax_toc();
void start_cyrax_bomb(int plrID);

void cyrax_ground_projectile_override_safe(int data);
void cyrax_bomb_process_explosion();
void cyrax_adjust_bomb_position_hack(int data);
void cyrax_update_cutter(int plrID, int object);
void cyrax_cutter_update_status(int plrID, int object);
void cyrax_cutter_rotate(int plrID, int object);
void cyrax_set_cutter_status(int plrID, int status);
void cyrax_cutter_hide(int plrID, int obj);
void cyrax_cutter_start(int plrID, int obj);
void cyrax_cutter_end(int plrID, int obj);
int cyrax_bomb_check_hack_safe(int status);
void cyrax_bomb_play_hit_sound();
void cyrax_reset_event();