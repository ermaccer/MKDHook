#pragma once
#define ORIGINAL_COMMANDS_NUM 1699

enum ECommands {
	// U PORTS
	mku_jax_pfx = 1721,
	// new commands
	_umkd_sonya_runtime = 2000,
	TOTAL_COMMANDS = 2100
};

extern int script_function_table[TOTAL_COMMANDS];

void init_script_hook();
void init_script_function_table();
void init_script_custom_function_table();
void dump_script_table();


// new funcs

void umkd_sonya_runtime();
