#include "goro.h"
#include "..\ps2mem.h"
#include "..\mips.h"
#include "..\mkdeception.h"
#include "..\generic.h"
#include "..\scripthook.h"
// fireball/fatality
struct  scan_action_fatality scan_goro_1 = {
	16980,
	0x3000019,
	18,
	MOVE_DOWN,
	MOVE_BACKWARDS,

	2.0f,
	0x1000032,
	DO_FATALITY_TWO,
	MOVE_FORWARD,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	MOVE_BACKWARDS,
	-1,
};

// spin
struct scan_action scan_goro_2 = {
	0,
	0x3000019,
	13,
	MOVE_DOWN,
	MOVE_FORWARD,
	-1,
	0,
	0
};


// stomps
struct scan_action_dual_one_fatality  scan_goro_3 = {
	16985 ,
	0x3000023,
	8,
	MOVE_UP,
	MOVE_DOWN,
	16985 ,
	0x3000019,
	9,
	MOVE_DOWN,
	MOVE_UP,

	2.0f,
	0x1000032,
	DO_FATALITY_ONE,
	MOVE_BACKWARDS,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	MOVE_FORWARD,
	-1,
};

// hk
struct scan_suicide scan_goro_suicide = {
	2.0f,
	0x1000032,
	DO_HARAKIRI,
	MOVE_UP,
	MOVE_FORWARD,
	MOVE_FORWARD,
	MOVE_BACKWARDS,
	-1
};

struct mk_file_entry goro_entry_table[GORO_FILES] = {
	{"goro.ssf"	,0, 4},

	{"goro.sec",0, 1},
	{"goro_ap.sec",0, 1},
	{"goro.mko",0, 3},
	{"sh_goro.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"goro_fx.mko",0,3},
	{"shokan.mko",0, 3},
	{"style_shokan.sec",0,1},
	{"kuatan.mko",0, 3},
	{"style_kuatan.sec",0,1},
	{"goro_gauntlets.mko",0, 3},
	{"style_goro_gauntlets.sec",0,1},
	{"goro_anims.sec",0, 2},
	{"fat_anims_goro_stab.sec",0, 2},
	{"fat_anims_goro_stretch.sec",0, 2},
	{"shokan_anims.sec",0,2},
	{"kuatan_anims.sec",0,2},
	{"goro_gauntlets_anims.sec",0,2},
};


// I:\ps2dvd\art\goro.ssf
struct mk_toc_entry goro_file_table[GORO_FILES + 1] = {
		{&goro_entry_table[0]	,0,0 },

		{&goro_entry_table[1]	,0,	   511104 },	// goro.sec
		{&goro_entry_table[2]	,0,    511104 },	// goro_ap.sec
		{&goro_entry_table[3]	,0,    52480  },	// goro.mko
		{&goro_entry_table[4]	,0,    267008 },	// sh_goro.sec
		{&goro_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&goro_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&goro_entry_table[7]	,0,    10016  },	// goro_fx.mko
		{&goro_entry_table[8] 	,0,	   11616  },	// shokan.mko
		{&goro_entry_table[9]	,0,    10112   },	// style_shokan.sec
		{&goro_entry_table[10]	,0,	   9856   },	// kuatan.mko
		{&goro_entry_table[11]	,0,    10112   },	// style_kuatan.sec
		{&goro_entry_table[12]	,0,	   15552  },	// goro_gauntlets.mko
		{&goro_entry_table[13]	,0,	   10112   },	// style_goro_gauntlets.sec
		{&goro_entry_table[14]	,0,	   252416 },	// goro_anims.sec
		{&goro_entry_table[15]	,0,	   131712 },	// fat_anims_goro_stab.sec
		{&goro_entry_table[16]	,0,	   203008 },	// fat_anims_goro_stretch.sec
		{&goro_entry_table[17]	,0,	   159744 },	// shokan_anims.sec
		{&goro_entry_table[18]	,0,	   169344 },	// kuatan_anims.sec
		{&goro_entry_table[19]	,0,	   183424 },	// goro_gauntlets_anims.sec

		{0,0,0}
};


struct mk_file_entry goro_alt_entry_table[GORO_FILES] = {
	{"goro_alt.ssf"	,0, 4},

