/* By Tsuki Superior
 * Abstract IO driver
 * 
 * To make a new IO driver, simply have it inherit from this class
 */

#ifndef __TSOS_NUCLEUS_IO_QUARK__
#define __TSOS_NUCLEUS_IO_QUARK__

#include "generic/driver.hpp"
#include "generic/types.hpp"

class IO_driver : public Driver
{
public:
  // Constructor
  IO_driver(void);

  //Default constructor
  ~IO_driver();

  // Get a uint8_t from the io ports
  virtual uint8_t get8(uint16_t port) = 0;

  // Send a uint8_t through the io ports
  virtual void put8(uint16_t port, uint8_t value) = 0;

  // Get a uint16_t from the io ports
  virtual uint16_t get16(uint16_t port) = 0;

  // Send a uint16_t through the io ports
  virtual void put16(uint16_t port, uint16_t value) = 0;

  // Get a uint32_t from the io ports
  virtual uint32_t get32(uint16_t port) = 0;

  // Send a uint32_t through the io ports
  virtual void put32(uint16_t port, uint32_t value) = 0;
};

#endif