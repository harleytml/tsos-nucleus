//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_DISK__
#define __TSOS_NUCLEUS_DISK__

#include "core.hpp"

// The main class controlling the disks
class Disk : public Module
{
public:
  // Constructor
  Disk(void);

  // Destructor
  ~Disk(void);

  // Get an amount of bytes from the disk
  uint8_t *getbytes(uint16_t offset, uint8_t len);

  // Get the sector size
  uint16_t getsectorsize(void);

  // Do not return till the disk is idle (for when you need to shutdown, reboot, or remove the disk)
  void commitall(void);

private:
  // Disk driver
  Disk_driver *driver;
};

class Disk_driver : public Driver
{
public:
  // Constructor
  Disk_driver(void);

  // Destructor
  ~Disk_driver(void);

  // Get bytes from the disk
  virtual void getbytes(uint8_t buffer, uint16_t offset, uint8_t len){};

  // Get the sector size
  virtual uint16_t getsectorsize(void){};
};

#endif
