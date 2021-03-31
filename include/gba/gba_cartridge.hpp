/* By Tsuki Superior
 * Gameboy Advanced Cartridge Driver 
 *
 * There are two ways to approach the problem of how to store memory on a 
 * game console like this, within the simplicity that is TS/OS so far.
 * You can either prepare save files and write to them as if there were a disk
 * Or you can simply, as I saw a sysv runtime on a GBA do, just simply append the disk
 * image to the end of the of the ROM, and address it as so.
 * 
 * The second option will be choosen because of the size limitation of the
 * save files, and also the fact that some emulators use save files that have a 
 * actual format and not just a blob of raw data
 */

#ifndef __TSOS_GBA_CARTRIDGE_DRIVER__
#define __TSOS_GBA_CARTRIDGE_DRIVER__

#include "generic/disk_driver.hpp"

class GBA_CARTRIDGE_driver : public Disk_driver
{
public:
  // Constructor
  GBA_CARTRIDGE_driver(void);

  ~GBA_CARTRIDGE_driver();

  bool detectsystem(void) final;

  void reset(void) final;

  // Get an amount of bytes from the disk
  void getbytes(uint8_t *buffer, uint16_t offset, uint8_t len) final;

  // Get the sector size
  uint16_t getsectorsize(void) final;
};

#endif
