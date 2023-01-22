#pragma once
#define CURRENT_ARGS 0x5D6C3C
void snd_req(int id);

// script funcs

void push_arg(int id, int data);
void push_argf(int id, float data);
void call_script_function(int id);

void sleep(int time);
void blend_to_ani(int anim, int unk, float unk2);