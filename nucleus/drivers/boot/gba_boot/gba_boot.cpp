//By Tsuki Superior
#include "gba_boot.hpp"

GBA_BOOT_driver::GBA_BOOT_driver(void)
{

    //Start a instance of the TS/OS api
    tsos = Tsos();
}

GBA_BOOT_driver::~GBA_BOOT_driver(void)
{
}

BOOLEAN GBA_BOOT_driver::detectsystem(void)
{

    //Well, if we made it this far, I think we can assume the module is good
    return TRUE;
}

void GBA_BOOT_driver::reboot(void)
{
}

void GBA_BOOT_driver::shutdown(void)
{
}
