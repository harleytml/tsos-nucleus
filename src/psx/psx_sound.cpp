//By Tsuki Superior
#include "psx_sound.hpp"

PSX_SOUND_driver::PSX_SOUND_driver(void)
{
  name = "Playstation X Sound";
}

bool PSX_SOUND_driver::detectsystem(void)
{
  return true;
}

void PSX_SOUND_driver::reset(void)
{
}

void PSX_SOUND_driver::playtone(uint32_t tone)
{
}