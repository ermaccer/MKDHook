#include "sound_bank.h"
#include <stdio.h>
#include "mkdeception.h"
#include "ps2mem.h"
#include "mips.h"


sbank_entry sbank_data[TOTAL_SOUND_BANKS] = {
	{0, 0, 0, "permanent", 0, 0, 0, 0, 0 }, //   0
	{0, 0, 0, "shell", 0, 0, 0, 0, 1 }, //   1
	{0, 0, 0, "shell_music", 0, 0, 0, 0, 2 }, //   2
	{0, 0, 0, "music_one_player_path", 0, 0, 0, 0, 3 }, //   3
	{0, 0, 0, "shell_jukebox", 0, 0, 0, 0, 4 }, //   4
	{0, 0, 0, "crypt", 0, 0, 0, 0, 5 }, //   5
	{0, 0, 0, "announcr", 0, 0, 0, 0, 6 }, //   6
	{0, 0, 0, "announcr_names", 0, 0, 0, 0, 7 }, //   7
	{0, 0, 0, "fightfx1", 0, 0, 0, 0, 8 }, //   8
	{0, 0, 0, "music_fatality", 0, 0, 0, 0, 9 }, //   9
	{0, 0, 0, "music_endings", 0, 0, 0, 0, 10 }, //  10
	{0, 0, 0, "music_tune_1", 0, 0, 0, 0, 11 }, //  11
	{0, 0, 1, "music_tune_2", 0, 0, 0, 0, 12 }, //  12
	{0, 0, 2, "music_tune_3", 0, 0, 0, 0, 13 }, //  13
	{0, 0, 3, "music_tune_4", 0, 0, 0, 0, 14 }, //  14
	{0, 0, 4, "music_tune_5", 0, 0, 0, 0, 15 }, //  15
	{0, 0, 5, "music_tune_6", 0, 0, 0, 0, 16 }, //  16
	{0, 0, 6, "music_tune_7", 0, 0, 0, 0, 17 }, //  17
	{0, 0, 7, "music_tune_8", 0, 0, 0, 0, 18 }, //  18
	{0, 0, 8, "music_tune_9", 0, 0, 0, 0, 19 }, //  19
	{0, 0, 9, "music_tune_10", 0, 0, 0, 0, 20 }, //  20
	{0, 0, 10, "music_tune_11", 0, 0, 0, 0, 21 }, //  21
	{0, 0, 11, "music_tune_12", 0, 0, 0, 0, 22 }, //  22
	{0, 0, 12, "music_tune_deadpool", 0, 0, 0, 0, 23 }, //  23
	{0, 0, 13, "music_tune_forest", 0, 0, 0, 0, 24 }, //  24
	{0, 0, 14, "music_tune_portal", 0, 0, 0, 0, 25 }, //  25
	{0, 0, 15, "music_tune_courtyard", 0, 0, 0, 0, 26 }, //  26
	{0, 0, 16, "music_tune_pit", 0, 0, 0, 0, 27 }, //  27
	{0, 0, 17, "music_boss_fight", 0, 0, 0, 0, 28 }, //  28
	{0, 0, 18, "music_tune_yin_yang", 0, 0, 0, 0, 29 }, //  29
	{0, 0, 0, "bg_beetle_lair", 0, 0, 0, 0, 30 }, //  30
	{0, 0, 1, "bg_slaughterhouse", 0, 0, 0, 0, 31 }, //  31
	{0, 0, 2, "bg_red_dragon", 0, 0, 0, 0, 32 }, //  32
	{0, 0, 3, "bg_sky_temple", 0, 0, 0, 0, 33 }, //  33
	{0, 0, 4, "bg_hell_foundry", 0, 0, 0, 0, 34 }, //  34
	{0, 0, 5, "bg_nether_belly", 0, 0, 0, 0, 35 }, //  35
	{0, 0, 6, "bg_kollapsing_kliffs", 0, 0, 0, 0, 36 }, //  36
	{0, 0, 7, "bg_dark_prison", 0, 0, 0, 0, 37 }, //  37
	{0, 0, 8, "bg_lost_warriors", 0, 0, 0, 0, 38 }, //  38
	{0, 0, 9, "bg_yinyang", 0, 0, 0, 0, 39 }, //  39
	{0, 0, 10, "bg_dragon_mountain", 0, 0, 0, 0, 40 }, //  40
	{0, 0, 11, "bg_dking_temple", 0, 0, 0, 0, 41 }, //  41
	{0, 0, 12, "bg_kuatan_palace", 0, 0, 0, 0, 42 }, //  42
	{0, 0, 13, "bg_lower_mines", 0, 0, 0, 0, 43 }, //  43
	{0, 0, 14, "bg_qc_fortress", 0, 0, 0, 0, 44 }, //  44
	{0, 0, 15, "bg_liukang_tomb", 0, 0, 0, 0, 45 }, //  45
	{0, 0, 16, "bg_dark_prison_vo", 0, 0, 0, 0, 46 }, //  46
	{0, 0, 17, "bg_nexus", 0, 0, 0, 0, 47 }, //  47
	{0, 0, 18, "chess_bg_deadpool", 0, 0, 0, 0, 48 }, //  48
	{0, 0, 19, "chess_bg_portal", 0, 0, 0, 0, 49 }, //  49
	{0, 0, 20, "chess_bg_courtyard", 0, 0, 0, 0, 50 }, //  50
	{0, 0, 21, "chess_bg_living_forest", 0, 0, 0, 0, 51 }, //  51
	{0, 0, 22, "chess_bg_the_pit", 0, 0, 0, 0, 52 }, //  52
	{0, 0, 0, "c_jax", 0, 0, 0, 0, 53 }, //  53
	{0, 0, 1, "c_scorpion", 0, 0, 0, 0, 54 }, //  54
	{0, 0, 2, "c_subzero", 0, 0, 0, 0, 55 }, //  55
	{0, 0, 3, "c_baraka", 0, 0, 0, 0, 56 }, //  56
	{0, 0, 4, "c_ermac", 0, 0, 0, 0, 57 }, //  57
	{0, 0, 5, "c_hutaro", 0, 0, 0, 0, 58 }, //  58
	{0, 0, 6, "c_kenshi", 0, 0, 0, 0, 59 }, //  59
	{0, 0, 7, "c_limai", 0, 0, 0, 0, 60 }, //  60
	{0, 0, 8, "c_liukang", 0, 0, 0, 0, 61 }, //  61
	{0, 0, 9, "c_mileena", 0, 0, 0, 0, 62 }, //  62
	{0, 0, 10, "c_nightwolf", 0, 0, 0, 0, 63 }, //  63
	{0, 0, 11, "c_sindel", 0, 0, 0, 0, 64 }, //  64
	{0, 0, 12, "c_boraicho", 0, 0, 0, 0, 65 }, //  65
	{0, 0, 13, "c_ashrah", 0, 0, 0, 0, 66 }, //  66
	{0, 0, 14, "c_jade", 0, 0, 0, 0, 67 }, //  67
	{0, 0, 15, "c_kabal", 0, 0, 0, 0, 68 }, //  68
	{0, 0, 16, "c_darrius", 0, 0, 0, 0, 69 }, //  69
	{0, 0, 17, "c_dragon_king", 0, 0, 0, 0, 70 }, //  70
	{0, 0, 18, "c_kira", 0, 0, 0, 0, 71 }, //  71
	{0, 0, 19, "c_smoke_noob", 0, 0, 0, 0, 72 }, //  72
	{0, 0, 20, "c_dairu", 0, 0, 0, 0, 73 }, //  73
	{0, 0, 21, "c_havik", 0, 0, 0, 0, 74 }, //  74
	{0, 0, 22, "c_kobra", 0, 0, 0, 0, 75 }, //  75
	{0, 0, 23, "c_raiden", 0, 0, 0, 0, 76 }, //  76
	{0, 0, 24, "c_shujinko", 0, 0, 0, 0, 77 }, //  77
	{0, 0, 25, "c_tanya", 0, 0, 0, 0, 78 }, //  78
	{0, 0, 0, "fs_concrete", 0, 0, 0, 0, 79 }, //  79
	{0, 0, 1, "fs_marble", 0, 0, 0, 0, 80 }, //  80
	{0, 0, 2, "fs_dirt", 0, 0, 0, 0, 81 }, //  81
	{0, 0, 3, "fs_wood", 0, 0, 0, 0, 82 }, //  82
	{0, 0, 0, "fighter_mlna", 0, 0, 0, 0, 83 }, //  83
	{0, 0, 1, "fighter_sz", 0, 0, 0, 0, 84 }, //  84
	{0, 0, 2, "fighter_brc", 0, 0, 0, 0, 85 }, //  85
	{0, 0, 3, "fighter_shuj_k", 0, 0, 0, 0, 86 }, //  86
	{0, 0, 4, "fighter_ashrah", 0, 0, 0, 0, 87 }, //  87
	{0, 0, 5, "fighter_baraka", 0, 0, 0, 0, 88 }, //  88
	{0, 0, 6, "fighter_dairu", 0, 0, 0, 0, 89 }, //  89
	{0, 0, 7, "fighter_ermac", 0, 0, 0, 0, 90 }, //  90
	{0, 0, 8, "fighter_hotaru", 0, 0, 0, 0, 91 }, //  91
	{0, 0, 9, "fighter_jade", 0, 0, 0, 0, 92 }, //  92
	{0, 0, 10, "fighter_kabal", 0, 0, 0, 0, 93 }, //  93
	{0, 0, 11, "fighter_kenshi", 0, 0, 0, 0, 94 }, //  94
	{0, 0, 12, "fighter_kira", 0, 0, 0, 0, 95 }, //  95
	{0, 0, 13, "fighter_kobra", 0, 0, 0, 0, 96 }, //  96
	{0, 0, 14, "fighter_limei", 0, 0, 0, 0, 97 }, //  97
	{0, 0, 15, "fighter_lk", 0, 0, 0, 0, 98 }, //  98
	{0, 0, 16, "fighter_nwolf", 0, 0, 0, 0, 99 }, //  99
	{0, 0, 17, "fighter_raiden", 0, 0, 0, 0, 100 }, // 100
	{0, 0, 18, "fighter_scorp", 0, 0, 0, 0, 101 }, // 101
	{0, 0, 19, "fighter_sebek", 0, 0, 0, 0, 102 }, // 102
	{0, 0, 20, "fighter_shuj", 0, 0, 0, 0, 103 }, // 103
	{0, 0, 21, "fighter_sindel", 0, 0, 0, 0, 104 }, // 104
	{0, 0, 22, "fighter_smnoob", 0, 0, 0, 0, 105 }, // 105
	{0, 0, 23, "fighter_tanya", 0, 0, 0, 0, 106 }, // 106
	{0, 0, 24, "fighter_jkelly", 0, 0, 0, 0, 107 }, // 107
	{0, 0, 25, "fighter_dking", 0, 0, 0, 0, 108 }, // 108
	{0, 0, 0, "chess", 0, 0, 0, 0, 109 }, // 109
	{0, 0, 0, "chess_music", 0, 0, 0, 0, 110 }, // 110
	{0, 0, 0, "chess_trans", 0, 0, 0, 0, 111 }, // 111
	{0, 0, 0, "konq_nis_intro", 0, 0, 0, 0, 112 }, // 112
	{0, 0, 0, "konq_map_general", 0, 0, 0, 0, 113 }, // 113
	{0, 0, 0, "konq_er1_map", 0, 0, 0, 0, 114 }, // 114
	{0, 0, 0, "konq_er2_map", 0, 0, 0, 0, 115 }, // 115
	{0, 0, 0, "konq_nr1_map", 0, 0, 0, 0, 116 }, // 116
	{0, 0, 0, "konq_kr1_map", 0, 0, 0, 0, 117 }, // 117
	{0, 0, 0, "konq_nx1_map", 0, 0, 0, 0, 118 }, // 118
	{0, 0, 0, "konq_ed1_map", 0, 0, 0, 0, 119 }, // 119
	{0, 0, 0, "konq_or1_map", 0, 0, 0, 0, 120 }, // 120
	{0, 0, 0, "konq_ow1_map", 0, 0, 0, 0, 121 }, // 121
	{0, 0, 0, "konq_er1_map_vo", 0, 0, 0, 0, 122 }, // 122
	{0, 0, 0, "konq_er2_map_vo", 0, 0, 0, 0, 123 }, // 123
	{0, 0, 0, "konq_nx1_map_vo", 0, 0, 0, 0, 124 }, // 124
	{0, 0, 0, "konq_ed1_map_vo", 0, 0, 0, 0, 125 }, // 125
	{0, 0, 0, "konq_or1_map_vo", 0, 0, 0, 0, 126 }, // 126
	{0, 0, 0, "konq_ow1_map_vo", 0, 0, 0, 0, 127 }, // 127
	{0, 0, 0, "konq_kr1_map_vo", 0, 0, 0, 0, 128 }, // 128
	{0, 0, 0, "konq_nr1_map_vo", 0, 0, 0, 0, 129 }, // 129
	{0, 0, 0, "konq_mission_general", 0, 0, 0, 0, 130 }, // 130
	{0, 0, 0, "konq_er1_mission", 0, 0, 0, 0, 131 }, // 131
	{0, 0, 0, "konq_er2_mission", 0, 0, 0, 0, 132 }, // 132
	{0, 0, 0, "konq_nr1_mission", 0, 0, 0, 0, 133 }, // 133
	{0, 0, 0, "konq_nx1_mission", 0, 0, 0, 0, 134 }, // 134
	{0, 0, 0, "konq_ed1_mission", 0, 0, 0, 0, 135 }, // 135
	{0, 0, 0, "konq_or1_mission", 0, 0, 0, 0, 136 }, // 136
	{0, 0, 0, "konq_ow1_mission", 0, 0, 0, 0, 137 }, // 137
	{0, 0, 0, "konq_kr1_mission", 0, 0, 0, 0, 138 }, // 138
	{0, 0, 0, "konq_er1_mission_vo", 0, 0, 0, 0, 139 }, // 139
	{0, 0, 0, "puzzle", 0, 0, 0, 0, 140 }, // 140
	{0, 0, 0, "pf_fightfx1", 0, 0, 0, 0, 141 }, // 141
	{0, 0, 0, "pf_super_arrange", 0, 0, 0, 0, 142 }, // 142
	{0, 0, 1, "pf_super_doublebomb", 0, 0, 0, 0, 143 }, // 143
	{0, 0, 2, "pf_super_drill", 0, 0, 0, 0, 144 }, // 144
	{0, 0, 3, "pf_super_jumble", 0, 0, 0, 0, 145 }, // 145
	{0, 0, 4, "pf_super_kollapse", 0, 0, 0, 0, 146 }, // 146
	{0, 0, 5, "pf_super_levitate", 0, 0, 0, 0, 147 }, // 147
	{0, 0, 6, "pf_super_stack", 0, 0, 0, 0, 148 }, // 148
	{0, 0, 7, "pf_super_storm", 0, 0, 0, 0, 149 }, // 149
	{0, 0, 8, "pf_super_freeze", 0, 0, 0, 0, 150 }, // 150
	{0, 0, 9, "pf_super_inviso", 0, 0, 0, 0, 151 }, // 151
	{0, 0, 10, "pf_super_breaker_buster", 0, 0, 0, 0, 152 }, // 152
	{0, 0, 11, "pf_super_edger", 0, 0, 0, 0, 153 }, // 153
	{0, 0, 26, "pf_jax", 0, 0, 0, 0, 154 }, // 154
	{0, 0, 27, "pf_scorpion", 0, 0, 0, 0, 155 }, // 155
	{0, 0, 0, "pf_fat_crusher", 0, 0, 0, 0, 156 }, // 156
	{0, 0, 1, "pf_fat_grinder", 0, 0, 0, 0, 157 }, // 157
	{0, 0, 2, "pf_fat_weight", 0, 0, 0, 0, 158 }, // 158
	{0, 0, 3, "pf_fat_fire", 0, 0, 0, 0, 159 }, // 159
	{0, 0, 4, "pf_fat_lightning", 0, 0, 0, 0, 160 }, // 160
	{0, 0, 5, "pf_fat_snake", 0, 0, 0, 0, 161 }, // 161
	{0, 0, 6, "pf_fat_stomper", 0, 0, 0, 0, 162 }, // 162
	{0, 0, 26, "c_icegirl", 0, 0, 0, 0, 163 }, //  163
	{0, 0, 27, "c_blaze", 0, 0, 0, 0, 164 }, //  164
};

