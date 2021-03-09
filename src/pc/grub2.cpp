//By Tsuki Superior
#include "grub2.hpp"

GRUB2_driver::GRUB2_driver(void)
{
    name = "Grand Unified Bootloader 2";
}

GRUB2_driver::~GRUB2_driver()
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

    //Lets actually reboot
    asm volatile("push 0xffff\n"
                 "push 0x0000\n"
                 "ret\n");
}

void GRUB2_driver::shutdown(void)
{
}