	{"goro_alt.sec",0, 1},
	{"goro_alt_ap.sec",0, 1},
	{"goro.mko",0, 3},
	{"sh_goro.sec",0, 1},
	{"fight_fx.mko",0,3},
	{"blood_fx.mko",0,3},
	{"goro_fx.mko",0,3},
	{"shokan.mko",0, 3},
	{"style_shokan.sec",0,1},
	{"kuatan.mko",0, 3},
	{"style_kuatan.sec",0,1},
	{"goro_gauntlets.mko",0, 3},
	{"style_goro_gauntlets.sec",0,1},
	{"goro_alt_anims.sec",0, 2},
	{"fat_anims_goro_stab.sec",0, 2},
	{"fat_anims_goro_stretch.sec",0, 2},
	{"shokan_anims.sec",0,2},
	{"kuatan_anims.sec",0,2},
	{"goro_gauntlets_anims.sec",0,2},
};


// I:\ps2dvd\art\goro_alt.ssf
struct mk_toc_entry goro_alt_file_table[GORO_FILES + 1] = {
		{&goro_alt_entry_table[0]	,0,0 },

		{&goro_alt_entry_table[1]	,0,	   529664 },	// goro_alt.sec
		{&goro_alt_entry_table[2]	,0,    529664 },	// goro_alt_ap.sec
		{&goro_alt_entry_table[3]	,0,    52480  },	// goro.mko
		{&goro_alt_entry_table[4]	,0,    267008 },	// sh_goro.sec
		{&goro_alt_entry_table[5]	,0,    10164  },	// fight_fx.mko
		{&goro_alt_entry_table[6]	,0,    21368  },	// blood_fx.mko
		{&goro_alt_entry_table[7]	,0,    10016  },	// goro_fx.mko
		{&goro_alt_entry_table[8] 	,0,	   11616  },	// shokan.mko
		{&goro_alt_entry_table[9]	,0,    10112   },	// style_shokan.sec
		{&goro_alt_entry_table[10]	,0,	   9856   },	// kuatan.mko
		{&goro_alt_entry_table[11]	,0,    10112   },	// style_kuatan.sec
		{&goro_alt_entry_table[12]	,0,	   15552  },	// goro_gauntlets.mko
		{&goro_alt_entry_table[13]	,0,	   10112   },	// style_goro_gauntlets.sec
		{&goro_alt_entry_table[14]	,0,	   252416 },	// goro_alt_anims.sec
		{&goro_alt_entry_table[15]	,0,	   131712 },	// fat_anims_goro_stab.sec
		{&goro_alt_entry_table[16]	,0,	   203008 },	// fat_anims_goro_stretch.sec
		{&goro_alt_entry_table[17]	,0,	   159744 },	// shokan_anims.sec
		{&goro_alt_entry_table[18]	,0,	   169344 },	// kuatan_anims.sec
		{&goro_alt_entry_table[19]	,0,	   183424 },	// goro_gauntlets_anims.sec

