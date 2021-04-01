/* By Tsuki Superior
 * Abstract Serial Driver
 * 
 * To make a new Serial driver, simply have it inherit from this class
 * 
 * Not sure how useful serial is (other than debugging), but I'll write drivers for it anyway
 */

#ifndef __TSOS_NUCLEUS_SERIAL_DRIVER__
#define __TSOS_NUCLEUS_SERIAL_DRIVER__

#include "generic/driver.hpp"
#include "generic/types.hpp"

class Serial_driver : public Driver
{
public:
  // Constructor
  Serial_driver(void);

  ~Serial_driver();

  // Exchange a byte
  virtual uint8_t exchangebyte(uint8_t b) = 0;

  // Is device there
  virtual bool isdevicethere(void) = 0;
};

#endif
