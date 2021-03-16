//By Tsuki Superior
#ifndef __TSOS_GBA_CARTRIDGE_DRIVER__
#define __TSOS_GBA_CARTRIDGE_DRIVER__

#include "disk_driver.hpp"

class PSX_DISK_driver : public Disk_driver
{
public:
  // Constructor
  PSX_DISK_driver(void);

  ~PSX_DISK_driver();

  bool detectsystem(void) override;

  void reset(void) override;

  // Get an amount of bytes from the disk
  void getbytes(uint8_t *buffer, uint16_t offset, uint8_t len) override;

  // Get the sector size
  uint16_t getsectorsize(void) override;
};

#endif
