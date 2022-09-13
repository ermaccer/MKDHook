#include "mkdmenu.h"
#include <stdio.h>
#define TRUE_FALSE(x) x ? "true" : "false"

struct Menu TheMenu;

int m_nCurrentPos = 0;
int m_nCurrentMenuOpen = MENU_DEFAULT;
int m_nTimer = 0;

int m_bScaleModifier = 0;
float m_nP1Scale = 1.0;
float m_nP2Scale = 1.0;

int m_bThirdPersonCam = 0;
int m_bThirdPersonCamMid = 0;

int menuAssoc[MENU_MAX_STRINGS * 2] =
{
	MENU_BAR_0,
	MENU_BAR_1,
	MENU_BAR_2,
	MENU_BAR_3,
	MENU_BAR_4,
	MENU_BAR_5,
	MENU_BAR_6,
	MENU_BAR_7
};

int menuStrings[MENU_MAX_STRINGS];
int titleBar;

char* menuNames[MENU_MAX_STRINGS] =
{
	"Player",
	"Camera"
};

char* menuNamesPlayer[MENU_MAX_STRINGS] =
{
	"P1 Scale Modifier",
	"P2 Scale Modifier",
	"Enable Scale Modifier",
	"Reset Scale Values"
};
char* menuNamesCamera[MENU_MAX_STRINGS] =
{
	"todo",
};

struct Menu GetMenu()
{
	return TheMenu;
}

int Menu_Init(int id, int font, char* text, int x, int y, int unk)
{
	int result = string_left_xy(id, font, text, x, y, unk);
	int offset = 0;
	titleBar = string_left_xy(MENU_BAR_0 - 1, 0, "MKDHook by ermaccer", x, y - 40, 88);

	for (int i = 0; i < MENU_MAX_STRINGS; i++)
	{
		int offset = i + 1;
		char tmp[128] = {};
		sprintf(tmp, "", i);
		menuStrings[i] = string_left_xy(menuAssoc[i], 0, tmp, x, y - 60 - (15 * (offset)), 88);
	}
	TheMenu.m_bActive = 0;
	TheMenu.plrPos.x = 0;
	TheMenu.plrPos.y = 0;
	TheMenu.plrPos.z = 0;
	m_nTimer = get_game_tick();
	m_nCurrentPos = 0;
	m_bScaleModifier = 0;
	return result;
}

void Menu_Draw()
{
	if (TheMenu.m_bActive)
	{
		string_set_alpha(MENU_BAR_0 - 1, 255);

		int str = 0;

		if (m_nCurrentMenuOpen == MENU_DEFAULT)
			str = TOTAL_MENU_DEFAULT;;
		if (m_nCurrentMenuOpen == MENU_PLAYER)
			str = TOTAL_PLAYER;
		if (m_nCurrentMenuOpen == MENU_CAMERA)
			str = TOTAL_CAMERA;
		for (int i = 0; i < str; i++)
		{
			if (m_nCurrentMenuOpen == MENU_DEFAULT)
			{
				update_string(menuStrings[i], 0, menuNames[i]);
			}
			if (m_nCurrentMenuOpen == MENU_PLAYER)
			{
				char tmp[256] = {};
				switch (m_nCurrentPos)
				{
				case 0:
					sprintf(tmp, "%s %d", "Value - ", (int)(m_nP1Scale * 100));
					break;
				case 1:
					sprintf(tmp, "%s %d", "Value - ", (int)(m_nP2Scale * 100));
					break;
				case 2:
					sprintf(tmp, "%s %s", "Value - ", TRUE_FALSE(m_bScaleModifier));
					break;
				}

				update_string(menuStrings[i], 0, menuNamesPlayer[i]);
				update_string(menuStrings[TOTAL_PLAYER + 1], 0, tmp);
			}
			if (m_nCurrentMenuOpen == MENU_CAMERA)
			{
				char tmp[256] = {};
				switch (m_nCurrentPos)
				{
				case 0:
					sprintf(tmp, "%s %s", "Value - ", TRUE_FALSE(m_bThirdPersonCam));
					break;
				}

				update_string(menuStrings[i], 0, menuNamesCamera[i]);
				update_string(menuStrings[TOTAL_CAMERA + 1], 0, tmp);
			}

			if (m_nCurrentPos == i)
				string_set_alpha(menuAssoc[i], 255);
			else
				string_set_alpha(menuAssoc[i], 128);



		}
	}
	else
	{
		string_set_alpha(MENU_BAR_0 - 1, 0);

		for (int i = 0; i < MENU_MAX_STRINGS; i++)
		{
			string_set_alpha(menuAssoc[i], 0);
		}
	}

}

