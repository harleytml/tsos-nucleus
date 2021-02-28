//By Tsuki Superior
#include "boot_module.hpp"

Boot::Boot(void)
{
#ifdef __PERSONAL_COMPUTER__
    attachdriver(grub2_driver);
#endif

#ifdef __GAMEBOY_ADVANCED__

    attachdriver(gba_boot_driver);
#endif
}

Boot::~Boot()
{
}

void Boot::reboot(void)
{
    driver->reboot();
}

void Boot::shutdown(void)
{
    // Destroy tsos, to trigger the kernel destruction
    driver->shutdown();
}

void Boot::fission(char *errormsg)
{
    reboot();
}