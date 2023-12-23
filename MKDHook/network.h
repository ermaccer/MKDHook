#pragma once
#define P2P_PACKET_SELECT_DATA 18
#define NETWORK_PLAYER_FLAGS 0x5E4354
typedef struct {
	int p1_id;
	int p1_flags;
	int p2_id;
	int p2_flags;
	// original is 4 bytes, but this is background so can split it into 2 shorts
	short background;
	short whoAmI;
}packet_select_screen_data;


void init_network_hook();

int send_packet(int packetType, void* data, int dataSize);
int select_screen_packet_hook(int packetType, packet_select_screen_data* data, int dataSize);

void process_select_screen_packet(packet_select_screen_data* data);