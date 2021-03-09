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
  bool detectsystem(void) override;

  // Reboot the system
  void reboot(void) override;

  // Shutdown the system
  void shutdown(void) override;
};

#endif
