//By Tsuki Superior
#include "atapi.hpp"

ATAPI_driver::ATAPI_driver(void)
{
  name = "AT Attachment Packet Interface";
}

ATAPI_driver::~ATAPI_driver()
{
}

bool ATAPI_driver::detectsystem()
{
  return true;
}

void ATAPI_driver::reset(void)
{
}

void ATAPI_driver::getbytes(uint8_t *buffer, uint16_t offset, uint8_t len)
{
}

uint16_t ATAPI_driver::getsectorsize(void)
{
  return 2048;
}
