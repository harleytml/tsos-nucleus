//By Tsuki Superior
#ifndef __TSOS_MODULE_CORE__
#define __TSOS_MODULE_CORE__

#include "./driver.hpp"
#include "./types.hpp"

// The base class of TS/OS modules
templete<class T> class Module
{
public:
  // Constructor
  Module<T>(void);

  // Destructor
  ~Module<T>();

  // The full name of the modules's target
  const char *name;

  // Attach a driver
  void attachdriver(T& d);

private:
  T* driver;
};

#endif