#include "character.h"
#include "mkdeception.h"

#include <stdio.h>
#include "ps2mem.h"
#include "mips.h"
// characters
#include "characters/character_list.h"

struct char_info_entry pCharTable[TOTAL_CHARACTERS] = {
	{"SCORPION"	, 0x5A1900	, 0x5A1A70	,"scorpion.mko"},
	{"BARAKA"	, 0x59B440	, 0x59B5B0	,"baraka.mko"},
	{"NOOB"	, 0x5A1040	, 0x5A1130	,"noob.mko"},
	{"SUB-ZERO"	, 0x5A2C60	, 0x5A2DD0	,"subzero.mko"},
	{"MILEENA"	, 0x59F050	, 0x59F1C0	,"mileena.mko"},
	{"NIGHTWOLF"	, 0x5A0CF0	, 0x5A0E80	,"nightwolf.mko"},
	{"ERMAC"	, 0x59C730	, 0x59C8B0	,"ermac.mko"},
	{"ASHRAH"	, 0x59AFE0	, 0x59B150	,"ashrah.mko"},
	{"SINDEL"	, 0x5A2220	, 0x5A2390	,"sindel.mko"},
	{"LI MEI"	, 0x59E820	, 0x59E6B0	,"limei.mko"},
	{"BO' RAI CHO"	, 0x59B870	, 0x59BA00	,"boraicho.mko"},
	{"HOTARU"	, 0x59CDE0	, 0x59CF50	,"hotaru.mko"},
	{"KENSHI"	, 0x59DA60	, 0x59DBD0	,"kenshi.mko"},
	{"SMOKE"	, 0x5A2890	, 0x5A29C0	,"smoke.mko"},
	{"HAVIK"	, 0x5A2590	, 0x5A26F0	,"skab.mko"},
	{"TANYA"	, 0x5A3050	, 0x5A31C0	,"tanya.mko"},
	{"LIU KANG"	, 0x59EC50	, 0x59EAE0	,"liukang.mko"},
	{"GHOST"	, 0x59EDE0	, 0x59EDE0	,"liukang_ghost.mko"},
	{"KIRA"	, 0x59DE60	, 0x59DFC0	,"kira.mko"},
	{"KABAL"	, 0x59D630	, 0x59D7A0	,"kabal.mko"},
	{"KOBRA"	, 0x59E270	, 0x59E3E0	,"kobra.mko"},
	{"JADE"	, 0x59D220	, 0x59D380	,"jade.mko"},
	{"DAIROU"	, 0x59C130	, 0x59C2A0	,"dairou.mko"},
	{"RAIDEN"	, 0x5A15D0	, 0x5A1740	,"raiden.mko"},
	{"DARRIUS"	, 0x59BCE0	, 0x59BE50	,"cassius.mko"},
	{"SHUJINKO"	, 0x5A1C90	, 0x5A1E20	,"shujinko.mko"},
	{"SHUJINKO"	, 0x5A1FB0	, 0x5A1FB0	,"shujinko_13.mko"},
	{"NOOB - SMOKE"	, 0x5A1490	, 0x5A1320	,"noobsmoke.mko"},
	{"MONSTER"	, 0x59CB40	, 0x59CB40	,"freak.mko"},
	{"ONAGA"	, (int)&dragonking_file_table	,(int)&dragonking_file_table	,"dragonking.mko"},
	{"JAX"	, 0x59FAA0	, 0x59FC10	,"mkda_jax.mko"},
	{"RAIDEN"	, 0x5A0700	, 0x5A0700	,"mkda_rayden.mko"},
	{"QUAN CHI"	, 0x5A0460	, 0x5A0460	,"mkda_quanchi.mko"},
	{"KUNG LAO"	, 0x5A00E0	, 0x5A00E0	,"mkda_kunglao.mko"},
	{"JOHNNY CAGE"	, 0x59F510	, 0x59F510	,"mkda_cage.mko"},
	{"SONYA"	, 0x5A0A50	, 0x5A0A50	,"mkda_sonya.mko"},
	{"NITARA"	, 0x5A0260	, 0x5A0260	,"mkda_nitara.mko"},
	{"SHANG TSUNG"	, 0x5A08C0	, 0x5A08C0	,"mkda_shang.mko"},
	{"FROST"	, 0x59F8D0	, 0x59F8D0	,"mkda_frost.mko"},
	{"KITANA"	, 0x59FE30	, 0x59FE30	,"mkda_kitana.mko"},
	{"DRAHMIN"	, 0x59F710	, 0x59F710	,"mkda_drahmin.mko"},
	{"KANO"	, (int)&mkda_kano_file_table	, (int)&mkda_kano_file_table		,"mkda_kano.mko"},
	{"MOKAP"	, (int)&mkda_mokap_file_table	, (int)&mkda_mokap_file_table		,"mkda_mokap.mko"},
	{"BLAZE"	, (int)&mkda_blaze_file_table	, (int)&mkda_blaze_file_table		,"mkda_blaze.mko"},
	// new
	{"SONYA"	,(int)&sonya_file_table	, (int)&sonya_alt_file_table	,"kira.mko"},
	// mku
	{"KITANA"	, (int)&kitana_file_table	, (int)&kitana_alt_file_table	,"kitana.mko"},
	{"JAX"	,	  (int)&jax_file_table	,	  (int)&jax_alt_file_table	,    "jax.mko"},
	{"FROST"	, (int)&frost_file_table	,	  (int)&frost_alt_file_table	,    "frost.mko"},
	{"BLAZE"	, (int)&blaze_file_table	, (int)&blaze_alt_file_table		,"blaze.mko"},
	{"SHAO KAHN"	, (int)&sk_file_table	, (int)&sk_alt_file_table	,"shaokahn.mko"},
	{"GORO"	, (int)&goro_file_table	, (int)&goro_alt_file_table	,"goro.mko"},
	// new
	{"DRAHMIN"	,(int)&drahmin_file_table	, (int)&drahmin_alt_file_table	,"drahmin.mko"},
	{"SAREENA"	,(int)&sareena_file_table	, (int)&sareena_alt_file_table	,"sareena.mko"},
	{"QUAN CHI"	,(int)&quan_file_table	, (int)&quan_alt_file_table	,"quan.mko"},
	{"SHANG TSUNG"	, (int)&shang_file_table	, (int)&shang_alt_file_table	,"shangtsung.mko"},
	{"KUNG LAO"	, (int)&kunglao_file_table	, (int)&kunglao_alt_file_table	,"kunglao.mko"},
	{"CAGE"	, (int)&cage_file_table	, (int)&cage_alt_file_table	,"cage.mko"},
	{"SEKTOR"	, (int)&sektor_file_table	, (int)&sektor_alt_file_table	,"sektor.mko"},
	{"RAIN"	, (int)&rain_file_table	, (int)&rain_alt_file_table	,"rain.mko"},
	{"NITARA"	, (int)&nitara_file_table	, (int)&nitara_alt_file_table	,"nitara.mko"},
	{"TREMOR"	, (int)&tremor_file_table	, (int)&tremor_file_table	,"tremor.mko"},
	{"CYRAX"	, (int)&cyrax_file_table	, (int)&cyrax_alt_file_table	,"cyrax.mko"},
	{"REIKO"	, (int)&reiko_file_table	, (int)&reiko_alt_file_table	,"reiko.mko"},
	{"RAIN"	, (int)&rain2_file_table	, (int)&rain2_file_table	,"rain.mko"},
	{"SCORPION"	, (int)&scorpion2_file_table	, (int)&scorpion2_file_table	,"scorpion.mko"},
	{"SUB-ZERO"	, (int)&subzero2_file_table	, (int)&subzero2_alt_file_table	,"subzero.mko"},
	{"ERMAC"	, (int)&ermac2_file_table	, (int)&ermac2_file_table	,"ermac.mko"},
	{"RAIDEN"	, (int)&raiden2_file_table	, (int)&raiden2_file_table	,"raiden.mko"},
};


