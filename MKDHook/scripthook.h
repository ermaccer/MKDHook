#pragma once
#include "character.h"
#include "build_config.h"
#include "mkdeception.h"

#define ORIGINAL_COMMANDS_NUM 1699



enum ECommands {
	// U PORTS
	mku_kitana_kod_stretcher = 1717,
	mku_frost_start_iceblock = 1718,
	mku_frost_start_icechunks = 1719,
	mku_jax_grab_weapon = 1720,
	mku_jax_pfx = 1721,
	mku_kitana_pfx,
	mku_kitana_pfx_destroy,
	mku_unknown_1724,
	mku_start_blaze_flaming_limbs = 1725,
	mku_reset_blaze_flaming_limbs = 1726,
	// gc commands
	gc_get_taunts_performed = 1900,
	gc_increment_taunts_performed = 1901,
	gc_set_flipped_bones = 1902,
	gc_start_goro_arms_fixup = 1903,
	reset_fake_bone_matcher = 1904,
	// new commands
	_umkd_sonya_runtime = 2000,
	jax_taunt = 2001,
	freeze_victim = 2002,
	force_fatality_end = 2003,

	TOTAL_COMMANDS = 2100
};

extern int script_function_table[TOTAL_COMMANDS];
extern int debugVar[2];
extern int cached_aux_weapon[2];

void init_script_hook();
void init_script_function_table();
void init_script_custom_function_table();
#ifndef PS2_BUILD
void dump_script_table();
#endif // !PS2_BUILD




// new funcs
void _null();
void umkd_sonya_runtime();
void _kitana_kod_stretcher();
void _jax_grab_aux_weapon();
void _jax_do_ground_blast();
void _jax_taunt();
void _start_blaze_flaming_limbs();
void _reset_blaze_flaming_limbs();
void _freeze_victim();
void _force_fatality_end();
void _reset_fake_bone_matcher();
void mku_kitana_curl_fx();
void mku_kitana_curl_pos_fix(int obj, int id, CVector* pos);
int mku_kitana_sfx_fix(int id);


void psp_reset_fake_bone_matcher(int obj, int a2, int a3, int a4, int a5, int a6, float flt);


// hooks

void fix_kitana_fan_lift(int id, int a2, float a3);
int cache_loaded_aux_weapon(int a1, int obj);
void pfxhandle_spawn_at_bid_next_aux_fix();
void pfxhandle_spawn_at_bid_next_bind_render_aux_fix();
