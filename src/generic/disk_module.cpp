//By Tsuki Superior
#include "disk_module.hpp"

Disk::Disk(void)
{
}

Disk::~Disk()
{
}

uint8_t *Disk::getbytes(uint16_t offset, uint8_t len)
{
    uint8_t *buffer = (uint8_t *)"";
    driver->getbytes(buffer, offset, len);
    return buffer;
}

uint16_t Disk::getsectorsize(void)
{
    return driver->getsectorsize();
}

void Disk::commitall(void)
{
}