// TODO: figure out what those floats do
character_timers pTimerTable[CHARACTER_TIMERS + 1] = {
	{ASHRAH, 825.0, 400.0, 350.0, 120.0, 60.0, 120.0, 5.0, 80.0},
	{BARAKA, 590.0, 370.0, 400.0, 120.0, 60.0, 120.0, 5.0, 120.0},
	{BORAICHO, 1100.0, 1030.0, 350.0, 120.0, 60.0, 120.0, 5.0, 120.0},
	{DARRIUS, 550.0, 500.0, 400.0, 120.0, 60.0, 120.0, 5.0, 70.0},
	{DAIROU, 630.0, 600.0, 250.0, 120.0, 60.0, 120.0, 5.0, 70.0},
	{ERMAC, 700.0, 650.0, 580.0, 120.0, 60.0, 120.0, 5.0, 90.0},
	{HOTARU, 465.0, 560.0, 430.0, 120.0, 60.0, 120.0, 5.0, 80.0},
	{JADE, 500.0, 550.0, 330.0, 120.0, 60.0, 120.0, 5.0, 70.0},
	{KABAL, 500.0, 500.0, 330.0, 150.0, 60.0, 120.0, 5.0, 140.0},
	{KENSHI, 780.0, 650.0, 600.0, 120.0, 60.0, 120.0, 5.0, 80.0},
	{KIRA, 700.0, 400.0, 360.0, 120.0, 60.0, 120.0, 5.0, 100.0},
	{KOBRA, 770.0, 430.0, 500.0, 120.0, 60.0, 120.0, 5.0, 135.0},
	{LI_MEI, 740.0, 430.0, 350.0, 120.0, 60.0, 120.0, 5.0, 50.0},
	{LIU_KANG, 490.0, 760.0, 400.0, 120.0, 60.0, 120.0, 5.0, 120.0},
	{MILEENA, 830.0, 570.0, 400.0, 120.0, 60.0, 120.0, 5.0, 120.0},
	{NIGHTWOLF, 550.0, 500.0, 450.0, 120.0, 60.0, 120.0, 5.0, 60.0},
	{NOOBSMOKE, 550.0, 930.0, 380.0, 160.0, 60.0, 120.0, 5.0, 120.0},
	{RAIDEN, 370.0, 390.0, 330.0, 120.0, 60.0, 120.0, 5.0, 120.0},
	{SCORPION, 370.0, 850.0, 350.0, 150.0, 60.0, 120.0, 5.0, 140.0},
	{SHUJINKO, 760.0, 580.0, 550.0, 160.0, 60.0, 120.0, 5.0, 110.0},
	{SINDEL, 420.0, 600.0, 250.0, 120.0, 60.0, 120.0, 5.0, 120.0},
	{HAVIK, 650.0, 690.0, 390.0, 120.0, 60.0, 120.0, 5.0, 70.0},
	{SUBZERO, 700.0, 860.0, 330.0, 150.0, 60.0, 120.0, 5.0, 40.0},
	{TANYA, 530.0, 560.0, 550.0, 120.0, 60.0, 120.0, 5.0, 70.0},
	
	// mku timers
	{KITANA, 1100.0, 1100.0, 330.0, 120.0, 60.0, 120.0, 5.0, 70.0},
	{GORO, 592.0, 600.0, 495.0, 120.0, 60.0, 120.0, 5.0, 140.0},
	{SHAO_KAHN, 454.0, 702.0, 518.0, 120.0, 60.0, 120.0, 5.0, 140.0},
	{FROST, 700.0, 700.0, 330.0, 150.0, 60.0, 120.0, 5.0, 40.0},
	{JAX, 500.0, 550.0, 330.0, 120.0, 60.0, 120.0, 5.0, 120.0},

	// umkd new timers
	{SCORPION2, 370.0, 850.0, 350.0, 150.0, 60.0, 120.0, 5.0, 140.0},
	{SUBZERO2, 700.0, 860.0, 330.0, 150.0, 60.0, 120.0, 5.0, 40.0},
	{ERMAC2, 700.0, 650.0, 580.0, 120.0, 60.0, 120.0, 5.0, 90.0},
	{RAIDEN2, 370.0, 390.0, 330.0, 120.0, 60.0, 120.0, 5.0, 120.0},

	{-1, 1500.0, 1500.0, 1500.0, 120.0, 60.0, 120.0, 5.0, 140.0}
};

