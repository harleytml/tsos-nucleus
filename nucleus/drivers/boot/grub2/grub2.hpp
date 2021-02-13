//By Tsuki Superior
#ifndef __TSOS_GRUB2_DRIVER__
#define __TSOS_GRUB2_DRIVER__

#include "../../../subsystems/boot/boot_module.hpp"
#include "../../../subsystems/boot/boot_driver.hpp"

class GRUB2_driver : public Boot_driver
{
public:
  //Constructor
  GRUB2_driver(void);

  //Destructor
  ~GRUB2_driver();

  //Detect the type of system its running on
  bool detectsystem(void);

  //Reboot the system
  void reboot(void);

  // Shutdown the system
  void shutdown(void);
};
#endif
