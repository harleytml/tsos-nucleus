//By Tsuki Superior

#ifndef __TSOS_NUCLEUS_DISK_DRIVER__
#define __TSOS_NUCLEUS_DISK_DRIVER__

#include "../../core/driver.hpp"
#include "../../core/types.hpp"

class Disk_driver : public Driver
{
public:
    // Constructor
    Disk_driver(void);

    // Destructor
    ~Disk_driver();

    // Get bytes from the disk
    virtual void getbytes(uint8_t buffer, uint16_t offset, uint8_t len) = 0;

    // Get the sector size
    virtual uint16_t getsectorsize(void) = 0;
};

#endif
