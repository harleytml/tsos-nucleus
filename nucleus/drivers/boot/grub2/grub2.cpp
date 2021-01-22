//By Tsuki Superior
#include "grub2.hpp"

GRUB2_driver::GRUB2_driver(void)
{

}

GRUB2_driver::~GRUB2_driver(void)
{
}

bool GRUB2_driver::detectsystem(void)
{
    return true;
}

// Defining the reboot function
void GRUB2_driver::reboot(void)
{
    uint16_t *post_reset_flag = (uint16_t *)0x400072;

    // Tell the BIOS to perform a warm boot
    *post_reset_flag = 0x1234;
}

void GRUB2_driver::shutdown(void)
{
}
