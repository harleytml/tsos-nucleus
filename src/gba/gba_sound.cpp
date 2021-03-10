//By Tsuki Superior
#include "gba_sound.hpp"

GBA_SOUND_driver::GBA_SOUND_driver(void)
{
    name = "Gameboy Advanced Sound";
}

bool GBA_SOUND_driver::detectsystem(void)
{
    return true;
}

void GBA_SOUND_driver::playtone(Tone tone)
{
}