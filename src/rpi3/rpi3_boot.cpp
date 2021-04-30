// By Tsuki Superior
#include <rpi3/rpi3_boot.hpp>

RPI3_BOOT_quark::RPI3_BOOT_quark(void)
{
    name = "Raspberry Pi 3 Boot";
}

RPI3_BOOT_quark::~RPI3_BOOT_quark(void)
{
}

bool RPI3_BOOT_quark::detectsystem(void)
{
    return true;
}

void RPI3_BOOT_quark::reset(void)
{
}

void RPI3_BOOT_quark::reboot(void)
{
}

void RPI3_BOOT_quark::shutdown(void)
{
}
