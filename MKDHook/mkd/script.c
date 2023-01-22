#include "script.h"
#include "..\scripthook.h"
void snd_req(int id)
{
	((void(*)(int))0x12B2B0)(id);
}

void push_arg(int id, int data)
{
	int* arg = (int*)CURRENT_ARGS;
	arg[id] = data;
}

void push_argf(int id, float data)
{
	int* arg = (int*)CURRENT_ARGS;
	arg[id] = data;
}

void call_script_function(int id)
{
	((void(*)())script_function_table[id])();
}

void sleep(int time)
{
	push_arg(0, time);
	call_script_function(0);
}

void blend_to_ani(int anim, int unk, float unk2)
{
	push_arg(0, anim);
	push_arg(1, unk);
	push_argf(2, unk2);
	call_script_function(13);
}
