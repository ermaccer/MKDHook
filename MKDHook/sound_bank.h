#pragma once
#include "build_config.h"
// 163
#define TOTAL_SOUND_BANKS 163 + TOTAL_NEW_BANKS


enum eNewBanks {
	BANK_C_ICEGIRL = 163,
	BANK_C_BLAZE = 164,
	BANK_C_SHAO_KAHN = 165,
	BANK_FIGHTER_KAHN = 166,
	BANK_C_GORO = 167,
	BANK_FIGHTER_GORO = 168,
	BANK_C_DRAHMIN = 169,
	BANK_C_QUANCHI = 170,
	TOTAL_NEW_BANKS = 8
};

typedef struct
{
	int field0;
	int field4;
	int field8;
	char* name;
	int field16;
	int field20;
	int field24;
	int field28;
	int field32;
} sbank_entry;


extern sbank_entry sbank_data[TOTAL_SOUND_BANKS];

void init_sound_bank_hook();

#ifndef PS2_BUILD
void dump_sound_bank_table();
#endif // !PS2_BUILD


