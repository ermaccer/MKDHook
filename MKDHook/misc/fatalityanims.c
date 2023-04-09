#include "fatalityanims.h"
#include "..\mkdeception.h"
#include "..\ps2mem.h"
#include "..\mips.h"

struct mk_file_entry fatalityanims_entry_table[FATANIMS_FILES] = {
	{"fatalityanims.ssf", 0, 4},
	{"fatality_art.sec", 0, 1},
	{"fat_anims_ashrah1.sec", 0, 2},
	{"fat_anims_ashrah2.sec", 0, 2},
	{"fat_anims_armchew.sec", 0, 2},
	{"fat_anims_armrip.sec", 0, 2},
	{"fat_anims_axethrow.sec", 0, 2},
	{"fat_anims_backpull.sec", 0, 2},
	{"fat_anims_baraka.sec", 0, 2},
	{"fat_anims_baraka2.sec", 0, 2},
	{"fat_anims_bodyslam.sec", 0, 2},
	{"fat_anims_boraicho_1.sec", 0, 2},
	{"fat_anims_boraicho_2.sec", 0, 2},
	{"fat_anims_chinesestar.sec", 0, 2},
	{"fat_anims_crunch.sec", 0, 2},
	{"fat_anims_cutintwo.sec", 0, 2},
	{"fat_anims_fotns_1.sec", 0, 2},
	{"fat_anims_gladiator.sec", 0, 2},
	{"fat_anims_headkick.sec", 0, 2},
	{"fat_anims_heartrip.sec", 0, 2},
	{"fat_anims_invisible.sec", 0, 2},
	{"fat_anims_kenshi.sec", 0, 2},
	{"fat_anims_kenshi2.sec", 0, 2},
	{"fat_anims_kickspin.sec", 0, 2},
	{"fat_anims_kira_1.sec", 0, 2},
	{"fat_anims_kira_2.sec", 0, 2},
	{"fat_anims_legrip_1.sec", 0, 2},
	{"fat_anims_liukang_headrip.sec", 0, 2},
	{"fat_anims_luikang.sec", 0, 2},
	{"fat_anims_mileena.sec", 0, 2},
	{"fat_anims_neckjab.sec", 0, 2},
	{"fat_anims_necktwist.sec", 0, 2},
	{"fat_anims_nightwolf.sec", 0, 2},
	{"fat_anims_ninja.sec", 0, 2},
	{"fat_anims_puzzle.sec", 0, 2},
	{"fat_anims_raiden_1.sec", 0, 2},
	{"fat_anims_raiden_2.sec", 0, 2},
	{"fat_anims_ribrip.sec", 0, 2},
	{"fat_anims_samurai.sec", 0, 2},
	{"fat_anims_scorpion.sec", 0, 2},
	{"fat_anims_shujinko_1.sec", 0, 2},
	{"fat_anims_Shujinko_2.sec", 0, 2},
	{"fat_anims_sindel.sec", 0, 2},
	{"fat_anims_spear2head_1.sec", 0, 2},
	{"fat_anims_spinerip.sec", 0, 2},
	{"fat_anims_stafftwirl.sec", 0, 2},
	{"fat_anims_subzero.sec", 0, 2},
	{"fat_anims_subzero2.sec", 0, 2},
	{"fat_anims_thighrip.sec", 0, 2},
	{"fat_anims_weaponkicks.sec", 0, 2},
	{"fat_anims_kitana_kiss.sec", 0, 2},
	{"fat_anims_jax1.sec", 0, 2},
	{"fat_anims_frost1.sec", 0, 2},
};

