//By Tsuki Superior
#include <pc/grub2.hpp>
#include <generic/nucleus_instance.hpp>

GRUB2_quark::GRUB2_quark(void)
{
  name = "Grand Unified Bootloader 2";
}

GRUB2_quark::~GRUB2_quark()
{
}

bool GRUB2_quark::detectsystem(void)
{
  return true;
}

void GRUB2_quark::reset(void)
{
}

//8042 reset
void GRUB2_quark::reboot(void)
{
  uint8_t good = 0x02;
  while (good & 0x02)
  {
    good = tsos->io.in8(0x64);
  }
  tsos->io.out8(0x64, 0xfe);
  __asm__("hlt");
}

void GRUB2_quark::shutdown(void)
{
}
