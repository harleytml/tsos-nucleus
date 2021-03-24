//By Tsuki Superior
#include "disk_module.hpp"
#include "nucleus_instance.hpp"

Disk::Disk(void)
{
#ifdef __PERSONAL_COMPUTER__
  static ATAPI_driver cd_driver = ATAPI_driver();

  attachdriver(cd_driver);
#endif

#ifdef __GAMEBOY_ADVANCED__
  static GBA_CARTRIDGE_driver gba_cartridge_driver = GBA_CARTRIDGE_driver();

  attachdriver(gba_cartridge_driver);
#endif

#ifdef __RASPBERRY_PI_3__
  static RPI3_SD_CARD_driver rpi3_sd_card_driver = RPI3_SD_CARD_driver();

  attachdriver(rpi3_sd_card_driver);
#endif
}

Disk::~Disk()
{
}

uint8_t *Disk::getbytes(uint16_t offset, uint8_t len) const
{
  uint8_t *buffer = (uint8_t *)"";
  driver->getbytes(buffer, offset, len);
  return buffer;
}

uint16_t Disk::getsectorsize(void) const
{
  return driver->getsectorsize();
}

void Disk::commitall(void) const
{
}
