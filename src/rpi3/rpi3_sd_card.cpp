//By Tsuki Superior
#include "rpi3_sd_card.hpp"

RPI3_SD_CARD_driver::RPI3_SD_CARD_driver(void)
{
  name = "Raspberry Pi 3 Secure Digital Card";
}

RPI3_SD_CARD_driver::~RPI3_SD_CARD_driver()
{
}

bool RPI3_SD_CARD_driver::detectsystem()
{
  return true;
}

void RPI3_SD_CARD_driver::reset(void)
{
}

void RPI3_SD_CARD_driver::getbytes(uint8_t *buffer, uint16_t offset, uint8_t len)
{
}

uint16_t RPI3_SD_CARD_driver::getsectorsize(void)
{
  return 0;
}
