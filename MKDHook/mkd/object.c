#include "object.h"


int mk_insert(int obj, int unk)
{
	return 	((int(*)(int, int))0x12E2B0)(obj, unk);
}

int insert_fgnd_mkobj(int obj)
{
	return 	((int(*)(int))0x13D3E0)(obj);
}

void destroy_mkobj(int obj)
{
	((int(*)(int))0x13B130)(obj);
}

void update_mkobj(int obj)
{
	((int(*)(int))0x13A9D0)(obj);
}

void obj_set_ang_vel(int obj, int vel)
{
	((int(*)(int, int))0x1362F0)(obj, vel);
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
	player_info* plr1 = (player_info*)PLAYER1_INFO;
	player_info* plr2 = (player_info*)PLAYER2_INFO;

	int p1_obj = plr1->pObject;
	int p2_obj = plr2->pObject;

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

int load_weapon_reflection(int a1, int obj)
{
	return 	((int(*)(int, int))0x229BD0)(a1, obj);
}

void load_moveset_weapons(moveset* mv, int obj)
{
	((void(*)(moveset*, int))0x133EE0)(mv, obj);
}

void obj_create_sobjs(int obj)
{
	((void(*)(int))0x139ED0)(obj);
}

int obj_first_sobj(int obj)
{
	return 	((int(*)(int))0x139610)(obj);
}

void sobj_set_priority(int obj, int value)
{
	((void(*)(int, int))0x13D600)(obj, value);
}

int obj_sever_limb(int obj, int boneID, int unk, int unk2)
{
	return 	((int(*)(int, int, int ,int))0x13C3C0)(obj, boneID, unk, unk2);
}

void plyr_obj_item_grab(int data, int a2, int a3, int model, int f1, int f2, int f3, int f4, int unk)
{
	((void(*)(int, int, int, int, int, int, int, int, int))0x228530)(data, a2, a3, model, f1, f2, f3, f4, unk);
}

void plyr_weapon_grab(int data, int obj)
{
	((void(*)(int, int))0x228530)(data, obj);
}

void plyr_weapon_show(int data, int unk, int entry)
{
	((void(*)(int, int, int))0x228B20)(data, unk, entry);
}

void plyr_weapon_hide(int data, int unk, int entry)
{
	((void(*)(int, int, int))0x228E50)(data, unk, entry);
}