// I:\ps2dvd\art\pselect.ssf
struct mk_toc_entry fatalityanims_file_table[FATANIMS_FILES + 1] = {
	{&fatalityanims_entry_table[0], 0, 0},
	{&fatalityanims_entry_table[1], 0, 105728},
	{&fatalityanims_entry_table[2], 0, 94336},
	{&fatalityanims_entry_table[3], 0, 50432},
	{&fatalityanims_entry_table[4], 0, 121984},
	{&fatalityanims_entry_table[5], 0, 91776},
	{&fatalityanims_entry_table[6], 0, 67200},
	{&fatalityanims_entry_table[7], 0, 100864},
	{&fatalityanims_entry_table[8], 0, 104192},
	{&fatalityanims_entry_table[9], 0, 67072},
	{&fatalityanims_entry_table[10], 0, 78336},
	{&fatalityanims_entry_table[11], 0, 102528},
	{&fatalityanims_entry_table[12], 0, 86912},
	{&fatalityanims_entry_table[13], 0, 83840},
	{&fatalityanims_entry_table[14], 0, 78464},
	{&fatalityanims_entry_table[15], 0, 85888},
	{&fatalityanims_entry_table[16], 0, 116608},
	{&fatalityanims_entry_table[17], 0, 92544},
	{&fatalityanims_entry_table[18], 0, 67840},
	{&fatalityanims_entry_table[19], 0, 74496},
	{&fatalityanims_entry_table[20], 0, 84096},
	{&fatalityanims_entry_table[21], 0, 162944},
	{&fatalityanims_entry_table[22], 0, 94336},
	{&fatalityanims_entry_table[23], 0, 53504},
	{&fatalityanims_entry_table[24], 0, 120192},
	{&fatalityanims_entry_table[25], 0, 65920},
	{&fatalityanims_entry_table[26], 0, 92544},
	{&fatalityanims_entry_table[27], 0, 64384},
	{&fatalityanims_entry_table[28], 0, 124032},
	{&fatalityanims_entry_table[29], 0, 104192},
	{&fatalityanims_entry_table[30], 0, 110336},
	{&fatalityanims_entry_table[31], 0, 94848},
	{&fatalityanims_entry_table[32], 0, 73856},
	{&fatalityanims_entry_table[33], 0, 93184},
	{&fatalityanims_entry_table[34], 0, 84736},
	{&fatalityanims_entry_table[35], 0, 37504},
	{&fatalityanims_entry_table[36], 0, 66944},
	{&fatalityanims_entry_table[37], 0, 104832},
	{&fatalityanims_entry_table[38], 0, 77568},
	{&fatalityanims_entry_table[39], 0, 113920},
	{&fatalityanims_entry_table[40], 0, 70016},
	{&fatalityanims_entry_table[41], 0, 76928},
	{&fatalityanims_entry_table[42], 0, 56192},
	{&fatalityanims_entry_table[43], 0, 109312},
	{&fatalityanims_entry_table[44], 0, 65408},
	{&fatalityanims_entry_table[45], 0, 124800},
	{&fatalityanims_entry_table[46], 0, 78208},
	{&fatalityanims_entry_table[47], 0, 102912},
	{&fatalityanims_entry_table[48], 0, 90752},
	{&fatalityanims_entry_table[49], 0, 103936},
	{&fatalityanims_entry_table[50], 0, 97792},
	{&fatalityanims_entry_table[51], 0, 88064},
	{&fatalityanims_entry_table[52], 0, 51328}, // frost

	{0,0,0}
};

void init_fatanims_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < FATANIMS_FILES; i++)
	{
		fatalityanims_entry_table[i].belong = &fatalityanims_file_table[0];
	}


	for (int i = 1; i < FATANIMS_FILES; i++)
	{
		fatalityanims_file_table[i].previousSize = baseSize;
		baseSize += (fatalityanims_file_table[i].size + 2048 - 1) & -2048;
	}
}

void init_fatanims_hook()
{
	init_fatanims_toc(); 
	int val = (int)&fatalityanims_file_table[0];

	patchInt(0x16D3F0, lui(a0, HIWORD(val)));
	patchInt(0x16D3F0 + 4, ori(a0, a0, LOWORD(val)));

	makeJal(0x16D400, load_new_fatanims);
	makeJal(0x26E3B4, load_new_fatanims);
	makeJal(0x26E5F4, load_new_fatanims);



}

void load_new_fatanims()
{
	load_ssf(&fatalityanims_file_table[0]);
}
