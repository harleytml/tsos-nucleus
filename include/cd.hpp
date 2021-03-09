//By Tsuki Superior
#ifndef __TSOS_CD_DRIVER__
#define __TSOS_CD_DRIVER__

#define SECTOR_SIZE 2048

#include "disk_driver.hpp"

class CD_driver : public Disk_driver
{
public:
  // Constructor
  CD_driver(void);

  ~CD_driver();

  bool detectsystem(void) override;

  // Get an amount of bytes from the disk
  void getbytes(uint8_t *buffer, uint16_t offset, uint8_t len) override;

  // Get the sector size
  uint16_t getsectorsize(void) override;
};

#endif
