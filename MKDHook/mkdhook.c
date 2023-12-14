#include "mkdhook.h"
#include "character.h"
#include "mkdmenu.h"
#include "stage.h"
#include "generic.h"
#include "settings.h"
#include "ps2mem.h"
int  current_select = 0;
int  select_timer = 0;
int  sound = 0; 

select_screen_entry pSelectTable[24] = {
	{KENSHI	, 86	, "HEAD_KENSHI"	, "HEAD_RANDOM"	, "BODY_KENSHI"	, "body_kenshi_alt.sec"	, "4"	, "TAI CHI"	, "JUDO"	, "KATANA"},
	{JADE	, 84	, "HEAD_JADE"	, "HEAD_RANDOM"	, "BODY_JADE"	, "body_jade_alt.sec"	, "5"	, "FAN ZI"	, "KUO SHOU"	, "BOJUTSU"},
	{SCORPION	, 95	, "HEAD_SCORPION"	, "HEAD_RANDOM"	, "BODY_SCORPION"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
	{MILEENA	, 91	, "HEAD_MILEENA"	, "HEAD_RANDOM"	, "BODY_MILEENA"	, "body_mileena_alt.sec"	, "2"	, "YING YEUNG"	, "MIAN CHUAN"	, "SAI"},
	{BARAKA	, 77	, "HEAD_BARAKA"	, "HEAD_RANDOM"	, "BODY_BARAKA"	, "body_baraka_alt.sec"	, "3"	, "SILAT"	, "HUNG GAR"	, "BLADES"},
	{SUBZERO	, 99	, "HEAD_SUBZERO"	, "HEAD_RANDOM"	, "BODY_SUBZERO"	, "body_subzero_alt.sec"	, "4"	, "SHOTOKAN"	, "DRAGON"	, "KORI BLADE"},
	{HAVIK	, 82	, "HEAD_HAVIK"	, "HEAD_RANDOM"	, "BODY_HAVIK"	, "body_havik_alt.sec"	, "5"	, "SNAKE"	, "TANG SOO DO"	, "MORNING STAR"},
	{SINDEL	, 97	, "HEAD_SINDEL"	, "HEAD_RANDOM"	, "BODY_SINDEL"	, "body_sindel_alt.sec"	, "3"	, "ZHA CHUAN"	, "FU JOW PAI"	, "KWAN DO"},
	
	{RAIDEN	, 94	, "HEAD_RAIDEN"	, "HEAD_RANDOM"	, "BODY_RAIDEN"	, "body_raiden_alt.sec"	, "4"	, "NAN CHUAN"	, "JUJUTSU"	, "STAFF"},
	{LI_MEI	, 89	, "HEAD_LIMEI"	, "HEAD_RANDOM"	, "BODY_LIMEI"	, "body_limei_alt.sec"	, "2"	, "MI ZONG"	, "LUI HE BA FA"	, "KUNLUN DAO"},
	{KABAL	, 85	, "HEAD_KABAL"	, "HEAD_RANDOM"	, "BODY_KABAL"	, "body_kabal_alt.sec"	, "2"	, "SUN BIN"	, "GOJU RYU"	, "HOOK SWORDS"},
	{ERMAC	, 81	, "HEAD_ERMAC"	, "HEAD_RANDOM"	, "BODY_ERMAC"	, "body_ermac_alt.sec"	, "4"	, "HUA CHUAN"	, "CHOY LEE FUT"	, "AXE"},
	{NIGHTWOLF	, 92	, "HEAD_NIGHTWOLF"	, "HEAD_RANDOM"	, "BODY_NIGHTWOLF"	, "body_nightwolf_alt.sec"	, "4"	, "VAL TUDO"	, "TAE KWAN DO"	, "TOMAHAWKS"},
	{BORAICHO	, 78	, "HEAD_BORAICHO"	, "HEAD_RANDOM"	, "BODY_BORAICHO"	, "body_boraicho_alt.sec"	, "4"	, "SUMO"	, "DRUNKEN FIST"	, "JOJUTSU"},
	{NOOBSMOKE	, 102	, "HEAD_SMOKENOOB"	, "HEAD_RANDOM"	, "BODY_SMOKENOOB"	, "body_smokenoob_alt.sec"	, "5"	, "NOOB - MONKEY"	, "SMOKE - MI TZU"	, " "},
	{TANYA	, 100	, "HEAD_TANYA"	, "HEAD_RANDOM"	, "BODY_TANYA"	, "body_tanya_alt.sec"	, "5"	, "ZI RAN MEN"	, "YUE CHUAN"	, "KOBU JUTSU"},
	
	{SHUJINKO	, 96	, "HEAD_SHUJINKO"	, "HEAD_RANDOM"	, "BODY_SHUJINKO"	, "body_shujinko_alt.sec"	, "5"	, "MANTIS"	, "SHAOLIN FIST"	, "DAN TIEN DAO"},
	{HOTARU	, 83	, "HEAD_HOTARU"	, "HEAD_RANDOM"	, "BODY_HOTARU"	, "body_hotaru_alt.sec"	, "1"	, "BA SHAN FAN"	, "PI GUA"	, "NAGINATA"},
	{ASHRAH	, 76	, "HEAD_ASHRA"	, "HEAD_RANDOM"	, "BODY_ASHRAH"	, "body_ashrah_alt.sec"	, "5"	, "CHOU JAIO"	, "BA GUA"	, "KRISS"},
	{DAIROU	, 79	, "HEAD_DAIROU"	, "HEAD_RANDOM"	, "BODY_DAIROU"	, "body_dairou_alt.sec"	, "5"	, "WING CHUN"	, "ESCRIMA"	, "AUTUMN DAO"},
	{KOBRA	, 88	, "HEAD_KOBRA"	, "HEAD_RANDOM"	, "BODY_KOBRA"	, "body_kobra_alt.sec"	, "1"	, "SHORIN RYU"	, "KICKBOXING"	, "KALI STICKS"},
	{DARRIUS	, 80	, "HEAD_DARRIUS"	, "HEAD_RANDOM"	, "BODY_DARRIUS"	, "body_darrius_alt.sec"	, "5"	, "SHINTO RYU"	, "LEOPARD"	, "GAUNTLETS"},
	{KIRA	, 87	, "HEAD_KIRA"	, "HEAD_RANDOM"	, "BODY_KIRA"	, "body_kira_alt.sec"	, "5"	, "XING YI"	, "KENPO"	, "DRAGON TEETH"},
	{LIU_KANG	, 90	, "HEAD_LIUKANG"	, "HEAD_RANDOM"	, "BODY_LIUKANG"	, "body_liukang_alt.sec"	, "5"	, "JUN FAN"	, "PAO CHUI"	, "NUNCHAKU"},
};

select_screen_entry pSelectTableNew[24] = {
		{SONYA,  SOUND_SONYA_SELECT	, "HEAD_SONYA"	, "HEAD_RANDOM"	, "BODY_SONYA"	, "body_sonya_alt.sec"	, "1"	, "KENPO"	, "TAE KWON DO"	, "KALI STICKS"},
		{KITANA, SOUND_KITANA_SELECT, "HEAD_KITANA"	, "HEAD_RANDOM"	, "BODY_KITANA"	, "body_kitana_alt.sec"	, "4"	, "EAGLE CLAW"	, "BA GUA"	, "STEEL FAN"},
		{JAX,  SOUND_JAX_SELECT	, "HEAD_JAX"	, "HEAD_RANDOM"	, "BODY_JAX"	, "body_jax_alt.sec"	, "2"	, "MUAY THAI"	, "JUDO"	, "TONFA"},
		{ONAGA,  SOUND_ONAGA_SELECT	, "HEAD_DRAGONKING"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "NULL"	,  "1"	, "DRAGON"	, ""	, ""},
		{SHAO_KAHN, SOUND_SHAO_SELECT	, "HEAD_SHAO_KAHN"	, "HEAD_RANDOM"	, "BODY_SHAO_KAHN"	, "body_shaokahn_alt.sec"	, "2"	, "TAI TZU"	, "LUI HE"	, "WRATH HAMMER"},
		{FROST,  SOUND_FROST_SELECT	, "HEAD_FROST"	, "HEAD_RANDOM"	, "BODY_FROST"	, "body_frost_alt.sec"	, "2"	, "TONG BEI"	, "YUAN YANG"	, "ICE DAGGERS"},
		{BLAZE,  SOUND_BLAZE_SELECT	, "HEAD_BLAZE"	, "HEAD_RANDOM"	, "BODY_BLAZE"	, "body_blaze_alt.sec"	, "3"	, "HAPKIDO"	, "JEET KUNE DO"	, "XING YI"},
		{GORO,  SOUND_GORO_SELECT	, "HEAD_GORO"	, "HEAD_RANDOM"	, "BODY_GORO"	, "body_goro_alt.sec"	, "3"	, "SHOKAN"	, "KUATAN"	, "DRAGON FANGS"},

		{DRAHMIN, SOUND_DRAHMIN_SELECT	, "HEAD_DRAHMIN"	, "HEAD_RANDOM"	, "BODY_DRAHMIN"	, "body_drahmin_alt.sec"	, "2"	, "HUNG GAR"	, "WRESTLING"	, "IRON CLUB"},
		{SAREENA, SOUND_SAREENA_SELECT	, "HEAD_SAREENA"	, "HEAD_RANDOM"	, "BODY_SAREENA"	, "body_sareena_alt.sec"	, "3"	, "BAJI QUAN"	, "YUAN YANG"	, "DEMON FANG"},
		{KUNG_LAO, SOUND_KUNG_LAO_SELECT	, "HEAD_KUNG_LAO"	, "HEAD_RANDOM"	, "BODY_KUNGLAO"	, "body_kung_alt.sec"	,	"2", "MANTIS"	, "SHAOLIN FIST"	, "BROADSWORD"},

		{QUAN_CHI, SOUND_QUAN_SELECT	, "HEAD_QUAN"	, "HEAD_RANDOM"	, "BODY_QUAN"	, "body_quan_alt.sec"	, "4"	, "TANG SOO DO"	, "ESCRIMA"	, "BROADSWORDS"},
		{SHANG_TSUNG, SOUND_SHANG_TSUNG_SELECT	, "HEAD_SHANG_TSUNG"	, "HEAD_RANDOM"	, "BODY_SHANGTSUNG"	, "body_shang_alt.sec"	, "3"	, "SNAKE"	, "CRANE"	, "STRAIGHT SWORD"},
		{CAGE,  SOUND_CAGE_SELECT	, "HEAD_CAGE"	, "HEAD_RANDOM"	, "BODY_CAGE"	, "body_cage_alt.sec",	"3", "SHORIN RYU"	, "JEET KUNE DO"	, "NUNCHAKU"},

		{SCORPION,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, ""	, ""	, ""	, ""},
		{SCORPION,  -1	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, ""	, ""	, ""	, ""},
		{0,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},

		{0,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{0,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{0,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},

		{0,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{0,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},
		{0,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},

		{0,  -1	, ""	, ""	, ""	, "NULL"	, ""	, ""	, ""	, ""},

};

#ifndef PS2_BUILD
select_screen_entry pSelectTableNPC[24] = {
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
};

#endif // !PS2_BUILD




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

	int maxSelect = Select_UMKD;
#ifndef PS2_BUILD
	if (settings.enable_npc_select)
		maxSelect = Select_NPC;
#endif

	if (current_select > maxSelect)
		current_select = Select_Default;

	swap_select_screen(1);
}

void swap_select_screen(int refresh)
{
	static int select_addr = 0x4FEF40;
	for (int i = 0; i < 24; i++)
	{
		int sel = (select_addr + (sizeof(select_screen_entry) * i));

		select_screen_entry ent = pSelectTable[i];

		if (current_select == Select_UMKD)
			ent = pSelectTableNew[i];
		
#ifndef PS2_BUILD
		if (current_select == Select_NPC)
			ent = pSelectTableNPC[i];
#endif // !PS2_BUILD

		*(int*)(sel + 0) = ent.characterID;
		*(int*)(sel + 4) = ent.soundID;
		*(int*)(sel + 8) = (int)&ent.headName[0];
		*(int*)(sel + 12) = (int)&ent.headLockedName[0];
		*(int*)(sel + 16) = (int)&ent.bodyName[0];
		*(int*)(sel + 20) = (int)&ent.bodyArchiveName[0];
		*(int*)(sel + 24) = (int)&ent.difficulty[0];
		*(int*)(sel + 28) = (int)&ent.style1[0];
		*(int*)(sel + 32) = (int)&ent.style2[0];
		*(int*)(sel + 36) = (int)&ent.style3[0];
	}

	if (get_game_state() == STATE_SELECT && refresh)
		refresh_screen();
}

void restore_select_screen()
{
	current_select = Select_Default;
	swap_select_screen(0);
}

void pselect_init_hook()
{
	((void(*)())0x196270)();
	restore_select_screen();
}

void hook_render()
{
	// unlock stuff
	*(int*)(0x5D4D08) = -1;
	*(int*)(0x5D4E10) = -1;
	*(int*)(0x5E47A8) = -1;

	process_mkdhook();
	render();
}


void process_mkdhook()
{
	// select screen stuff
	{
		if (get_game_state() == STATE_SELECT)
		{
			if (!(get_game_mode() == MODE_PUZZLE))
			{
				if (check_switch(0, PAD_L3) || check_switch(1, PAD_L3))
					process_swap_select_screen();
			}
		}
		// reducing amount of calls
		//else
		//{
		//	restore_select_screen();
		//}
	
	}

	if (get_game_state() == STATE_GAME)
	{
		update_characters();
	}

#ifndef PS2_BUILD
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
#endif

}
