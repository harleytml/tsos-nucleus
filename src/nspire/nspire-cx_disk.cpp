//By Tsuki Superior
#include <nspire/nspire-cx_disk.hpp>

NSPIRE_CX_DISK_quark::NSPIRE_CX_DISK_quark(void)
{
  name = "Texas Instruments Nspire CX Disk";
}

NSPIRE_CX_DISK_quark::~NSPIRE_CX_DISK_quark()
{
}

bool NSPIRE_CX_DISK_quark::detectsystem()
{
  return true;
}

void NSPIRE_CX_DISK_quark::reset(void)
{
}

void NSPIRE_CX_DISK_quark::getbytes(uint8_t *buffer, uint16_t offset, uint8_t len)
{
}

uint16_t NSPIRE_CX_DISK_quark::getsectorsize(void)
{
  return 0;
}
