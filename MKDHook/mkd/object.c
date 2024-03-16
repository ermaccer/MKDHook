#include "object.h"


int get_new_mkobj(int frameID)
{
	return 	((int(*)(int, int))0x13D1C0)(frameID, 0);
}

int check_item_obj(int obj)
{
	int ptr = 0;
	if (obj)
	{
		ptr = *(int*)(obj);
		if (ptr)
		{
			if (*(int*)(ptr + 4) != *(int*)(obj + 4))
				ptr = 0;
		}
		else
			ptr = 0;
	}

	return ptr;
}

int mk_insert(int obj, int unk)
{
	return 	((int(*)(int, int))0x12E2B0)(obj, unk);
}

int insert_fgnd_mkobj(int obj)
{
	return 	((int(*)(int))0x13D3E0)(obj);
}

int insert_particle_mkobj(int obj)
{
	return 	((int(*)(int))0x13D3C0)(obj);
}

void destroy_mkobj(int obj)
{
	((int(*)(int))0x13B130)(obj);
}

void update_mkobj(int obj)
{
	((int(*)(int))0x13A9D0)(obj);
}

void obj_set_pos(int obj, CVector* pos)
{
	((int(*)(int, CVector*))0x1363F0)(obj, pos);
}

void obj_set_ang_vel(int obj, int vel)
{
	((int(*)(int, int))0x1362F0)(obj, vel);
}

void obj_set_pos_vel(int obj, CVector* vel)
{
	((int(*)(int, CVector*))0x136350)(obj, vel);
}

void obj_set_gravity(int obj, float val)
{
	*(int*)(obj + 8) = *(int*)(obj + 8) & 0xFFFFFF7F | 0x80;
	*(float*)(obj + 48) = val;
}

void set_obj_flag(int obj, int flag, int status)
{
	int newFlag = 0;
	if (status)
		newFlag = *(int*)(obj + 8) | (1 << flag);
	else
		newFlag = *(int*)(obj + 8) & ~(1 << flag);
	*(int*)(obj + 8) = newFlag;
}

void obj_set_bone_collapse_flag(int obj, int id)
{
	((int(*)(int, int))0x1384D0)(obj, id);
}

void obj_clear_bone_collapse_flag(int obj, int id)
{
	((int(*)(int, int))0x138490)(obj, id);
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

void collapse_bone(int object, int id, int status)
{
	int numBones = *(int*)(object + 76);
	int skeleton = *(int*)(object + 72);

	if (id > numBones)
		return;

	if (status)
		obj_set_bone_collapse_flag(object, id);
	else
		obj_clear_bone_collapse_flag(object, id);
}

bone_data* get_bone(int object, int id)
{
	if (!object)
		return 0;
	int skeleton = *(int*)(object + 72);
	
	if (!skeleton)
		return 0;

	int bone_ptr = *(int*)(skeleton + (4 * id));
	
	if (!bone_ptr)
		return 0;

	bone_data* bone = (bone_data*)(bone_ptr);

	return bone;
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

void quat_to_matrix(int matrix, int quat)
{
	((void(*)(int, int))0x160070)(matrix, quat);
}

void vector_to_matrix(CVector* vector, int matrix)
{
	((void(*)(CVector*, int))0x1603F0)(vector, matrix);
}

void matrix_mult_matrix(int dst, int src, int mult)
{
	((void(*)(int, int, int))0x15F8A0)(dst, src, mult);
}

void matrix_to_quat(int matrix, int quat)
{
	((void(*)(int, int))0x160180)(quat, matrix);
}
