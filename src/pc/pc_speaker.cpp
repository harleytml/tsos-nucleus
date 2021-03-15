//By Tsuki Superior
#include "pc_speaker.hpp"

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
  outb(0x43, 0xb6);
  outb(0x42, (uint8_t)(div));
  outb(0x42, (uint8_t)(div >> 8));

  //And play the sound using the PC speaker
  tmp = inb(0x61);
  if (tmp != (tmp | 3))
  {
    outb(0x61, tmp | 3);
  }
}

void PC_SPEAKER_driver::killsound(void)
{
  uint8_t tmp = inb(0x61) & 0xfc;
  outb(0x61, tmp);
}