// By Tsuki Superior
#include <vexpress-a15/vexpress-a15_sound.hpp>

VEXPRESS_A15_SOUND_quark::VEXPRESS_A15_SOUND_quark(void)
{
    name = "Versatile Express A15";
}

bool VEXPRESS_A15_SOUND_quark::detectsystem(void)
{
    return true;
}

void VEXPRESS_A15_SOUND_quark::reset(void)
{
}

void VEXPRESS_A15_SOUND_quark::playtone(uint32_t tone)
{
}

void VEXPRESS_A15_SOUND_quark::killsound(void)
{
}