//By Tsuki Superior
#include "nspire-cx/nspire-cx_boot.hpp"

NSPIRE_CX_BOOT_quark::NSPIRE_CX_BOOT_quark(void)
{
  name = "Texas Instruments Nspire CX Boot";
}

NSPIRE_CX_BOOT_quark::~NSPIRE_CX_BOOT_quark(void)
{
}

bool NSPIRE_CX_BOOT_quark::detectsystem(void)
{
  return true;
}

void NSPIRE_CX_BOOT_quark::reset(void)
{
}

void NSPIRE_CX_BOOT_quark::reboot(void)
{
}

void NSPIRE_CX_BOOT_quark::shutdown(void)
{
}
