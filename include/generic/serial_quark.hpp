/* By Tsuki Superior
 * Abstract Serial Quark
 * 
 * To make a new Serial quark, simply have it inherit from this class
 * 
 * Not sure how useful serial is (other than debugging), but I'll write quarks for it anyway
 */

#ifndef __TSOS_NUCLEUS_SERIAL_QUARK__
#define __TSOS_NUCLEUS_SERIAL_QUARK__

#include <generic/quark.hpp>
#include <generic/types.hpp>

class Serial_quark : public Quark
{
public:
  // Constructor
  Serial_quark(void);

  ~Serial_quark();

  // Is device there
  virtual bool isdevicereadytotransmit(void) = 0;

  // Is device there
  virtual bool isdevicereadytoreceive(void) = 0;

  // Send a byte
  virtual void inbyte(uint8_t byte) = 0;

  // Send a byte
  virtual uint8_t outbyte(void) = 0;
};

#endif
