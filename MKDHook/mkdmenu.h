#pragma once
#include "mkdeception.h"


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

	MENU_MAX_STRINGS = 8
};

enum eMenuPages {
	MENU_DEFAULT = -1,
	MENU_PLAYER,
	MENU_CAMERA
};

enum eMenuDefault {
	DEFAULT_PLAYER,
	DEFAULT_CAMERA,
	TOTAL_MENU_DEFAULT
};

enum eMenuPlayer {
	PLAYER1_SCALE,
	PLAYER2_SCALE,
	PLAYER_POS_READ,
	TOTAL_PLAYER
};

enum eMenuCamera {
	THIRD_PERSON,
	THIRD_PERSON_LOWER,
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


struct Menu {
	char m_bActive;
	struct CVector plrPos;
};

struct Menu GetMenu();

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
void Menu_ProcessCamera();
void Menu_ClearStrings();