//By Tsuki Superior
#include "rpi3/rpi3_boot.hpp"

RPI3_BOOT_driver::RPI3_BOOT_driver(void)
{
  name = "Raspberry Pi 3 Boot";
}

RPI3_BOOT_driver::~RPI3_BOOT_driver(void)
{
}

bool RPI3_BOOT_driver::detectsystem(void)
{
  return true;
}

void RPI3_BOOT_driver::reset(void)
{
}

void RPI3_BOOT_driver::reboot(void)
{
}

void RPI3_BOOT_driver::shutdown(void)
{
}
