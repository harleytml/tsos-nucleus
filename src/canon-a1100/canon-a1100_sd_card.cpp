//By Tsuki Superior
#include <canon-a1100/canon-a1100_sd_card.hpp>

CANON_A1100_SD_CARD_quark::CANON_A1100_SD_CARD_quark(void)
{
  name = "Canon Powershot A1100 IS Secure Digital Card";
}

CANON_A1100_SD_CARD_quark::~CANON_A1100_SD_CARD_quark()
{
}

bool CANON_A1100_SD_CARD_quark::detectsystem()
{
  return true;
}

void CANON_A1100_SD_CARD_quark::reset(void)
{
}

void CANON_A1100_SD_CARD_quark::getbytes(uint8_t *buffer, uint16_t offset, uint8_t len)
{
}

uint16_t CANON_A1100_SD_CARD_quark::getsectorsize(void)
{
  return 0;
}
