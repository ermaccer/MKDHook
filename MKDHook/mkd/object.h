#pragma once
#include "core.h"
#include "plr_info.h"

typedef struct {
	char pad[84];
	int flags;
	char _pad[88];
	CVector scale;

}bone_data;

int mk_insert(int obj, int unk);
int insert_fgnd_mkobj(int obj);
void destroy_mkobj(int obj);
void update_mkobj(int obj);
void obj_set_ang_vel(int obj, int vel);

void get_matrix_right(int obj, CVector* mat);
void get_matrix_forward(int obj, CVector* mat);
void get_bone_pos(int obj, int id, CVector* pos);

void scale_bone(int object, int id, float scale);

int get_id_from_object(int obj);
void obj_set_color_for_all_materials(int obj, char* color);

int load_weapon(int a1, int obj);
int load_weapon_reflection(int a1, int obj);
void load_moveset_weapons(moveset* mv, int obj);

void obj_create_sobjs(int obj);
int obj_first_sobj(int obj);
void sobj_set_priority(int obj, int value);
int obj_sever_limb(int obj, int boneID, int unk, int unk2);

void plyr_obj_item_grab(int data, int a2, int a3, int model, int f1, int f2, int f3, int f4, int unk);
void plyr_weapon_grab(int data, int obj);
void plyr_weapon_show(int data, int unk, int entry);
void plyr_weapon_hide(int data, int unk, int entry);