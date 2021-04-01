/* By Tsuki Superior
 * Abstract Serial Driver
 * 
 * To make a new Serial quark, simply have it inherit from this class
 * 
 * Not sure how useful serial is (other than debugging), but I'll write quarks for it anyway
 */

#ifndef __TSOS_NUCLEUS_SERIAL_QUARK__
#define __TSOS_NUCLEUS_SERIAL_QUARK__

#include "generic/quark.hpp"
#include "generic/types.hpp"

class Serial_quark : public Driver
{
public:
  // Constructor
  Serial_quark(void);

  ~Serial_quark();

  // Exchange a byte
  virtual uint8_t exchangebyte(uint8_t b) = 0;

  // Is device there
  virtual bool isdevicethere(void) = 0;
};

#endif
