//By Tsuki Superior
#include "pc/atapi.hpp"

ATAPI_quark::ATAPI_quark(void)
{
  name = "AT Attachment Packet Interface";
}

ATAPI_quark::~ATAPI_quark()
{
}

bool ATAPI_quark::detectsystem()
{
  return true;
}

void ATAPI_quark::reset(void)
{
}

void ATAPI_quark::getbytes(uint8_t *buffer, uint16_t offset, uint8_t len)
{
}

uint16_t ATAPI_quark::getsectorsize(void)
{
  return 2048;
}
