#pragma once
#include "mkdeception.h"
#include "mouse.h"
#include "types.h"
#include "characters/character_list.h"
#include "build_config.h"

//#define SOUNDDEBUG_KEY

enum eMenuStringIDs
{
	MENU_BAR_0 = 38420,
	MENU_BAR_1,
	MENU_BAR_2,
	MENU_BAR_3,
	MENU_BAR_4,
	MENU_BAR_5,
	MENU_BAR_6,
	MENU_BAR_7,
	MENU_BAR_8,
	MENU_BAR_9,

	MENU_MAX_STRINGS = 10
};

enum eMenuPages {
	MENU_DEFAULT = -1,
	MENU_PLAYER,
	MENU_CAMERA,
	MENU_SPEED,
	MENU_MISC
};

enum eMenuDefault {
	DEFAULT_PLAYER,
	DEFAULT_CAMERA,
	DEFAULT_SPEED,
	DEFAULT_MISC,
	TOTAL_MENU_DEFAULT
};

enum eMenuPlayer {
	PLAYER1_SCALE,
	PLAYER2_SCALE,
	SCALE_MODIFIER,
	SCALE_RESET_VALUES,
	TOTAL_PLAYER
};

enum eMenuSpeed {
	SLOWMOTION,
	FREEZE_WORLD,
	RESET_SPEED,
	TOTAL_SPEED
};

enum eMenuMisc {
	KILL_HUD,
	DISABLE_FAT_CAMERA,
	ENABLE_FAT_CAMERA,
	CHUB_MODE,
	SKINNY_MODE,
	TOTAL_MISC
};

enum eMenuCamera {
	FIRST_PERSON,
	THIRD_PERSON,
	FOV_72,
	FOV_90,
	FOV_95,
	FOV_110,
	FOV_120,
	FREE_CAMERA,
	TOTAL_CAMERA
};

enum eScaleValue {
	NORMAL,
	SMALL,
	LARGE,
	XL,
	TWOD,
	TOTAL_SCALE_VALUES
};

extern CVector camPos;
extern CVector camRot;

struct Menu {
	char m_bActive;
	char m_bIsReady;
	CVector plrPos;
};

struct Menu GetMenu();

#ifndef  PS2_BUILD
int Menu_Init(int id, int font, char* text, int x, int y, int unk);
void Menu_Draw();
void Menu_Process();
void Menu_Process_Toggles();
void Menu_Toggle();
void Menu_KeyUp();
void Menu_KeyDown();
void Menu_KeyCross();
void Menu_KeyCircle();
void Menu_KeyTriangle();
void Menu_ProcessPlayer();
void Menu_ProcessPlayerReverse();
void Menu_ProcessMisc();
void Menu_ProcessSpeed();
void Menu_ProcessCamera();
void Menu_ClearStrings();
void Menu_Unset();
void Menu_ProcessCustomCams();
void Menu_ProcessFreeCamera();
void Menu_Toggle_FreeCam();
void Menu_Toggle_KFP();
void Menu_Toggle_KFP_Look();
void Menu_Toggle_KHud();
void Menu_Toggle_FreezeWorld();
void setFov(float value);
void Menu_Init_Vars();
void Menu_K_Reset();
void disable_fatality_camera();
void enable_fatality_camera();
void enable_chubbozo_mode();
void enable_skinny_mode();
void enable_bigheads();

// funcs

void update_player1_scale();
void update_player2_scale();

void test_sound();

// konquest 
void konquest_camera();
void Konquest_Process_Cameras();




#endif // ! PS2_BUILD

