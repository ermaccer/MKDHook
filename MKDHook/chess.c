#include "chess.h"
#include "mkdeception.h"
#include "ps2mem.h"
#include "character.h"
#include "mips.h"

struct mk_file_entry chess_entry_table[CHESS_FILES] = {
	{"mk_chess.ssf"	,0, 4},

	{"mk_chess.sec",0,1},
	{"mkc_hotaru.sec",0,1},
	{"mkc_mileena.sec",0,1},
	{"mkc_nightwolf.sec",0,1},
	{"mkc_boraicho.sec",0,1},
	{"mkc_baraka.sec",0,1},
	{"mkc_scorpion.sec",0,1},
	{"mkc_subzero.sec",0,1},
	{"mkc_ermac.sec",0,1},
	{"mkc_kenshi.sec",0,1},
	{"mkc_sindel.sec",0,1},
	{"mkc_ashrah.sec",0,1},
	{"mkc_limei.sec",0,1},
	{"mkc_skab.sec",0,1},
	{"mkc_tanya.sec",0,1},
	{"mkc_liukang.sec",0,1},
	{"mkc_kira.sec",0,1},
	{"mkc_kabal.sec",0,1},
	{"mkc_kobra.sec",0,1},
	{"mkc_jade.sec",0,1},
	{"mkc_dairou.sec",0,1},
	{"mkc_raiden.sec",0,1},
	{"mkc_cassius.sec",0,1},
	{"mkc_noobsmoke.sec",0,1},
	{"mkc_shujinko.sec",0,1},
	{"mkc_shaokhan.sec",0,1},
	{"mkc_goro.sec",0,1},
	{"mkc_jax.sec",0,1},
	{"mkc_frost.sec",0,1},
	{"mkc_kitana.sec",0,1},
	{"mkc_blaze.sec",0,1},
	{"mkc_sonya.sec",0,1},
	{"mkc_drahmin.sec",0,1},
	{"mkc_sareena.sec",0,1},
	{"mkc_quan.sec",0,1},
	{"mkc_shang.sec",0,1},
	{"mkc_kung.sec",0,1},
	{"mkc_cage.sec",0,1},
	{"mkc_sektor.sec",0,1},
	{"mkc_rain.sec",0,1},
	{"mkc_nitara.sec",0,1},
	{"board_game_config.mko",0,3},
	{"boardgame_fx.mko",0,3},
	{"boardgame_strings_eng.mko",0,3},
	{"boardgame_strings_spa.mko",0,3},
	{"boardgame_strings_ger.mko",0,3},
	{"boardgame_strings_fre.mko",0,3},
	{"boardgame_strings_ita.mko",0,3},
	{"boardgame_strings_eng_uk.mko",0,3},
	{"mk_chess_anims.sec",0,2},

};

// I:\ps2dvd\art\mk_chess.ssf
struct mk_toc_entry chess_file_table[CHESS_FILES + 1] = {
		{&chess_entry_table[0]	,0,0 },

