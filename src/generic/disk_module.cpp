//By Tsuki Superior
#include "disk_module.hpp"
#include "nucleus_instance.hpp"

Disk::Disk(void)
{
#ifdef __PERSONAL_COMPUTER__
    static CD_driver cd_driver = CD_driver();

    if (attachdriver(cd_driver))
    {
        return;
    }
#endif

#ifdef __GAMEBOY_ADVANCED__
    static GBA_CARTRIDGE_driver gba_cartridge_driver = GBA_CARTRIDGE_driver();

    if (attachdriver(gba_cartridge_driver))
    {
        return;
    }
#endif

#ifdef __PLAYSTATION_X__
    static PSX_DISK_driver psx_disk_driver = PSX_DISK_driver();

    if (attachdriver(psx_disk_driver))
    {
        return;
    }
#endif
}

Disk::~Disk()
{
}

uint8_t *Disk::getbytes(uint16_t offset, uint8_t len)
{
    uint8_t *buffer = (uint8_t *)"";
    driver->getbytes(buffer, offset, len);
    return buffer;
}

uint16_t Disk::getsectorsize(void)
{
    return driver->getsectorsize();
}

void Disk::commitall(void)
{
}
