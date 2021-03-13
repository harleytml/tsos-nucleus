//By Tsuki Superior
#include "gba_gamepad.hpp"

GBA_GAMEPAD_driver::GBA_GAMEPAD_driver(void)
{
    name = "Gameboy Advanced Gamepad";
}

GBA_GAMEPAD_driver::~GBA_GAMEPAD_driver()
{
}

bool GBA_GAMEPAD_driver::detectsystem(void)
{
    return true;
}

void GBA_GAMEPAD_driver::reset(void)
{
}

key_identifier GBA_GAMEPAD_driver::getkey(void)
{
    return KEY_NULL;
}

void GBA_GAMEPAD_driver::waitkey(void)
{
}

// Is shift pressed
bool GBA_GAMEPAD_driver::isshiftpressed(void)
{
    return false;
}

// Is alt pressed
bool GBA_GAMEPAD_driver::isaltpressed(void)
{
    return false;
}

// Is ctrl pressed
bool GBA_GAMEPAD_driver::isctrlpressed(void)
{
    return false;
}
