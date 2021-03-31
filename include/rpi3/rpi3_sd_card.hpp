//By Tsuki Superior
#ifndef __TSOS_RPI3_SD_CARD_DRIVER__
#define __TSOS_RPI3_SD_CARD_DRIVER__

#include "generic/disk_driver.hpp"

class RPI3_SD_CARD_driver : public Disk_driver
{
public:
  // Constructor
  RPI3_SD_CARD_driver(void);

  ~RPI3_SD_CARD_driver();

  bool detectsystem(void) final;

  void reset(void) final;

  // Get an amount of bytes from the disk
  void getbytes(uint8_t *buffer, uint16_t offset, uint8_t len) final;

  // Get the sector size
  uint16_t getsectorsize(void) final;
};

#endif
