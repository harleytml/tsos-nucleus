/* By Tsuki Superior
 * Generic Boot Module
 *
 * This module, like the other modules, acts as a wrapper to call the drivers
 * It has one more function, known as the fission, which is like the BSOD of
 * Windows, or the Kernel Panic of the *nix operating systems
 */

#ifndef __TSOS_NUCLEUS_BOOT_NUCLEON__
#define __TSOS_NUCLEUS_BOOT_NUCLEON__

#include "generic/driver.hpp"
#include "generic/module.hpp"
#include "generic/types.hpp"
#include "generic/boot_driver.hpp"
#include "generic/current_config.hpp"

// The main class controlling the system runtime
class Boot : public Module<Boot_driver>
{
public:
  // Constructor
  Boot(void);

  // Constructor
  ~Boot();

  // Reboot the system
  void reboot(void) const;

  // Shutdown the system
  void shutdown(void) const;

  // The equivelant kernel panic, or bsod,
  void fission(const char *errormsg) const;
};

#endif
