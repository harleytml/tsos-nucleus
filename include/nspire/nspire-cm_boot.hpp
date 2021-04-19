//By Tsuki Superior
#pragma once

#include <generic/boot_quark.hpp>

class NSPIRE_CM_BOOT_quark : public Boot_quark
{
public:
  // Constructor
  NSPIRE_CM_BOOT_quark(void);

  // Destructor
  ~NSPIRE_CM_BOOT_quark();

  // Detect the type of system its running on
  bool detectsystem(void) final;

  void reset(void) final;

  // Reboot the system
  void reboot(void) final;

  // Shutdown the system
  void shutdown(void) final;
};
