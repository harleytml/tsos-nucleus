// By Tsuki Superior
#include <vexpress-a15/vexpress-a15_boot.hpp>

VEXPRESS_A15_BOOT_quark::VEXPRESS_A15_BOOT_quark(void)
{
    name = "Versatile Express A15";
}

VEXPRESS_A15_BOOT_quark::~VEXPRESS_A15_BOOT_quark(void)
{
}

bool VEXPRESS_A15_BOOT_quark::detectsystem(void)
{
    return true;
}

void VEXPRESS_A15_BOOT_quark::reset(void)
{
}

void VEXPRESS_A15_BOOT_quark::reboot(void)
{
}

// From the chdk project
void VEXPRESS_A15_BOOT_quark::shutdown(void)
{
}
