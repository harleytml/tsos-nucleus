//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_DISK_MODULE__
#define __TSOS_NUCLEUS_DISK_MODULE__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"
#include "../../core/core.hpp"
#include "./disk_driver.hpp"

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
