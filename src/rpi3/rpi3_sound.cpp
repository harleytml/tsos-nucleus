//By Tsuki Superior
#include "rpi3/rpi3_sound.hpp"

RPI3_SOUND_driver::RPI3_SOUND_driver(void)
{
  name = "Raspberry Pi 3 Sound";
}

bool RPI3_SOUND_driver::detectsystem(void)
{
  return true;
}

void RPI3_SOUND_driver::reset(void)
{
}

void RPI3_SOUND_driver::playtone(uint32_t tone)
{
}

void RPI3_SOUND_driver::killsound(void)
{
}