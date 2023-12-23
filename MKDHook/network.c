#include "network.h"
#include "mkdeception.h"
#include "mips.h"
#include "ps2mem.h"

void init_network_hook()
{
    // allow both players to send packets, by default only P1 sends select info
    NOP(0x195D60);
    // replace select screen IDs with actual selected IDs, also reports network pid
    makeJal(0x195D70, select_screen_packet_hook);
    // replace packet 18 function
    makeJmp(0x192690, process_select_screen_packet);
}

int send_packet(int packetType, void* data, int dataSize)
{
    return ((int(*)(int, void*, int))0x3F5780)(packetType, data, dataSize);
}

int select_screen_packet_hook(int packetType, packet_select_screen_data* data, int dataSize)
{
    player_info* p1 = (player_info*)PLAYER1_INFO;
    player_info* p2 = (player_info*)PLAYER2_INFO;
    int network_flags = *(int*)NETWORK_PLAYER_FLAGS;

    data->p1_id = p1->characterID;
    data->p2_id = p2->characterID;

    data->background = *(int*)(CUR_BGND);

    short myID = 1;
    if (network_flags & 2)
        myID = 0;
    data->whoAmI = myID;

    return send_packet(packetType, data, dataSize);
}

void process_select_screen_packet(packet_select_screen_data* data)
{
    player_info* p1 = (player_info*)PLAYER1_INFO;
    player_info* p2 = (player_info*)PLAYER2_INFO;

    short myID = data->whoAmI;

    if (myID == 1)
    {
        p2->characterID = data->p2_id;
        p2->flags = data->p2_flags;
    }
    else
    {
        p1->characterID = data->p1_id;
        p1->flags = data->p1_flags;
    }

    *(int*)(CUR_BGND) = data->background;
}
