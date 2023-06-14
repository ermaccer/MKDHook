#pragma once
#include "build_config.h"
#ifndef PS2_BUILD
enum KeyboardBufState
{
    CurrentState,
    PreviousState,

    StateNum,

    CheatStringLen = 25,
    StateSize = 256
};

struct CMouseControllerState
{
    char	lmb;
    char	rmb;
    char	mmb;
    char	wheelUp;
    char	wheelDown;
    char	bmx1;
    char	bmx2;
    float   Z;
    float   X;
    float   Y;
};
#endif

float GetMouseX();
float GetMouseY();


char GetAsyncKeyState(int vKey);