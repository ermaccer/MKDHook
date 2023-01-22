#include "object.h"


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
