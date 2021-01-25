//By Tsuki Superior
#ifndef __TSOS_DMG_BOOT_DRIVER__
#define __TSOS_DMG_BOOT_DRIVER__

#include "../../../subsystems/boot/boot.hpp"

class DMG_BOOT_driver : public Boot_driver
{
public:
  // Constructor
  DMG_BOOT_driver(void);

  // Destructor
  ~DMG_BOOT_driver(void);

  bool detectsystem(void);
  
  // Reboot the system
  void reboot(void);

  // Shutdown the system
  void shutdown(void);
};
#endif
