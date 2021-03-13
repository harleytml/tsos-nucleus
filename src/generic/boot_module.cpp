//By Tsuki Superior
#include "boot_module.hpp"

Boot::Boot(void)
{
#ifdef __PERSONAL_COMPUTER__
    static GRUB2_driver grub2_driver = GRUB2_driver();

    if (attachdriver(grub2_driver))
    {
        return;
    }
#endif

#ifdef __GAMEBOY_ADVANCED__
    static GBA_BOOT_driver gba_boot_driver = GBA_BOOT_driver();

    if (attachdriver(gba_boot_driver))
    {
        return;
    }
#endif

#ifdef __PLAYSTATION_X__
    static PSX_BOOT_driver psx_boot_driver = PSX_BOOT_driver();

    if (attachdriver(psx_boot_driver))
    {
        return;
    }
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
}