// By Tsuki Superior
#include <rpi3/rpi3_sound.hpp>

RPI3_SOUND_quark::RPI3_SOUND_quark(void)
{
    name = "Raspberry Pi 3 Sound";
}

bool RPI3_SOUND_quark::detectsystem(void)
{
    return true;
}

void RPI3_SOUND_quark::reset(void)
{
}

void RPI3_SOUND_quark::playtone(uint32_t tone)
{
}

void RPI3_SOUND_quark::killsound(void)
{
}