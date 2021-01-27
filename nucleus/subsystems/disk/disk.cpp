//By Tsuki Superior
#include "./disk.hpp"

Disk::Disk(void)
{
}

Disk::~Disk(void)
{
}

uint8_t *Disk::getbytes(uint16_t offset, uint8_t len)
{
    uint8_t * buffer = (uint8_t)(new char(len));
    driver->getbytes(buffer, offset, len);
    return buffer;
}

uint16_t Disk::getsectorsize(void)
{
    return driver->getsectorsize();
}

Disk_driver::Disk_driver(void)
{
}

Disk_driver::~Disk_driver()
{
}
