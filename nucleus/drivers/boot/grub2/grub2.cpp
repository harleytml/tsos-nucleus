//By Tsuki Superior
#include "grub2.hpp"

GRUB2_driver::GRUB2_driver(void)
{

    //Start a instance of the TS/OS api
    tsos = Tsos();
}

GRUB2_driver::~GRUB2_driver(void)
{
}

bool GRUB2_driver::detectsystem(void)
{

    //Well, if we made it this far, I think we can assume the module is good
    return true;
}

//This is a rather old and crusty reboot method....
void GRUB2_driver::reboot(void)
{
    uint16_t *post_reset_flag = (uint16_t *)0x400072;

    //Tell the BIOS we want a warm boot
    *post_reset_flag = 0x1234;
}

void GRUB2_driver::shutdown(void)
{
    //Well... old pcs cannot truely "shutdown" from software alone...
}
