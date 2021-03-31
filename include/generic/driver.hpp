/* By Tsuki Superior
 * Abstract Driver
 *
 * This is the abstract class that all the subclasses of
 * drivers inherit from.
 *  
 */

#ifndef __TSOS_DRIVER_CORE__
#define __TSOS_DRIVER_CORE__

#include "generic/types.hpp"

// The class for drivers
class Driver
{
public:
  // Constructor
  Driver(void);

  // Destructor
  ~Driver();

  // A function called to determine if a driver should be used.
  virtual bool detectsystem(void) = 0;

  virtual void reset(void) = 0;

  // The name of said driver
  char *name;
};

#endif
