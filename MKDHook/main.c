#include <stdio.h>
#include "ps2mem.h"
#include "mkdeception.h"
#include "mkdplrinfo.h"
#include "mkdhook.h"
#include "mkdmenu.h"
#include "stage.h"

void dummy() {}
int dummy_true() { return 1; }
int CompatibleCRCList[] = { 0x7C22850A };
void init()
{
    MKDeception_Init();
    Menu_Init_Vars();
    //calculate_custom_toc();
    //set_char_table();
    //dump_char_table();


   // skip intro
   *(int*)0x197258 = 0;
   *(int*)0x196F58 = 0;


   makeJal(0x132750, hook_character_lock_status);
   makeJal(0x1340E8, hook_character_lock_status);
   makeJal(0x15D3E8, hook_character_lock_status);
   makeJal(0x190CF4, hook_character_lock_status);
   makeJal(0x190DA0, hook_character_lock_status);
   makeJal(0x191074, hook_character_lock_status);
   makeJal(0x193690, hook_character_lock_status);
   makeJal(0x193DE8, hook_character_lock_status);
   makeJal(0x1941DC, hook_character_lock_status);
   makeJal(0x194880, hook_character_lock_status);
   makeJal(0x196138, hook_character_lock_status);
   makeJal(0x1961C4, hook_character_lock_status);
   makeJal(0x2D8878, hook_character_lock_status);
   makeJal(0x3827A4, hook_character_lock_status);
   makeJal(0x382934, hook_character_lock_status);
   makeJal(0x3E835C, hook_character_lock_status);
   makeJal(0x3E84F8, hook_character_lock_status);
   makeJal(0x3E8F8C, hook_character_lock_status);
  
   makeJal(0x1238C4, hook_render);
   
   makeJal(0x1A3EFC, Menu_Init);

   init_stage_hook();
    

   game_printf("MKDHook init!\n");
  // *(float*)(0x5E8C60) = 16 / 9;
   //*(float*)(0x5D4DD4) = 95.0f;
}

int main()
{
    return 0;
}
