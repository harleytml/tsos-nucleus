//By Tsuki Superior
#include "generic/disk_nucleon.hpp"
#include "generic/nucleus_instance.hpp"

Disk::Disk(void)
{
#ifdef __PERSONAL_COMPUTER__
  static ATAPI_quark cd_quark = ATAPI_quark();

  attachquark(cd_quark);
#endif

#ifdef __GAMEBOY_ADVANCED__
  static GBA_CARTRIDGE_quark gba_cartridge_quark = GBA_CARTRIDGE_quark();

  attachquark(gba_cartridge_quark);
#endif

#ifdef __RASPBERRY_PI_3__
  static RPI3_SD_CARD_quark rpi3_sd_card_quark = RPI3_SD_CARD_quark();

  attachquark(rpi3_sd_card_quark);
#endif
}

Disk::~Disk()
{
}

uint8_t *Disk::getbytes(uint16_t offset, uint8_t len) const
{
  uint8_t *buffer = (uint8_t *)"";
  quark->getbytes(buffer, offset, len);
  return buffer;
}

uint16_t Disk::getsectorsize(void) const
{
  return quark->getsectorsize();
}

void Disk::commitall(void) const
{
}
