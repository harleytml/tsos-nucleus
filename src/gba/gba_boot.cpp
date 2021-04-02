//By Tsuki Superior
#include "gba/gba_boot.hpp"

GBA_BOOT_quark::GBA_BOOT_quark(void)
{
  name = "Gameboy Advanced Boot";
}

GBA_BOOT_quark::~GBA_BOOT_quark(void)
{
}

bool GBA_BOOT_quark::detectsystem(void)
{
  return true;
}

void GBA_BOOT_quark::reset(void)
{
}

void GBA_BOOT_quark::reboot(void)
{
  extern void start();
  start();
}

void GBA_BOOT_quark::shutdown(void)
{
  while (true)
  {
  }
}
