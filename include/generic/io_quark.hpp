/* By Tsuki Superior
 * Abstract IO quark
 * 
 * To make a new IO quark, simply have it inherit from this class
 */

#ifndef __TSOS_NUCLEUS_IO_QUARK__
#define __TSOS_NUCLEUS_IO_QUARK__

#include <generic/quark.hpp>
#include <generic/types.hpp>

class IO_quark : public Quark
{
public:
  // Constructor
  IO_quark(void);

  //Default constructor
  ~IO_quark();

  // Get a uint8_t from the io ports
  virtual uint8_t in8(uint16_t port) = 0;

  // Send a uint8_t through the io ports
  virtual void out8(uint16_t port, uint8_t value) = 0;

  // Get a uint16_t from the io ports
  virtual uint16_t in16(uint16_t port) = 0;

  // Send a uint16_t through the io ports
  virtual void out16(uint16_t port, uint16_t value) = 0;

  // Get a uint32_t from the io ports
  virtual uint32_t in32(uint16_t port) = 0;

  // Send a uint32_t through the io ports
  virtual void out32(uint16_t port, uint32_t value) = 0;
};

#endif