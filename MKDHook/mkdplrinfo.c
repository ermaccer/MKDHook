#include "mkdplrinfo.h"
#include "mkdeception.h"
#include <stdio.h>
#include "ps2mem.h"

struct mk_file_entry frost_file_entry_table[] = {
	{"mkda_frost.ssf"	,0, 4, 0},
	{"mkda_frost.sec"	,0, 1, 0},
	{"mkda_frost_ap.sec"	,0, 1, 0},
	{"sh_mkda_frost.sec"	,0, 1, 0},
	{"mkda_frost.mko"	,0, 3, 0},
	{"blood_fx.mko"	,0	,3 , 0},
	{"fight_fx.mko"	,0	,3 , 0},
	{"fujowpai.mko"	,0	,3 , 0},
	{"style_fu_jow_pai.sec"	,0,1 },
	{"yuanyang.mko"	,0, 3},
	{"style_yuan_yang.sec",0,1,0},
	{"sai.mko"	,0, 3,0},
	{"style_sai.sec", 0,1,0 },
	{"frost_anims.sec"	,0, 2,0},
	{"pz_jax_anims.sec"	,0, 2,0},
	{"fujowpai_anims.sec"	,0, 2,0},
	{"yuanyang_anims.sec"	,0, 2,0},
	{"sai_anims.sec"	,0, 2,0},
	{"fat_anims_subzero2.sec"	,0, 2,0},
	{"fat_anims_frost1.sec"	,0, 2,0},
	{"frost_fx.mko"	,0	,3 , 0},
};

struct mk_file_entry frost_unchained_file_entry_table[] = {
	{"frost.ssf"	,0, 4, 0},
	{"frost.sec"	,0, 1, 0},
	{"frost_ap.sec"	,0, 1, 0},
	{"sh_frost.sec"	,0, 1, 0},
	{"frost.mko"	,0, 3, 0},
	{"blood_fx.mko"	,0	,3 , 0},
	{"fight_fx.mko"	,0	,3 , 0},
	{"tongbei.mko"	,0	,3 , 0},
	{"style_tongbei.sec"	,0,1 },
	{"yuanyang.mko"	,0, 3},
	{"style_yuan_yang.sec",0,1,0},
	{"daggers.mko"	,0, 3,0},
	{"style_daggers.sec", 0,1,0 },
	{"frost_anims.sec"	,0, 2,0},
	{"pz_jax_anims.sec"	,0, 2,0},
	{"tongbei_anims.sec"	,0, 2,0},
	{"yuanyang_anims.sec"	,0, 2,0},
	{"daggers_anims.sec"	,0, 2,0},
	{"fat_anims_subzero2.sec"	,0, 2,0},
	{"fat_anims_frost1.sec"	,0, 2,0},
	{"frost_fx.mko"	,0	,3 , 0},

};

struct mk_file_entry alt_frost_unchained_file_entry_table[] = {
	{"frost.ssf"	,0, 4, 0},
	{"frost_alt.sec"	,0, 1, 0},
	{"frost_alt_ap.sec"	,0, 1, 0},
	{"sh_frost.sec"	,0, 1, 0},
	{"frost.mko"	,0, 3, 0},
	{"blood_fx.mko"	,0	,3 , 0},
	{"fight_fx.mko"	,0	,3 , 0},
	{"tongbei.mko"	,0	,3 , 0},
	{"style_tongbei.sec"	,0,1 },
	{"yuanyang.mko"	,0, 3},
	{"style_yuan_yang.sec",0,1,0},
	{"daggers.mko"	,0, 3,0},
	{"style_daggers.sec", 0,1,0 },
	{"frost_alt_anims.sec"	,0, 2,0},
	{"pz_jax_anims.sec"	,0, 2,0},
	{"tongbei_anims.sec"	,0, 2,0},
	{"yuanyang_anims.sec"	,0, 2,0},
	{"daggers_anims.sec"	,0, 2,0},
	{"fat_anims_subzero2.sec"	,0, 2,0},
	{"fat_anims_frost1.sec"	,0, 2,0},
	{"frost_fx.mko"	,0	,3 , 0},

};


struct mk_toc_entry frost_table[] = {
		{&frost_file_entry_table[0]	,0,0 },
		{&frost_file_entry_table[1]	,0,569088},
		{&frost_file_entry_table[2]	,0,569088},
		{&frost_file_entry_table[3]	,0,244864},
		{&frost_file_entry_table[4]	,0,33888},
		{&frost_file_entry_table[5]	,0,21368},
		{&frost_file_entry_table[6]	,0,10164},
		{&frost_file_entry_table[7]	,0,12580},
		{&frost_file_entry_table[8]	,0,10112},
		{&frost_file_entry_table[9]	,0,9076},
		{&frost_file_entry_table[10]	,0,10112},
		{&frost_file_entry_table[11]	,0,14284},
		{&frost_file_entry_table[12]	,0,6016},
		{&frost_file_entry_table[13]	,0,42752},
		{&frost_file_entry_table[14]	,0,52352},
		{&frost_file_entry_table[15]	,0,155904},
		{&frost_file_entry_table[16]	,0,168576},
		{&frost_file_entry_table[17]	,0,232960},
		{&frost_file_entry_table[18]	,0,51328},
		{&frost_file_entry_table[19]	,0,112000},
		{&frost_file_entry_table[20]	,0,23904},
		{0,0,0}
};


