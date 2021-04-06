//By Tsuki Superior
#include <pc/atapi.hpp>
#include <generic/nucleus_instance.hpp>

ATAPI_quark::ATAPI_quark(void)
{
  name = "AT Attachment Packet Interface";
  channels[0] = IDEChannelRegisters();
  channels[1] = IDEChannelRegisters();
  ide_devices[0] = IDE_device();
  ide_devices[1] = IDE_device();
  ide_devices[2] = IDE_device();
  ide_devices[3] = IDE_device();
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

void ATAPI_quark::insl(uint32_t port, void *addr, uint32_t cnt)
{
  __asm__ volatile(
      "cld;"
      "repne; insl;"
      : "=D"(addr), "=c"(cnt)
      : "d"(port), "0"(addr), "1"(cnt)
      : "memory", "cc");
}

void ATAPI_quark::ide_write(uint8_t channel, uint8_t reg, uint8_t data)
{
  if ((reg > 0x07) && (reg < 0x0c))
  {
    ide_write(channel, ATA_REG_CONTROL, 0x80 | channels[channel].nIEN);
  }
  if (reg < 0x08)
  {
    tsos->io.out8(channels[channel].base + reg - 0x00, data);
  }
  else if (reg < 0x0c)
  {
    tsos->io.out8(channels[channel].base + reg - 0x06, data);
  }
  else if (reg < 0x0e)
  {
    tsos->io.out8(channels[channel].ctrl + reg - 0x0A, data);
  }
  else if (reg < 0x16)
  {
    tsos->io.out8(channels[channel].bmide + reg - 0x0E, data);
  }
  if ((reg > 0x07) && (reg < 0x0c))
  {
    ide_write(channel, ATA_REG_CONTROL, channels[channel].nIEN);
  }
}

uint8_t ATAPI_quark::ide_read(uint8_t channel, uint8_t reg)
{
  uint8_t result = 0;
  if ((reg > 0x07) && (reg < 0x0c))
  {
    ide_write(channel, ATA_REG_CONTROL, 0x80 | channels[channel].nIEN);
  }
  if (reg < 0x08)
  {
    result = tsos->io.in8(channels[channel].base + reg - 0x00);
  }
  else if (reg < 0x0c)
  {
    result = tsos->io.in8(channels[channel].base + reg - 0x06);
  }
  else if (reg < 0x0e)
  {
    result = tsos->io.in8(channels[channel].ctrl + reg - 0x0A);
  }
  else if (reg < 0x16)
  {
    result = tsos->io.in8(channels[channel].bmide + reg - 0x0E);
  }
  if ((reg > 0x07) && (reg < 0x0c))
  {
    ide_write(channel, ATA_REG_CONTROL, channels[channel].nIEN);
  }
  return result;
}

void ATAPI_quark::ide_read_buffer(uint8_t channel, uint8_t reg, void *buffer, uint32_t quads)
{
  if ((reg > 0x07) && (reg < 0x0c))
  {
    ide_write(channel, ATA_REG_CONTROL, 0x80 | channels[channel].nIEN);
  }
  __asm__ volatile("pushw %es; movw %ds, %ax; movw %ax, %es");
  if (reg < 0x08)
  {
    insl(channels[channel].base + reg - 0x00, buffer, quads);
  }
  else if (reg < 0x0C)
  {
    insl(channels[channel].base + reg - 0x06, buffer, quads);
  }
  else if (reg < 0x0E)
  {
    insl(channels[channel].ctrl + reg - 0x0A, buffer, quads);
  }
  else if (reg < 0x16)
  {
    insl(channels[channel].bmide + reg - 0x0E, buffer, quads);
  }
  __asm__ volatile("popw %es;");
  if ((reg > 0x07) && (reg < 0x0C))
  {
    ide_write(channel, ATA_REG_CONTROL, channels[channel].nIEN);
  }
}

uint8_t ATAPI_quark::ide_polling(uint8_t channel, uint32_t advanced_check)
{

  // (I) Delay 400 nanosecond for BSY to be set:
  // -------------------------------------------------
  for (int i = 0; i < 4; i++)
  {
    ide_read(channel, ATA_REG_ALTSTATUS); // Reading the Alternate Status port wastes 100ns; loop four times.
  }

  // (II) Wait for BSY to be cleared:
  // -------------------------------------------------
  while (ide_read(channel, ATA_REG_STATUS) & ATA_SR_BSY)
  {
  }; // Wait for BSY to be zero.

  if (advanced_check)
  {
    uint8_t state = ide_read(channel, ATA_REG_STATUS); // Read Status Register.

    // (III) Check For Errors:
    // -------------------------------------------------
    if (state & ATA_SR_ERR)
    {
      return 2; // Error.
    }

    // (IV) Check If Device fault:
    // -------------------------------------------------
    if (state & ATA_SR_DF)
    {
      return 1; // Device Fault.
    }

    // (V) Check DRQ:
    // -------------------------------------------------
    // BSY = 0; DF = 0; ERR = 0 so we should check for DRQ now.
    if ((state & ATA_SR_DRQ) == 0)
    {
      return 3; // DRQ should be set
    }
  }

  return 0; // No Error.
}
