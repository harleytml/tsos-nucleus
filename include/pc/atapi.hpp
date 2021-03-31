//By Tsuki Superior
#ifndef __TSOS_ATAPI_DRIVER__
#define __TSOS_ATAPI_DRIVER__

#include "generic/disk_driver.hpp"

class ATAPI_driver : public Disk_driver
{
public:
  // Constructor
  ATAPI_driver(void);

  ~ATAPI_driver();

  bool detectsystem(void) final;

  void reset(void) final;

  // Get an amount of bytes from the disk
  void getbytes(uint8_t *buffer, uint16_t offset, uint8_t len) final;

  // Get the sector size
  uint16_t getsectorsize(void) final;
};

#endif
