//By Tsuki Superior
#include "./dmg_boot.hpp"

DMG_BOOT_driver::DMG_BOOT_driver(void)
{
    name="Dot Matrix Game Boot";
}

DMG_BOOT_driver::~DMG_BOOT_driver()
{
}

bool DMG_BOOT_driver::detectsystem(void)
{

    return true;
}

void DMG_BOOT_driver::reboot(void)
{
}

void DMG_BOOT_driver::shutdown(void)
{
}
