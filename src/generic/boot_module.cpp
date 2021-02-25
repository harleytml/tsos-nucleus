//By Tsuki Superior
#include "boot_module.hpp"

Boot::Boot(void)
{
#ifdef __PERSONAL_COMPUTER__
    GRUB2_driver grub2_driver = GRUB2_driver();

    attachdriver(grub2_driver);
#endif

#ifdef __GAMEBOY_ADVANCED__
    GBA_BOOT_driver gba_boot_driver = GBA_BOOT_driver();

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