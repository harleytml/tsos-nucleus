//By Tsuki Superior
#ifndef __TSOS_CANON_A1100_BOOT_QUARK__
#define __TSOS_CANON_A1100_BOOT_QUARK__

#include "generic/boot_quark.hpp"

class CANON_A1100_BOOT_quark : public Boot_quark
{
public:
  // Constructor
  CANON_A1100_BOOT_quark(void);

  // Destructor
  ~CANON_A1100_BOOT_quark();

  // Detect the type of system its running on
  bool detectsystem(void) final;

  void reset(void) final;

  // Reboot the system
  void reboot(void) final;

  // Shutdown the system
  void shutdown(void) final;
};

#endif
