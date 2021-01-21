//By Tsuki Superior
#ifndef __TSOS_ELF_DRIVER__
#define __TSOS_ELF_DRIVER__

#include "process.hpp"

class ELF_driver : public Process_driver
{
public:
  ELF_driver(void);
  bool detectsystem(void);
  bool isvalidexecutable(char *path);
  machine_type machine = GENERIC;
};

#endif