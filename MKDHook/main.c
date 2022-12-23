#include <stdio.h>
#include "ps2mem.h"
#include "mkdeception.h"
#include "character.h"
#include "mkdhook.h"
#include "mkdmenu.h"
#include "stage.h"
#include "ladder.h"
#include "moves.h"

int CompatibleCRCList[] = { 0x7C22850A };

void dummy() {}
int dummy_true() { return 1; }

void init()
{
    MKDeception_Init();
    Menu_Init_Vars();


   // skip intro
   *(int*)0x197258 = 0;
   *(int*)0x196F58 = 0;
   makeJmp(0x197698, (void*)0x19776C);

   makeJal(0x1238C4, hook_render);
   makeJal(0x1A3EFC, Menu_Init);

   init_character_hook();
   init_stage_hook();
   init_ladder_hook();
   init_moves_hook();

   game_printf("MKDHook init!\n");
}

int main()
{
    return 0;
}
