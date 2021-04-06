/* By Tsuki Superior
 * Abstract Quark
 *
 * This is the abstract class that all the subclasses of
 * quarks inherit from.
 *  
 */

#ifndef __TSOS_DRIVER_CORE__
#define __TSOS_DRIVER_CORE__

#include <generic/types.hpp>

// The class for quarks
class Quark
{
public:
  // Constructor
  Quark(void);

  // Destructor
  ~Quark();

  // A function called to determine if a quark should be used.
  virtual bool detectsystem(void) = 0;

  virtual void reset(void) = 0;

  // The name of said quark
  char *name;
};

#endif
