//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_BOOT__
#define __TSOS_NUCLEUS_BOOT__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"

extern Tsos tsos;

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

// The main class controlling the system runtime
class Boot : public Module
{
public:
  // Constructor
  Boot(void);

  // Constructor
  ~Boot(void);

  // Reboot the system
  void reboot(void);

  // Shutdown the system
  void shutdown(void);

  // The equivelant kernel panic, or bsod,
  void fission(char *errormsg);

private:
  // The boot driver being used
  Boot_driver *driver;
};


#endif
