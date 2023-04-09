#pragma once
#define CURRENT_ARGS 0x5D6C3C 
#define ACTIVE_SCRIPT 0x5D6C40
#define AP_DATA	0x5D6330
#define APROC	0x5D6338
#define SCRIPT_OBJ 0x627A14


//SOUNDS
// 14 - screaming
// 21 - choking
int snd_req(int id);
int snd_req_vol(int id, float vol);
void snd_stop(int sound);

int create_mkproc_generic_nostack(int id, int a2, void* pFunc, int unk, int* result);
int am_i_flipped();
int am_i_flipped_direct(int obj);
void swap_active_proc();

int get_cur_proc_pobj();

void freeze_player();

void init_ground_move();

int plyr_aux_weapon_release(int a1);
int plyr_aux_weapon_grab(int a1, int a2);
int plyr_obj_item_grab(int a1, int a2, int a3, int a4);

void pfx_bind_emitter_num_to_obj_bone(int pfx, int obj, int boneID, int pfxID);

// script funcs

void set_arg_num(int num);
void push_arg(int id, int data);
void push_argf(int id, float data);
int  get_arg(int id);
void call_script_function(int id);

void reaction_xfer_him(int id, int a2, float a3);

void sleep(int time);
void blend_to_ani(int anim, int unk, float unk2);
void force_away(int a1, int a2);

