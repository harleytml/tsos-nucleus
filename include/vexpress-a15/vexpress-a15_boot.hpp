//By Tsuki Superior
#pragma once

#include <generic/boot_quark.hpp>

class VEXPRESS_A15_BOOT_quark : public Boot_quark
{
public:
  // Constructor
  VEXPRESS_A15_BOOT_quark(void);

  // Destructor
  ~VEXPRESS_A15_BOOT_quark();

  // Detect the type of system its running on
  bool detectsystem(void) final;

  void reset(void) final;

  // Reboot the system
  void reboot(void) final;

  // Shutdown the system
  void shutdown(void) final;
};
