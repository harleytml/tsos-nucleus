//By Tsuki Superior
#include <pc/multiboot.hpp>
#include <generic/nucleus_instance.hpp>

MULTIBOOT_quark::MULTIBOOT_quark(void)
{
  name = "Multiboot";
}

MULTIBOOT_quark::~MULTIBOOT_quark()
{
}

bool MULTIBOOT_quark::detectsystem(void)
{
  return true;
}

void MULTIBOOT_quark::reset(void)
{
}

//8042 reset
void MULTIBOOT_quark::reboot(void)
{
  uint8_t good = 0x02;
  while (good & 0x02)
  {
    good = tsos->io.in8(0x64);
  }
  tsos->io.out8(0x64, 0xfe);
  __asm__("hlt");
}

void MULTIBOOT_quark::shutdown(void)
{
}
