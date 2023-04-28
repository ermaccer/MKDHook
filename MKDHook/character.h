#pragma once
#include "toc.h"

enum characters
{
	SCORPION,
	BARAKA,
	NOOB,
	SUBZERO,
	MILEENA,
	NIGHTWOLF,
	ERMAC,
	ASHRAH,
	SINDEL,
	LI_MEI,
	BORAICHO,
	HOTARU,
	KENSHI,
	SMOKE,
	HAVIK,
	TANYA,
	LIU_KANG,
	GHOST,
	KIRA,
	KABAL,
	KOBRA,
	JADE,
	DAIROU,
	RAIDEN,
	DARRIUS,
	SHUJINKO,
	SHUJINKO_13,
	NOOBSMOKE,
	MONSTER,
	ONAGA,
	MKDA_JAX,
	MKDA_RAIDEN,
	MKDA_QUAN_CHI,
	MKDA_KUNG_LAO,
	MKDA_CAGE,
	MKDA_SONYA,
	MKDA_NITARA,
	MKDA_SHANG_TSUNG,
	MKDA_FROST,
	MKDA_KITANA,
	MKDA_DRAHMIN,
	// restored npcs
	MKDA_KANO,
	MKDA_MOKAP,
	MKDA_BLAZE,

	// new characters
	SONYA,
	// mku
	KITANA,
	JAX,
	FROST,
	BLAZE,
	// mku/gc
	SHAO_KAHN,
	TOTAL_CHARACTERS
};


struct char_info_entry {
	char* name;
	int file_table;
	int alt_file_table;
	char* scriptName;
};


typedef struct {
	int characterID;
	int soundID;
	char* headName;
	char* headLockedName;
	char* bodyName;
	char* bodyArchiveName;
	char* difficulty;
	char* style1;
	char* style2;
	char* style3;
}select_screen_entry;



extern struct char_info_entry pCharTable[TOTAL_CHARACTERS];

void dump_char_table();
void set_char_table();

void init_character_hook();
void init_character_tocs();

int hook_character_lock_status(int id, int param);