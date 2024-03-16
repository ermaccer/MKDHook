#include "shangtsung.h"
#include "..\ps2mem.h"
#include "..\mips.h"
#include "..\mkdeception.h"
#include "..\generic.h"
#include "..\scripthook.h"
#include <math.h>



int shang_emitter_particle_handle[2][SHANG_TOTAL_EMITTERS] = { 0 };
int shang_emitter_fx_handle[2][SHANG_TOTAL_FX] = { 0 };
int shang_balls_exploded[2] = { 0 };
int shang_balls_script_hit[2] = { 0 };
float shang_balls_distance[2][2] = {0};


// skull
struct scan_action scan_shang_1 = {
	17027,
	0x3000019,
	16,
	MOVE_DOWN,
	MOVE_FORWARD,
	-1,
	0,
	0
};

// balls
struct scan_action_dual scan_shang_2 = {
	0,
	0x3000019,
	21,
	MOVE_FORWARD,
	MOVE_BACKWARDS,

	0,
	0x3000019,
	22,
	MOVE_BACKWARDS,
	MOVE_FORWARD,

	-1,
};

// soul steal
struct scan_action scan_shang_3 = {
	4640,
	0x3000019,
	19,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

struct mk_file_entry shang_entry_table[SHANG_FILES] = {
	{"shangtsung.ssf"	,0, 4},

