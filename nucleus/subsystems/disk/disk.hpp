//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_DISK__
#define __TSOS_NUCLEUS_DISK__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"
#include "../../core/core.hpp"

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

// The main class controlling the disks
class Disk : public Module<Disk_driver>
{
public:
  // Constructor
  Disk(void);

  // Destructor
  ~Disk();

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

#endif
