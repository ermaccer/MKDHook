#include "kitana.h"
#include "..\mkdeception.h"


// fan lift & fan throw
struct scan_action_dual scan_kitana_1 = {
	4621,
	0x300001E,
	27,
	MOVE_BACKWARDS,
	MOVE_FORWARD,

	16925,
	0x3000019,
	20,
	MOVE_DOWN,
	MOVE_FORWARD,

	-1,
};




// kiss_of_death
struct scan_fatality scan_kitana_2 = {
	2.0f,
	0x1000032,
	DO_FATALITY_ONE,
	MOVE_DOWN,
	MOVE_UP,
	MOVE_FORWARD,
	MOVE_FORWARD,
	-1,
};

// pretty kick
struct scan_action scan_kitana_3 = {
	0,
	0x3000019,
	26,
	MOVE_UP,
	-1,
	0,
	0,
	0
};

// teleport
struct scan_action scan_kitana_4 = {
	16936,
	0x3000019,
	30,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};



struct mk_file_entry kitana_entry_table[KITANA_FILES] = {
	{"kitana.ssf"	,0, 4},

	{"kitana.sec",0, 1},
	{"kitana_ap.sec",0, 1},
	{"kitana.mko",0, 3},
	{"sh_kitana.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"kitana_fx.mko",0,3},
	{"eagleclaw.mko",0, 3},
	{"style_eagle_claw.sec",0,1},
	{"k_bagua.mko",0, 3},
	{"style_k_bagua.sec",0,1},
	{"steelfan.mko",0, 3},
	{"style_steel_fan.sec",0,1},
	{"kitana_anims.sec",0, 2},
	{"fat_anims_kitana_kiss.sec",0,2},
	{"eagleclaw_anims.sec",0, 2},
	{"k_bagua_anims.sec",0, 2},
	{"steelfan_anims.sec",0,2},
	{"pz_jax_anims.sec",0,2},
};

// I:\ps2dvd\art\kitana.ssf
struct mk_toc_entry kitana_file_table[KITANA_FILES + 1] = {
		{&kitana_entry_table[0]	,0,0 },

		{&kitana_entry_table[1]	,0,	   521600 },	// kitana.sec
		{&kitana_entry_table[2]	,0,    521600 },	// kitana_ap.sec
		{&kitana_entry_table[3]	,0,    58848  },	// kitana.mko
		{&kitana_entry_table[4]	,0,    328064 },	// sh_kitana.sec
		{&kitana_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&kitana_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&kitana_entry_table[7]	,0,    10592  },	// kitana_fx.mko
		{&kitana_entry_table[8] ,0,	   16608  },	// eagleclaw.mko
		{&kitana_entry_table[9]	,0,    10112  },	// style_eagle_claw.sec
		{&kitana_entry_table[10],0,	   13056  },	// k_bagua.mko
		{&kitana_entry_table[11],0,    6016   },	// style_k_bagua.sec
		{&kitana_entry_table[12],0,	   12000  },	// steelfan.mko
		{&kitana_entry_table[13],0,	   10112  },	// style_steel_fan.sec
		{&kitana_entry_table[14],0,	   87936  },	// kitana_anims.sec
		{&kitana_entry_table[15],0,	   97792  },	// fat_anims_kitana_kiss.sec
		{&kitana_entry_table[16],0,	   166016 },	// eagleclaw_anims.sec
		{&kitana_entry_table[17],0,	   179840 },	// k_bagua_anims.sec
		{&kitana_entry_table[18],0,	   247424 },	// steelfan_anims.sec
		{&kitana_entry_table[19],0,	   52352  },	// pz_jax_anims.sec

		{0,0,0}
};


struct mk_file_entry kitana_alt_entry_table[KITANA_FILES] = {
	{"kitana_alt.ssf"	,0, 4},

	{"kitana_alt.sec",0, 1},
	{"kitana_alt_ap.sec",0, 1},
	{"kitana.mko",0, 3},
	{"sh_kitana.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"kitana_fx.mko",0,3},
	{"eagleclaw.mko",0, 3},
	{"style_eagle_claw.sec",0,1},
	{"k_bagua.mko",0, 3},
	{"style_k_bagua.sec",0,1},
	{"steelfan.mko",0, 3},
	{"style_steel_fan.sec",0,1},
	{"kitana_alt_anims.sec",0, 2},
	{"fat_anims_kitana_kiss.sec",0,2},
	{"eagleclaw_anims.sec",0, 2},
	{"k_bagua_anims.sec",0, 2},
	{"steelfan_anims.sec",0,2},
	{"pz_jax_anims.sec",0,2},
};

// I:\ps2dvd\art\kitana_alt.ssf
struct mk_toc_entry kitana_alt_file_table[KITANA_FILES + 1] = {
		{&kitana_alt_entry_table[0]	,0,0 },

