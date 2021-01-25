//By Tsuki Superior
#include "./dmg_sound.hpp"

DMG_SOUND_driver::DMG_SOUND_driver(void)
{
    name = "Dot Matrix Game Sound";
}

// This check is pointless to do, but I will do it anyway in the spirit of TS/OS
bool DMG_SOUND_driver::detectsystem(void)
{

    // Check to make sure this isn't a Gameboy Color
    if (*((uint8_t *)0x147) != 0x80)
    {

        // Returns the type of the system
        return true;
    }

    /* This was compiled wrong if the code reaches here
   	   The header has the wrong value, because it was compiled for the Gameboy Color
   	   So we will induce a fission */
    tsos.boot.fission("NUCLEUS DETECTED HARDWARE FAULT");

    // So the compiler doesn't complain
    return false;
}

void DMG_SOUND_driver::playtone(Tone tone)
{
}
