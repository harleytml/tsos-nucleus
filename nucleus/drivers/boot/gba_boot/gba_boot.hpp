//By Tsuki Superior
#ifndef __TSOS_GBA_BOOT_DRIVER__
#define __TSOS_GBA_BOOT_DRIVER__

#include "boot.hpp"

class GBA_BOOT_driver : public Boot_driver
{
public:
  //Constructor
  GBA_BOOT_driver(void);

  //Destructor
  ~GBA_BOOT_driver(void);

  //Detect the system its running on
  BOOLEAN detectsystem(void);

  //Reboot the system
  void reboot(void);

  //Shutdown system
  void shutdown(void);
};

#endif