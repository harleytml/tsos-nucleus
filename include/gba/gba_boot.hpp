//By Tsuki Superior
#ifndef __TSOS_GBA_BOOT_DRIVER__
#define __TSOS_GBA_BOOT_DRIVER__

#include "boot_driver.hpp"

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
