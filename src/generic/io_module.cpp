//By Tsuki Superior
#include "generic/io_module.hpp"
#include "generic/nucleus_instance.hpp"

IO::IO(void)
{
#ifdef __PERSONAL_COMPUTER__
  static PC_IO_driver pc_io_driver = PC_IO_driver();
  if (attachdriver(pc_io_driver))
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
  driver->reset();
}

// Get a uint8_t from the io ports
uint8_t IO::get8(uint16_t port)
{
  return driver->get8(port);
}

// Send a uint8_t through the io ports
void IO::put8(uint16_t port, uint8_t value)
{
  driver->put8(port, value);
}

// Get a uint16_t from the io ports
uint8_t IO::get16(uint16_t port)
{
  return driver->get16(port);
}

// Send a uint16_t through the io ports
void IO::put16(uint16_t port, uint16_t value)
{
  driver->put16(port, value);
}

// Get a uint32_t from the io ports
uint8_t IO::get32(uint16_t port)
{
  return driver->get32(port);
}

// Send a uint32_t through the io ports
void IO::put32(uint16_t port, uint32_t value)
{
  driver->put32(port, value);
}