#include "moves.h"
#include "mkdeception.h"
#include "mips.h"
#include "ps2mem.h"
#include "character.h"

// use someone else scan jump for others
#define SCAN1_UNIVERSAL_JUMP 0x2026E8
#define SCAN2_UNIVERSAL_JUMP 0x202190
#define SCAN3_UNIVERSAL_JUMP 0x201E80
#define SCAN4_UNIVERSAL_JUMP 0x2019A0

// characters for scan tables 

#include "characters/character_list.h"

int scan_table_1_jump_table[] = {
	0x2025B8,	 //		SCORPION,
	SCAN1_UNIVERSAL_JUMP,	 // 	BARAKA,
	SCAN1_UNIVERSAL_JUMP,	 // 	NOOB,
	0x202730,	 // 	SUBZERO,
	0x20278C,	 // 	MILEENA,
	0x202604,	 // 	NIGHTWOLF,
	0x20269C,	 // 	ERMAC,
	0x2026B0,	 // 	ASHRAH,
	0x2026C4,	 // 	SINDEL,
	0x202778,	 // 	LI_MEI,
	0x2027A0,	 // 	BORAICHO,
	0x202754,	 // 	HOTARU,
	0x2026FC,	 // 	KENSHI,
	SCAN1_UNIVERSAL_JUMP,	 // 	SMOKE,
	0x202674,	 // 	HAVIK,
	0x20284C,	 // 	TANYA,
	0x202814,	 // 	LIU_KANG,
	0x202814,	 // 	GHOST,-- swapped to lk
	0x202828,	 // 	KIRA,
	0x2027B4,	 // 	KABAL,
	0x2027EC,	 // 	KOBRA,
	0x202618,	 // 	JADE,
	0x2027C8,	 // 	DAIROU,
	0x202800,	 // 	RAIDEN,
	0x202688,	 // 	DARRIUS,
	0x202860,	 // 	SHUJINKO,
	0x202884,	 // 	SHUJINKO_13,
	0x20262C,	 // 	NOOBSMOKE,
	0x2025E0,	 // 	MONSTER,
	0x2028A8,	 // 	ONAGA,
	0x2028B4, //	MKDA_JAX,
	SCAN1_UNIVERSAL_JUMP, //	MKDA_RAIDEN,
	0x2028B4, //	MKDA_QUAN_CHI,
	SCAN1_UNIVERSAL_JUMP, //	MKDA_KUNG_LAO,
	0x2028B4, //  MKDA_CAGE,
	0x2028B4, //  MKDA_SONYA,
	0x2028B4, //  MKDA_NITARA,
	0x2028B4, //  MKDA_SHANG_TSUNG,
	0x2028B4, //  MKDA_FROST,
	0x2028B4, //  MKDA_KITANA,
	0x2028B4, //  MKDA_DRAHMIN,
	0x2028B4, //  MKDA_KANO,
	0x2028B4, //  MKDA_MOKAP,
	0x2028B4, //  MKDA_BLAZE,
	SCAN1_UNIVERSAL_JUMP, //  UMKD_SONYA,
	SCAN1_UNIVERSAL_JUMP, //  KITANA
	SCAN1_UNIVERSAL_JUMP, // JAX
	SCAN1_UNIVERSAL_JUMP, //  FROST
	SCAN1_UNIVERSAL_JUMP, //  BLAZE
	SCAN1_UNIVERSAL_JUMP, //  SHAOKAHN
	SCAN1_UNIVERSAL_JUMP, //  GORO
};


