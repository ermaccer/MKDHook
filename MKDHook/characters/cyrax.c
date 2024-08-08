#include "cyrax.h"
#include "..\mkd\object.h"
#include "..\scripthook.h"

int cyrax_emitter_fx_handle[2] = {};
int cyrax_cutter_status[2] = {};
int cyrax_bomb_emitter[2] = {};
int cyrax_last_bomb_player = 0;
// bombs
struct scan_action_dual scan_cyrax_1 = {
	17046,
	0x300001E,
	16,
	MOVE_BACKWARDS,
	MOVE_FORWARD,

	17046,
	0x300001E,
	29,
	MOVE_FORWARD,
	MOVE_BACKWARDS,

	-1,
};



// spinkick
struct scan_action scan_cyrax_3 = {
	16949,
	0x3000019,
	23,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

// cutter
struct scan_action scan_cyrax_4 = {
	4629,
	0x300001E,
	8,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};


struct mk_file_entry cyrax_entry_table[CYRAX_FILES] = {
	{"cyrax.ssf"	,0, 4},

	{"cyrax.sec",0, 1},
	{"cyrax_ap.sec",0, 1},
	{"cyrax.mko",0, 3},
	{"sh_cyrax.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"cyrax_fx.mko",0,3},
	{"ninjitsu.mko",0, 3},
	{"style_ninjitsu.sec",0,1},
	{"sambo.mko",0, 3},
	{"style_sambo.sec",0,1},
	{"pulseblade.mko",0, 3},
	{"style_pulseblade.sec",0,1},
	{"cyrax_anims.sec",0, 2},
	{"ninjitsu_anims.sec",0, 2},
	{"sambo_anims.sec",0, 2},
	{"pulseblade_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

struct mk_file_entry cyrax_alt_entry_table[CYRAX_FILES] = {
	{"cyrax_alt.ssf"	,0, 4},

	{"cyrax_alt.sec",0, 1},
	{"cyrax_alt_ap.sec",0, 1},
	{"cyrax.mko",0, 3},
	{"sh_cyrax.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"cyrax_fx.mko",0,3},
	{"ninjitsu.mko",0, 3},
	{"style_ninjitsu.sec",0,1},
	{"sambo.mko",0, 3},
	{"style_sambo.sec",0,1},
	{"pulseblade.mko",0, 3},
	{"style_pulseblade.sec",0,1},
	{"cyrax_alt_anims.sec",0, 2},
	{"ninjitsu_anims.sec",0, 2},
	{"sambo_anims.sec",0, 2},
	{"pulseblade_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};


// I:\ps2dvd\art\cyrax.ssf
struct mk_toc_entry cyrax_file_table[CYRAX_FILES + 1] = {
		{&cyrax_entry_table[0]	,0,0 },

		{&cyrax_entry_table[1]		,0,		531072 },	// cyrax.sec             
		{&cyrax_entry_table[2]		,0,		531072 },	// cyrax_ap.sec        
		{&cyrax_entry_table[3]		,0,		21920  },	// cyrax.mko   
		{&cyrax_entry_table[4]		,0,		392320 },	// sh_cyrax.sec           
		{&cyrax_entry_table[5]		,0,		10164  },	// fight_fx.mko         
		{&cyrax_entry_table[6]		,0,		21368  },	// blood_fx.mko         
		{&cyrax_entry_table[7]		,0,		14112  },	// cyrax_fx.mko          
		{&cyrax_entry_table[8] 		,0,		13120  },	// ninjitsu.mko         
		{&cyrax_entry_table[9]		,0,		10112  },	// style_ninjitsu.sec   
		{&cyrax_entry_table[10]		,0,		7040   },	// sambo.mko        
		{&cyrax_entry_table[11]		,0,		10112  },	// style_sambo.sec  
		{&cyrax_entry_table[12]		,0,		11872  },	// pulseblade.mko        
		{&cyrax_entry_table[13]		,0,		10112  },	// style_pulseblade.sec  
		{&cyrax_entry_table[14]		,0,		68224  },	// cyrax_anims.sec       
		{&cyrax_entry_table[15]		,0,		161536 },	// ninjitsu_anims.sec   
		{&cyrax_entry_table[16]		,0,		197376 },	// sambo_anims.sec  
		{&cyrax_entry_table[17]		,0,		219648 },	// pulseblade_anims.sec  
		{&cyrax_entry_table[18]		,0,		53120  },	// pz_noob_anims.sec

		{0,0,0}
};

// I:\ps2dvd\art\cyrax_alt.ssf
struct mk_toc_entry cyrax_alt_file_table[CYRAX_FILES + 1] = {
		{&cyrax_alt_entry_table[0]	,0,0 },

		{&cyrax_alt_entry_table[1]		,0,		582528 },	// cyrax_alt.sec             
		{&cyrax_alt_entry_table[2]		,0,		582528 },	// cyrax_alt_ap.sec        
		{&cyrax_alt_entry_table[3]		,0,		21920  },	// cyrax.mko   
		{&cyrax_alt_entry_table[4]		,0,		390016 },	// sh_cyrax.sec           
		{&cyrax_alt_entry_table[5]		,0,		10164  },	// fight_fx.mko         
		{&cyrax_alt_entry_table[6]		,0,		21368  },	// blood_fx.mko         
		{&cyrax_alt_entry_table[7]		,0,		14112  },	// cyrax_fx.mko          
		{&cyrax_alt_entry_table[8] 		,0,		13120  },	// ninjitsu.mko         
		{&cyrax_alt_entry_table[9]		,0,		10112  },	// style_ninjitsu.sec   
		{&cyrax_alt_entry_table[10]		,0,		7040   },	// sambo.mko        
		{&cyrax_alt_entry_table[11]		,0,		10112  },	// style_sambo.sec  
		{&cyrax_alt_entry_table[12]		,0,		11872  },	// pulseblade.mko        
		{&cyrax_alt_entry_table[13]		,0,		10112  },	// style_pulseblade.sec  
		{&cyrax_alt_entry_table[14]		,0,		68224  },	// cyrax_alt_anims.sec       
		{&cyrax_alt_entry_table[15]		,0,		161536 },	// ninjitsu_anims.sec   
		{&cyrax_alt_entry_table[16]		,0,		197376 },	// sambo_anims.sec  
		{&cyrax_alt_entry_table[17]		,0,		219648 },	// pulseblade_anims.sec  
		{&cyrax_alt_entry_table[18]		,0,		53120  },	// pz_noob_anims.sec

		{0,0,0}
};



void init_cyrax_toc()
{
	cyrax_emitter_fx_handle[0] = 0;
	cyrax_emitter_fx_handle[1] = 0;
	cyrax_cutter_status[0] = 0;
	cyrax_cutter_status[1] = 0;
	cyrax_bomb_emitter[0] = 0;
	cyrax_bomb_emitter[1] = 0;
	cyrax_last_bomb_player = 0;

	int baseSize = 2048;
	for (int i = 0; i < CYRAX_FILES; i++)
	{
		cyrax_entry_table[i].belong = &cyrax_file_table[0];
	}


	for (int i = 1; i < CYRAX_FILES; i++)
	{
		cyrax_file_table[i].previousSize = baseSize;
		baseSize += (cyrax_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;

	for (int i = 0; i < CYRAX_FILES; i++)
	{
		cyrax_alt_entry_table[i].belong = &cyrax_alt_file_table[0];
	}


	for (int i = 1; i < CYRAX_FILES; i++)
	{
		cyrax_alt_file_table[i].previousSize = baseSize;
		baseSize += (cyrax_alt_file_table[i].size + 2048 - 1) & -2048;
	}

}

void start_cyrax_bomb(int plrID)
{
	cyrax_last_bomb_player = plrID;
	if (!cyrax_bomb_emitter[plrID])
		cyrax_bomb_emitter[plrID] = get_new_mkobj(33577);

	fx_handle explosion = fx_by_owner("sparkhit", plrID + 1);
	fx_reset(explosion);
	cyrax_emitter_fx_handle[plrID] = explosion;
}

void cyrax_ground_projectile_override_safe(int data)
{
	int projectile_proc_data = *(int*)0x5D724C;
	int projectile_reaction_id = *(int*)(projectile_proc_data + 68);
	if (projectile_reaction_id == CYRAX_BOMB_REACTION_ID)
	{
		cyrax_bomb_process_explosion();
	}


	((void(*)(int))0x3D04C0)(data);
}

void cyrax_bomb_process_explosion()
{
	snd_req(CYRAX_BOMB_SOUND_ID);
	fx_pause_emit(fx_by_owner("sparkhit", cyrax_last_bomb_player + 1));
	resume_effect_at_obj_bid(cyrax_bomb_emitter[cyrax_last_bomb_player], 0, cyrax_emitter_fx_handle[cyrax_last_bomb_player], 1, 0);
}

void cyrax_adjust_bomb_position_hack(int data)
{
	int projectile_proc_data = *(int*)0x5D724C;
	int projectile_reaction_id = *(int*)(projectile_proc_data + 68);

	if (projectile_reaction_id == CYRAX_BOMB_REACTION_ID)
	{
		int projectile_obj = *(int*)(projectile_proc_data + 40);
		*(float*)(projectile_obj + 164) += 0.2125f;

		int emitter = cyrax_bomb_emitter[cyrax_last_bomb_player];
		if (emitter)
		{
			CVector pos = { *(float*)(projectile_obj + 160), *(float*)(projectile_obj + 164), *(float*)(projectile_obj + 168) };
			obj_set_pos(emitter, &pos);
			update_mkobj(emitter);
		}
		cyrax_bomb_play_hit_sound();

	}
	((void(*)(int))0x3D0C30)(data);
}

void cyrax_update_cutter(int plrID, int object)
{
	cyrax_cutter_update_status(plrID, object);
	cyrax_cutter_rotate(plrID, object);
}

void cyrax_cutter_update_status(int plrID, int object)
{
	if (!object)
		return;

	int aux_weapon = cached_aux_weapon[plrID];
	if (!aux_weapon)
		return;

	int status = cyrax_cutter_status[plrID];

	switch (status)
	{
	case CYRAX_CUTTER_STATUS_HIDE:
		cyrax_cutter_hide(plrID, aux_weapon);
		break;
	case CYRAX_CUTTER_STATUS_START:
		cyrax_cutter_start(plrID, aux_weapon);
		break;
	case CYRAX_CUTTER_STATUS_END:
		cyrax_cutter_end(plrID, aux_weapon);
		break;
	default:
		break;
	}

	
}

void cyrax_cutter_rotate(int plrID, int object)
{
	if (!object)
		return;

	int aux_weapon = cached_aux_weapon[plrID];
	if (!aux_weapon)
		return;

	bone_data* cutter_blade = get_bone(aux_weapon, CYRAX_CUTTER_BLADE_BONE_ID);

	// clean up required for aux weapon bone
	cutter_blade->flags = 0x400;

	char mat[64] = {};
	char newMat[64] = {};

	quat_to_matrix((int)&mat, (int)&cutter_blade->rotation);

	float value = randu(CYRAX_CUTTER_BLADE_SPEED) / 100.0f;

	CVector rotationAngle = {};

	rotationAngle.x = value;

	vector_to_matrix(&rotationAngle, (int)&newMat);
	matrix_mult_matrix((int)&mat, (int)&mat, (int)&newMat);
	matrix_to_quat((int)&mat, (int)&cutter_blade->rotation);
}


void cyrax_set_cutter_status(int plrID, int status)
{
	cyrax_cutter_status[plrID] = status;
}

void cyrax_cutter_hide(int plrID, int obj)
{
	aux_weapon_set_hidden(plrID, 1);

	*(char*)(obj + 8) = *(char*)(obj + 8) & 0xFFFFFFBF | 0x40;

	
	*(float*)(obj + 240) = 0.0f;
	*(float*)(obj + 244) = 0.0f;
	*(float*)(obj + 248) = 0.0f;
	
}

void cyrax_cutter_start(int plrID, int obj)
{
	aux_weapon_set_hidden(plrID, 0);

	float curScale = *(float*)(obj + 240);
	if (curScale <= 1.0f)
	{
		curScale += CYRAX_CUTTER_SCALE_SPEED;
	}

	if (curScale > 1.0f)
		curScale = 1.0f;

	*(float*)(obj + 240) = curScale;
	*(float*)(obj + 244) = curScale;
	*(float*)(obj + 248) = curScale;
}

void cyrax_cutter_end(int plrID, int obj)
{
	float curScale = *(float*)(obj + 240);
	if (curScale > 0.0f)
	{
		curScale -= CYRAX_CUTTER_SCALE_SPEED;
	}
	*(float*)(obj + 240) = curScale;
	*(float*)(obj + 244) = curScale;
	*(float*)(obj + 248) = curScale;

	if (curScale <= 0.0)
	{
		*(float*)(obj + 240) = 0.0f;
		*(float*)(obj + 244) = 0.0f;
		*(float*)(obj + 248) = 0.0f;

		cyrax_cutter_status[plrID] = CYRAX_CUTTER_STATUS_HIDE;
	}
}

int cyrax_bomb_check_hack_safe(int status)
{
	int projectile_proc_data = *(int*)0x5D724C;
	int projectile_reaction_id = *(int*)(projectile_proc_data + 68);

	if (projectile_reaction_id == CYRAX_BOMB_REACTION_ID)
	{
		float projectile_alive_time = *(float*)(projectile_proc_data + 48);

		int progress = (int)projectile_alive_time;
		if (progress <= CYRAX_BOMB_EXPLODE_TIME && status)
		{
			cyrax_bomb_process_explosion();
			return status;
		}
		else
			return 0;
	}

	return 	status;
}

void cyrax_bomb_play_hit_sound()
{
	static int bomb_sounds[3] = {
		7591, 7592, 7593
	};

	int val = randu(3);

	snd_req(bomb_sounds[val]);
}

void cyrax_reset_event()
{
	cyrax_bomb_emitter[0] = 0;
	cyrax_bomb_emitter[1] = 0;
	cyrax_last_bomb_player = 0;
}
