#pragma once
#define TOTAL_SOUNDS 7224 + EXTRA_SOUNDS
#define EXTRA_SOUNDS 2

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
};

extern sound_entry mk_sound_table[TOTAL_SOUNDS];

void init_sound_hook();

void dump_sound_table();
