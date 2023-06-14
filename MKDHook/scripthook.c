#include "scripthook.h"
#include "mkdeception.h"
#include <stdio.h>
#include "ps2mem.h"
#include "mips.h"
#include "sound.h"
#include "characters/character_list.h"
#include "types.h"

int script_function_table[TOTAL_COMMANDS] = { 0 };
int debugVar[2] = { 0 };
int cached_aux_weapon[2] = { 0 };

void init_script_hook()
{
	int val = (int)&script_function_table;
	debugVar[0] = 7233;
	debugVar[1] = 3;
	cached_aux_weapon[0] = 0;
	cached_aux_weapon[1] = 0;

	init_script_function_table();

	patchInt(0x21B5E0, 0x24030834);
	patchInt(0x21B5A0, lui(a2, HIWORD(val)));
	patchInt(0x21B5AC, ori(a2, a2, LOWORD(val)));

	makeJal(0x1FB948, fix_kitana_fan_lift);
	makeJal(0x268D74, mku_kitana_curl_pos_fix);
	makeJal(0x268954, mku_kitana_sfx_fix);
	makeJal(0x134B5C, cache_loaded_aux_weapon);

}

void init_script_function_table()
{
	for (int i = 0; i < TOTAL_COMMANDS; i++)
		script_function_table[i] = (int)&_null;


	int script_addr4 = 0x502E70;
	for (int i = 0; i < ORIGINAL_COMMANDS_NUM; i++)
	{
		int func = *(int*)(script_addr4 + (sizeof(int) * i));
		script_function_table[i] = func;
	}

	init_script_custom_function_table();
}

void init_script_custom_function_table()
{
	// fixes

	script_function_table[1470] = (int)&pfxhandle_spawn_at_bid_next_aux_fix;
	script_function_table[1473] = (int)&pfxhandle_spawn_at_bid_next_bind_render_aux_fix;
	script_function_table[1488] = (int)&fat_sz_start_iceblock;

	// gc

	script_function_table[gc_get_taunts_performed] = (int)&get_taunts_performed;
	script_function_table[gc_increment_taunts_performed] = (int)&increment_taunts_performed;

	script_function_table[gc_start_goro_arms_fixup] = (int)&start_goro_arms_fixup;
	script_function_table[gc_set_flipped_bones] = (int)&set_goro_flipped_bones;

	script_function_table[reset_fake_bone_matcher] = (int)&_reset_fake_bone_matcher;

	// mku

	script_function_table[mku_kitana_pfx] = (int)&mku_kitana_curl_fx;
	script_function_table[mku_kitana_pfx_destroy] = (int)&_null;
	script_function_table[mku_kitana_kod_stretcher] = (int)&_kitana_kod_stretcher;
	script_function_table[mku_frost_start_iceblock] = (int)&fat_frost_start_iceblock;
	script_function_table[mku_frost_start_icechunks] = (int)&fat_frost_start_icechunks;
	script_function_table[mku_jax_grab_weapon] = (int)&_jax_grab_aux_weapon;
	script_function_table[mku_jax_pfx] = (int)&_jax_do_ground_blast;
	script_function_table[mku_start_blaze_flaming_limbs] = (int)&_start_blaze_flaming_limbs;
	script_function_table[mku_reset_blaze_flaming_limbs] = (int)&_reset_blaze_flaming_limbs;

	// umkd
	script_function_table[jax_taunt] = (int)&_jax_taunt;
	script_function_table[freeze_victim] = (int)&_freeze_victim;
	script_function_table[force_fatality_end] = (int)&_force_fatality_end;
}

#ifndef PS2_BUILD
void dump_script_table()
{
	int script_addr4 = 0x502E70;

	char msgBuffer[1256];
	for (int i = 0; i < ORIGINAL_COMMANDS_NUM; i++)
	{
		int func = *(int*)(script_addr4 + (sizeof(int) * i));
		sprintf(msgBuffer, "script_function_table[%d] = 0x%X;\n", i, func);
		_printf(msgBuffer);
	}
}
#endif

void _null()
{

}

void umkd_sonya_runtime()
{
	blend_to_ani(403, 3, 0.2f);
	sleep(5000);
}

