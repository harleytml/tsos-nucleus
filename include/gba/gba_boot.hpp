/* By Tsuki Superior
 * Gameboy Advanced Boot Driver 
 *
 * Note that the GBA is a simple game console
 * and therefore has no hardware provided functions for anything
 * contained in the module
 * 
 * To shutdown, TS/OS will power down every piece of hardware it can, then go into a loop
 * To reboot, TS/OS will just simply just jump back to the boot code
 * 
 */

#ifndef __TSOS_GBA_BOOT_DRIVER__
#define __TSOS_GBA_BOOT_DRIVER__

#include "generic/boot_driver.hpp"

class GBA_BOOT_driver : public Boot_driver
{
public:
  // Constructor
  GBA_BOOT_driver(void);

  // Destructor
  ~GBA_BOOT_driver();

  // Detect the type of system its running on
  bool detectsystem(void) final;

  void reset(void) final;

  // Reboot the system
  void reboot(void) final;

  // Shutdown the system
  void shutdown(void) final;
};

#endif
