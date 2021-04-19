//By Tsuki Superior
#ifndef __TSOS_MULTIBOOT_QUARK__
#define __TSOS_MULTIBOOT_QUARK__

#include <generic/boot_quark.hpp>

class MULTIBOOT_quark : public Boot_quark
{
public:
  //Constructor
  MULTIBOOT_quark(void);

  //Destructor
  ~MULTIBOOT_quark();

  //Detect the type of system its running on
  bool detectsystem(void) final;

  void reset(void) final;

  //Reboot the system
  void reboot(void) final;

  // Shutdown the system
  void shutdown(void) final;
};
#endif
