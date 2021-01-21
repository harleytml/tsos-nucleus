//By Tsuki Superior
#include "dmg_gamepad.hpp"

DMG_GAMEPAD_driver::DMG_GAMEPAD_driver(void)
{
    name = "Dot Matrix Game Gamepad";
}

// This check is not needed, since the difference between a GBC and a DMG is a read only byte in the rom header, but I'll include it anyway
bool DMG_GAMEPAD_driver::detectsystem(void)
{

    // Checking to make sure this isn't a Gameboy Color
    if (*((uint8_t *)0x147) != 0x80)
    {

        // Cheking if this system is a Gameboy, or a Gameboy Pocket
        return true;
    }

    // This was compiled wrong if the code reaches here
    // The header has the wrong value, because it was compiled for the Gameboy Color
    // So we will induce a fission
    tsos.boot.fission("NUCLEUS DETECTED HARDWARE FAULT");

    // So the compiler doesn't complain
    return false;
}

key_identifier DMG_GAMEPAD_driver::getkey(void)
{
}
