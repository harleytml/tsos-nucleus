//By Tsuki Superior
#include <nspire/nspire-cm_disk.hpp>

NSPIRE_CM_DISK_quark::NSPIRE_CM_DISK_quark(void)
{
  name = "Texas Instruments Nspire CM Disk";
}

NSPIRE_CM_DISK_quark::~NSPIRE_CM_DISK_quark()
{
}

bool NSPIRE_CM_DISK_quark::detectsystem()
{
  return true;
}

void NSPIRE_CM_DISK_quark::reset(void)
{
}

void NSPIRE_CM_DISK_quark::getbytes(uint8_t *buffer, uint16_t offset, uint8_t len)
{
}

uint16_t NSPIRE_CM_DISK_quark::getsectorsize(void)
{
  return 0;
}
