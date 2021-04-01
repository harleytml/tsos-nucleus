/* By Tsuki Superior
 * Gameboy Advanced Boot Driver 
 *
 * Note that the GBA is a simple game console
 * and therefore has no hardware provided functions for anything
 * contained in the nucleon
 * 
 * To shutdown, TS/OS will power down every piece of hardware it can, then go into a loop
 * To reboot, TS/OS will just simply just jump back to the boot code
 * 
 */

#ifndef __TSOS_GBA_BOOT_QUARK__
#define __TSOS_GBA_BOOT_QUARK__

#include "generic/boot_quark.hpp"

class GBA_BOOT_quark : public Boot_quark
{
public:
  // Constructor
  GBA_BOOT_quark(void);

  // Destructor
  ~GBA_BOOT_quark();

  // Detect the type of system its running on
  bool detectsystem(void) final;

  void reset(void) final;

  // Reboot the system
  void reboot(void) final;

  // Shutdown the system
  void shutdown(void) final;
};

#endif
