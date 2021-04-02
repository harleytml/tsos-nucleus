//By Tsuki Superior
#include "gba/gba_cartridge.hpp"

GBA_CARTRIDGE_quark::GBA_CARTRIDGE_quark(void)
{
  name = "Gameboy Advanced Cartridge";
}

GBA_CARTRIDGE_quark::~GBA_CARTRIDGE_quark()
{
}

bool GBA_CARTRIDGE_quark::detectsystem()
{
  return true;
}

void GBA_CARTRIDGE_quark::reset(void)
{
}

void GBA_CARTRIDGE_quark::getbytes(uint8_t *buffer, uint16_t offset, uint8_t len)
{
  extern void *memcpy(void *dstptr, const void *srcptr, size_t size);

  memcpy((void *)buffer, (void *)(0 + offset), len);
}

uint16_t GBA_CARTRIDGE_quark::getsectorsize(void)
{
  return 0;
}
