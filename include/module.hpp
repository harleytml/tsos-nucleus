//By Tsuki Superior
#ifndef __TSOS_MODULE_CORE__
#define __TSOS_MODULE_CORE__

#include "driver.hpp"
#include "types.hpp"

// The base class of TS/OS modules
template <class T>
class Module
{
public:
  // Constructor
  Module(void);

  // Destructor
  ~Module();

  // The full name of the modules's target
  const char *name;

  // Attach a driver
  void attachdriver(T &d) const;

private:
  T *driver;
};

#endif