//By Tsuki Superior
#ifndef __TSOS_GRUB2_DRIVER__
#define __TSOS_GRUB2_DRIVER__

#include "generic/boot_driver.hpp"

class GRUB2_driver : public Boot_driver
{
public:
  //Constructor
  GRUB2_driver(void);

  //Destructor
  ~GRUB2_driver();

  //Detect the type of system its running on
  bool detectsystem(void) final;

  void reset(void) final;

  //Reboot the system
  void reboot(void) final;

  // Shutdown the system
  void shutdown(void) final;
};
#endif
