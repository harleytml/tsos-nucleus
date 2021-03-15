//By Tsuki Superior
#include "psx_boot.hpp"

PSX_BOOT_driver::PSX_BOOT_driver(void)
{
  name = "Playstation X Boot";
}

PSX_BOOT_driver::~PSX_BOOT_driver(void)
{
}

bool PSX_BOOT_driver::detectsystem(void)
{
  return true;
}

void PSX_BOOT_driver::reset(void)
{
}

void PSX_BOOT_driver::reboot(void)
{
}

void PSX_BOOT_driver::shutdown(void)
{
}
