/* By Tsuki Superior
 * Disk Nucleon
 * 
 * This is the wrapper nucleon for the quarks.
 */

#pragma once

#include <generic/quark.hpp>
#include <generic/nucleon.hpp>
#include <generic/types.hpp>
#include <generic/disk_quark.hpp>
#include <generic/current_config.hpp>

// The main class controlling the disks
class Disk : public Nucleon<Disk_quark>
{
public:
  // Constructor
  Disk(void);

  // Destructor
  ~Disk();

  // Get an amount of bytes from the disk
  void getbytes(uint32_t offset, uint16_t len, uint8_t *data) const;

  // Get an amount of bytes from the disk
  void setbytes(uint32_t offset, uint16_t len, uint8_t *data) const;

  // Get the sector size
  uint16_t getsectorsize(void) const;

  // Do not return till the disk is idle (for when you need to shutdown, reboot, or remove the disk)
  void commitall(void) const;
};
