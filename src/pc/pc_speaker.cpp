//By Tsuki Superior
#include "pc/pc_speaker.hpp"
#include "generic/nucleus_instance.hpp"

PC_SPEAKER_driver::PC_SPEAKER_driver(void)
{
  name = "PC Speaker";
}

bool PC_SPEAKER_driver::detectsystem(void)
{
  return true;
}

void PC_SPEAKER_driver::reset(void)
{
}

void PC_SPEAKER_driver::playtone(uint32_t tone)
{
  uint32_t div;
  uint8_t tmp;

  //Set the PIT to the desired frequency
  div = 1193180 / tone;
  tsos->io.put8(0x43, 0xb6);
  tsos->io.put8(0x42, (uint8_t)(div));
  tsos->io.put8(0x42, (uint8_t)(div >> 8));

  //And play the sound using the PC speaker
  tmp = tsos->io.get8(0x61);
  if (tmp != (tmp | 3))
  {
    tsos->io.put8(0x61, tmp | 3);
  }
}

void PC_SPEAKER_driver::killsound(void)
{
  uint8_t tmp = tsos->io.get8(0x61) & 0xfc;
  tsos->io.put8(0x61, tmp);
}