#ifndef PS2_BUILD
void dump_char_table()
{
	int select_addr = 0x4FB810;
	char msgBuffer[1256];
	for (int i = 0; i < 41; i++)
	{
		struct  char_info_entry chr = *(struct char_info_entry*)(select_addr + (sizeof(struct char_info_entry) * i));
		sprintf(msgBuffer, "{\"%s\"\t, 0x%X\t, 0x%X\t,\"%s\"},\n",
			chr.name,
			chr.file_table,
			chr.alt_file_table,
			chr.scriptName);
		_printf(msgBuffer);
	}
}
#endif

void set_char_table()
{
	int select_addr = 0x504D10;

	for (int i = 0; i < 41; i++)
		*(struct char_info_entry*)(select_addr + (sizeof(struct char_info_entry) * i)) = pCharTable[i];
}

void init_character_hook()
{
	init_character_tocs();

	static int val = 0;
	
	patchShort(0x1326B4, TOTAL_CHARACTERS);
	patchShort(0x1326F0, TOTAL_CHARACTERS);
	patchShort(0x130E08, TOTAL_CHARACTERS);
	patchShort(0x131088, TOTAL_CHARACTERS);
	patchShort(0x193880, TOTAL_CHARACTERS);
	patchShort(0x40BEA4, TOTAL_CHARACTERS);
	
	{
		val = (int)&pCharTable[0];
		patchInt(0x16D3AC, lui(v0, HIWORD(val)));
		patchInt(0x16D3AC + 4, ori(v0, v0, LOWORD(val)));

		patchInt(0x1938D8, lui(v0, HIWORD(val)));
		patchInt(0x1938D8 + 4, ori(v0, v0, LOWORD(val)));

		patchInt(0x1A3ED0, lui(v1, HIWORD(val)));
		patchInt(0x1A3ED8, ori(v1, v1, LOWORD(val)));

		patchInt(0x1A3FA4, lui(v1, HIWORD(val)));
		patchInt(0x1A3FAC, ori(v1, v1, LOWORD(val)));

		patchInt(0x264EF4, lui(v1, HIWORD(val)));
		patchInt(0x264EFC, ori(v1, v1, LOWORD(val)));

		patchInt(0x264F10, lui(v1, HIWORD(val)));
		patchInt(0x264F18, ori(v1, v1, LOWORD(val)));


		patchInt(0x2E5EC8, lui(v0, HIWORD(val)));
		patchInt(0x2E5EC8 + 4, ori(v0, v0, LOWORD(val)));

		// TODO: implement krypt names for new chars when new bios are in somehow
		//patchInt(0x3EB790, lui(v0, HIWORD(val)));
		//patchInt(0x3EB7A0, ori(v0, v0, LOWORD(val)));
		//

		patchInt(0x40BE8C, lui(v0, HIWORD(val)));
		patchInt(0x40BE8C + 4, ori(v0, v0, LOWORD(val)));

		val += 4;
		patchInt(0x130DEC, lui(v0, HIWORD(val)));
		patchInt(0x130DF4, ori(v0, v0, LOWORD(val)));

		patchInt(0x132888, lui(v0, HIWORD(val)));
		patchInt(0x132888 + 4, ori(v0, v0, LOWORD(val)));

		val += 4;
		patchInt(0x130DD4, lui(v0, HIWORD(val)));
		patchInt(0x130DDC, ori(v0, v0, LOWORD(val)));

		patchInt(0x132864, lui(v0, HIWORD(val)));
		patchInt(0x132864 + 4, ori(v0, v0, LOWORD(val)));


		val += 4;
		patchInt(0x130E10, lui(v0, HIWORD(val)));
		patchInt(0x130E34, ori(v0, v0, LOWORD(val)));

		patchInt(0x131098, lui(v0, HIWORD(val)));
		patchInt(0x131098 + 4, ori(v0, v0, LOWORD(val)));

	}
	
	{
		val = (int)&pTimerTable[0];
		patchInt(0x16CC94, lui(v0, HIWORD(val)));
		patchInt(0x16CC94 + 4, ori(v0, v0, LOWORD(val)));

		patchInt(0x16CCA8, lui(a0, HIWORD(val)));
		patchInt(0x16CCA8 + 4, ori(a0, a0, LOWORD(val)));

		patchInt(0x170328, lui(a1, HIWORD(val)));
		patchInt(0x17032C, ori(a1, a1, LOWORD(val)));

		patchInt(0x17033C, lui(a0, HIWORD(val)));
		patchInt(0x17033C + 4, ori(a0, a0, LOWORD(val)));

		patchInt(0x1703B4, lui(a1, HIWORD(val)));
		patchInt(0x1703B4 + 4, ori(a1, a1, LOWORD(val)));

		val += 4;
		patchInt(0x17036C, lui(v0, HIWORD(val)));
		patchInt(0x170374, ori(v0, v0, LOWORD(val)));
		
		val += 4;
		patchInt(0x17038C, lui(v0, HIWORD(val)));
		patchInt(0x170394, ori(v0, v0, LOWORD(val)));

		val += 4;
		patchInt(0x1703E0, lui(v0, HIWORD(val)));
		patchInt(0x1703E8, ori(v0, v0, LOWORD(val)));

		val += 4;
		patchInt(0x16CCE0, lui(a0, HIWORD(val)));
		patchInt(0x16CCE8, ori(a0, a0, LOWORD(val)));

		val += 4;
		patchInt(0x16CCF0, lui(v0, HIWORD(val)));
		patchInt(0x16CCF8, ori(v0, v0, LOWORD(val)));

		val += 4;
		patchInt(0x16D33C, lui(a0, HIWORD(val)));
		patchInt(0x16D34C, ori(a0, a0, LOWORD(val)));

		val += 4;
		patchInt(0x16D344, lui(v1, HIWORD(val)));
		patchInt(0x16D354, ori(v1, v1, LOWORD(val)));

		val += 4;
		patchInt(0x16D350, lui(v0, HIWORD(val)));
		patchInt(0x16D358, ori(v0, v0, LOWORD(val)));
	}
	


	makeJal(0x132750, hook_character_lock_status);
	makeJal(0x1340E8, hook_character_lock_status);
	makeJal(0x15D3E8, hook_character_lock_status);
	makeJal(0x190CF4, hook_character_lock_status);
	makeJal(0x190DA0, hook_character_lock_status);
	makeJal(0x191074, hook_character_lock_status);
	makeJal(0x193690, hook_character_lock_status);
	makeJal(0x193DE8, hook_character_lock_status);
	makeJal(0x1941DC, hook_character_lock_status);
	makeJal(0x194880, hook_character_lock_status);
	makeJal(0x196138, hook_character_lock_status);
	makeJal(0x1961C4, hook_character_lock_status);
	makeJal(0x2D8878, hook_character_lock_status);
	makeJal(0x3827A4, hook_character_lock_status);
	makeJal(0x382934, hook_character_lock_status);
	makeJal(0x3E835C, hook_character_lock_status);
	makeJal(0x3E84F8, hook_character_lock_status);
	makeJal(0x3E8F8C, hook_character_lock_status);
}

void init_character_tocs()
{
	init_scorpion_toc();
	init_subzero_toc();
	init_ermac_toc();
	init_raiden_toc();
	init_mkda_kano_toc();
	init_mkda_mokap_toc();
	init_mkda_blaze_toc();
	init_sonya_toc();
	init_kitana_toc();
	init_jax_toc();
	init_dragonking_toc();
	init_frost_toc();
	init_blaze_toc();
	init_sk_toc();
	init_goro_toc();
	init_drahmin_toc();
	init_sareena_toc();
	init_quan_toc();
	init_shang_toc();
	init_kunglao_toc();
	init_cage_toc();
	init_sektor_toc();
	init_rain_toc();
	init_nitara_toc();
	init_tremor_toc();
	init_cyrax_toc();
	init_reiko_toc();
}

int hook_character_lock_status(int id, int param)
{
	id = SCORPION;
	return is_char_locked(id, param);
}

