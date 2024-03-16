#include "sektor.h"


// straight missile
struct scan_action scan_sektor_1 = {
	4629,
	0x300001E,
	16,
	MOVE_DOWN,
	MOVE_FORWARD,
	-1,
	0,
	0
};

// flamethrower
struct scan_action scan_sektor_3 = {
	17048,
	0x3000019,
	13,
	MOVE_FORWARD,
	MOVE_FORWARD,
	-1,
	0,
	0
};

// tele punch
struct scan_action scan_sektor_4 = {
	16927,
	0x3000019,
	23,
	MOVE_FORWARD,
	MOVE_FORWARD,
	-1,
	0,
	0
};

int sektor_chest_status[2] = { 0 };
int sektor_chest_angle[2] = { 0 };

struct mk_file_entry sektor_entry_table[SEKTOR_FILES] = {
	{"sektor.ssf"	,0, 4},

	{"sektor.sec",0, 1},
	{"sektor_ap.sec",0, 1},
	{"sektor.mko",0, 3},
	{"sh_sektor.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"sektor_fx.mko",0,3},
	{"ninjitsu.mko",0, 3},
	{"style_ninjitsu.sec",0,1},
	{"shuaichiao.mko",0, 3},
	{"style_shuaichiao.sec",0,1},
	{"pulseblades.mko",0, 3},
	{"style_pulseblades.sec",0,1},
	{"sektor_anims.sec",0, 2},
	{"ninjitsu_anims.sec",0, 2},
	{"shuaichiao_anims.sec",0, 2},
	{"pulseblades_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\sektor.ssf
struct mk_toc_entry sektor_file_table[SEKTOR_FILES + 1] = {
		{&sektor_entry_table[0]	,0,0 },

		{&sektor_entry_table[1]		,0,		531072 },	// sektor.sec             
		{&sektor_entry_table[2]		,0,		531072 },	// sektor_ap.sec        
		{&sektor_entry_table[3]		,0,		24576  },	// sektor.mko   
		{&sektor_entry_table[4]		,0,		313728 },	// sh_sektor.sec           
		{&sektor_entry_table[5]		,0,		10164  },	// fight_fx.mko         
		{&sektor_entry_table[6]		,0,		21368  },	// blood_fx.mko         
		{&sektor_entry_table[7]		,0,		14112  },	// sektor_fx.mko          
		{&sektor_entry_table[8] 	,0,		13120  },	// ninjitsu.mko         
		{&sektor_entry_table[9]		,0,		10112  },	// style_ninjitsu.sec   
		{&sektor_entry_table[10]	,0,		8320   },	// shuaichiao.mko        
		{&sektor_entry_table[11]	,0,		10112  },	// style_shuaichiao.sec  
		{&sektor_entry_table[12]	,0,		12544  },	// pulseblades.mko        
		{&sektor_entry_table[13]	,0,		10112  },	// style_pulseblades.sec  
		{&sektor_entry_table[14]	,0,		120320 },	// sektor_anims.sec       
		{&sektor_entry_table[15]	,0,		154132 },	// ninjitsu_anims.sec   
		{&sektor_entry_table[16]	,0,		174720 },	// shuaichiao_anims.sec  
		{&sektor_entry_table[17]	,0,		164400 },	// pulseblades_anims.sec  
		{&sektor_entry_table[18]	,0,		53120  },	// pz_noob_anims.sec

		{0,0,0}
};

struct mk_file_entry sektor_alt_entry_table[SEKTOR_FILES] = {
	{"sektor_alt.ssf"	,0, 4},

	{"sektor_alt.sec",0, 1},
	{"sektor_alt_ap.sec",0, 1},
	{"sektor.mko",0, 3},
	{"sh_sektor.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"sektor_fx.mko",0,3},
	{"ninjitsu.mko",0, 3},
	{"style_ninjitsu.sec",0,1},
	{"shuaichiao.mko",0, 3},
	{"style_shuaichiao.sec",0,1},
	{"pulseblades.mko",0, 3},
	{"style_pulseblades.sec",0,1},
	{"sektor_alt_anims.sec",0, 2},
	{"ninjitsu_anims.sec",0, 2},
	{"shuaichiao_anims.sec",0, 2},
	{"pulseblades_anims.sec",0,2},
	{"pz_noob_anims.sec",0,2},
};

// I:\ps2dvd\art\sektor_alt.ssf
struct mk_toc_entry sektor_alt_file_table[SEKTOR_FILES + 1] = {
		{&sektor_alt_entry_table[0]	,0,0 },

		{&sektor_alt_entry_table[1]		,0,		616832 },	// sektor_alt.sec             
		{&sektor_alt_entry_table[2]		,0,		616832 },	// sektor_alt_ap.sec        
		{&sektor_alt_entry_table[3]		,0,		24576  },	// sektor.mko   
		{&sektor_alt_entry_table[4]		,0,		313728 },	// sh_sektor.sec           
		{&sektor_alt_entry_table[5]		,0,		10164  },	// fight_fx.mko         
		{&sektor_alt_entry_table[6]		,0,		21368  },	// blood_fx.mko         
		{&sektor_alt_entry_table[7]		,0,		14112  },	// sektor_fx.mko          
		{&sektor_alt_entry_table[8] 	,0,		13120  },	// ninjitsu.mko         
		{&sektor_alt_entry_table[9]		,0,		10112  },	// style_ninjitsu.sec   
		{&sektor_alt_entry_table[10]	,0,		8320   },	// shuaichiao.mko        
		{&sektor_alt_entry_table[11]	,0,		10112  },	// style_shuaichiao.sec  
		{&sektor_alt_entry_table[12]	,0,		12544  },	// pulseblades.mko        
		{&sektor_alt_entry_table[13]	,0,		10112  },	// style_pulseblades.sec  
		{&sektor_alt_entry_table[14]	,0,		120320 },	// sektor_alt_anims.sec       
		{&sektor_alt_entry_table[15]	,0,		154132 },	// ninjitsu_anims.sec   
		{&sektor_alt_entry_table[16]	,0,		174720 },	// shuaichiao_anims.sec  
		{&sektor_alt_entry_table[17]	,0,		164400 },	// pulseblades_anims.sec  
		{&sektor_alt_entry_table[18]	,0,		53120  },	// pz_noob_anims.sec

		{0,0,0}
};

void init_sektor_toc()
{
	sektor_chest_status[0] = 0;
	sektor_chest_status[1] = 0;
	sektor_chest_angle[0] = 0;
	sektor_chest_angle[1] = 0;
	int baseSize = 2048;
	for (int i = 0; i < SEKTOR_FILES; i++)
	{
		sektor_entry_table[i].belong = &sektor_file_table[0];
	}


	for (int i = 1; i < SEKTOR_FILES; i++)
	{
		sektor_file_table[i].previousSize = baseSize;
		baseSize += (sektor_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;
	for (int i = 0; i < SEKTOR_FILES; i++)
	{
		sektor_alt_entry_table[i].belong = &sektor_alt_file_table[0];
	}


	for (int i = 1; i < SEKTOR_FILES; i++)
	{
		sektor_alt_file_table[i].previousSize = baseSize;
		baseSize += (sektor_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}

void sektor_set_chest_status(int id, int status)
{
	sektor_chest_status[id] = status;
}

void sektor_update_chest_piece(bone_data* bone, int id, int right, int isAlt)
{
	static float defaultQuat[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	bone->flags |= 0x400;

	int status = sektor_chest_status[id];

	if (status == SEKTOR_CHEST_STATUS_START_OPENING || status == SEKTOR_CHEST_STATUS_START_CLOSING)
	{
		char mat[64] = {};
		char newMat[64] = {};

		quat_to_matrix((int)&mat, (int)&bone->rotation);

		float value = sektor_chest_angle[id] / 100.0f;

		if (right)
			value *= -1.0f;

		CVector rotationAngle = {};

		if (isAlt)
			rotationAngle.x = value;
		else
			rotationAngle.y = value;

		vector_to_matrix(&rotationAngle, (int)&newMat);
		matrix_mult_matrix((int)&mat, (int)&mat, (int)&newMat);
		matrix_to_quat((int)&mat, (int)&bone->rotation);
	}
	else if (status == SEKTOR_CHEST_STATUS_FORCE_CLOSE)
	{	
		bone->rotation[0] = defaultQuat[0];
		bone->rotation[1] = defaultQuat[0];
		bone->rotation[2] = defaultQuat[2];
		bone->rotation[3] = defaultQuat[3];
		//sektor_chest_status[id] = SEKTOR_CHEST_STATUS_DEFAULT;
	}	

}


void sektor_update_chest(int id, int object, int flags)
{
	bone_data* left_chest = get_bone(object,SEKTOR_CHEST_LEFT_BONE_ID);
	bone_data* right_chest = get_bone(object, SEKTOR_CHEST_RIGHT_BONE_ID);

	if (!left_chest)
		return;
	if (!right_chest)
		return;

	switch (sektor_chest_status[id])
	{
	case SEKTOR_CHEST_STATUS_START_OPENING:
		if (sektor_chest_angle[id] <= SEKTOR_CHEST_OPEN_MAX)
			sektor_chest_angle[id]++;
		break;
	case SEKTOR_CHEST_STATUS_START_CLOSING:
		if (sektor_chest_angle[id] > SEKTOR_CHEST_CLOSE_MAX)
			sektor_chest_angle[id]--;
		if (sektor_chest_angle[id] == SEKTOR_CHEST_CLOSE_MAX)
			sektor_chest_status[id] = SEKTOR_CHEST_STATUS_FORCE_CLOSE;
		break;
	case SEKTOR_CHEST_STATUS_FORCE_CLOSE:
		sektor_chest_angle[id] = 0;
		break;
	default:
		break;
	}

	sektor_update_chest_piece(left_chest, id, 0, flags & 1);
	sektor_update_chest_piece(right_chest, id, 1, flags & 1);
}

void sektor_reset_event()
{
	sektor_chest_status[0] = 0;
	sektor_chest_status[1] = 0;
	sektor_chest_angle[0] = 0;
	sektor_chest_angle[1] = 0;
}
