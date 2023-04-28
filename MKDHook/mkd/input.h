#pragma once

enum pad_button {
	PAD_L2,
	PAD_R2,
	PAD_L1,
	PAD_R1,
	PAD_TRIANGLE,
	PAD_CIRCLE,
	PAD_CROSS,
	PAD_SQUARE,
	PAD_SELECT,
	PAD_L3,
	PAD_R3,
	PAD_START,
	PAD_UP,
	PAD_RIGHT,
	PAD_DOWN,
	PAD_LEFT,
	PAD_ANY,
	PAD_L2R2,

};

int check_switch(int player, int button);
void get_stick_pos(int player, int stick, float* x, float* y);
void scan_switch_sequences(int* action);
int was_button_pressed(int button);
int my_joypad_state_5();