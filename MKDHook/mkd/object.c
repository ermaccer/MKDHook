#include "object.h"


int mk_insert(int obj, int unk)
{
	return 	((int(*)(int, int))0x12E2B0)(obj, unk);
}

int insert_fgnd_mkobj(int obj)
{
	return 	((int(*)(int))0x13D3E0)(obj);
}

void get_matrix_right(int obj, CVector* mat)
{
	mat->x = *(float*)(*(int*)(obj + 36) + 0);
	mat->y = *(float*)(*(int*)(obj + 36) + 4);
	mat->z = *(float*)(*(int*)(obj + 36) + 8);
}

void get_matrix_forward(int obj, CVector* mat)
{
	mat->x = *(float*)(*(int*)(obj + 36) + 32 + 0);
	mat->y = *(float*)(*(int*)(obj + 36) + 32 + 4);
	mat->z = *(float*)(*(int*)(obj + 36) + 32 + 8);
}

void get_bone_pos(int obj, int id, CVector* pos)
{
	((void(*)(int, int, CVector*))0x1388F0)(obj, id, pos);
}

void scale_bone(int object, int id, float scale)
{
	int skeleton = *(int*)(object + 72);

	int bone_ptr = *(int*)(skeleton + (4 * id));
	bone_data* bone = (bone_data*)(bone_ptr);

	if (bone)
	{
		bone->flags |= 0x400;
		bone->scale.x = scale;
		bone->scale.y = scale;
		bone->scale.z = scale;
	}
}


int get_id_from_object(int obj)
{
	player_info plr1 = *(player_info*)PLAYER1_INFO;
	player_info plr2 = *(player_info*)PLAYER2_INFO;

	int p1_obj = plr1.pObject;
	int p2_obj = plr2.pObject;

	if (obj == p1_obj)
		return 0;

	if (obj == p2_obj)
		return 1;

	return -1;
}

void obj_set_color_for_all_materials(int obj, char* color)
{
	((void(*)(int, char*))0x18AD10)(obj, color);
}

int load_weapon(int a1, int obj)
{
	return 	((int(*)(int, int))0x229960)(a1, obj);
}