		{&chess_entry_table[1], 0,  835200},    //	mk_chess.sec
		{&chess_entry_table[2], 0,  132736},    //	mkc_hotaru.sec
		{&chess_entry_table[3], 0,  116480},    //	mkc_mileena.sec
		{&chess_entry_table[4], 0,  125696},    //	mkc_nightwolf.sec
		{&chess_entry_table[5], 0,  143616},    //	mkc_boraicho.sec
		{&chess_entry_table[6], 0,  137600},    //	mkc_baraka.sec
		{&chess_entry_table[7], 0,  140032},    //	mkc_scorpion.sec
		{&chess_entry_table[8], 0,  120192},    //	mkc_subzero.sec
		{&chess_entry_table[9], 0,  112512},    //	mkc_ermac.sec
		{&chess_entry_table[10], 0, 118528},    //	mkc_kenshi.sec
		{&chess_entry_table[11], 0, 122240},    //	mkc_sindel.sec
		{&chess_entry_table[12], 0, 139264},    //	mkc_ashrah.sec
		{&chess_entry_table[13], 0, 141440},    //	mkc_limei.sec
		{&chess_entry_table[14], 0, 145664},    //	mkc_skab.sec
		{&chess_entry_table[15], 0, 133120},    //	mkc_tanya.sec
		{&chess_entry_table[16], 0, 123008},    //	mkc_liukang.sec
		{&chess_entry_table[17], 0, 132352},    //	mkc_kira.sec
		{&chess_entry_table[18], 0, 137728},    //	mkc_kabal.sec
		{&chess_entry_table[19], 0, 125312},    //	mkc_kobra.sec
		{&chess_entry_table[20], 0, 126720},    //	mkc_jade.sec
		{&chess_entry_table[21], 0, 139904},    //	mkc_dairou.sec
		{&chess_entry_table[22], 0, 157440},    //	mkc_raiden.sec
		{&chess_entry_table[23], 0, 119168},    //	mkc_cassius.sec
		{&chess_entry_table[24], 0, 124288},    //	mkc_noobsmoke.sec
		{&chess_entry_table[25], 0, 137728},    //	mkc_shujinko.sec
		{&chess_entry_table[26], 0, 146688},    //	mkc_shaokhan.sec
		{&chess_entry_table[27], 0, 125312},    //	mkc_goro.sec
		{&chess_entry_table[28], 0, 121216},    //	mkc_jax.sec
		{&chess_entry_table[29], 0, 116480},    //	mkc_frost.sec
		{&chess_entry_table[30], 0, 113408},    //	mkc_kitana.sec
		{&chess_entry_table[31], 0, 109056},    //	mkc_blaze.sec
		{&chess_entry_table[32], 0, 124544},    //	mkc_sonya.sec
		{&chess_entry_table[33], 0, 118528},    //	mkc_drahmin.sec
		{&chess_entry_table[34], 0, 121344},    //	mkc_sareena.sec
		{&chess_entry_table[35], 0, 118016},    //	mkc_quan.sec
		{&chess_entry_table[36], 0, 128512},    //	mkc_shang.sec
		{&chess_entry_table[37], 0, 127104},    //	mkc_kung.sec
		{&chess_entry_table[38], 0, 126848},    //	mkc_cage.sec
		{&chess_entry_table[39], 0, 146688},    //	mkc_sektor.sec
		{&chess_entry_table[40], 0, 113408},    //	mkc_rain.sec
		{&chess_entry_table[41], 0, 135168},    //	mkc_nitara.sec
		{&chess_entry_table[42], 0, 32832 },    //	board_game_config.mko
		{&chess_entry_table[43], 0, 22152 },    //	boardgame_fx.mko
		{&chess_entry_table[44], 0, 1628  },    //	boardgame_strings_eng.mko
		{&chess_entry_table[45], 0, 1792  },    //	boardgame_strings_spa.mko
		{&chess_entry_table[46], 0, 1604  },    //	boardgame_strings_ger.mko
		{&chess_entry_table[47], 0, 1732  },    //	boardgame_strings_fre.mko
		{&chess_entry_table[48], 0, 1716  },    //	boardgame_strings_ita.mko
		{&chess_entry_table[49], 0, 1628  },    //	boardgame_strings_eng_uk.mko
		{&chess_entry_table[50], 0, 354432},    //	mk_chess_anims.sec


		{0,0,0}
};


static int chess_characters[CHESS_PIECES] = {
	SCORPION, BARAKA, SUBZERO, MILEENA, NIGHTWOLF, ERMAC, 
	ASHRAH, SINDEL, LI_MEI, BORAICHO, HOTARU, KENSHI, HAVIK, 
	TANYA, LIU_KANG, KIRA, KABAL, KOBRA, JADE, DAIROU, 
	RAIDEN, DARRIUS, SHUJINKO, NOOBSMOKE, SHAO_KAHN, GORO,
	FROST, KITANA, JAX, BLAZE, SONYA, DRAHMIN, SAREENA, QUAN_CHI,
	SHANG_TSUNG, KUNG_LAO, CAGE, SEKTOR, RAIN, NITARA
};

void init_chess_hook()
{
	makeJal(0x382EE0, load_new_chess);
	makeJal(0x383B1C, load_new_chess);

	patchShort(0x384E3C, CHESS_PIECES);
	patchShort(0x385704, CHESS_PIECES);


	patchShort(0x382698, CHESS_PIECES);
	patchShort(0x382734, CHESS_PIECES);

	patchShort(0x382840, CHESS_PIECES);
	patchShort(0x3828DC, CHESS_PIECES);

	int val;
	val = (int)&chess_characters[0];

	patchInt(0x3826AC, lui(v0, HIWORD(val)));
	patchInt(0x3826B4, ori(v0, v0, LOWORD(val)));

	patchInt(0x38270C, lui(a1, HIWORD(val)));
	patchInt(0x382714, ori(a1, a1, LOWORD(val)));

	patchInt(0x382854, lui(v0, HIWORD(val)));
	patchInt(0x38285C, ori(v0, v0, LOWORD(val)));

	patchInt(0x3828B4, lui(a1, HIWORD(val)));
	patchInt(0x3828BC, ori(a1, a1, LOWORD(val)));


	int baseSize = 2048;
	for (int i = 0; i < CHESS_FILES; i++)
	{
		chess_entry_table[i].belong = &chess_file_table[0];
	}


	for (int i = 1; i < CHESS_FILES; i++)
	{
		chess_file_table[i].previousSize = baseSize;
		baseSize += (chess_file_table[i].size + 2048 - 1) & -2048;
	}


}

void load_new_chess()
{
	load_ssf(&chess_file_table[0]);
}