		{&kitana_alt_entry_table[1]	,0,	   497280 },	// kitana_alt.sec
		{&kitana_alt_entry_table[2]	,0,    497280 },	// kitana_alt_ap.sec
		{&kitana_alt_entry_table[3]	,0,    58848  },	// kitana.mko
		{&kitana_alt_entry_table[4]	,0,    328064 },	// sh_kitana.sec
		{&kitana_alt_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&kitana_alt_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&kitana_alt_entry_table[7]	,0,    10592  },	// kitana_fx.mko
		{&kitana_alt_entry_table[8] ,0,	   16608  },	// eagleclaw.mko
		{&kitana_alt_entry_table[9]	,0,    10112  },	// style_eagle_claw.sec
		{&kitana_alt_entry_table[10],0,	   13056  },	// k_bagua.mko
		{&kitana_alt_entry_table[11],0,    6016   },	// style_k_bagua.sec
		{&kitana_alt_entry_table[12],0,	   12000  },	// steelfan.mko
		{&kitana_alt_entry_table[13],0,	   10112  },	// style_steel_fan.sec
		{&kitana_alt_entry_table[14],0,	   93184  },	// kitana_alt_anims.sec
		{&kitana_alt_entry_table[15],0,	   97792  },	// fat_anims_kitana_kiss.sec
		{&kitana_alt_entry_table[16],0,	   166016 },	// eagleclaw_anims.sec
		{&kitana_alt_entry_table[17],0,	   179840 },	// k_bagua_anims.sec
		{&kitana_alt_entry_table[18],0,	   247424 },	// steelfan_anims.sec
		{&kitana_alt_entry_table[19],0,	   52352  },	// pz_jax_anims.sec

		{0,0,0}
};


void init_kitana_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < KITANA_FILES; i++)
	{
		kitana_entry_table[i].belong = &kitana_file_table[0];
	}


	for (int i = 1; i < KITANA_FILES; i++)
	{
		kitana_file_table[i].previousSize = baseSize;
		baseSize += (kitana_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;

	for (int i = 0; i < KITANA_FILES; i++)
	{
		kitana_alt_entry_table[i].belong = &kitana_alt_file_table[0];
	}


	for (int i = 1; i < KITANA_FILES; i++)
	{
		kitana_alt_file_table[i].previousSize = baseSize;
		baseSize += (kitana_alt_file_table[i].size + 2048 - 1) & -2048;
	}
}

kitana_bone_stretcher_entry kitana_bone_stretchers[NUM_STRETCHBONES] = {
	{9, 1.0, 0.0, 1.0},
	{17, 1.0, 0.0, 1.0},
	{15, 1.0, 0.0, 1.0},
	{3, 1.0, 0.0, 1.0},
	{2, 1.0, 0.0, 1.0},
	{1, 1.0, 0.0, 1.0},
	{5, 1.0, 0.0, 1.0},
	{4, 1.0, 0.0, 1.0},
	{19, 0.0, 1.0, 1.0},
	{18, 0.0, 1.0, 1.0},
	{21, 0.0, 1.0, 1.0},
	{20, 0.0, 1.0, 1.0},
	{25, 0.0, 1.0, 1.0},
	{24, 0.0, 1.0, 1.0},
};


int bone_stretcher_flags[] = {
	16383, 16383, 16383, 16335, 16335,
	16383, 16383, 16335, 16383, 16383,
	16323, 16383, 16383, 16383, 16383,
	16383, 16383, 16383, 16383, 16383,
	16383, 16335, 16334, 16383, 16383,
	975,   16383, 16383, 16383, 16383,
	16383, 16383, 16383, 16383, 16383,
	16383,
};

// on psp
// $f12 - scale value
// $a0 - enemy object

void kitana_kod_stretcher(int object, float scale)
{
	int script = *(int*)*(int*)SCRIPT_OBJ;
	int his_obj = *(int*)(PLAYER2_OBJ);

	// TODO:: figure this out
	// looks like some flags on psp for each character but there's no immediate visual difference with these active
	// or not

	/*
	player_info* info = (player_info*)(script + 0x18);

	int is_alt = info->flags & 1;
	int characterID = info->characterID;

	int strFlag = bone_stretcher_flags[characterID];
	*/

	for (int i = 0; i < NUM_STRETCHBONES; i++)
	{
		kitana_bone_stretcher_entry bs = kitana_bone_stretchers[i];
		int skeleton = *(int*)(object + 72);

		int bone_ptr = *(int*)(skeleton + (4 * bs.boneID));
		bone_data* bone = (bone_data*)(bone_ptr);

		if (bone)
		{
			bone->flags |= 0x400;
			bone->scale.x = (bs.x * scale) + 1.0f;
			bone->scale.y = (bs.y * scale) + 1.0f;
			bone->scale.z = (bs.z * scale) + 1.0f;
		}
	}

}

void kitana_fanlift_voice()
{
	return;

	player_data* plyr_data = *(player_data**)(PLAYER_DATA);
	//plyr_data = (player_data*)plyr_data->field_10;

	swap_active_proc();

	int snd = ((int(*)(int))0x12B7D0)(68);
	plyr_data->field_6B0 = snd;

	swap_active_proc();

	//plyr_data = (player_data*)plyr_data->field_10;
}
