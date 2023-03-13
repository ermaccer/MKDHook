#include "pselect.h"
#include "..\mkdeception.h"
#include "..\ps2mem.h"


struct mk_file_entry pselect_entry_table[PSELECT_FILES] = {
	{"pselect.ssf"	,0, 4},
	{"pselect_art.sec"	,0, 1},
	{"bg_pselect_art.sec"	,0, 1}, // bg - board game
	{"pz_pselect_art.sec"	,0, 1},
	{"body_ashrah_alt.sec"	,0, 1},
	{"body_baraka_alt.sec"	,0, 1},
	{"body_boraicho_alt.sec"	,0, 1},
	{"body_dairou_alt.sec"	,0, 1},
	{"body_darrius_alt.sec"	,0, 1},
	{"body_ermac_alt.sec"	,0, 1},
	{"body_havik_alt.sec"	,0, 1},
	{"body_hotaru_alt.sec"	,0, 1},
	{"body_jade_alt.sec"	,0, 1},
	{"body_kabal_alt.sec"	,0, 1},
	{"body_kenshi_alt.sec"	,0, 1},
	{"body_kira_alt.sec"	,0, 1},
	{"body_kobra_alt.sec"	,0, 1},
	{"body_limei_alt.sec"	,0, 1},
	{"body_liukang_alt.sec"	,0, 1},
	{"body_mileena_alt.sec"	,0, 1},
	{"body_nightwolf_alt.sec"	,0, 1},
	{"body_raiden_alt.sec"	,0, 1},
	{"body_scorpion_alt.sec"	,0, 1},
	{"body_shujinko_alt.sec"	,0, 1},
	{"body_sindel_alt.sec"	,0, 1},
	{"body_smokenoob_alt.sec"	,0, 1},
	{"body_subzero_alt.sec"	,0, 1},
	{"body_tanya_alt.sec"	,0, 1},
	{"body_sonya_alt.sec"	,0, 1},
	{"body_kitana_alt.sec"	,0, 1},
	{"body_jax_alt.sec"	,0, 1},
};

// I:\ps2dvd\art\pselect.ssf
struct mk_toc_entry pselect_file_table[PSELECT_FILES + 1] = {
		{&pselect_entry_table[0]	,0,0 },

		{&pselect_entry_table[1]	,0,3603456}, // pselect
		{&pselect_entry_table[2]	,0,1514624}, // bg
		{&pselect_entry_table[3]	,0,1528960},  // pz
		// ALT RENDERS
		{&pselect_entry_table[4]	,0,67456},  // ALT
		{&pselect_entry_table[5]	,0,67456},  // ALT
		{&pselect_entry_table[6]	,0,67456},  // ALT
		{&pselect_entry_table[7]	,0,67456},  // ALT
		{&pselect_entry_table[8]	,0,67456},  // ALT
		{&pselect_entry_table[9]	,0,67456},  // ALT
		{&pselect_entry_table[10]	,0,67456},  // ALT
		{&pselect_entry_table[11]	,0,67456},  // ALT
		{&pselect_entry_table[12]	,0,67456},  // ALT
		{&pselect_entry_table[13]	,0,67456},  // ALT
		{&pselect_entry_table[14]	,0,67456},  // ALT
		{&pselect_entry_table[15]	,0,67456},  // ALT
		{&pselect_entry_table[16]	,0,67456},  // ALT
		{&pselect_entry_table[17]	,0,67456},  // ALT
		{&pselect_entry_table[18]	,0,67456},  // ALT
		{&pselect_entry_table[19]	,0,67456},  // ALT
		{&pselect_entry_table[20]	,0,67456},  // ALT
		{&pselect_entry_table[21]	,0,67456},  // ALT
		{&pselect_entry_table[22]	,0,67456},  // ALT
		{&pselect_entry_table[23]	,0,67456},  // ALT
		{&pselect_entry_table[24]	,0,67456},  // ALT
		{&pselect_entry_table[25]	,0,67456},  // ALT
		{&pselect_entry_table[26]	,0,67456},  // ALT
		{&pselect_entry_table[27]	,0,67456},  // ALT
		{&pselect_entry_table[28]	,0,67456},  // sonya_alt
		{&pselect_entry_table[29]	,0,67456},  // KITANA_alt
		{&pselect_entry_table[30]	,0,67456},  // jax_alt
		{0,0,0}
};

void init_pselect_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < PSELECT_FILES; i++)
	{
		pselect_entry_table[i].belong = &pselect_file_table[0];
	}


	for (int i = 1; i < PSELECT_FILES; i++)
	{
		pselect_file_table[i].previousSize = baseSize;
		baseSize += (pselect_file_table[i].size + 2048 - 1) & -2048;
	}
}

void init_pselect_hook()
{
	init_pselect_toc();

	makeJal(0x194554, load_new_pselect);
	makeJal(0x1950F4, load_new_pselect);
	makeJal(0x195514, load_new_pselect);
	makeJal(0x195A74, load_new_pselect);
}

void load_new_pselect()
{
	load_ssf(&pselect_file_table[0]);
}
