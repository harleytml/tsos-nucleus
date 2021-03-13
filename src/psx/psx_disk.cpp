//By Tsuki Superior
#include "psx_disk.hpp"

PSX_DISK_driver::PSX_DISK_driver(void)
{
    name = "Playstation X Disk";
}

PSX_DISK_driver::~PSX_DISK_driver()
{
}

bool PSX_DISK_driver::detectsystem()
{
    return true;
}

void PSX_DISK_driver::reset(void)
{
}

void PSX_DISK_driver::getbytes(uint8_t *buffer, uint16_t offset, uint8_t len)
{
}

uint16_t PSX_DISK_driver::getsectorsize(void)
{
    return 0;
}
