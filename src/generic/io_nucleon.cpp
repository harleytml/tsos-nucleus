//By Tsuki Superior
#include "generic/io_nucleon.hpp"
#include "generic/nucleus_instance.hpp"

IO::IO(void)
{
#ifdef __PERSONAL_COMPUTER__
  static PC_IO_quark pc_io_quark = PC_IO_quark();
  if (attachquark(pc_io_quark))
  {
  }
#endif

#ifdef __GAMEBOY_ADVANCED__

#endif

#ifdef __RASPBERRY_PI_3__

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
uint8_t IO::get8(uint16_t port)
{
  return quark->get8(port);
}

// Send a uint8_t through the io ports
void IO::put8(uint16_t port, uint8_t value)
{
  quark->put8(port, value);
}

// Get a uint16_t from the io ports
uint8_t IO::get16(uint16_t port)
{
  return quark->get16(port);
}

// Send a uint16_t through the io ports
void IO::put16(uint16_t port, uint16_t value)
{
  quark->put16(port, value);
}

// Get a uint32_t from the io ports
uint8_t IO::get32(uint16_t port)
{
  return quark->get32(port);
}

// Send a uint32_t through the io ports
void IO::put32(uint16_t port, uint32_t value)
{
  quark->put32(port, value);
}