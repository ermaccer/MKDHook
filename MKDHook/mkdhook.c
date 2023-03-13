#include "mkdhook.h"
#include "character.h"
#include "mkdmenu.h"
#include "stage.h"

int  current_select = 0;
int  select_timer = 0;
int sound;

select_screen_entry pSelectTable[27] = {
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

select_screen_entry pSelectTableNew[27] = {
		{SONYA,  SOUND_SONYA_SELECT	, "HEAD_SONYA"	, "HEAD_RANDOM"	, "BODY_SONYA"	, "body_sonya_alt.sec"	, "1"	, "KENPO"	, "TAE KWON DO"	, "KALI STICKS"},
		{KITANA, SOUND_KITANA_SELECT, "HEAD_KITANA"	, "HEAD_RANDOM"	, "BODY_KITANA"	, "body_kitana_alt.sec"	, "4"	, "EAGLE CLAW"	, "BA GUA"	, "STEEL FAN"},
		{JAX,  SOUND_JAX_SELECT	, "HEAD_JAX"	, "HEAD_RANDOM"	, "BODY_JAX"	, "body_jax_alt.sec"	, "2"	, "MUAY THAI"	, "JUDO"	, "TONFA"},
		{ONAGA,  SOUND_ONAGA_SELECT	, "HEAD_DRAGONKING"	, "HEAD_KOBRA_LOCKED"	, "BODY_RANDOM"	, "NULL"	,  "1"	, "DRAGON"	, ""	, ""},
		{-1,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "NULL"	, "2"	, ""	, ""	, ""},
		{-1,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "NULL"	, "2"	, ""	, ""	, ""},
		{-1,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "NULL"	, "2"	, ""	, ""	, ""},
		{-1,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "NULL"	, "2"	, ""	, ""	, ""},

		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{-1,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
};

select_screen_entry pSelectTableNPC[27] = {
		{MONSTER, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{ONAGA,  13	, "HEAD_KOBRA_LOCKED"	, "HEAD_KOBRA_LOCKED"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	,  "1"	, "DRAGON"	, ""	, ""},
		{SHUJINKO_13	, 96	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, "MANTIS"	, "SHAOLIN FIST"	, "DAN TIEN DAO"},
		{MKDA_QUAN_CHI	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "4"	, "TANG SOO DO"	, "ESCRIMA"	, "BROADSWORD"},
		{MKDA_SHANG_TSUNG	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "3"	, "SNAKE"	, "MANTIS"	, ""},
		{MKDA_NITARA	, -1, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, "LEOPARD"	, "FU JOW PAI"	, "DRAGON TEETH"},
		{MKDA_SONYA,  -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	,  "1"	, "KENPO"	, "TAE KWON DO"	, "KALI STICKS"},
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
		{MKDA_KANO	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "3"	, "SHINTO RYU"	, "JEET KUNE DO"	, "NUNCHAKU"},
		{MKDA_MOKAP	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "3"	, "SHINTO RYU"	, "JEET KUNE DO"	, "NUNCHAKU"},
		{MKDA_BLAZE	, -1	, "HEAD_KOBRA_LOCKED"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "3"	, "SHINTO RYU"	, "JEET KUNE DO"	, "NUNCHAKU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
		{MONSTER,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
};



void init_mkdhook_vars()
{
	select_timer = get_game_tick();
	current_select = Select_Default;
	sound = 6824;
}

void hook_new_select_table(int status)
{
	current_select = status;
	refresh_screen();
}

void process_swap_select_screen()
{
	if (get_game_tick() - select_timer <= 15) return;
	select_timer = get_game_tick();
	snd_req(SELECT_SCREEN_SWAP_SOUND);
	current_select++;

	if (current_select > Select_NPC)
		current_select = Select_Default;

	swap_select_screen();
}

void swap_select_screen()
{
	int select_addr = 0x4FEF40;
	for (int i = 0; i < 24; i++)
	{
		int sel = (select_addr + (sizeof(select_screen_entry) * i));

		select_screen_entry ent = pSelectTable[i];

		if (current_select == Select_UMKD)
			ent = pSelectTableNew[i];
		
		if (current_select == Select_NPC)
			ent = pSelectTableNPC[i];

		*(int*)(sel + 0) = ent.characterID;
		*(int*)(sel + 4) = ent.soundID;
		*(int*)(sel + 8) =  (int)&ent.headName[0];
		*(int*)(sel + 12) = (int)&ent.headLockedName[0];
		*(int*)(sel + 16) = (int)&ent.bodyName[0];
		*(int*)(sel + 20) = (int)&ent.bodyArchiveName[0];
		*(int*)(sel + 24) = (int)&ent.difficulty[0];
		*(int*)(sel + 28) = (int)&ent.style1[0];
		*(int*)(sel + 32) = (int)&ent.style2[0];
		*(int*)(sel + 36) = (int)&ent.style3[0];
	}

	if (get_game_state() == STATE_SELECT)
		refresh_screen();
}

void restore_select_screen()
{
	current_select = Select_Default;
	swap_select_screen();
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
			if (!(get_game_mode() == MODE_PUZZLE || get_game_mode() == MODE_CHESS))
			{
				if (check_switch(0, PAD_L3))
					process_swap_select_screen();

				if (check_switch(1, PAD_L3))
					process_swap_select_screen();
			}
		}
		else
		{
			restore_select_screen();
		}

	}


	// stage things
	if (get_game_mode() == MODE_PUZZLE || get_game_mode() == MODE_CHESS)
		restore_stage_luis();
	else
		hook_stage_select();
	

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