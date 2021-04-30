/* By Tsuki Superior
 * Abstract Disk Quark
 *
 * To make a new Disk quark, simply have it inherit from this class
 */

#pragma once

#include <generic/quark.hpp>
#include <generic/types.hpp>

class Disk_quark : public Quark
{
  public:
    // Constructor
    Disk_quark(void);

    // Destructor
    ~Disk_quark();

    // Get bytes from the disk
    virtual void getbytes(uint8_t *buffer, uint16_t offset, uint8_t len) = 0;

    // Get the sector size
    virtual uint16_t getsectorsize(void) = 0;
};
