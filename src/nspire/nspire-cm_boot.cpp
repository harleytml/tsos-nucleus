// By Tsuki Superior
#include <nspire/nspire-cm_boot.hpp>

NSPIRE_CM_BOOT_quark::NSPIRE_CM_BOOT_quark(void)
{
    name = "Texas Instruments Nspire CM Boot";
}

NSPIRE_CM_BOOT_quark::~NSPIRE_CM_BOOT_quark(void)
{
}

bool NSPIRE_CM_BOOT_quark::detectsystem(void)
{
    return true;
}

void NSPIRE_CM_BOOT_quark::reset(void)
{
}

void NSPIRE_CM_BOOT_quark::reboot(void)
{
}

void NSPIRE_CM_BOOT_quark::shutdown(void)
{
}
