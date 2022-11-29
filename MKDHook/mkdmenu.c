#include "mkdmenu.h"
#include <stdio.h>
#include "mips.h"
#include "ps2mem.h"
#define TRUE_FALSE(x) x ? "true" : "false"

struct CVector camPos;
struct CVector camRot;

struct Menu TheMenu;
float headOffset = 0.0f;
float headDistance = 0.0f;

float headOffset3 =1.0f;
float headDistance3 = -2.15f;

int m_nCurrentPos = 0;
int m_nCurrentMenuOpen = MENU_DEFAULT;
int m_nTimer = 0;

int m_bScaleModifier = 0;
float m_nP1Scale = 1.0;
float m_nP2Scale = 1.0;

int m_bFirstPersonCam = 0;
int m_bThirdPersonCam = 0;
int m_bFreeCamera = 0;

int menuAssoc[MENU_MAX_STRINGS * 2] =
{
	MENU_BAR_0,
	MENU_BAR_1,
	MENU_BAR_2,
	MENU_BAR_3,
	MENU_BAR_4,
	MENU_BAR_5,
	MENU_BAR_6,
	MENU_BAR_7,
	MENU_BAR_8,
	MENU_BAR_9,
};

int menuStrings[MENU_MAX_STRINGS] = {};
int titleBar;

const char* menuNames[MENU_MAX_STRINGS] =
{
	"Player",
	"Camera",
	"Misc.",
};

const char* menuNamesPlayer[MENU_MAX_STRINGS] =
{
	"P1 Scale Modifier",
	"P2 Scale Modifier",
	"Enable Scale Modifier",
	"Reset Scale Values"
};

const char* menuNamesCamera[MENU_MAX_STRINGS] =
{
	"First Person Camera",
	"Third Person Camera",
	"Set FOV to 72 (default)",
	"Set FOV to 90",
	"Set FOV to 95",
	"Set FOV to 110",
	"Set FOV to 120",
	"Free Camera"
};

const char* menuNamesMisc[MENU_MAX_STRINGS] =
{
	"Kill HUD",
	"Disable Fatality Camera",
	"Enable Fatality Camera"
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
	TheMenu.m_bIsReady = 0;
	for (int i = 0; i < MENU_MAX_STRINGS; i++)
	{
		int offset = i + 1;
		static char tmp[128] = {};
		sprintf(tmp, "", i);
		menuStrings[i] = string_left_xy(menuAssoc[i], 0, tmp, x, y - 60 - (15 * (offset)), 88);
	}
	TheMenu.m_bIsReady = 1;
	TheMenu.m_bActive = 0;
	TheMenu.plrPos.x = 0;
	TheMenu.plrPos.y = 0;
	TheMenu.plrPos.z = 0;
	m_bFirstPersonCam = 0;
	m_bFreeCamera = 0;
	m_bThirdPersonCam = 0;
	m_nTimer = get_game_tick();
	m_nCurrentPos = 0;
	m_bScaleModifier = 0;
	return result;
}

void Menu_Draw()
{
	if (!TheMenu.m_bIsReady)
		return;

	if (TheMenu.m_bActive)
	{
		string_set_alpha(MENU_BAR_0 - 1, 255);

		int str = TOTAL_MENU_DEFAULT;
		if (m_nCurrentMenuOpen == MENU_DEFAULT)
			str = TOTAL_MENU_DEFAULT;
		if (m_nCurrentMenuOpen == MENU_PLAYER)
			str = TOTAL_PLAYER;
		if (m_nCurrentMenuOpen == MENU_MISC)
			str = TOTAL_MISC;
		if (m_nCurrentMenuOpen == MENU_CAMERA)
			str = TOTAL_CAMERA;
		for (int i = 0; i < str; i++)
		{
			if (m_nCurrentMenuOpen == MENU_DEFAULT)
				update_string(menuStrings[i], 0, menuNames[i]);
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
					sprintf(tmp, "%s %s", "Value - ", TRUE_FALSE(m_bFirstPersonCam));
					break;
				case 1:
					sprintf(tmp, "%s %s", "Value - ", TRUE_FALSE(m_bThirdPersonCam));
					break;
				case FREE_CAMERA:
					sprintf(tmp, "%s %s", "Value - ", TRUE_FALSE(m_bFreeCamera));
					break;
				default:
					sprintf(tmp, "Restart match for FOV changes to apply.");
					break;
				}
				update_string(menuStrings[TOTAL_CAMERA + 1], 0, tmp);
				update_string(menuStrings[i], 0, menuNamesCamera[i]);
			}
			if (m_nCurrentMenuOpen == MENU_MISC)
			{
				char tmp[256] = {};
				update_string(menuStrings[TOTAL_PLAYER + 1], 0, tmp);
				update_string(menuStrings[i], 0, menuNamesMisc[i]);
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

	if (GetAsyncKeyState(71))
		Menu_Toggle_FreeCam();


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
		if (m_nCurrentMenuOpen == MENU_MISC)
			str = TOTAL_MISC;
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
	if (m_bFirstPersonCam || m_bThirdPersonCam)
		Menu_ProcessCustomCams();
	else
		Menu_ProcessFreeCamera();
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
	if (m_nCurrentMenuOpen == MENU_MISC)
		Menu_ProcessMisc();
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
		m_nP2Scale -= 0.1f;

		if (m_nP2Scale < 0)
			m_nP2Scale = 0;
		break;
	default:
		break;
	}
}

