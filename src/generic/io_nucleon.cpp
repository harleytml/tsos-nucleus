//By Tsuki Superior
#include <generic/io_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

IO::IO(void)
{
#ifdef __PERSONAL_COMPUTER__
  static PC_IO_quark pc_io_quark = PC_IO_quark();
  if (attachquark(pc_io_quark))
  {
  }
#endif

#ifdef __RASPBERRY_PI_3__
  static RPI3_IO_quark rpi3_io_quark = RPI3_IO_quark();
  if (attachquark(rpi3_io_quark))
  {
  }
#endif
}

IO::~IO()
{
}

void IO::reset(void) const
{
  quark->reset();
}

// Get a uint8_t from the io ports
uint8_t IO::in8(size_t port)
{
  return quark->in8(port);
}

// Send a uint8_t through the io ports
void IO::out8(size_t port, uint8_t value)
{
  quark->out8(port, value);
}

// Get a uint16_t from the io ports
uint8_t IO::in16(size_t port)
{
  return quark->in16(port);
}

// Send a uint16_t through the io ports
void IO::out16(size_t port, uint16_t value)
{
  quark->out16(port, value);
}

// Get a uint32_t from the io ports
uint8_t IO::in32(size_t port)
{
  return quark->in32(port);
}

// Send a uint32_t through the io ports
void IO::out32(size_t port, uint32_t value)
{
  quark->out32(port, value);
}