#include "camera.h"

void set_cam_position(CVector* pos)
{
	((void(*)(CVector*))0x186FA0)(pos);
}

void set_cam_rotation(CVector* rot)
{
	((void(*)(CVector*))0x186F50)(rot);
}

void set_cam_target(CVector* target)
{
	((void(*)(CVector*))0x186C90)(target);
}

void cam_recalc_midpoint()
{
	((void(*)())0x1833C0)();
}