struct char_info_entry pCharTable[] = {
	{"SCORPION"	, 0x5AD100	, 0x5AD270	,"scorpion.mko"},
	{"BARAKA"	, 0x5A6C40	, 0x5A6DB0	,"baraka.mko"},
	{"NOOB"	, 0x5AC840	, 0x5AC930	,"noob.mko"},
	{"SUB-ZERO"	, 0x5AE460	, 0x5AE5D0	,"subzero.mko"},
	{"MILEENA"	, 0x5AA850	, 0x5AA9C0	,"mileena.mko"},
	{"NIGHTWOLF"	, 0x5AC4F0	, 0x5AC680	,"nightwolf.mko"},
	{"ERMAC"	, 0x5A7F30	, 0x5A80B0	,"ermac.mko"},
	{"ASHRAH"	, 0x5A67E0	, 0x5A6950	,"ashrah.mko"},
	{"SINDEL"	, 0x5ADA20	, 0x5ADB90	,"sindel.mko"},
	{"LI MEI"	, 0x5AA020	, 0x5A9EB0	,"limei.mko"},
	{"BO' RAI CHO"	, 0x5A7070	, 0x5A7200	,"boraicho.mko"},
	{"HOTARU"	, 0x5A85E0	, 0x5A8750	,"hotaru.mko"},
	{"KENSHI"	, 0x5A9260	, 0x5A93D0	,"kenshi.mko"},
	{"SMOKE"	, 0x5AE090	, 0x5AE1C0	,"smoke.mko"},
	{"HAVIK"	, 0x5ADD90	, 0x5ADEF0	,"skab.mko"},
	{"TANYA"	, 0x5AE850	, 0x5AE9C0	,"tanya.mko"},
	{"LIU KANG"	, 0x5AA450	, 0x5AA2E0	,"liukang.mko"},
	{"GHOST"	, 0x5AA5E0	, 0x5AA5E0	,"liukang_ghost.mko"},
	{"KIRA"	, 0x5A9660	, 0x5A97C0	,"kira.mko"},
	{"KABAL"	, 0x5A8E30	, 0x5A8FA0	,"kabal.mko"},
	{"KOBRA"	, 0x5A9A70	, 0x5A9BE0	,"kobra.mko"},
	{"JADE"	, 0x5A8A20	, 0x5A8B80	,"jade.mko"},
	{"DAIROU"	, 0x5A7930	, 0x5A7AA0	,"dairou.mko"},
	{"RAIDEN"	, 0x5ACDD0	, 0x5ACF40	,"raiden.mko"},
	{"DARRIUS"	, 0x5A74E0	, 0x5A7650	,"cassius.mko"},
	{"SHUJINKO"	, 0x5AD490	, 0x5AD620	,"shujinko.mko"},
	{"SHUJINKO"	, 0x5AD7B0	, 0x5AD7B0	,"shujinko_13.mko"},
	{"NOOB - SMOKE"	, 0x5ACC90	, 0x5ACB20	,"noobsmoke.mko"},
	{"MONSTER"	, 0x5A8340	, 0x5A8340	,"freak.mko"},
	{"ONAGA"	, 0x5A7CD0	, 0x5A7CD0	,"dragonking.mko"},
	{"JAX"	, 0x5AB2A0	, 0x5AB410	,"mkda_jax.mko"},
	{"RAIDEN"	, 0x5ABF00	, 0x5ABF00	,"mkda_rayden.mko"},
	{"QUAN CHI"	, 0x5ABC60	, 0x5ABC60	,"mkda_quanchi.mko"},
	{"KUNG LAO"	, 0x5AB8E0	, 0x5AB8E0	,"mkda_kunglao.mko"},
	{"JOHNNY CAGE"	, 0x5AAD10	, 0x5AAD10	,"mkda_cage.mko"},
	{"SONYA"	, 0x5AC250	, 0x5AC250	,"mkda_sonya.mko"},
	{"NITARA"	, 0x5ABA60	, 0x5ABA60	,"mkda_nitara.mko"},
	{"SHANG TSUNG"	, 0x5AC0C0	, 0x5AC0C0	,"mkda_shang.mko"},
	{"FROST"	,(int)&frost_table[0]	, (int)&frost_table[0]	,"mkda_frost.mko"},
	{"KITANA"	, 0x5AB630	, 0x5AB630	,"mkda_kitana.mko"},
	{"DRAHMIN"	, 0x5AAF10	, 0x5AAF10	,"mkda_drahmin.mko"},
};

void dump_char_table()
{
	int select_addr = 0x504D10;
	char msgBuffer[1256];
	for (int i = 0; i < 41; i++)
	{
		struct  char_info_entry chr = *(struct char_info_entry*)(select_addr + (sizeof(struct char_info_entry) * i));
		sprintf(msgBuffer, "{\"%s\"\t, 0x%X\t, 0x%X\t,\"%s\"},\n",
			chr.name,
			chr.file_table,
			chr.alt_file_table,
			chr.scriptName);
		game_printf(msgBuffer);
	}
}

void set_char_table()
{
	int select_addr = 0x504D10;

	for (int i = 0; i < 41; i++)
		*(struct char_info_entry*)(select_addr + (sizeof(struct char_info_entry) * i)) = pCharTable[i];
}

void calculate_custom_toc()
{
	// from toceditor

	// FROST
	for (int i = 0; i < 21; i++)
	{
		frost_file_entry_table[i].belong = &frost_table[0];
	}

	int baseSize = 2048;
	for (int i = 1; i < 21; i++)
	{
		frost_table[i].previousSize = baseSize;
		baseSize += (frost_table[i].size + 2048 - 1) & -2048;

	}
}