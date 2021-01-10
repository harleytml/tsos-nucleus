//By Tsuki Superior
#include "dmg_boot.hpp"

DMG_BOOT_driver::DMG_BOOT_driver(void)
{

    //Start a instance of the TS/OS api
    tsos = new Tsos();
}

DMG_BOOT_driver::~DMG_BOOT_driver(void)
{
}

BOOLEAN DMG_BOOT_driver::detectsystem(void)
{

    //Well, if we made it this far, I think we can assume the module is good
    return TRUE;
}

void DMG_BOOT_driver::reboot(void)
{
}

void DMG_BOOT_driver::shutdown(void)
{
}
