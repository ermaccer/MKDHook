#include "mouse.h"
struct CMouseControllerState MouseState[StateNum] = { {1} };
char KeyboardState[StateNum][StateSize] = { {1} };


float GetMouseX()
{
    return MouseState->X;
}

float GetMouseY()
{
    return MouseState->Y;
}

char GetAsyncKeyState(int vKey)
{
    return KeyboardState[CurrentState][vKey];
}
