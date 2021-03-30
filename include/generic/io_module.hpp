//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_IO_MODULE__
#define __TSOS_NUCLEUS_IO_MODULE__

#include "driver.hpp"
#include "module.hpp"
#include "types.hpp"
#include "io_driver.hpp"
#include "current_config.hpp"

// The main class controlling video
class IO : public Module<IO_driver>
{
public:
  // Constructor
  IO(void);

  // Destructor
  ~IO();

  // Initialize the video system
  void reset(void) const;

  // Get a uint8_t from the io ports
  uint8_t get8(uint16_t port);

  // Send a uint8_t through the io ports
  void put8(uint16_t port, uint8_t value);

  // Get a uint16_t from the io ports
  uint8_t get16(uint16_t port);

  // Send a uint16_t through the io ports
  void put16(uint16_t port, uint16_t value);

  // Get a uint32_t from the io ports
  uint8_t get32(uint16_t port);

  // Send a uint32_t through the io ports
  void put32(uint16_t port, uint32_t value);
};

#endif
