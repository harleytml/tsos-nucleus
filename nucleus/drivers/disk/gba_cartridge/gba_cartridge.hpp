//By Tsuki Superior
#ifndef __TSOS_GBA_CARTRIDGE_DRIVER__
#define __TSOS_GBA_CARTRIDGE_DRIVER__

#include "disk.hpp"

class GBA_CARTRIDGE_driver : public Disk_driver
{
public:
    //Constructor
    GBA_CARTRIDGE_driver(void);
    bool detectsystem(void);

    //Get a amount of bytes from the disk
    char *getbytes(uint16_t offset, uint8_t len);

    //Get the sector size
    uint16_t getsectorsize(void);

private:
};

#endif