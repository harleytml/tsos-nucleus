//By Tsuki Superior
#ifndef __TSOS_ATAPI_DRIVER__
#define __TSOS_ATAPI_DRIVER__

#include "disk_driver.hpp"

class ATAPI_driver : public Disk_driver
{
public:
  // Constructor
  ATAPI_driver(void);

  ~ATAPI_driver();

  bool detectsystem(void) override;

  void reset(void) override;

  // Get an amount of bytes from the disk
  void getbytes(uint8_t *buffer, uint16_t offset, uint8_t len) override;

  // Get the sector size
  uint16_t getsectorsize(void) override;
};

#endif
