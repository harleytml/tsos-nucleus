//By Tsuki Superior
#ifndef __TSOS_GRUB2_QUARK__
#define __TSOS_GRUB2_QUARK__

#include <generic/boot_quark.hpp>

class GRUB2_quark : public Boot_quark
{
public:
  //Constructor
  GRUB2_quark(void);

  //Destructor
  ~GRUB2_quark();

  //Detect the type of system its running on
  bool detectsystem(void) final;

  void reset(void) final;

  //Reboot the system
  void reboot(void) final;

  // Shutdown the system
  void shutdown(void) final;
};
#endif
