/* By Tsuki Superior
 * Disk Module
 * 
 * This is the wrapper module for the drivers.
 */

#ifndef __TSOS_NUCLEUS_DISK_MODULE__
#define __TSOS_NUCLEUS_DISK_MODULE__

#include "generic/driver.hpp"
#include "generic/module.hpp"
#include "generic/types.hpp"
#include "generic/disk_driver.hpp"
#include "generic/current_config.hpp"

// The main class controlling the disks
class Disk : public Module<Disk_driver>
{
public:
  // Constructor
  Disk(void);

  // Destructor
  ~Disk();

  // Get an amount of bytes from the disk
  uint8_t *getbytes(uint16_t offset, uint8_t len) const;

  // Get the sector size
  uint16_t getsectorsize(void) const;

  // Do not return till the disk is idle (for when you need to shutdown, reboot, or remove the disk)
  void commitall(void) const;
};

#endif
