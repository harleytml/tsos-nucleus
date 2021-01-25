//By Tsuki Superior
#include "./gba_boot.hpp"

GBA_BOOT_driver::GBA_BOOT_driver(void)
{
    name = "Gameboy Advanced Boot";
}

GBA_BOOT_driver::~GBA_BOOT_driver(void)
{
}

bool GBA_BOOT_driver::detectsystem(void)
{

    return true;
}

void GBA_BOOT_driver::reboot(void)
{
}

void GBA_BOOT_driver::shutdown(void)
{
}
