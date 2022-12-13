#include "mkdhook.h"
#include "mkdplrinfo.h"
#include "mkdmenu.h"

int  bSwapStatus = 0;
int  menu_string = 0;


struct select_screen_entry pSelectTable[] = {
	{KENSHI	, 86	, "HEAD_KENSHI"	, "HEAD_KENSHI_LOCKED"	, "BODY_KENSHI"	, "body_kenshi_alt.sec"	, "4"	, "TAI CHI"	, "JUDO"	, "KATANA"},
	{JADE	, 84	, "HEAD_JADE"	, "HEAD_JADE_LOCKED"	, "BODY_JADE"	, "body_jade_alt.sec"	, "5"	, "FAN ZI"	, "KUO SHOU"	, "BOJUTSU"},
	{SCORPION	, 95	, "HEAD_SCORPION"	, "HEAD_SCORPION"	, "BODY_SCORPION"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
	{MILEENA	, 91	, "HEAD_MILEENA"	, "HEAD_SCORPION"	, "BODY_MILEENA"	, "body_mileena_alt.sec"	, "2"	, "YING YEUNG"	, "MIAN CHUAN"	, "SAI"},
	{BARAKA	, 77	, "HEAD_BARAKA"	, "HEAD_SCORPION"	, "BODY_BARAKA"	, "body_baraka_alt.sec"	, "3"	, "SILAT"	, "HUNG GAR"	, "BLADES"},
	{SUBZERO	, 99	, "HEAD_SUBZERO"	, "HEAD_SCORPION"	, "BODY_SUBZERO"	, "body_subzero_alt.sec"	, "4"	, "SHOTOKAN"	, "DRAGON"	, "KORI BLADE"},
	{HAVIK	, 82	, "HEAD_HAVIK"	, "HEAD_SKAB_LOCKED"	, "BODY_HAVIK"	, "body_havik_alt.sec"	, "5"	, "SNAKE"	, "TANG SOO DO"	, "MORNING STAR"},
	{SINDEL	, 97	, "HEAD_SINDEL"	, "HEAD_SINDEL_LOCKED"	, "BODY_SINDEL"	, "body_sindel_alt.sec"	, "3"	, "ZHA CHUAN"	, "FU JOW PAI"	, "KWAN DO"},
	{RAIDEN	, 94	, "HEAD_RAIDEN"	, "HEAD_RAIDEN_LOCKED"	, "BODY_RAIDEN"	, "body_raiden_alt.sec"	, "4"	, "NAN CHUAN"	, "JUJUTSU"	, "STAFF"},
	{LI_MEI	, 89	, "HEAD_LIMEI"	, "HEAD_LIMEI_LOCKED"	, "BODY_LIMEI"	, "body_limei_alt.sec"	, "2"	, "MI ZONG"	, "LUI HE BA FA"	, "KUNLUN DAO"},
	{KABAL	, 85	, "HEAD_KABAL"	, "HEAD_KABAL_LOCKED"	, "BODY_KABAL"	, "body_kabal_alt.sec"	, "2"	, "SUN BIN"	, "GOJU RYU"	, "HOOK SWORDS"},
	{ERMAC	, 81	, "HEAD_ERMAC"	, "HEAD_SCORPION"	, "BODY_ERMAC"	, "body_ermac_alt.sec"	, "4"	, "HUA CHUAN"	, "CHOY LEE FUT"	, "AXE"},
	{NIGHTWOLF	, 92	, "HEAD_NIGHTWOLF"	, "HEAD_SCORPION"	, "BODY_NIGHTWOLF"	, "body_nightwolf_alt.sec"	, "4"	, "VAL TUDO"	, "TAE KWAN DO"	, "TOMAHAWKS"},
	{BORAICHO	, 78	, "HEAD_BORAICHO"	, "HEAD_SCORPION"	, "BODY_BORAICHO"	, "body_boraicho_alt.sec"	, "4"	, "SUMO"	, "DRUNKEN FIST"	, "JOJUTSU"},
	{NOOBSMOKE	, 102	, "HEAD_SMOKENOOB"	, "HEAD_SMOKENOOB_LOCKED"	, "BODY_SMOKENOOB"	, "body_smokenoob_alt.sec"	, "5"	, "NOOB - MONKEY"	, "SMOKE - MI TZU"	, " "},
	{TANYA	, 100	, "HEAD_TANYA"	, "HEAD_TANYA_LOCKED"	, "BODY_TANYA"	, "body_tanya_alt.sec"	, "5"	, "ZI RAN MEN"	, "YUE CHUAN"	, "KOBU JUTSU"},
	{SHUJINKO	, 96	, "HEAD_SHUJINKO"	, "HEAD_SHUJINKO_LOCKED"	, "BODY_SHUJINKO"	, "body_shujinko_alt.sec"	, "5"	, "MANTIS"	, "SHAOLIN FIST"	, "DAN TIEN DAO"},
	{HOTARU	, 83	, "HEAD_HOTARU"	, "HEAD_HOTARU_LOCKED"	, "BODY_HOTARU"	, "body_hotaru_alt.sec"	, "1"	, "BA SHAN FAN"	, "PI GUA"	, "NAGINATA"},
	{ASHRAH	, 76	, "HEAD_ASHRA"	, "HEAD_SCORPION"	, "BODY_ASHRAH"	, "body_ashrah_alt.sec"	, "5"	, "CHOU JAIO"	, "BA GUA"	, "KRISS"},
	{DAIROU	, 79	, "HEAD_DAIROU"	, "HEAD_DAIROU_LOCKED"	, "BODY_DAIROU"	, "body_dairou_alt.sec"	, "5"	, "WING CHUN"	, "ESCRIMA"	, "AUTUMN DAO"},
	{KOBRA	, 88	, "HEAD_KOBRA"	, "HEAD_KOBRA_LOCKED"	, "BODY_KOBRA"	, "body_kobra_alt.sec"	, "1"	, "SHORIN RYU"	, "KICKBOXING"	, "KALI STICKS"},
	{DARRIUS	, 80	, "HEAD_DARRIUS"	, "HEAD_SHINJINKO_LOCKED"	, "BODY_DARRIUS"	, "body_darrius_alt.sec"	, "5"	, "SHINTO RYU"	, "LEOPARD"	, "GAUNTLETS"},
	{KIRA	, 87	, "HEAD_KIRA"	, "HEAD_KIRA_LOCKED"	, "BODY_KIRA"	, "body_kira_alt.sec"	, "5"	, "XING YI"	, "KENPO"	, "DRAGON TEETH"},
	{LIU_KANG	, 90	, "HEAD_LIUKANG"	, "HEAD_LIUKANG_LOCKED"	, "BODY_LIUKANG"	, "body_liukang_alt.sec"	, "5"	, "JUN FAN"	, "PAO CHUI"	, "NUNCHAKU"},
};

struct select_screen_entry pSelectTableNew[] = {
		{MONSTER, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{ONAGA,  13	, "HEAD_KOBRA_LOCKED"	, "HEAD_KOBRA_LOCKED"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	,  "1"	, "DRAGON"	, ""	, ""},
		{SHUJINKO_13	, 96	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, "MANTIS"	, "SHAOLIN FIST"	, "DAN TIEN DAO"},
		{MKDA_QUAN_CHI	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "4"	, "TANG SOO DO"	, "ESCRIMA"	, "BROADSWORD"},
		{MKDA_SHANG_TSUNG	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "3"	, "SNAKE"	, "MANTIS"	, ""},
		{MKDA_NITARA	, -1, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, "LEOPARD"	, "FU JOW PAI"	, "DRAGON TEETH"},
		{MKDA_SONYA	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "1"	, "KENPO"	, "TAE KWON DO"	, "KALI STICKS"},
		{MKDA_CAGE	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "3"	, "SHINTO RYU"	, "JEET KUNE DO"	, "NUNCHAKU"},
		{MKDA_KUNG_LAO	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "MANTIS"	, "SHAOLIN FIST"	, "BROADSWORD"},
		{MKDA_DRAHMIN	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, ""	, ""	, "IRON CLUB"},
		{MKDA_FROST	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, ""	, ""	, ""},
		{MKDA_JAX	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, ""	, ""	, ""},
		{MKDA_KITANA	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM" , "body_scorpion_alt.sec"	, "5"	, "JUN FAN"	, "PAO CHUI"	, "NUNCHAKU"},
		{MKDA_RAIDEN	, -1	,	"HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM" , "body_scorpion_alt.sec"	, "4"	, "NAN CHUAN"	, "JUJUTSU"	, "STAFF"},
		{SMOKE	, 98	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_SMOKE"	, "body_scorpion_alt.sec"	, "5"	, "MI TZU"	, ""	, ""},
		{NOOB	, 93	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_NOOB2"	, "body_scorpion_alt.sec"	, "5"	, "MONKEY"	, ""	, ""},
		{GHOST	, 90	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_GHOST" , "body_scorpion_alt.sec"	, "5"	, "JUN FAN"	, "PAO CHUI"	, "NUNCHAKU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
};



int hook_character_lock_status(int id, int param)
{
    id = 0;
    return is_char_locked(id, param);
}

void hook_new_select_table(int status)
{
	bSwapStatus = status;

	int select_addr = 0x4FEF40;
	char msgBuffer[1256];
	for (int i = 0; i < 24; i++)
	{
		int sel = (select_addr + (sizeof(struct select_screen_entry) * i));
		if (bSwapStatus)
		{
			*(int*)(sel + 0) = pSelectTable[i].characterID;
			*(int*)(sel + 4) = pSelectTable[i].soundID;
			*(int*)(sel + 8) = (int)&pSelectTable[i].headName[0];
			*(int*)(sel + 12) = (int)&pSelectTable[i].headLockedName[0];
			*(int*)(sel + 16) = (int)&pSelectTable[i].bodyName[0];
			*(int*)(sel + 20) = (int)&pSelectTable[i].bodyArchiveName[0];
			*(int*)(sel + 24) = (int)&pSelectTable[i].difficulty[0];
			*(int*)(sel + 28) = (int)&pSelectTable[i].style1[0];
			*(int*)(sel + 32) = (int)&pSelectTable[i].style2[0];
			*(int*)(sel + 36) = (int)&pSelectTable[i].style3[0];

		}
		else
		{
			*(int*)(sel + 0) = pSelectTableNew[i].characterID;
			*(int*)(sel + 4) = pSelectTableNew[i].soundID;
			*(int*)(sel + 8) = (int)&pSelectTableNew[i].headName[0];
			*(int*)(sel + 12) = (int)&pSelectTableNew[i].headLockedName[0];
			*(int*)(sel + 16) = (int)&pSelectTableNew[i].bodyName[0];
			*(int*)(sel + 20) = (int)&pSelectTableNew[i].bodyArchiveName[0];
			*(int*)(sel + 24) = (int)&pSelectTableNew[i].difficulty[0];
			*(int*)(sel + 28) = (int)&pSelectTableNew[i].style1[0];
			*(int*)(sel + 32) = (int)&pSelectTableNew[i].style2[0];
			*(int*)(sel + 36) = (int)&pSelectTableNew[i].style3[0];
		}


	}
	game_printf("screen swapped\n");
	refresh_screen();
}

void restore_select_screen()
{
	hook_new_select_table(1);
}

void hook_render()
{
	process_mkdhook();
	render();
}

void process_mkdhook()
{
	// select screen stuff
	{
		if (get_game_state() == STATE_SELECT)
		{
			if (pressed_button(0, PAD_L3))
				hook_new_select_table(0);

			if (pressed_button(0, PAD_R3))
				hook_new_select_table(1);
		}
		else
			restore_select_screen();
	}
	

 	if (get_game_state() == STATE_GAME)
	{
		Menu_Process();
	}
	else
		Menu_Unset();


	if (get_game_state() == STATE_KONQUEST)
	{
		Konquest_Process_Cameras();
	}
	else
		Menu_K_Reset();

}