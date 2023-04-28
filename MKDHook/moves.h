#pragma once

// REFERENCE
//  1 - [] 2 - /\ 3 - X 4 - O


#define DO_FATALITY_ONE 0x202DA0
#define DO_FATALITY_TWO 0x202CE0
#define DO_HARAKIRI		0x202C50

enum scan_enum {
	MOVE_FORWARD = 0x80000001,
	MOVE_BACKWARDS = 0x80000002,
	MOVE_UP = 0x80000003,
	MOVE_DOWN = 0x80000004,
};

struct scan_action {
	int state;
	unsigned int unk;
	unsigned int functionId;
	unsigned int directions[3]; // -1 ends
	unsigned int _unk[5];
};

struct scan_action_dual {
	int state;
	unsigned int unk;
	unsigned int functionId;
	unsigned int directions[2]; // -1 ends

	int state2;
	int unk2;
	unsigned int functionId2;
	unsigned int directions2[3]; // -1 ends
	
};

struct scan_action_dual_fatality {
	int state;
	unsigned int unk;
	unsigned int functionId;
	unsigned int directions[2]; // -1 ends

	// fatality part
	float unkf;
	int unk2f;
	int function;
	unsigned int fdirections[4];


	float unkf2;
	int unk2f2;
	int function2;
	unsigned int fdirections2[5];
};

struct scan_action_triple {
	int state;
	unsigned int unk;
	unsigned int functionId;
	unsigned int directions[2]; // -1 ends

	int state2;
	int unk2;
	unsigned int functionId2;
	unsigned int directions2[2]; // -1 ends

	int state3;
	int unk3;
	unsigned int functionId3;
	unsigned int directions3[3]; // -1 ends

};

struct scan_action_fatality {
	int state;
	unsigned int unk;
	unsigned int functionId;
	unsigned int directions[2]; // -1 ends

	// fatality part
	float unkf;
	int unk2f;
	int function;
	unsigned int fdirections[8]; // -1 ends
};

struct scan_fatality {
	// fatality part
	float unkf;
	int unk2f;
	int function;
	unsigned int fdirections[8]; // -1 ends
};


struct scan_suicide {
	float unkf;
	int unk2f;
	int function;
	unsigned int fdirections[5]; // -1 ends
};


void init_moves_hook();

// hooks
int swap_scan_table_1();
int swap_scan_table_2();
int swap_scan_table_3();
int swap_scan_table_4();

void do_harakiri_hook();

// dumpers 
void dump_scan_table_1();
void dump_scan_table_2();
void dump_scan_table_3();
void dump_scan_table_4();