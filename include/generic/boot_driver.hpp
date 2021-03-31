/* By Tsuki Superior
 * Generic Boot Driver
 *
 * This is a abstract class that all the Boot drivers inherit from
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
