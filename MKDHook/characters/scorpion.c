#include "scorpion.h"


struct scan_action scan_scorpion_2 = {
	16907,
	0x3000019,
	9,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1,
	0,
	0
};

struct scan_action_dual scan_scorpion_3 = {
	// move 1
	0,
	0x3000019,
	6,
	MOVE_FORWARD,
	MOVE_BACKWARDS,
	// move 2
	16915,
	0x3000019,
	11,
	MOVE_DOWN,
	MOVE_BACKWARDS,
	-1
};