int scan_table_2_jump_table[] = {
	0x2021CC, //	 SCORPION,
	0x202230, // 	BARAKA,
	0x20239C, // 	NOOB,
	0x202258, // 	SUBZERO,
	0x202304, // 	MILEENA,
	0x2021B8, // 	NIGHTWOLF,
	SCAN2_UNIVERSAL_JUMP, // 	ERMAC,
	0x2021E0, // 	ASHRAH,
	0x20239C, // 	SINDEL,
	0x202244, // 	LI_MEI,
	0x2022E0, // 	BORAICHO,
	0x20217C, // 	HOTARU,
	0x20226C, // 	KENSHI,
	0x20239C, // 	SMOKE,
	0x202208, // 	HAVIK,
	0x202368, // 	TANYA,
	0x2021A4, // 	LIU_KANG,
	0x2021A4, // 	GHOST, -- swapped to lk
	0x20239C, // 	KIRA,
	0x202318, // 	KABAL,
	0x202340, // 	KOBRA,
	0x20237C, // 	JADE,
	0x20232C, // 	DAIROU,
	0x202354, // 	RAIDEN,
	0x20221C, // 	DARRIUS,
	0x202280, // 	SHUJINKO,
	0x202294, // 	SHUJINKO_13,
	0x2022A8, // 	NOOBSMOKE,
	0x2021F4, // 	MONSTER,
	0x202390, // 	ONAGA,
	0x20239C, //	MKDA_JAX,
	SCAN2_UNIVERSAL_JUMP, //	MKDA_RAIDEN,
	0x20239C, //	MKDA_QUAN_CHI,
	0x20239C, //	MKDA_KUNG_LAO,
	0x20239C, //  MKDA_CAGE,
	0x20239C, //  MKDA_SONYA,
	0x20239C, //  MKDA_NITARA,
	0x20239C, //  MKDA_SHANG_TSUNG,
	0x20239C, //  MKDA_FROST,
	0x20239C, //  MKDA_KITANA,
	0x20239C, //  MKDA_DRAHMIN,
	0x20239C, //  MKDA_KANO,
	0x20239C, //  MKDA_MOKAP,
	0x20239C, //  MKDA_BLAZE,
	SCAN2_UNIVERSAL_JUMP, //  UMKD_SONYA,
	SCAN2_UNIVERSAL_JUMP, //  KITANA
	SCAN2_UNIVERSAL_JUMP, //  JAX
	0x20239C, //  FROST
	SCAN2_UNIVERSAL_JUMP, //  BLAZE
	SCAN2_UNIVERSAL_JUMP, //  SHAOKAHN
	SCAN2_UNIVERSAL_JUMP, //  GORO
};

int scan_table_3_jump_table[] = {
	0x201DE0, //    SCORPION,
	0x201D94, // 	BARAKA,
	0x201F64, // 	NOOB,
	0x201DBC, // 	SUBZERO,
	0x201ED0, // 	MILEENA,
	0x201F64, // 	NIGHTWOLF,
	0x201D6C, // 	ERMAC,
	SCAN3_UNIVERSAL_JUMP, // 	ASHRAH,
	0x201D80, // 	SINDEL,
	0x201E44, // 	LI_MEI,
	0x201E6C, // 	BORAICHO,
	0x201F64, // 	HOTARU,
	0x201E58, // 	KENSHI,
	0x201F64, // 	SMOKE,
	0x201E1C, // 	HAVIK,
	0x201EE4, // 	TANYA,
	0x201F1C, // 	LIU_KANG,
	0x201F1C, // 	GHOST, -- swapped to lk
	0x201EBC, // 	KIRA,
	0x201E08, // 	KABAL,
	0x201F64, // 	KOBRA,
	0x201F08, // 	JADE,
	0x201E94, // 	DAIROU,
	0x201EA8, // 	RAIDEN,
	0x201E30, // 	DARRIUS,
	0x201F44, // 	SHUJINKO,
	0x201F58, // 	SHUJINKO_13,
	0x201DA8, // 	NOOBSMOKE,
	0x201DF4, // 	MONSTER,
	0x201F30, // 	ONAGA,
	0x201F64, //	MKDA_JAX,
	SCAN3_UNIVERSAL_JUMP, //	MKDA_RAIDEN,
	0x201F64, //	MKDA_QUAN_CHI,
	0x201F64, //	MKDA_KUNG_LAO,
	0x201F64, //  MKDA_CAGE,
	0x201F64, //  MKDA_SONYA,
	0x201F64, //  MKDA_NITARA,
	0x201F64, //  MKDA_SHANG_TSUNG,
	0x201F64, //  MKDA_FROST,
	0x201F64, //  MKDA_KITANA,
	0x201F64, //  MKDA_DRAHMIN,
	0x201F64, //  MKDA_KANO,
	0x201F64, //  MKDA_MOKAP,
	0x201F64, //  MKDA_BLAZE,
	SCAN3_UNIVERSAL_JUMP, //  UMKD_SONYA,
	SCAN3_UNIVERSAL_JUMP, //  KITANA
	SCAN3_UNIVERSAL_JUMP, //  JAX
	SCAN3_UNIVERSAL_JUMP, //  FROST
	SCAN3_UNIVERSAL_JUMP, //  BLAZE
	SCAN3_UNIVERSAL_JUMP, //  SHAOKAHN
	SCAN3_UNIVERSAL_JUMP, //  GORO
};

