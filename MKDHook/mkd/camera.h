#pragma once
#include "core.h"

void set_cam_position(CVector* pos);
void set_cam_rotation(CVector* rot);
void set_cam_target(CVector* target);

void cam_recalc_midpoint();