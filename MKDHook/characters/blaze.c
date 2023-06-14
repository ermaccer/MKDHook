#pragma once
#include "blaze.h"
#include "..\mkdeception.h"
#include "..\sound.h"
#include "..\character.h"

// flame ball
struct scan_action scan_blaze_1 = {
	4629,
	0x300001E,
	5,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};

// drahmin uppercut
struct scan_action scan_blaze_2 = {
	0,
	0x3000019,
	4,
	MOVE_BACKWARDS,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0
};

// charge
struct scan_action scan_blaze_3 = {
	4630,
	0x300001E,
	3,
	MOVE_DOWN,
	MOVE_FORWARD,
	-1,
	0,
	0
};



struct mk_file_entry blaze_entry_table[BLAZE_FILES] = {
	{"blaze.ssf"	,0, 4},

	{"blaze.sec",0, 1},
	{"blaze_ap.sec",0, 1},
	{"blaze.mko",0, 3},
	{"sh_blaze.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"blaze_fx.mko",0,3},
	{"hapkido.mko",0, 3},
	{"style_hapkido.sec",0,1},
	{"jeetkunedo.mko",0, 3},
	{"style_jeet_kun_do.sec",0,1},
	{"xing_yi.mko",0, 3},
	{"style_xing_yi.sec",0,1},
	{"blaze_anims.sec",0, 2},
	{"hapkido_anims.sec",0,2},
	{"jeetkunedo_anims.sec",0,2},
	{"xing_yi_anims.sec",0, 2},
	{"pz_jax_anims.sec",0,2},
};
// I:\ps2dvd\art\blaze.ssf
struct mk_toc_entry blaze_file_table[BLAZE_FILES + 1] = {
		{&blaze_entry_table[0]	,0,0 },

		{&blaze_entry_table[1]	,0,	   351616 },	// blaze.sec
		{&blaze_entry_table[2]	,0,    351616 },	// blaze_ap.sec
		{&blaze_entry_table[3]	,0,    12928  },	// blaze.mko
		{&blaze_entry_table[4]	,0,    209664 },	// sh_blaze.sec
		{&blaze_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&blaze_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&blaze_entry_table[7]	,0,    6112   },	// blaze_fx.mko
		{&blaze_entry_table[8]  ,0,	   16480  },	// hapkido.mko
		{&blaze_entry_table[9]	,0,    10112  },	// style_hapkido.sec
		{&blaze_entry_table[10] ,0,	   14592  },	// jeetkunedo.mko
		{&blaze_entry_table[11] ,0,    10112  },	// style_jeet_kun_do.sec
		{&blaze_entry_table[12] ,0,	   14816  },	// xing_yi.mko
		{&blaze_entry_table[13] ,0,	   10112  },	// style_xing_yi.sec
		{&blaze_entry_table[14] ,0,	   39552  },	// blaze_anims.sec
		{&blaze_entry_table[15] ,0,	   182144 },	// hapkido_anims.sec
		{&blaze_entry_table[16] ,0,	   195328 },	// jeetkunedo_anims.sec
		{&blaze_entry_table[17] ,0,	   162048 },	// xing_yi_anims.sec
		{&blaze_entry_table[18] ,0,	   52352  },	// pz_jax_anims.sec

		{0,0,0}
};


int blaze_flaming_limbs_fx_handles[2][11] = { 0 };
int blaze_flaming_limbs_sound_handle[2] = { 0 };

void init_blaze()
{
	blaze_flaming_limbs_sound_handle[0] = 0;
	blaze_flaming_limbs_sound_handle[1] = 0;
	

	for (int i = 0; i < 2; i++)
	{
		for (int a = 0; a < 11; a++)
			blaze_flaming_limbs_fx_handles[i][a] = 0;
	}
}

void init_blaze_toc()
{
	init_blaze();

	int baseSize = 2048;
	for (int i = 0; i < BLAZE_FILES; i++)
	{
		blaze_entry_table[i].belong = &blaze_file_table[0];
	}


	for (int i = 1; i < BLAZE_FILES; i++)
	{
		blaze_file_table[i].previousSize = baseSize;
		baseSize += (blaze_file_table[i].size + 2048 - 1) & -2048;
	}
}

void start_blaze_flaming_limbs(int id)
{
	player_info* plr_info = (player_info*)PLAYER1_INFO;
	if (id == 1)
		plr_info = (player_info*)(PLAYER2_INFO);

	int obj = plr_info->pObject;

	// right
	blaze_flaming_limbs_fx_handles[id][0] = pfxhandle_spawn_at_bid_next(fx("blaze_body_flame_rs"), obj, 17);
	blaze_flaming_limbs_fx_handles[id][1] = pfxhandle_spawn_at_bid_next(fx("blaze_body_flame_re"), obj, 21);
	blaze_flaming_limbs_fx_handles[id][2] = pfxhandle_spawn_at_bid_next(fx("blaze_body_flame_rh"), obj, 2);
	blaze_flaming_limbs_fx_handles[id][3] = pfxhandle_spawn_at_bid_next(fx("blaze_body_flame_rk"), obj, 5);
	blaze_flaming_limbs_fx_handles[id][4] = pfxhandle_spawn_at_bid_next(fx("blaze_body_flame_ra"), obj, 8);
	// left
	blaze_flaming_limbs_fx_handles[id][5] = pfxhandle_spawn_at_bid_next(fx("blaze_body_flame_ls"), obj, 15);
	blaze_flaming_limbs_fx_handles[id][6] = pfxhandle_spawn_at_bid_next(fx("blaze_body_flame_le"), obj, 20);
	blaze_flaming_limbs_fx_handles[id][7] = pfxhandle_spawn_at_bid_next(fx("blaze_body_flame_lh"), obj, 1);
	blaze_flaming_limbs_fx_handles[id][8] = pfxhandle_spawn_at_bid_next(fx("blaze_body_flame_lk"), obj, 4);
	blaze_flaming_limbs_fx_handles[id][9] = pfxhandle_spawn_at_bid_next(fx("blaze_body_flame_la"), obj, 7);

	blaze_flaming_limbs_sound_handle[id] = snd_req(SOUND_BLAZE_FLAMELOOP);
}

void reset_blaze_flaming_limbs(int id)
{
	player_info* plr_info = (player_info*)PLAYER1_INFO;
	if (id == 1)
		plr_info = (player_info*)(PLAYER2_INFO);

	if (blaze_flaming_limbs_sound_handle[id])
	{
		snd_stop(blaze_flaming_limbs_sound_handle[id]);
		blaze_flaming_limbs_sound_handle[id] = 0;
	}



	for (int i = 0; i < 11; i++)
	{
		if (blaze_flaming_limbs_fx_handles[id][i])
			fx_reset_emit((fx_handle)blaze_flaming_limbs_fx_handles[i]);
		blaze_flaming_limbs_fx_handles[id][i] = 0;
	}
}

void blaze_reset_event()
{
	int apdata = *(int*)AP_DATA;
	int procID = *(int*)(apdata + 8);

	if (procID == 4097)
		reset_blaze_flaming_limbs(0);
	else
		reset_blaze_flaming_limbs(1);
}

void blaze_destroy_event(int id)
{
	if (blaze_flaming_limbs_sound_handle[id])
	{
		snd_stop(blaze_flaming_limbs_sound_handle[id]);
		blaze_flaming_limbs_sound_handle[id] = 0;
	}


	for (int i = 0; i < 11; i++)
		blaze_flaming_limbs_fx_handles[id][i] = 0;
}

void blaze_fatality_watch()
{

}
