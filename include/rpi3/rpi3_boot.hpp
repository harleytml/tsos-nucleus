//By Tsuki Superior
#ifndef __TSOS_RPI3_BOOT_DRIVER__
#define __TSOS_RPI3_BOOT_DRIVER__

#include "boot_driver.hpp"

class RPI3_BOOT_driver : public Boot_driver
{
public:
  // Constructor
  RPI3_BOOT_driver(void);

  // Destructor
  ~RPI3_BOOT_driver();

  // Detect the type of system its running on
  bool detectsystem(void) override;

  void reset(void) override;

  // Reboot the system
  void reboot(void) override;

  // Shutdown the system
  void shutdown(void) override;
};

#endif
