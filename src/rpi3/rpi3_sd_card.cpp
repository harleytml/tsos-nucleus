//By Tsuki Superior
#include <rpi3/rpi3_sd_card.hpp>

RPI3_SD_CARD_quark::RPI3_SD_CARD_quark(void)
{
  name = "Raspberry Pi 3 Secure Digital Card";
}

RPI3_SD_CARD_quark::~RPI3_SD_CARD_quark()
{
}

bool RPI3_SD_CARD_quark::detectsystem()
{
  return true;
}

void RPI3_SD_CARD_quark::reset(void)
{
}

void RPI3_SD_CARD_quark::getbytes(uint8_t *buffer, uint16_t offset, uint8_t len)
{
}

uint16_t RPI3_SD_CARD_quark::getsectorsize(void)
{
  return 0;
}
