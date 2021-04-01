/* By Tsuki Superior
 * Abstract Boot Driver
 *
 * To make a new Boot driver, simply have it inherit from this class
 */

#ifndef __TSOS_NUCLEUS_BOOT_DRIVER__
#define __TSOS_NUCLEUS_BOOT_DRIVER__

#include "generic/driver.hpp"

class Boot_driver : public Driver
{
public:
  // Constructor
  Boot_driver(void);

  // Destructor
  ~Boot_driver();

  // Reboot the system
  virtual void reboot(void) = 0;

  // Shutdown the system
  virtual void shutdown(void) = 0;
};

#endif