		{0,0,0}
};


weapon_mdl_description gauntlet_lr = { 0 };
weapon_mdl_description gauntlet_ll = { 0 };

weapon_entry goro_gauntlet_ll_p1 = { 0 };
weapon_entry goro_gauntlet_lr_p1 = { 0 };
weapon_entry goro_gauntlet_ll_p2 = { 0 };
weapon_entry goro_gauntlet_lr_p2 = { 0 };

moveset goro_wp_mv_p1 = { 0 };
moveset goro_wp_mv_p2 = { 0 };
int	   goro_wp_dsc_ptrs[3] = { 0 };

int gauntlet_weapon_bones[2] = {
	1, 0
};

int gauntlet_trail_bones[2] = {
	8193, 0
};

int gauntlet_trail_anchors[18] = {
	0,
	1,
	0xBE800000,
	0,
	0x3E800000,
	7,
	0,
	0,
	0xBD4CCCCD,
	0,
	0,
	1,
	0,
	0,
	0xBD4CCCCD,
	0,
	0x3F000000,
};

int gauntlet_trail_tails[3] = {
	6, 12, 0
};



void init_goro_toc()
{
	init_goro_patches();
	goro_reset_event();
	int baseSize = 2048;
	for (int i = 0; i < GORO_FILES; i++)
	{
		goro_entry_table[i].belong = &goro_file_table[0];
	}


	for (int i = 1; i < GORO_FILES; i++)
	{
		goro_file_table[i].previousSize = baseSize;
		baseSize += (goro_file_table[i].size + 2048 - 1) & -2048;
	}

	baseSize = 2048;

	for (int i = 0; i < GORO_FILES; i++)
	{
		goro_alt_entry_table[i].belong = &goro_alt_file_table[0];
	}


	for (int i = 1; i < GORO_FILES; i++)
	{
		goro_alt_file_table[i].previousSize = baseSize;
		baseSize += (goro_alt_file_table[i].size + 2048 - 1) & -2048;
	}

}

void init_goro_patches()
{
	static const char* wpName = "WEAPON";
	static const char* trName = "WEAPON_TR";

	gauntlet_ll.modelName = wpName;
	gauntlet_ll.bones = gauntlet_weapon_bones;
	gauntlet_ll.boneID = 84;

	//gauntlet_ll.trailName = trName;
	//gauntlet_ll.trailUnk = 3;
	//gauntlet_ll.trailBones = gauntlet_trail_bones;
	//gauntlet_ll.trailTails = gauntlet_trail_tails;
	//gauntlet_ll.trailAnchors = gauntlet_trail_anchors;


	gauntlet_ll.flt_one = -0.12f;
	gauntlet_ll.flt_two = -1.5707964f;
	gauntlet_ll.flt_three = 0.15000001f;
	gauntlet_ll.flt_four = 0.40000001f;
	gauntlet_ll.flt_five = -0.2f;
	gauntlet_ll.flt_six = 0.5f;
	gauntlet_ll.someID = 0x4D;

	gauntlet_lr.modelName = wpName;
	gauntlet_lr.bones = gauntlet_weapon_bones;
	gauntlet_lr.boneID = 71;

	//gauntlet_lr.trailName = trName;
	//gauntlet_lr.trailUnk = 3;
	//gauntlet_lr.trailBones = gauntlet_trail_bones;
	//gauntlet_lr.trailTails = gauntlet_trail_tails;
	//gauntlet_lr.trailAnchors = gauntlet_trail_anchors;


	gauntlet_lr.flt_one = 0.12f;
	gauntlet_lr.flt_two = 1.5707964f;
	gauntlet_lr.flt_three = 0.15000001f;
	gauntlet_lr.flt_four = 0.40000001f;
	gauntlet_lr.flt_five = -0.2f;
	gauntlet_lr.flt_six = 0.5f;
	gauntlet_lr.someID = 0x4D;


	
}
goro_bone_map goro_arm_fixup_map[NUM_GOROMAPBONES] = {
	{0xC, 0x43},
	{0xF, 0x44},
	{0x12, 0x45},
	{0x14, 0x46},
	{0x16, 0x47},
	{0x18, 0x48},
	{0xE, 0x50},
	{0x11, 0x51},
	{0x13, 0x52},
	{0x15, 0x53},
	{0x17, 0x54},
	{0x19, 0x55},
};


void start_goro_arms_fixup()
{
	// proc moved to general update!!!
	//init_goro_patches();
	start_goro_extra_weapons();
}


void start_goro_extra_weapons()
{
	int plyr_data = *(int*)(PLAYER_DATA);
	int plyr_obj = *(int*)(PLAYER_OBJ);
	int wp_data = *(int*)(plyr_data + 724);
	int wp_data_field8 = *(int*)(wp_data + 8);


	moveset* mv = &goro_wp_mv_p1;
	weapon_entry* wep_ll = &goro_gauntlet_ll_p1;
	weapon_entry* wep_lr = &goro_gauntlet_lr_p1;

	if (*(int*)(plyr_data + 432) == 1)
	{
		mv = &goro_wp_mv_p2;
		wep_ll = &goro_gauntlet_ll_p2;
		wep_lr = &goro_gauntlet_lr_p2;
	}


	goro_wp_dsc_ptrs[1] = (int)&gauntlet_ll;
	goro_wp_dsc_ptrs[2] = (int)&gauntlet_lr;

	mv->description = (int*)&goro_wp_dsc_ptrs;
	mv->data = wp_data_field8;
	
	// safer on ps2
	load_moveset_weapons(mv, plyr_obj);


	*wep_ll = mv->modelData[0];
	*wep_lr = mv->modelData[1];



	/*

	weapon_entry* wep_ll = &goro_gauntlet_ll_p1;
	weapon_entry* wep_lr = &goro_gauntlet_lr_p1;

	if (*(int*)(plyr_data + 432) == 1)
	{
		wep_ll = &goro_gauntlet_ll_p2;
		wep_lr = &goro_gauntlet_lr_p2;
	}

	int gll = load_weapon((int)&gauntlet_ll, plyr_obj);

	if (gll)
	{
		wep_ll->obj = gll;
		wep_ll->objUnk = *(int*)(gll + 4);

		mk_insert(gll, wp_data_field8 + 148);

		int reflection = load_weapon_reflection((int)&gauntlet_ll, plyr_obj);
		if (reflection)
		{
			wep_ll->reflection = reflection;
			wep_ll->reflectionUnk = *(int*)(reflection + 4);

			mk_insert(reflection, wp_data_field8 + 148);

			obj_create_sobjs(reflection);
			sobj_set_priority(obj_first_sobj(reflection), 6);

		}
	}


	int glr = load_weapon((int)&gauntlet_lr, plyr_obj);

	if (glr)
	{
		wep_lr->obj = glr;
		wep_lr->objUnk = *(int*)(glr + 4);

		mk_insert(glr, wp_data_field8 + 148);

		int reflection = load_weapon_reflection((int)&gauntlet_lr, plyr_obj);
		if (reflection)
		{
			wep_lr->reflection = reflection;
			wep_lr->reflectionUnk = *(int*)(reflection + 4);

			mk_insert(reflection, wp_data_field8 + 148);

			obj_create_sobjs(reflection);
			sobj_set_priority(obj_first_sobj(reflection), 6);

		}
	}
	*/
}

void set_goro_flipped_bones()
{
	int args = *(int*)(CURRENT_ARGS);
	int bones = *(int*)(args + 4);
	int plyr_obj = *(int*)(PLAYER_OBJ);
	*(int*)(plyr_obj + 140) = bones;
}

void goro_arms_bone_copy(int object)
{
	int numBones = *(int*)(object + 76);
	int skeleton = *(int*)(object + 72);

	if (skeleton)
	{
		for (int i = 0; i < NUM_GOROMAPBONES; i++)
		{
			int srcBoneID = goro_arm_fixup_map[i].src;
			int dstBoneID = goro_arm_fixup_map[i].dest;

			if (srcBoneID < numBones && dstBoneID < numBones)
			{
				int bone_ptr = *(int*)(skeleton + (4 * srcBoneID));
				bone_data* srcBone = (bone_data*)(bone_ptr);
				if (srcBone)
				{
					bone_ptr = *(int*)(skeleton + (4 * dstBoneID));
					bone_data* dstBone = (bone_data*)(bone_ptr);

					if (dstBone)
					{
						if (*(int*)(bone_ptr + 104) != *(int*)0x5D62AC)
						{
							static float goro_interp_val = 0.89999998f;

							asm volatile ("lw      $v1,  %[x]" ::[x] "m" (goro_interp_val));
							asm volatile ("mtc1 $v1, $f12");
							((int(*)(int, int, int))0x28D350)((int)dstBone + 208, (int)dstBone + 208, (int)srcBone + 208);
							dstBone->flags |= 0x4000;

							int dstQuat = (int)dstBone + 224;
							int srcQuat = (int)dstBone + 208;

							*(int*)(dstQuat + 0) = *(int*)(srcQuat + 0);
							*(int*)(dstQuat + 4) = *(int*)(srcQuat + 4);
							*(int*)(dstQuat + 8) = *(int*)(srcQuat + 8);
							*(int*)(dstQuat + 12) = *(int*)(srcQuat + 12);

						}
					}
				}
			}
		}
	}
	
}

void goro_reset_event()
{
	goro_gauntlet_ll_p1.obj = 0;
	goro_gauntlet_ll_p1.objUnk = 0;
	goro_gauntlet_ll_p1.reflection = 0;
	goro_gauntlet_ll_p1.reflectionUnk = 0;
	goro_gauntlet_ll_p1.field16 = 0;
	goro_gauntlet_ll_p1.field20 = 0;

	goro_gauntlet_lr_p1.obj = 0;
	goro_gauntlet_lr_p1.objUnk = 0;
	goro_gauntlet_lr_p1.reflection = 0;
	goro_gauntlet_lr_p1.reflectionUnk = 0;
	goro_gauntlet_lr_p1.field16 = 0;
	goro_gauntlet_lr_p1.field20 = 0;

	goro_gauntlet_ll_p2.obj = 0;
	goro_gauntlet_ll_p2.objUnk = 0;
	goro_gauntlet_ll_p2.reflection = 0;
	goro_gauntlet_ll_p2.reflectionUnk = 0;
	goro_gauntlet_ll_p2.field16 = 0;
	goro_gauntlet_ll_p2.field20 = 0;

	goro_gauntlet_lr_p2.obj = 0;
	goro_gauntlet_lr_p2.objUnk = 0;
	goro_gauntlet_lr_p2.reflection = 0;
	goro_gauntlet_lr_p2.reflectionUnk = 0;
	goro_gauntlet_lr_p2.field16 = 0;
	goro_gauntlet_lr_p2.field20 = 0;
}
