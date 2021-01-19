//By Tsuki Superior
#include "dmg_boot.hpp"

DMG_BOOT_driver::DMG_BOOT_driver(void)
{

}

DMG_BOOT_driver::~DMG_BOOT_driver(void)
{
}

bool DMG_BOOT_driver::detectsystem(void)
{

    //Well, if we made it this far, I think we can assume the module is good
    return true;
}

void DMG_BOOT_driver::reboot(void)
{
}

void DMG_BOOT_driver::shutdown(void)
{
}