void init_sound_bank_hook()
{
	// num
	patchShort(0x129C2C, TOTAL_SOUND_BANKS);
	patchShort(0x129C8C, TOTAL_SOUND_BANKS);

	patchShort(0x12A2E8, TOTAL_SOUND_BANKS);
	patchShort(0x12A3AC, TOTAL_SOUND_BANKS);

	patchShort(0x12A4E0, TOTAL_SOUND_BANKS);

	patchShort(0x12A754, TOTAL_SOUND_BANKS);

	patchShort(0x12A950, TOTAL_SOUND_BANKS);

	patchShort(0x12AB70, TOTAL_SOUND_BANKS);


	int val;
	val = (int)&sbank_data[0];
	// field0

	patchInt(0x129354, lui(v0, HIWORD(val)));
	patchInt(0x12935C, ori(v0, v0, LOWORD(val)));

	patchInt(0x129C58, lui(v0, HIWORD(val)));
	patchInt(0x129C60, ori(v0, v0, LOWORD(val)));

	patchInt(0x12A040, lui(v1, HIWORD(val)));
	patchInt(0x12A048, ori(v1, v1, LOWORD(val)));

	patchInt(0x12A220, lui(v1, HIWORD(val)));
	patchInt(0x12A228, ori(v1, v1, LOWORD(val)));

	patchInt(0x12A220, lui(v1, HIWORD(val)));
	patchInt(0x12A228, ori(v1, v1, LOWORD(val)));

	patchInt(0x12A2C4, lui(v1, HIWORD(val)));
	patchInt(0x12A2CC, ori(v1, v1, LOWORD(val)));

	patchInt(0x12A380, lui(a0, HIWORD(val)));
	patchInt(0x12A388, ori(a0, a0, LOWORD(val)));

	patchInt(0x12A4BC, lui(v1, HIWORD(val)));
	patchInt(0x12A4C4, ori(v1, v1, LOWORD(val)));

	patchInt(0x12A7F0, lui(a0, HIWORD(val)));
	patchInt(0x12A7F8, ori(a0, a0, LOWORD(val)));

	patchInt(0x12A81C, lui(a1, HIWORD(val)));
	patchInt(0x12A82C, ori(a1, a1, LOWORD(val)));

	patchInt(0x12A858, lui(a1, HIWORD(val)));
	patchInt(0x12A868, ori(a1, a1, LOWORD(val)));

	patchInt(0x12A894, lui(a1, HIWORD(val)));
	patchInt(0x12A8A4, ori(a1, a1, LOWORD(val)));

	patchInt(0x12A8D4, lui(a1, HIWORD(val)));
	patchInt(0x12A8E4, ori(a1, a1, LOWORD(val)));

	patchInt(0x12AA04, lui(v1, HIWORD(val)));
	patchInt(0x12AA0C, ori(v1, v1, LOWORD(val)));

	patchInt(0x12AA7C, lui(v0, HIWORD(val)));
	patchInt(0x12AA84, ori(v0, v0, LOWORD(val)));

	patchInt(0x12ABBC, lui(v1, HIWORD(val)));
	patchInt(0x12ABBC + 4, ori(v1, v1, LOWORD(val)));

	patchInt(0x12ABDC, lui(v1, HIWORD(val)));
	patchInt(0x12ABDC + 4, ori(v1, v1, LOWORD(val)));

	patchInt(0x12B474, lui(v1, HIWORD(val)));
	patchInt(0x12B47C, ori(v1, v1, LOWORD(val)));

	// field4
	val += 4;

	patchInt(0x12A7FC, lui(v1, HIWORD(val)));
	patchInt(0x12A804, ori(v1, v1, LOWORD(val)));

	patchInt(0x12A830, lui(a0, HIWORD(val)));
	patchInt(0x12A824, ori(a0, a0, LOWORD(val)));

	patchInt(0x12A860, lui(a0, HIWORD(val)));
	patchInt(0x12A86C, ori(a0, a0, LOWORD(val)));

	patchInt(0x12A89C, lui(a0, HIWORD(val)));
	patchInt(0x12A8A8, ori(a0, a0, LOWORD(val)));

	patchInt(0x12A8DC, lui(a0, HIWORD(val)));
	patchInt(0x12A8E8, ori(a0, a0, LOWORD(val)));

	patchInt(0x12AA64, lui(v1, HIWORD(val)));
	patchInt(0x12AA64 + 4, ori(v1, v1, LOWORD(val)));

	patchInt(0x12ABF0, lui(a0, HIWORD(val)));
	patchInt(0x12ABF8, ori(a0, a0, LOWORD(val)));

	// field8
	val += 4;

	patchInt(0x12AAF4, lui(v1, HIWORD(val)));
	patchInt(0x12AAFC, ori(v1, v1, LOWORD(val)));

	// name
	val += 4;

	patchInt(0x12AA2C, lui(v0, HIWORD(val)));
	patchInt(0x12AA34, ori(v0, v0, LOWORD(val)));

	patchInt(0x12AB90, lui(v0, HIWORD(val)));
	patchInt(0x12AB98, ori(v0, v0, LOWORD(val)));

	// field16
	val += 4;

	patchInt(0x12AA94, lui(v0, HIWORD(val)));
	patchInt(0x12AA9C, ori(v0, v0, LOWORD(val)));

	// field20
	val += 4;

	patchInt(0x12A834, lui(v1, HIWORD(val)));
	patchInt(0x12A83C, ori(v1, v1, LOWORD(val)));

	patchInt(0x12A870, lui(v1, HIWORD(val)));
	patchInt(0x12A878, ori(v1, v1, LOWORD(val)));

	patchInt(0x12A8AC, lui(v1, HIWORD(val)));
	patchInt(0x12A8B4, ori(v1, v1, LOWORD(val)));

	patchInt(0x12A8EC, lui(v1, HIWORD(val)));
	patchInt(0x12A8F4, ori(v1, v1, LOWORD(val)));

	patchInt(0x12AAD8, lui(v0, HIWORD(val)));
	patchInt(0x12AAE0, ori(v0, v0, LOWORD(val)));

	// field24
	val += 4;

	patchInt(0x12AAB4, lui(v0, HIWORD(val)));
	patchInt(0x12AABC, ori(v0, v0, LOWORD(val)));

	// field28
	val += 4;

	patchInt(0x12AAB8, lui(v1, HIWORD(val)));
	patchInt(0x12AAC0, ori(v1, v1, LOWORD(val)));

	val = (int)&sbank_data[141];
	patchInt(0x129334, lui(v0, HIWORD(val)));
	patchInt(0x12933C, ori(v0, v0, LOWORD(val)));

	patchInt(0x12B454, lui(v1, HIWORD(val)));
	patchInt(0x12B45C, ori(v1, v1, LOWORD(val)));
}

void dump_sound_bank_table()
{
	int addr = 0x4F9950;
	_printf("DUMPING SOUND banks\n");
	char msgBuffer[1256] = {};
	for (int i = 0; i < TOTAL_SOUND_BANKS; i++)
	{
		sbank_entry snd = *(sbank_entry*)(addr + (sizeof(sbank_entry) * i));
		//	sprintf(msgBuffer, "{%d, %d, %d, %d, %x, %d, %d},\n", snd.field0, snd.field4, snd.field8, snd.field12, snd.volume, snd.field20, snd.field24);
		_printf("{%d, %d, %d, \"%s\", %d, %d, %d, ", snd.field0, snd.field4, snd.field8, snd.name, snd.field16, snd.field20, snd.field24);
		_printf("%d, %d }", snd.field28, snd.field32);
		_printf(" # %3d\n", i);
	}
}
