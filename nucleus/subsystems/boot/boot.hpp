//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_BOOT__
#define __TSOS_NUCLEUS_BOOT__

#include "core.hpp"

//The main class controlling the system runtime
class Boot : public Module
{
public:
  //Constructor
  Boot(void);

  //Constructor
  ~Boot(void);

  //Reboot the system
  void reboot(void);

  //Shutdown the system
  void shutdown(void);

  //The equivelant kernel panic, or bsod,
  void fission(char *errormsg);

private:
  //The boot driver being used
  Boot_driver *driver;
};

class Boot_driver : public Driver
{
public:
  //Constructor
  Boot_driver(void);

  //Destructor
  ~Boot_driver(void);

  //Reboot the system
  virtual void reboot(void){};

  //Shutdown system
  virtual void shutdown(void){};
};

#endif