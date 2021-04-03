//By Tsuki Superior
#include "pc/atapi.hpp"
#include "generic/nucleus_instance.hpp"

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

void ATAPI_quark::ide_write(uint8_t channel, uint8_t reg, uint8_t data)
{
  if (reg > 0x07 && reg < 0x0C)
  {
    ide_write(channel, ATA_REG_CONTROL, 0x80 | channels[channel].nIEN);
  }
  if (reg < 0x08)
  {
    tsos->io.out8(channels[channel].base + reg - 0x00, data);
  }
  else if (reg < 0x0C)
  {
    tsos->io.out8(channels[channel].base + reg - 0x06, data);
  }
  else if (reg < 0x0E)
  {
    tsos->io.out8(channels[channel].ctrl + reg - 0x0A, data);
  }
  else if (reg < 0x16)
  {
    tsos->io.out8(channels[channel].bmide + reg - 0x0E, data);
  }
  if (reg > 0x07 && reg < 0x0C)
  {
    ide_write(channel, ATA_REG_CONTROL, channels[channel].nIEN);
  }
}

uint8_t ATAPI_quark::ide_read(uint8_t channel, uint8_t reg)
{
  uint8_t result = 0;
  if (reg > 0x07 && reg < 0x0C)
  {
    ide_write(channel, ATA_REG_CONTROL, 0x80 | channels[channel].nIEN);
  }
  if (reg < 0x08)
  {
    result = tsos->io.in8(channels[channel].base + reg - 0x00);
  }
  else if (reg < 0x0C)
  {
    result = tsos->io.in8(channels[channel].base + reg - 0x06);
  }
  else if (reg < 0x0E)
  {
    result = tsos->io.in8(channels[channel].ctrl + reg - 0x0A);
  }
  else if (reg < 0x16)
  {
    result = tsos->io.in8(channels[channel].bmide + reg - 0x0E);
  }
  if (reg > 0x07 && reg < 0x0C)
  {
    ide_write(channel, ATA_REG_CONTROL, channels[channel].nIEN);
  }
  return result;
}

/*

void ATAPI_quark::ide_read_buffer(uint8_t channel, uint8_t reg, uint32_t buffer,
                                  uint32_t quads)
{
  if (reg > 0x07 && reg < 0x0C)
  {
    ide_write(channel, ATA_REG_CONTROL, 0x80 | channels[channel].nIEN);
  }
  asm("pushw %es; movw %ds, %ax; movw %ax, %es");
  if (reg < 0x08)
  {
    tsos->io.in32(channels[channel].base + reg - 0x00, buffer, quads);
  }
  else if (reg < 0x0C)
  {
    tsos->io.in32(channels[channel].base + reg - 0x06, buffer, quads);
  }
  else if (reg < 0x0E)
  {
    tsos->io.in32(channels[channel].ctrl + reg - 0x0A, buffer, quads);
  }
  else if (reg < 0x16)
  {
    tsos->io.in32(channels[channel].bmide + reg - 0x0E, buffer, quads);
  }
  asm("popw %es;");
  if (reg > 0x07 && reg < 0x0C)
  {
    ide_write(channel, ATA_REG_CONTROL, channels[channel].nIEN);
  }
}
*/