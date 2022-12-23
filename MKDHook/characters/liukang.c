#include "liukang.h"


struct scan_action scan_lk_2 = {
	16976,
	0x3000019,
	16,
	MOVE_FORWARD,
	MOVE_FORWARD,
	-1,
	0,
	0
};


struct scan_action_fatality scan_lk_3 = {
	16953,
	0x3000019,
	24,
	MOVE_DOWN,
	MOVE_FORWARD,

	// fatality part
	0x3FFFFFFE,
	0x1000032,
	0x202CE0,
	MOVE_FORWARD,
	MOVE_FORWARD,
	MOVE_UP,
	MOVE_UP
	-1
};


struct scan_action scan_lk_4 = {
	12801,
	0x3000019,
	15,
	MOVE_FORWARD,
	MOVE_FORWARD,
	-1,
	0,
	0
};