int scan_table_4_jump_table[] = {
	0x201B0C,	  //	SCORPION,
	0x201B0C,	  //	BARAKA,
	0x201B0C,	  //	NOOB,
	0x2019A0, //	SUBZERO,
	0x201928, //	MILEENA,
	0x201900, //	NIGHTWOLF,
	0x2018A8, //	ERMAC,
	0x20193C, //	ASHRAH,
	0x201B0C, //	SINDEL,
	0x201978, //	LI_MEI,
	0x2019B4, //	BORAICHO,
	0x201950, //	HOTARU,
	0x20198C, //	KENSHI,
	SCAN4_UNIVERSAL_JUMP, //	SMOKE,
	0x201914, //	HAVIK,
	0x201A84, //	TANYA,
	0x201A98, //	LIU_KANG,
	0x201A98, //	GHOST, -- swapped to lk
	0x201A24, //	KIRA,
	0x2019C8, //	KABAL,
	0x2019FC, //	KOBRA,
	0x201A70, //	JADE,
	0x201B0C, //	DAIROU,
	0x201A10, //	RAIDEN,
	0x201964, //	DARRIUS,
	0x201AAC, //	SHUJINKO,
	0x201AE0, //	SHUJINKO_13,
	0x201A38, //	NOOBSMOKE,
	0x2018DC, //	MONSTER,
	0x201B0C, //	ONAGA,
	0x201B0C, //	MKDA_JAX,
	SCAN4_UNIVERSAL_JUMP, //	MKDA_RAIDEN,
	0x201B0C, //	MKDA_QUAN_CHI,
	0x2018EC, //	MKDA_KUNG_LAO,
	0x201B0C, //  MKDA_CAGE,
	0x201B0C, //  MKDA_SONYA,
	0x201B0C, //  MKDA_NITARA,
	0x201B0C, //  MKDA_SHANG_TSUNG,
	0x201B0C, //  MKDA_FROST,
	0x201B0C, //  MKDA_KITANA,
	0x201B0C, //  MKDA_DRAHMIN,
	0x201B0C, //  MKDA_KANO,
	0x201B0C, //  MKDA_MOKAP,
	0x201B0C, //  MKDA_BLAZE,
	0x201B0C, //  UMKD_SONYA,
	0x201B0C, //  KITANA,
	SCAN4_UNIVERSAL_JUMP, //	JAX
	SCAN4_UNIVERSAL_JUMP, //	FROST
	0x201B0C, // BLAZE
	0x201B0C, // SHAOKAHN
	0x201B0C, // GORO
};


void init_moves_hook()
{
	makeJal(0x202574, swap_scan_table_1);
	makeJal(0x202138, swap_scan_table_2);
	makeJal(0x201D28, swap_scan_table_3);
	makeJal(0x201860, swap_scan_table_4);
	makeJal(0x20C4DC, do_harakiri_hook);


	// SCAN 1 ([])
	short scan_1_size = sizeof(scan_table_1_jump_table) / sizeof(int);
	patchShort(0x202594, scan_1_size);

	static int scan_1_table_ptr = (int)&scan_table_1_jump_table[0];

	patchInt(0x20259C, lui(v1, HIWORD(scan_1_table_ptr)));
	patchInt(0x2025A4, ori(v1, v1, LOWORD(scan_1_table_ptr)));

	// SCAN 2 (/\)
	short scan_2_size = sizeof(scan_table_2_jump_table) / sizeof(int);
	patchShort(0x202158, scan_2_size);

	static int scan_2_table_ptr = (int)&scan_table_2_jump_table[0];

	patchInt(0x202160, lui(v1, HIWORD(scan_2_table_ptr)));
	patchInt(0x202168, ori(v1, v1, LOWORD(scan_2_table_ptr)));


	// SCAN 3 (X)
	short scan_3_size = sizeof(scan_table_3_jump_table) / sizeof(int);
	patchShort(0x201D48, scan_3_size);

	static int scan_3_table_ptr = (int)&scan_table_3_jump_table[0];

	patchInt(0x201D50, lui(v1, HIWORD(scan_3_table_ptr)));
	patchInt(0x201D58, ori(v1, v1, LOWORD(scan_3_table_ptr)));

	// SCAN 4 (o)

	short scan_4_size = sizeof(scan_table_4_jump_table) / sizeof(int);
	patchShort(0x201880, 0);
	patchShort(0x201884, scan_4_size);

	static int scan_4_table_ptr = (int)&scan_table_4_jump_table[0];

	patchInt(0x20188C, lui(v1, HIWORD(scan_4_table_ptr)));
	patchInt(0x201894, ori(v1, v1, LOWORD(scan_4_table_ptr)));

}


