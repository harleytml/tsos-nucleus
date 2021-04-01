//By Tsuki Superior
#include "gba/gba_sound.hpp"

GBA_SOUND_quark::GBA_SOUND_quark(void)
{
  name = "Gameboy Advanced Sound";
}

bool GBA_SOUND_quark::detectsystem(void)
{
  return true;
}

void GBA_SOUND_quark::reset(void)
{
}

void GBA_SOUND_quark::playtone(uint32_t tone)
{
}

void GBA_SOUND_quark::killsound(void)
{
}