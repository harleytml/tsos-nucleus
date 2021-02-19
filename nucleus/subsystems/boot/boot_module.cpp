//By Tsuki Superior
#include "./boot_module.hpp"

Boot::Boot(void)
{
}

Boot::~Boot()
{
}

void Boot::reboot(void)
{
    driver->reboot();
}

void Boot::shutdown(void)
{

    // Destroy tsos, to trigger the kernel destruction
    delete tsos;
    driver->shutdown();
}

void Boot::fission(char *errormsg)
{
    reboot();
}