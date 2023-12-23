#pragma once
#define CURRENT_ARGS 0x5D6C3C 
#define ACTIVE_SCRIPT 0x5D6C40
#define AP_DATA	0x5D6330
#define APROC	0x5D6338
#define SCRIPT_OBJ 0x627A14


int snd_req(int id);
int snd_req_vol(int id, float vol);
void snd_stop(int sound);
void set_music(int id);


int find_mkproc_pid(int id);
int create_mkproc_generic_nostack(int id, int a2, void* pFunc, int unk, int* result);
void destroy_mkprocs_pid(int id);
int am_i_flipped();
int am_i_flipped_direct(int obj);
void swap_active_proc();

int get_cur_proc_pobj();

void freeze_player();

void init_ground_move();

int plyr_aux_weapon_release(int a1);
int plyr_aux_weapon_grab(int a1, int a2);

void pfx_bind_emitter_num_to_obj_bone(int pfx, int obj, int boneID, int pfxID);

int get_new_emitter_obj(int frameID);

void execute_rx_cleanup(int pData);
void reaction_xfer_him(int id, int a2, float a3);
// script funcs
void force_away(int a1, int a2);

