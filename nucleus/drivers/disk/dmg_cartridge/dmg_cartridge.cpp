//By Tsuki Superior
#include "./dmg_cartridge.hpp"

DMG_CARTRIDGE_driver::DMG_CARTRIDGE_driver(void)
{
    name = "Dot Matrix Game Cartridge";
}

char *DMG_CARTRIDGE_driver::getbytes(uint16_t offset, uint8_t len)
{
    // Well, the DMG cartridge has several types actually, but they pretty much act as one.
    // The difference lies in the synthax of the byte you write to the rom sector to retrive a new sector.
    // Please reference the GBCPUman (found online)
}

uint16_t DMG_CARTRIDGE_driver::getsectorsize(void)
{
    return 0x1000;
}
