#include "mouse.h"
#ifndef PS2_BUILD
struct CMouseControllerState MouseState[StateNum] = { {1} };
char KeyboardState[StateNum][StateSize] = { {1} };
#endif

float GetMouseX()
{
#ifndef PS2_BUILD
    return MouseState->X;
#else 
    return 0.0f;
#endif

}

float GetMouseY()
{
#ifndef PS2_BUILD
    return MouseState->Y;
#else 
    return 0.0f;
#endif
}

char GetAsyncKeyState(int vKey)
{
#ifndef PS2_BUILD
    return KeyboardState[CurrentState][vKey];
#else
    return 0;
#endif
}
