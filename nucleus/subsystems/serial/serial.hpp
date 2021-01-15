//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_SERIAL__
#define __TSOS_NUCLEUS_SERIAL__

#include "core.hpp"

//The main class controlling serial
class Serial : public Module
{
public:
  //Constructor
  Serial(void);

  //Destructor
  ~Serial(void);

  //Exchange a byte
  uint8_t exchangebyte(uint8_t b);

  //Is device there
  bool isdevicethere(void);

private:
  //Serial driver
  Serial_driver *driver;
};

class Serial_driver : public Driver
{
public:
  //Constructor
  Serial_driver(void);

  //Exchange a byte
  virtual uint8_t exchangebyte(uint8_t b){};

  //Is device there
  virtual bool isdevicethere(void){};
};

#endif