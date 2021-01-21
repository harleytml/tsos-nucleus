//By Tsuki Superior
#ifndef __TSOS_DMG_CARTRIDGE_DRIVER__
#define __TSOS_DMG_CARTRIDGE_DRIVER__

#include "disk.hpp"

class DMG_CARTRIDGE_driver : public Disk_driver
{
public:
    // Constructor
    DMG_CARTRIDGE_driver(void);
    bool detectsystem(void);

    // Get an amount of bytes from the disk
    char *getbytes(uint16_t offset, uint8_t len);

    // Get the sector size
    uint16_t getsectorsize(void);

private:
};

enum DMG_CARTRIDGE_type
{
    MBC1
};

#endif