#pragma GCC push_options
#pragma GCC optimize ("O3")

int swap_scan_table_1()
{
	player_data* plyr_data = *(player_data**)(PLAYER_DATA);
	int p2_pdata = *(int*)(P2_PLAYER_DATA);
	static int scan_action_set = (int)&scan_null;
	if (plyr_data)
	{
		switch (plyr_data->characterID)
		{
		case BARAKA:
			scan_action_set = (int)&scan_baraka_1;
			break;
		case SMOKE:
			scan_action_set = (int)&scan_smoke_1;
			break;
		case NOOB:
			scan_action_set = (int)&scan_noob_1;
			break;
		case MKDA_KUNG_LAO:
			scan_action_set = (int)&scan_mkda_kung_lao_1;
			break;
		case MKDA_RAIDEN:
			scan_action_set = (int)&scan_mkda_raiden_1;
			break;
		case SONYA:
			if (*(int*)(p2_pdata + 544) < 2)
				scan_action_set = (int)&scan_sonya_1;
			else
				scan_action_set = (int)&scan_null;
			break;
		case KITANA:
			if ((*(int*)(p2_pdata + 532) & 0x400) == 0)
				scan_action_set = (int)&scan_kitana_1;
			else
				scan_action_set = (int)&scan_null;
			break;
		case JAX:
			scan_action_set = (int)&scan_jax_1;
			break;
		case FROST:
			scan_action_set = (int)&scan_frost_1;
			break;
		case BLAZE:
			scan_action_set = (int)&scan_blaze_1;
			break;
		case SHAO_KAHN:
			scan_action_set = (int)&scan_sk_1;
			break;
		case GORO:
			scan_action_set = (int)&scan_goro_1;
			break;
		default:
			scan_action_set = (int)&scan_null;
			break;
		}
		patchInt(0x2026E8, lui(a0, HIWORD(scan_action_set)));
		patchInt(0x2026F0, ori(a0, a0, LOWORD(scan_action_set)));

	}
	
	return my_joypad_state_5();
}

int swap_scan_table_2()
{
	player_data* plyr_data = *(player_data**)(PLAYER_DATA);
	static int scan_action_set = (int)&scan_null;
	if (plyr_data)
	{
		switch (plyr_data->characterID)
		{
		case ERMAC:
			scan_action_set = (int)&scan_ermac_2;
			break;
		case SONYA:
			scan_action_set = (int)&scan_sonya_2;
			break;
		case MKDA_RAIDEN:
			scan_action_set = (int)&scan_mkda_raiden_2;
			break;
		case KITANA:
			scan_action_set = (int)&scan_kitana_2;
			break;
		case JAX:
			scan_action_set = (int)&scan_jax_2;
			break;
		case BLAZE:
			scan_action_set = (int)&scan_blaze_2;
			break;
		case SHAO_KAHN:
			scan_action_set = (int)&scan_sk_2;
			break;
		case GORO:
			scan_action_set = (int)&scan_goro_2;
			break;
		default:
			scan_action_set = (int)&scan_null;
			break;
		}
	}

	patchInt(0x202190, lui(a0, HIWORD(scan_action_set)));
	patchInt(0x202198, ori(a0, a0, LOWORD(scan_action_set)));

	return my_joypad_state_5();
}

