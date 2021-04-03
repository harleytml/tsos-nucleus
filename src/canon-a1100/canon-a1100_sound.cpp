//By Tsuki Superior
#include "canon-a1100/canon-a1100_sound.hpp"

CANON_A1100_SOUND_quark::CANON_A1100_SOUND_quark(void)
{
  name = "Canon Powershot A1100 IS Sound";
}

bool CANON_A1100_SOUND_quark::detectsystem(void)
{
  return true;
}

void CANON_A1100_SOUND_quark::reset(void)
{
}

void CANON_A1100_SOUND_quark::playtone(uint32_t tone)
{
}

void CANON_A1100_SOUND_quark::killsound(void)
{
}