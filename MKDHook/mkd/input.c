#include "input.h"

int check_switch(int player, int button)
{
	return ((int(*)(int, int))0x16ACE0)(player, button);
}

void get_stick_pos(int player, int stick, float* x, float* y)
{
	((void(*)(int, int, float*, float*))0x16A8B0)(player, stick, x, y);
}

int my_joypad_state_5()
{
	return ((int(*)())0x1F8390)();
}
