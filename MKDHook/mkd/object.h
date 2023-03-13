#pragma once
#include "core.h"

typedef struct {
	char pad[84];
	int flags;
	char _pad[88];
	CVector scale;

}bone_data;

int mk_insert(int obj, int unk);
int insert_fgnd_mkobj(int obj);

void get_matrix_right(int obj, CVector* mat);
void get_matrix_forward(int obj, CVector* mat);
void get_bone_pos(int obj, int id, CVector* pos);

void scale_bone(int object, int id, float scale);

int get_id_from_object(int obj);
void obj_set_color_for_all_materials(int obj, char* color);

int load_weapon(int a1, int obj);