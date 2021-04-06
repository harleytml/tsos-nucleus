/* By Tsuki Superior
 * Generic Boot Nucleon
 *
 * This nucleon, like the other nucleons, acts as a wrapper to call the quarks
 * It has one more function, known as the fission, which is like the BSOD of
 * Windows, or the Kernel Panic of the *nix operating systems
 */

#ifndef __TSOS_NUCLEUS_BOOT_NUCLEON__
#define __TSOS_NUCLEUS_BOOT_NUCLEON__

#include <generic/quark.hpp>
#include <generic/nucleon.hpp>
#include <generic/types.hpp>
#include <generic/boot_quark.hpp>
#include <generic/current_config.hpp>

// The main class controlling the system runtime
class Boot : public Nucleon<Boot_quark>
{
public:
  // Constructor
  Boot(void);

  // Constructor
  ~Boot();

  // Reboot the system
  void reboot(void) const;

  // Shutdown the system
  void shutdown(void) const;

  // The equivelent kernel panic, or bsod,
  void fission(const char *errormsg) const;
};

#endif
