/* By Tsuki Superior
 * Abstract Boot Quark
 *
 * To make a new Boot quark, simply have it inherit from this class
 */

#ifndef __TSOS_NUCLEUS_BOOT_QUARK__
#define __TSOS_NUCLEUS_BOOT_QUARK__

#include <generic/quark.hpp>

class Boot_quark : public Quark
{
public:
  // Constructor
  Boot_quark(void);

  // Destructor
  ~Boot_quark();

  // Reboot the system
  virtual void reboot(void) = 0;

  // Shutdown the system
  virtual void shutdown(void) = 0;
};

#endif