int swap_scan_table_3()
{
	player_data* plyr_data = *(player_data**)(PLAYER_DATA);
	int p2_pdata = *(int*)(P2_PLAYER_DATA);
	static int scan_action_set = (int)&scan_null;

	if (plyr_data)
	{
		switch (plyr_data->characterID)
		{
		case ASHRAH:
			scan_action_set = (int)&scan_ashrah_3;
			break;
		case MKDA_RAIDEN:
			scan_action_set = (int)&scan_mkda_raiden_3;
			break;
		case SONYA:
			scan_action_set = (int)&scan_sonya_3;
			break;
		case KITANA:
			scan_action_set = (int)&scan_kitana_3;
			break;
		case JAX:
			scan_action_set = (int)&scan_jax_3;
			break;
		case FROST:
			if ((*(int*)(p2_pdata + 532) & 0x400) == 0)
				scan_action_set = (int)&scan_frost_3;
			else
				scan_action_set = (int)&scan_null;
			break;
		case BLAZE:
			scan_action_set = (int)&scan_blaze_3;
			break;
		case SHAO_KAHN:
			scan_action_set = (int)&scan_sk_3;
			break;
		case GORO:
			if ((*(int*)(p2_pdata + 532) & 0x400) == 0)
				scan_action_set = (int)&scan_goro_3;
			else
				scan_action_set = (int)&scan_null;
			break;
		default:
			scan_action_set = (int)&scan_null;
			break;
		}
	}

	patchInt(0x201E80, lui(a0, HIWORD(scan_action_set)));
	patchInt(0x201E88, ori(a0, a0, LOWORD(scan_action_set)));

	return my_joypad_state_5();
}

int swap_scan_table_4()
{
	player_data* plyr_data = *(player_data**)(PLAYER_DATA);
	static int scan_action_set = (int)&scan_null;

	if (plyr_data)
	{
		switch (plyr_data->characterID)
		{
		case SUBZERO:
			scan_action_set = (int)&scan_subzero_4;
			break;
		case SMOKE:
			scan_action_set = (int)&scan_smoke_4;
			break;
		case MKDA_RAIDEN:
			scan_action_set = (int)&scan_mkda_raiden_4;
			break;
		case JAX:
			scan_action_set = (int)&scan_jax_4;
			break;
		case FROST:
			scan_action_set = (int)&scan_frost_4;
			break;
		default:
			scan_action_set = (int)&scan_null;
			break;
		}
		patchInt(0x2019A0, lui(a0, HIWORD(scan_action_set)));
		patchInt(0x2019A8, ori(a0, a0, LOWORD(scan_action_set)));

	}
	
	return my_joypad_state_5();
}
#pragma GCC pop_options

void do_harakiri_hook()
{
	player_data* plyr_data = *(player_data**)(PLAYER_DATA);

	int chrID = plyr_data->characterID;
	if (chrID == SHAO_KAHN)
	{
		if (was_button_pressed(PAD_SQUARE))
			scan_switch_sequences((int*)&scan_sk_suicide);
	}
	else if (chrID == GORO)
	{
		if (was_button_pressed(PAD_CIRCLE))
			scan_switch_sequences((int*)&scan_goro_suicide);
	}
	else
		((void(*)())0x20C710)();
}

#ifndef PS2_BUILD
void dump_scan_table_1()
{
	int select_addr = 0x595AD0;

	for (int i = 0; i < 30; i++)
	{
		int jmp = *(int*)(select_addr + (sizeof(int) * i));
		_printf("0x%X,\n", jmp);
	}
}

void dump_scan_table_2()
{
	int select_addr = 0x595A50;

	for (int i = 0; i < 30; i++)
	{
		int jmp = *(int*)(select_addr + (sizeof(int) * i));
		_printf("0x%X,\n", jmp);
	}
}

void dump_scan_table_3()
{
	int select_addr = 0x5959D0;

	for (int i = 0; i < 30; i++)
	{
		int jmp = *(int*)(select_addr + (sizeof(int) * i));
		_printf("0x%X,\n", jmp);
	}
}

void dump_scan_table_4()
{
	int select_addr = 0x595944;

	for (int i = 0; i < 31 + 3; i++)
	{
		int jmp = *(int*)(select_addr + (sizeof(int) * i));
		_printf("0x%X,\n", jmp);
	}
}
#endif