#include <stdio.h>
#include "ps2mem.h"
#include "mkdeception.h"
#include "mkdplrinfo.h"
#include "mkdhook.h"
#include "mkdmenu.h"

int CompatibleCRCList[] = { 0x43341C03 };
void init()
{
    MKDeception_Init();

    //calculate_custom_toc();
    //set_char_table();
    //dump_char_table();


   // skip intro
   *(int*)0x1980F8 = 0;
   *(int*)0x197DF8 = 0;

   makeJal(0x1328E0, hook_character_lock_status);
   makeJal(0x134278, hook_character_lock_status);
   makeJal(0x15DE88, hook_character_lock_status);
   makeJal(0x191AB4, hook_character_lock_status);
   makeJal(0x191B60, hook_character_lock_status);
   makeJal(0x191E84, hook_character_lock_status);
   makeJal(0x1944E0, hook_character_lock_status);
   makeJal(0x194C98, hook_character_lock_status);
   makeJal(0x19508C, hook_character_lock_status);
   makeJal(0x195730, hook_character_lock_status);
   makeJal(0x196FE8, hook_character_lock_status);
   makeJal(0x197074, hook_character_lock_status);
   makeJal(0x2DB048, hook_character_lock_status);
   makeJal(0x387264, hook_character_lock_status);
   makeJal(0x3873F4, hook_character_lock_status);
   makeJal(0x3ED1FC, hook_character_lock_status);
   makeJal(0x3ED398, hook_character_lock_status);
   makeJal(0x3EDEEC, hook_character_lock_status);

   makeJal(0x1238FC, hook_render);
   
   makeJal(0x1A50FC, Menu_Init);
   game_printf("MKDHook init!\n");
  // *(float*)(0x5E8C60) = 16 / 9;
  // *(float*)(0x5E8C64) = 110.0f;

}

int main()
{
    return 0;
}