void Menu_Process()
{
	if (pressed_button(0, PAD_L3))
		Menu_Toggle();

	if (TheMenu.m_bActive)
	{
		if (pressed_button(0, PAD_CROSS))
			Menu_KeyCross();
		
		if (pressed_button(0, PAD_TRIANGLE))
			Menu_KeyTriangle();

		if (pressed_button(0, PAD_CIRCLE))
			Menu_KeyCircle();

		if (pressed_button(0, PAD_UP))
			Menu_KeyUp();

		if (pressed_button(0, PAD_DOWN))
			Menu_KeyDown();

		int str = TOTAL_MENU_DEFAULT;

		if (m_nCurrentMenuOpen == MENU_PLAYER)
			str = TOTAL_PLAYER;
		if (m_nCurrentMenuOpen == MENU_CAMERA)
			str = TOTAL_CAMERA;

		if (m_nCurrentPos < 0) m_nCurrentPos = str - 1;
		if (m_nCurrentPos >= str) m_nCurrentPos = 0;
	}
	Menu_Draw();
	Menu_Process_Toggles();
}

void Menu_Process_Toggles()
{
	if (m_bScaleModifier)
	{
		update_player1_scale();
		update_player2_scale();
	}
}

void Menu_Toggle()
{
	if (get_game_tick() - m_nTimer <= 15) return;
	m_nTimer = get_game_tick();
	TheMenu.m_bActive = !TheMenu.m_bActive;

	if (TheMenu.m_bActive)
		pause(1);
	else
		pause(0);
}

void Menu_KeyUp()
{
	if (get_game_tick() - m_nTimer <= 10) return;
	m_nTimer = get_game_tick();
	m_nCurrentPos -= 1;
}

void Menu_KeyDown()
{
	if (get_game_tick() - m_nTimer <= 10) return;
	m_nTimer = get_game_tick();
	m_nCurrentPos += 1;
}

void Menu_KeyCross()
{
	if (get_game_tick() - m_nTimer <= 10) return;
	m_nTimer = get_game_tick();
	Menu_ClearStrings();
	if (m_nCurrentMenuOpen == MENU_DEFAULT)
		m_nCurrentMenuOpen = m_nCurrentPos;
	else
	{
		if (m_nCurrentMenuOpen == MENU_PLAYER)
			Menu_ProcessPlayer();
		if (m_nCurrentMenuOpen == MENU_CAMERA)
			Menu_ProcessCamera();
	}

}

void Menu_KeyCircle()
{
	if (get_game_tick() - m_nTimer <= 10) return;
	m_nTimer = get_game_tick();
	if (!(m_nCurrentMenuOpen == MENU_DEFAULT))
	m_nCurrentMenuOpen = MENU_DEFAULT;
	Menu_ClearStrings();
}

void Menu_KeyTriangle()
{
	if (get_game_tick() - m_nTimer <= 10) return;
	m_nTimer = get_game_tick();

	if (m_nCurrentMenuOpen == MENU_PLAYER)
		Menu_ProcessPlayerReverse();
}

void Menu_ProcessPlayer()
{
	switch (m_nCurrentPos)
	{
	case 0:
		m_nP1Scale += 0.1f;
		break;
	case 1:
		m_nP2Scale += 0.1f;
		break;
	case 2:
		m_bScaleModifier= !m_bScaleModifier;
		break;
	case 3:
		m_nP1Scale = 1.0f;
		m_nP2Scale = 1.0f;
		break;
	default:
		break;
	}
}

void Menu_ProcessPlayerReverse()
{
	switch (m_nCurrentPos)
	{
	case 0:
		m_nP1Scale -= 0.1f;
		if (m_nP1Scale < 0)
			m_nP1Scale = 0;
		break;
	case 1:
		m_nP1Scale -= 0.1f;

		if (m_nP2Scale < 0)
			m_nP2Scale = 0;
		break;
	default:
		break;
	}
}

void Menu_ProcessCamera()
{
	switch (m_nCurrentPos)
	{
	case 0:
		m_bThirdPersonCam = !m_bThirdPersonCam;
		break;
	default:
		break;
	}
}

void Menu_ClearStrings()
{
	string_set_alpha(MENU_BAR_0 - 1, 0);

	for (int i = 0; i < MENU_MAX_STRINGS; i++)
	{
		string_set_alpha(menuAssoc[i], 0);
	}
}

void update_player1_scale()
{
	struct player_info plr1 = *(struct player_info*)PLAYER1_INFO;
	if (plr1.pObject)
	{
		int obj = plr1.pObject;
		float scale = m_nP1Scale;

		{
			*(char*)(obj + 8) = *(char*)(obj + 8) & 0xFFFFFFBF | 0x40;

			{
				*(float*)(obj + 240) = scale;
				*(float*)(obj + 244) = scale;
				*(float*)(obj + 248) = scale;
			}
		}
	}
}

void update_player2_scale()
{
	struct player_info plr2 = *(struct player_info*)PLAYER2_INFO;
	if (plr2.pObject)
	{
		int obj = plr2.pObject;
		float scale = m_nP2Scale;

		{
			*(char*)(obj + 8) = *(char*)(obj + 8) & 0xFFFFFFBF | 0x40;

			{
				*(float*)(obj + 240) = scale;
				*(float*)(obj + 244) = scale;
				*(float*)(obj + 248) = scale;
			}
		}
	}
}