void _kitana_kod_stretcher()
{
	int args = *(int*)(CURRENT_ARGS);
	kitana_kod_stretcher(*(int*)(args + 4), *(float*)(args + 8));
}

void _jax_grab_aux_weapon()
{
	int args = *(int*)(CURRENT_ARGS);
	int result = jax_grab_aux_weapon(*(int*)(args + 4), *(int*)(args + 8));
	int* ac = (int*)ACTIVE_SCRIPT;
	ac[11] = result;
}

void _jax_do_ground_blast()
{
	jax_start_blast();
}

void _jax_taunt()
{
	random_jax_taunt();
}

void _start_blaze_flaming_limbs()
{
	int args = *(int*)(CURRENT_ARGS);
	start_blaze_flaming_limbs(*(int*)(args + 4));
}

void _reset_blaze_flaming_limbs()
{
	int args = *(int*)(CURRENT_ARGS);
	reset_blaze_flaming_limbs(*(int*)(args + 4));
}

void _freeze_victim()
{
	swap_active_proc();
	freeze_player();
	snd_req(SOUND_FROST_FREEZE);
	swap_active_proc();
}

void _force_fatality_end()
{
	patchInt(0x5D6500, 1);
}

void _reset_fake_bone_matcher()
{
	int args = *(int*)(CURRENT_ARGS);
	psp_reset_fake_bone_matcher(*(int*)(args + 4),
		*(int*)(args + 8),
		*(int*)(args + 12),
		*(int*)(args + 16),
		*(int*)(args + 20),
		*(int*)(args + 24),
		*(float*)(args + 28)
		);
}

void mku_kitana_curl_fx()
{
	//asm volatile ("jal 0x22E870");
	((void(*)())0x22E870)();
}

void mku_kitana_curl_pos_fix(int obj, int id, CVector* pos)
{
	int plrID = get_id_from_object(obj);
	int charID = get_character_id(plrID);

	if (charID >= 0)
	{
		if (charID == SINDEL)
		{
			id = 16;

			patchFloat(0x5D50AC, 5.0f);
			patchFloat(0x5D50A8, 8.0f);
		}
		else if (charID == KITANA)
		{
			id = 26;
			if (am_i_flipped_direct(obj))
				id = 27;

			patchFloat(0x5D50AC, 3.45f);
			patchFloat(0x5D50A8, 4.0f);
		}
	}

	get_bone_pos(obj, id, pos);
}

int mku_kitana_sfx_fix(int id)
{
	player_data* plyr_data = *(player_data**)(PLAYER_DATA);
	int chr = plyr_data->characterID;

	if (id == 754)
	{
		if (chr == KITANA)
			id = SOUND_KITANA_FANLIFT;
	}
	return snd_req(id);
}

void psp_reset_fake_bone_matcher(int obj, int a2, int a3, int a4, int a5, int a6, float flt)
{
	int v7; 
	int v8; 
	int v10; 
	bool v11; 
	int v12; 
	int v13; 
	int v14; 
	int v15; 
	int v16; 

	v7 = *(int*)(obj + 16);
	v8 = 0;
	if (v7)
	{
		v8 = 0;
		if (*(int*)(v7 + 4) == *(int*)(obj + 20))
			v8 = *(int*)(obj + 16);
	}
	v10 = v8;
	v11 = v8 == 0;
	v12 = a6;
	if (!v11 && a6)
	{
		*(float*)(obj + 76) = flt;
		*(float*)(obj + 80) = flt;
		*(int*)(obj + 24) = a6;
		*(int*)(obj + 28) = *(int*)(a6 + 4);
		if (a2)
		{
			*(int*)(obj + 40) = *(int*)a2;
			v13 = *(int*)(obj + 32);
			*(int*)(obj + 44) = *(int*)(a2 + 4);
			*(int*)(obj + 48) = *(int*)(a2 + 8);
			*(int*)(obj + 32) = v13 | 1;
		}
		if (a3)
		{
			*(int*)(obj + 52) = *(int*)a3;
			v14 = *(int*)(obj + 32);
			*(int*)(obj + 56) = *(int*)(a3 + 4);
			*(int*)(obj + 60) = *(int*)(a3 + 8);
			*(int*)(obj + 32) = v14 | 2;
		}
		if (a4)
		{
			*(int*)(obj + 64) = *(int*)a4;
			v15 = *(int*)(obj + 32);
			*(int*)(obj + 68) = *(int*)(a4 + 4);
			*(int*)(obj + 72) = *(int*)(a4 + 8);
			*(int*)(obj + 32) = v15 | 4;
		}
		*(int*)(obj + 36) = a5;
		v16 = *(int*)(v12 + 72);
		if (*(int*)(v16 + 4 * a5))
		{
			*(int*)(*(int*)(v16 + 4 * a5) + 84) |= 8u;
			if (flt != 0.0)
			{
				*(float*)(obj + 76) = flt;
				*(float*)(obj + 80) = flt;
				*(int*)(obj + 84) = *(int*)(*(int*)(v10 + 36) + 48);
				*(int*)(obj + 88) = *(int*)(*(int*)(v10 + 36) + 52);
				*(int*)(obj + 92) = *(int*)(*(int*)(v10 + 36) + 56);
			}
		}
	}
}


