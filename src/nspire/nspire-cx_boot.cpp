//By Tsuki Superior
#include "canon-a1100/canon-a1100_boot.hpp"

CANON_A1100_BOOT_quark::CANON_A1100_BOOT_quark(void)
{
  name = "Canon Powershot A1100 IS Boot";
}

CANON_A1100_BOOT_quark::~CANON_A1100_BOOT_quark(void)
{
}

bool CANON_A1100_BOOT_quark::detectsystem(void)
{
  return true;
}

void CANON_A1100_BOOT_quark::reset(void)
{
}

void CANON_A1100_BOOT_quark::reboot(void)
{
}

void CANON_A1100_BOOT_quark::shutdown(void)
{
}
