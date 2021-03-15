//By Tsuki Superior
#include "grub2.hpp"

GRUB2_driver::GRUB2_driver(void)
{
  name = "Grand Unified Bootloader 2";
}

GRUB2_driver::~GRUB2_driver()
{
}

bool GRUB2_driver::detectsystem(void)
{
  return true;
}

void GRUB2_driver::reset(void)
{
}

//8042 reset
void GRUB2_driver::reboot(void)
{
  uint8_t good = 0x02;
  while (good & 0x02)
  {
    good = inb(0x64);
  }
  outb(0x64, 0xfe);
  __asm__("hlt");
}

void GRUB2_driver::shutdown(void)
{
}
