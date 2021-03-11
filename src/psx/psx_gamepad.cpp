//By Tsuki Superior
#include "psx_gamepad.hpp"

PSX_GAMEPAD_driver::PSX_GAMEPAD_driver(void)
{
    name = "Playstation X Gamepad";
}

PSX_GAMEPAD_driver::~PSX_GAMEPAD_driver()
{
}

bool PSX_GAMEPAD_driver::detectsystem(void)
{
    return true;
}

key_identifier PSX_GAMEPAD_driver::getkey(void)
{
    return KEY_NULL;
}

void PSX_GAMEPAD_driver::waitkey(void)
{
}

// Is shift pressed
bool PSX_GAMEPAD_driver::isshiftpressed(void)
{
    return false;
}

// Is alt pressed
bool PSX_GAMEPAD_driver::isaltpressed(void)
{
    return false;
}

// Is ctrl pressed
bool PSX_GAMEPAD_driver::isctrlpressed(void)
{
    return false;
}