	{"shangtsung.sec",0, 1},
	{"shangtsung_ap.sec",0, 1},
	{"shangtsung.mko",0, 3},
	{"sh_shangtsung.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"shangtsung_fx.mko",0,3},
	{"snake.mko",0, 3},
	{"style_snake.sec",0,1},
	{"crane.mko",0, 3},
	{"style_crane.sec",0,1},
	{"ssword.mko",0, 3},
	{"style_ssword.sec",0,1},
	{"shangtsung_anims.sec",0, 2},
	{"fat_anims_luikang.sec",0, 2},
	{"fat_anims_heartrip.sec",0, 2},
	{"snake_anims.sec",0, 2},
	{"crane_anims.sec",0, 2},
	{"ssword_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\shangtsung.ssf
struct mk_toc_entry shang_file_table[SHANG_FILES + 1] = {
		{&shang_entry_table[0]	,0,0 },

		{&shang_entry_table[1]	,0,	   505088 },	// shangtsung.sec        
		{&shang_entry_table[2]	,0,    505600 },	// shangtsung_ap.sec     
		{&shang_entry_table[3]	,0,    40224  },	// shangtsung.mko        
		{&shang_entry_table[4]	,0,    258304 },	// sh_shangtsung.sec     
		{&shang_entry_table[5]	,0,    10164  },	// fight_fx.mko          
		{&shang_entry_table[6]	,0,    21368  },	// blood_fx.mko          
		{&shang_entry_table[7]	,0,    10720  },	// shangtsung_fx.mko     
		{&shang_entry_table[8] 	,0,	   13984  },	// snake.mko        
		{&shang_entry_table[9]	,0,    10112  },	// style_snake.sec  
		{&shang_entry_table[10]	,0,	   12672  },	// crane.mko        
		{&shang_entry_table[11]	,0,    10112  },	// style_crane.sec  
		{&shang_entry_table[12]	,0,	   11424  },	// ssword.mko                  
		{&shang_entry_table[13]	,0,	   10112  },	// style_ssword.sec        
		{&shang_entry_table[14]	,0,	   133376 },	// shangtsung_anims.sec  
		{&shang_entry_table[15]	,0,	   124032 },	// fat_anims_luikang.sec 
		{&shang_entry_table[16]	,0,	   74496  },	// fat_anims_heartrip.sec
		{&shang_entry_table[17]	,0,	   145664 },	// snake_anims.sec  
		{&shang_entry_table[18]	,0,	   165504 },	// crane_anims.sec      
		{&shang_entry_table[19]	,0,	   207744 },	// ssword_anims.sec        
		{&shang_entry_table[20]	,0,	   53120  },	// pz_noob_anims.sec     

		{0,0,0}
};

struct mk_file_entry shang_alt_entry_table[SHANG_FILES] = {
	{"shangtsung_alt.ssf"	,0, 4},

	{"shangtsung_alt.sec",0, 1},
	{"shangtsung_alt_ap.sec",0, 1},
	{"shangtsung.mko",0, 3},
	{"sh_shangtsung.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"shangtsung_fx.mko",0,3},
	{"snake.mko",0, 3},
	{"style_snake.sec",0,1},
	{"crane.mko",0, 3},
	{"style_crane.sec",0,1},
	{"ssword.mko",0, 3},
	{"style_ssword.sec",0,1},
	{"shangtsung_alt_anims.sec",0, 2},
	{"fat_anims_luikang.sec",0, 2},
	{"fat_anims_heartrip.sec",0, 2},
	{"snake_anims.sec",0, 2},
	{"crane_anims.sec",0, 2},
	{"ssword_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\shangtsung_alt.ssf
struct mk_toc_entry shang_alt_file_table[SHANG_FILES + 1] = {
		{&shang_alt_entry_table[0]	,0,0 },

		{&shang_alt_entry_table[1]	,0,	   465152 },	// shangtsung_alt.sec        
		{&shang_alt_entry_table[2]	,0,    465152 },	// shangtsung_alt_ap.sec     
		{&shang_alt_entry_table[3]	,0,    40224  },	// shangtsung.mko        
		{&shang_alt_entry_table[4]	,0,    258304 },	// sh_shangtsung.sec     
		{&shang_alt_entry_table[5]	,0,    10164  },	// fight_fx.mko          
		{&shang_alt_entry_table[6]	,0,    21368  },	// blood_fx.mko          
		{&shang_alt_entry_table[7]	,0,    10720  },	// shangtsung_fx.mko     
		{&shang_alt_entry_table[8] 	,0,	   13984  },	// snake.mko        
		{&shang_alt_entry_table[9]	,0,    10112  },	// style_snake.sec  
		{&shang_alt_entry_table[10]	,0,	   12672  },	// crane.mko        
		{&shang_alt_entry_table[11]	,0,    10112  },	// style_crane.sec  
		{&shang_alt_entry_table[12]	,0,	   11424  },	// ssword.mko                  
		{&shang_alt_entry_table[13]	,0,	   10112  },	// style_ssword.sec        
		{&shang_alt_entry_table[14]	,0,	   133504 },	// shangtsung_alt_anims.sec  
		{&shang_alt_entry_table[15]	,0,	   124032 },	// fat_anims_luikang.sec 
		{&shang_alt_entry_table[16]	,0,	   74496  },	// fat_anims_heartrip.sec
		{&shang_alt_entry_table[17]	,0,	   145664 },	// snake_anims.sec  
		{&shang_alt_entry_table[18]	,0,	   165504 },	// crane_anims.sec      
		{&shang_alt_entry_table[19]	,0,	   207744 },	// ssword_anims.sec        
		{&shang_alt_entry_table[20]	,0,	   53120  },	// pz_noob_anims.sec     

		{0,0,0}
};


void init_shang_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < SHANG_FILES; i++)
	{
		shang_entry_table[i].belong = &shang_file_table[0];
	}


	for (int i = 1; i < SHANG_FILES; i++)
	{
		shang_file_table[i].previousSize = baseSize;
		baseSize += (shang_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;

	for (int i = 0; i < SHANG_FILES; i++)
	{
		shang_alt_entry_table[i].belong = &shang_alt_file_table[0];
	}


	for (int i = 1; i < SHANG_FILES; i++)
	{
		shang_alt_file_table[i].previousSize = baseSize;
		baseSize += (shang_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}

int shangtsung_make_new_balls(int plrID)
{
	if (!shang_emitter_particle_handle[plrID][0])
		shang_emitter_particle_handle[plrID][0] = get_new_mkobj(33577);
	if (!shang_emitter_particle_handle[plrID][1])
		shang_emitter_particle_handle[plrID][1] = get_new_mkobj(33577);
	if (!shang_emitter_particle_handle[plrID][2])
		shang_emitter_particle_handle[plrID][2] = get_new_mkobj(33577);

	if (shang_emitter_particle_handle[plrID][0] && shang_emitter_particle_handle[plrID][1] && shang_emitter_particle_handle[plrID][2])
		return 1;

	return 0;
}


void shangtsung_check_for_balls(int plrID)
{
	if (!shang_emitter_particle_handle[plrID][0])
		return;

	if (!shang_emitter_particle_handle[plrID][1])
		return;

	if (!shang_emitter_particle_handle[plrID][2])
		return;

	//if (check_item_obj(shang_emitter_particle_handle[plrID][0]))
	//{
	//	destroy_mkobj(shang_emitter_particle_handle[plrID][0]);
	//	shang_emitter_particle_handle[plrID][0] = 0;
	//}
	//if (check_item_obj(shang_emitter_particle_handle[plrID][1]))
	//{
	//	destroy_mkobj(shang_emitter_particle_handle[plrID][1]);
	//	shang_emitter_particle_handle[plrID][1] = 0;
	//}
	//
	//if (check_item_obj(shang_emitter_particle_handle[plrID][2]))
	//{
	//	destroy_mkobj(shang_emitter_particle_handle[plrID][2]);
	//	shang_emitter_particle_handle[plrID][2] = 0;
	//}


	shang_emitter_particle_handle[plrID][0] = 0;
	shang_emitter_particle_handle[plrID][1] = 0;
	shang_emitter_particle_handle[plrID][2] = 0;
}

float p_shangtsung_balls_proc()
{
	int apdata = *(int*)AP_DATA;
	if (!apdata)
		return 1.0f;

	int plrID = get_id_from_object(apdata);

	if (shang_balls_exploded[plrID])
		return 1.0f;

	int* ball_1 = &shang_emitter_particle_handle[plrID][0];
	int* ball_2 = &shang_emitter_particle_handle[plrID][1];

	if (p_shangtsung_are_balls_touching(plrID, *ball_1, *ball_2))
	{
		if (!shang_balls_exploded[plrID])
		{
			p_shangtsung_explode_balls(plrID, *ball_1, *ball_2, shang_balls_script_hit[plrID]);
			shang_balls_exploded[plrID] = 1;
		}

		return 1.0f;
	}

	p_shangtsung_update_ball(*ball_1, apdata, shang_balls_distance[plrID][0], shang_balls_distance[plrID][1]);
	p_shangtsung_update_ball(*ball_2, apdata, shang_balls_distance[plrID][0], -shang_balls_distance[plrID][1]);
	
	return 1.0f;
}


void p_shangtsung_update_ball(int obj, int plrObj, float speed, float angle)
{
	CVector pos;
	CVector forward;
	CVector right;

	pos = *(CVector*)(obj + 160);
	get_matrix_forward(plrObj, &forward);
	get_matrix_right(plrObj, &right);


	pos.x += forward.x * speed;
	pos.y += forward.y * speed;
	pos.z += forward.z * speed;

	pos.x += right.x * angle * -1.0f;
	pos.y += right.y * angle * -1.0f;
	pos.z += right.z * angle * -1.0f;

	obj_set_pos(obj, &pos);
	update_mkobj(obj);
}

void shangtsung_balls_set_on_fire(int plrID)
{
	int obj = shang_emitter_particle_handle[plrID][0];
	int obj2 = shang_emitter_particle_handle[plrID][1];
	int obj3 = shang_emitter_particle_handle[plrID][2];
	int playerObj = *(int*)PLAYER_OBJ;


	shang_emitter_fx_handle[plrID][SHANG_FX_LEFT] = fx("ball_l_proj");
	shang_emitter_fx_handle[plrID][SHANG_FX_RIGHT] = fx("ball_r_proj");

	shang_emitter_fx_handle[plrID][SHANG_FX_LEFT_TRAIL] = fx("ball_l_trail");
	shang_emitter_fx_handle[plrID][SHANG_FX_RIGHT_TRAIL] = fx("ball_r_trl");


	shang_emitter_fx_handle[plrID][SHANG_FX_EXPLOSION] = fx("balls_explode");

	{
		CVector pos;
		get_bone_pos(playerObj, 24, &pos);

		obj_set_pos(obj, &pos);
		update_mkobj(obj);

		resume_effect_at_obj_bid(obj, 0, shang_emitter_fx_handle[plrID][SHANG_FX_LEFT], 2, 0);
		resume_effect_at_obj_bid(obj, 0, shang_emitter_fx_handle[plrID][SHANG_FX_LEFT_TRAIL], 2, 0);

	}

	{
		CVector pos;
		get_bone_pos(playerObj, 25, &pos);

		obj_set_pos(obj2, &pos);
		update_mkobj(obj2);

		resume_effect_at_obj_bid(obj2, 0, shang_emitter_fx_handle[plrID][SHANG_FX_RIGHT], 2, 0);
		resume_effect_at_obj_bid(obj2, 0, shang_emitter_fx_handle[plrID][SHANG_FX_RIGHT_TRAIL], 2, 0);

	}
	{
		CVector pos = { 0.0f, 0.0f, 0.0f };
		obj_set_pos(obj3, &pos);
		update_mkobj(obj3);
	}

}

void start_shangtsung_balls(int plrID, int type)
{
	shangtsung_check_for_balls(plrID);

	shang_balls_script_hit[plrID] = 0;
	shang_balls_exploded[plrID] = 0;

	if (!shangtsung_make_new_balls(plrID))
		return;

	
	fx_reset(fx_by_owner("ball_l_trail", plrID + 1));
	fx_reset(fx_by_owner("ball_r_trl", plrID + 1));
	fx_reset(fx_by_owner("ball_l_proj", plrID + 1));
	fx_reset(fx_by_owner("ball_r_proj", plrID + 1));
	fx_reset(fx_by_owner("balls_explode", plrID + 1));

	shangtsung_balls_set_on_fire(plrID);

	float distance = 0.045f;
	float speed = 0.165f;

	if (type == 1)
	{
		distance = 0.0275f;
		speed = 0.257f;
	}
		
	shang_balls_distance[plrID][0] = speed;
	shang_balls_distance[plrID][1] = distance;


	if (!find_mkproc_pid(SHANG_BALLS_PROC_ID + plrID))
	{
		int proc = create_mkproc_generic_nostack(SHANG_BALLS_PROC_ID + plrID, 14, p_shangtsung_balls_proc, 0, 0);

		if (proc)
			mk_insert(*(int*)PLAYER_OBJ, proc + 232);
	}

}

void shang_explode_ball(int plrID)
{
	shang_balls_script_hit[plrID] = 1;
}


int p_shangtsung_are_balls_touching(int plrID, int obj, int obj2)
{
	if (shang_balls_script_hit[plrID])
		return 1;

	{
		CVector pos = *(CVector*)(obj + 160);
		CVector pos2 = *(CVector*)(obj2 + 160);

		static CVector result;

		result.x = pos2.x - pos.x;
		result.y = pos2.y - pos.y;
		result.z = pos2.z - pos.z;
		float dist = sqrt((result.x * result.x) + (result.y * result.y) + (result.z * result.z));

		if (dist < 0.2f)
		{
			snd_req(7555);
			return 1;
		}
	}


	return 0;
}

void p_shangtsung_explode_balls(int plrID, int obj, int obj2, int hit)
{
	fx_pause_emit(fx_by_owner("ball_l_trail", plrID + 1));
	fx_pause_emit(fx_by_owner("ball_r_trl", plrID + 1));
	fx_pause_emit(fx_by_owner("ball_l_proj", plrID + 1));
	fx_pause_emit(fx_by_owner("ball_r_proj", plrID + 1));

	if (hit)
	{
		player_info* p1 = (player_info*)(PLAYER1_INFO);
		player_info* p2 = (player_info*)(PLAYER2_INFO);

		int plrObj = p2->pObject;
		if (plrID == 1)
			plrObj = p1->pObject;

		resume_effect_at_obj_bid(plrObj, 16, shang_emitter_fx_handle[plrID][SHANG_FX_EXPLOSION], 1, 0);
	}
	else
	{
		obj_set_pos(shang_emitter_particle_handle[plrID][SHANG_BALL_EXPLOSION], (CVector*)(obj + 160));
		update_mkobj(shang_emitter_particle_handle[plrID][SHANG_BALL_EXPLOSION]);
		resume_effect_at_obj_bid(obj, 0, shang_emitter_fx_handle[plrID][SHANG_FX_EXPLOSION], 1, 0);
	}

}


void shangtsung_reset_event()
{
	int apdata = *(int*)AP_DATA;
	int procID = *(int*)(apdata + 8);

	if (procID == 4097)
		reset_shangtsung_emitters(0);
	else
		reset_shangtsung_emitters(1);

}

void reset_shangtsung_emitters(int plrID)
{
	for (int i = 0; i < SHANG_TOTAL_EMITTERS; i++)
		shang_emitter_particle_handle[plrID][i] = 0;

	for (int i = 0; i < SHANG_TOTAL_FX; i++)
		shang_emitter_fx_handle[plrID][i] = 0;
}