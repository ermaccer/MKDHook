#pragma once
#include "character.h"
#define ORIGINAL_COMMANDS_NUM 1699

enum ECommands {
	// U PORTS
	mku_jax_pfx = 1721,
	mku_kitana_pfx,
	mku_kitana_pfx_destroy,
	// new commands
	_umkd_sonya_runtime = 2000,
	TOTAL_COMMANDS = 2100
};

extern int script_function_table[TOTAL_COMMANDS];
extern int debugVar[2];

void init_script_hook();
void init_script_function_table();
void init_script_custom_function_table();
void dump_script_table();


// new funcs
void _null();
void umkd_sonya_runtime();
void mku_kitana_curl_fx();


// hooks

void fix_kitana_fan_lift(int id, int a2, float a3);