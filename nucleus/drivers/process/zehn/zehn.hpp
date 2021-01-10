//By Tsuki Superior
#ifndef __TSOS_ZEHN_DRIVER__
#define __TSOS_ZEHN_DRIVER__

#include "process.hpp"

class ZEHN_driver: public Process_driver
{
 public:
  ZEHN_driver(void);
  BOOLEAN detectsystem(void);
  BOOLEAN isvalidexecutable(char * path);
  machine_type machine=GENERIC;
};

#endif