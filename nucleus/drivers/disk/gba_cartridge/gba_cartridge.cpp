//By Tsuki Superior
#include "gba_cartridge.hpp"

GBA_CARTRIDGE_driver::GBA_CARTRIDGE_driver(void)
{
    name = "Gameboy Advanced Cartridge";
}

char *GBA_CARTRIDGE_driver::getbytes(uint16_t offset, uint8_t len)
{
}

uint16_t GBA_CARTRIDGE_driver::getsectorsize(void)
{
}
