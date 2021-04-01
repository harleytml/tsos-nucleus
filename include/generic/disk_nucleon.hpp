/* By Tsuki Superior
 * Disk Nucleon
 * 
 * This is the wrapper nucleon for the quarks.
 */

#ifndef __TSOS_NUCLEUS_DISK_NUCLEON__
#define __TSOS_NUCLEUS_DISK_NUCLEON__

#include "generic/quark.hpp"
#include "generic/nucleon.hpp"
#include "generic/types.hpp"
#include "generic/disk_quark.hpp"
#include "generic/current_config.hpp"

// The main class controlling the disks
class Disk : public Nucleon<Disk_quark>
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
