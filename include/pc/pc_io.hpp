#ifndef __TSOS_NUCLEUS_PC_IO_QUARK__
#define __TSOS_NUCLEUS_PC_IO_QUARK__

#include "generic/types.hpp"
#include "generic/io_quark.hpp"

class PC_IO_quark : public IO_quark
{
public:
  PC_IO_quark(void);

  ~PC_IO_quark();

  bool detectsystem(void) final;

  void reset(void) final;

  // Get a uint8_t from the io ports
  uint8_t in8(uint16_t port) final;

  // Send a uint8_t through the io ports
  void out8(uint16_t port, uint8_t value) final;

  // Get a uint16_t from the io ports
  uint16_t in16(uint16_t port) final;

  // Send a uint16_t through the io ports
  void out16(uint16_t port, uint16_t value) final;

  // Get a uint32_t from the io ports
  uint32_t in32(uint16_t port) final;

  // Send a uint32_t through the io ports
  void out32(uint16_t port, uint32_t value) final;
};

#endif
