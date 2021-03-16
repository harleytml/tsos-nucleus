//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_BOOT_MODULE__
#define __TSOS_NUCLEUS_BOOT_MODULE__

#include "driver.hpp"
#include "module.hpp"
#include "types.hpp"
#include "boot_driver.hpp"
#include "current_config.hpp"

// The main class controlling the system runtime
class Boot : public Module<Boot_driver>
{
public:
  // Constructor
  Boot(void);

  // Constructor
  ~Boot();

  // Reboot the system
  void reboot(void);

  // Shutdown the system
  void shutdown(void);

  // The equivelant kernel panic, or bsod,
  void fission(const char *errormsg);
};

#endif