void fix_kitana_fan_lift(int id, int a2, float a3)
{
	// mku kitana fan lift hack
	// fixes a bug where fan lift hits like 10-50 times
	// doesnt xfer if the lifted flag is set
	// also an issue in real mku
	player_data* plyr_data = *(player_data**)(PLAYER_DATA);

	if (plyr_data)
	{
		int chrID_p1 = plyr_data->characterID;
		if (chrID_p1 == KITANA)
		{
			int p2_pdata = *(int*)(P2_PLAYER_DATA);
			int flags = *(int*)(p2_pdata + 532);

			if (id == 318)
			{
				int his_obj = *(int*)PLAYER2_OBJ;
				int chrID = get_character_id(get_id_from_object(his_obj));

				if (chrID == ONAGA)
					return;

				if (flags & 0x4000)
					return;
			}
		}


	}

	reaction_xfer_him(id, a2, a3);
	if (plyr_data)
	{
		int chrID_p1 = plyr_data->characterID;
		if (chrID_p1 == KITANA)
		{
			int p2_pdata = *(int*)(P2_PLAYER_DATA);
			int flags = *(int*)(p2_pdata + 532);

			if (id == 318 && !(flags & 0x4000))
				kitana_fanlift_voice();
		}
	}

}


int cache_loaded_aux_weapon(int a1, int obj)
{
	// fix for gun fire
	// seems its impossible to access aux weapon object in mkd ps2
	// so aux objs are cached for both players
	// and then swapped for jax during FX call to make gun work
	

	int wep = load_weapon(a1, obj);

	int id = get_id_from_object(obj);
	int chrID = get_character_id(id);

	if (chrID == JAX)
		cached_aux_weapon[id] = wep;



	return wep;
}

void pfxhandle_spawn_at_bid_next_aux_fix()
{
	int plyr_obj = *(int*)PLAYER_OBJ;
	int id = get_id_from_object(plyr_obj);
	int chrID = get_character_id(id);

	int args = *(int*)(CURRENT_ARGS);
	int arg2 = *(int*)(args + 8);

	if (chrID == JAX)
	{
		// if a2 isnt player, it must be aux obj 
		if (arg2 != plyr_obj)
		{
			*(int*)(args + 8) = cached_aux_weapon[id];
		}
	}



	((void(*)())0x22EAF0)();

}

void pfxhandle_spawn_at_bid_next_bind_render_aux_fix()
{
	int plyr_obj = *(int*)PLAYER_OBJ;
	int id = get_id_from_object(plyr_obj);
	int chrID = get_character_id(id);

	int args = *(int*)(CURRENT_ARGS);
	int arg2 = *(int*)(args + 8);

	if (chrID == JAX)
	{
		// if a2 isnt player, it must be aux obj 
		if (arg2 != plyr_obj)
		{
			*(int*)(args + 8) = cached_aux_weapon[id];
		}
	}


	((void(*)())0x22EA40)();
}