void Menu_ProcessMisc()
{
	switch (m_nCurrentPos)
	{
	case 0:
		setup_fatality_scene();
		break;
	case 1:
		disable_fatality_camera();
		break;
	case 2:
		enable_fatality_camera();
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
		m_bFirstPersonCam = !m_bFirstPersonCam;
		break;
	case 1:
		m_bThirdPersonCam = !m_bThirdPersonCam;
		break;
	case FOV_72:
		setFov(72.0f);
		break;
	case FOV_90:
		setFov(90.0f);
		break;
	case FOV_95:
		setFov(95.0f);
		break;
	case FOV_110:
		setFov(110.0f);
		break;
	case FOV_120:
		setFov(120.0f);
		break;
	case FREE_CAMERA:
		m_bFreeCamera = !m_bFreeCamera;
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

void Menu_Unset()
{
	TheMenu.m_bIsReady = 0;
}

void Menu_ProcessCustomCams()
{
	struct player_info plr1 = *(struct player_info*)PLAYER1_INFO;
	struct player_info plr2 = *(struct player_info*)PLAYER2_INFO;
	if (plr1.pObject && plr2.pObject)
	{
		struct CVector headPos;
		struct CVector rightMat;
		struct CVector forwardMat;
		struct CVector headPosP2;
		static int id = 16;
		if (m_bThirdPersonCam)
			id = 14;
		else
			id = 16;

		get_bone_pos(plr1.pObject, id, &headPos);
		get_bone_pos(plr2.pObject, id, &headPosP2);

		get_matrix_right(plr1.pObject, &rightMat);
		get_matrix_forward(plr1.pObject, &forwardMat);

		if (m_bFirstPersonCam)
		{
			headPos.x += rightMat.x * headOffset;
			headPos.y += rightMat.y * headOffset;
			headPos.z += rightMat.z * headOffset;

			headPos.x += forwardMat.x * headDistance;
			headPos.y += forwardMat.y * headDistance;
			headPos.z += forwardMat.z * headDistance;
		}
		else
		{
			headPos.y += headOffset3;

			headPos.x += forwardMat.x * headDistance3;
			headPos.y += forwardMat.y * headDistance3;
			headPos.z += forwardMat.z * headDistance3;
		}

		set_cam_pos(&headPos);
		set_cam_target(&headPosP2);
	}
}

void Menu_ProcessFreeCamera()
{
	int camera = *(int*)0x5D6698;

	if (m_bFreeCamera)
	{
		static float camSpeed = 0.15f;

		if (GetAsyncKeyState(90))
			camSpeed = 0.07f;
		else
			camSpeed = 0.15f;

		if (GetAsyncKeyState(87))
			camPos.z -= camSpeed;
		if (GetAsyncKeyState(83))
			camPos.z += camSpeed;

		if (GetAsyncKeyState(65))
			camPos.x -= camSpeed;
		if (GetAsyncKeyState(68))
			camPos.x += camSpeed;

		if (GetAsyncKeyState(81))
			camPos.y += camSpeed;
		if (GetAsyncKeyState(69))
			camPos.y -= camSpeed;

		if (GetAsyncKeyState(37))
			camRot.y += camSpeed / 4.0f;
		if (GetAsyncKeyState(39))
			camRot.y -= camSpeed / 4.0f;

		if (GetAsyncKeyState(38))
			camRot.x -= camSpeed / 4.0f;
		if (GetAsyncKeyState(40))
			camRot.x += camSpeed / 4.0f;

		if (GetAsyncKeyState(88))
			camRot.z -= camSpeed / 4.0f;
		if (GetAsyncKeyState(67))
			camRot.z += camSpeed / 4.0f;

		set_cam_pos(&camPos);
		set_cam_rot(&camRot);



	}
	else
	{
		if (camera)
		{
			camPos = *(struct CVector*)(camera + 160);
			camRot = *(struct CVector*)(camera + 208);
		}

	}

}

void Menu_Toggle_FreeCam()
{
	if (get_game_tick() - m_nTimer <= 15) return;
	m_nTimer = get_game_tick();
	m_bFreeCamera = !m_bFreeCamera;
}

void setFov(float value)
{
	*(float*)(0x5D4DD4) = value;
}

void disable_fatality_camera()
{
	NOP(0x26E1FC);
	NOP(0x26E1E0);
	NOP(0x26D9C8);
	NOP(0x26D9AC);
}

void enable_fatality_camera()
{
	patchInt(0x26E1FC, jal(0x12C3E0));
	patchInt(0x26E1E0, jal(0x17CF00));
	patchInt(0x26D9C8, jal(0x12C3E0));
	patchInt(0x26D9AC, jal(0x17CF00));
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
void konquest_camera()
{
	int monk = get_monk();
	int camera = *(int*)0x5D6698;
	if (monk)
	{
		static struct CVector k_camRot;
		struct CVector pos = *(struct CVector*)(monk + 160);
		get_bone_pos(monk, 10, &pos);
		setFov(100.0f);
		set_cam_pos(&pos);
		if (camera && !pressed_button(0, PAD_R3))
			k_camRot = *(struct CVector*)(camera + 208);
		else if (pressed_button(0, PAD_R3))
			set_cam_rot(&k_camRot);

		if (pressed_button(0,PAD_L3))
			konquest_hide_hud(0);
	}
}
