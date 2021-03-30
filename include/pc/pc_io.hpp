#ifndef __TSOS_NUCLEUS_PC_IO_DRIVER__
#define __TSOS_NUCLEUS_PC_IO_DRIVER__

#include "types.hpp"
#include "io_driver.hpp"

class PC_IO_driver : public IO_driver
{
public:
  PC_IO_driver(void);

  ~PC_IO_driver();

  bool detectsystem(void) override;

  void reset(void) override;

  // Get a uint8_t from the io ports
  uint8_t get8(uint16_t port) override;

  // Send a uint8_t through the io ports
  void put8(uint16_t port, uint8_t value) override;

  // Get a uint16_t from the io ports
  uint16_t get16(uint16_t port) override;

  // Send a uint16_t through the io ports
  void put16(uint16_t port, uint16_t value) override;

  // Get a uint32_t from the io ports
  uint32_t get32(uint16_t port) override;

  // Send a uint32_t through the io ports
  void put32(uint16_t port, uint32_t value) override;
};

#endif
