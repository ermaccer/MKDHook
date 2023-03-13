#pragma once
#define TOTAL_SOUNDS 7224 + EXTRA_SOUNDS
#define EXTRA_SOUNDS TOTAL_NEW_SOUNDS

typedef struct {
	int field0;
	int field4;
	int field8;
	int field12;
	float volume;
	int field20;
	int field24;
}sound_entry;

enum eNewSounds {
	SOUND_SONYA_SELECT = 7224,
	SOUND_SONYA_WINS = 7225,
	SOUND_KITANA_SELECT,
	SOUND_KITANA_WINS,
	SOUND_ONAGA_SELECT,
	SOUND_KITANA_FANLIFT,
	SOUND_KITANA_KISS,
	SOUND_KITANA_FAT_STRETCH,
	SOUND_KITANA_FAT_UNSTRETCH,
	SOUND_KITANA_FAT_BLOWUP,
	SOUND_JAX_FAT_SPLAT,
	SOUND_JAX_SP_GUN,
	SOUND_JAX_SELECT,
	SOUND_JAX_WINS,
	TOTAL_NEW_SOUNDS = 14
};

extern sound_entry mk_sound_table[TOTAL_SOUNDS];

void init_sound_hook();

void dump_sound_table();
