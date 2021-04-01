/* By Tsuki Superior
 * Gameboy Advanced IO Port Driver 
 *
 * The driver for the GBA's io port
 * The GBA has a simple serial port that is usually used for transmitting game 
 * data.
 */

#ifndef __TSOS_GBA_IO_PORT_QUARK__
#define __TSOS_GBA_IO_PORT_QUARK__

#include "generic/serial_driver.hpp"

class GBA_IO_PORT_driver : public Serial_driver
{
public:
  GBA_IO_PORT_driver(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isdevicethere(void) final;
  uint8_t exchangebyte(uint8_t b) final;
};

#endif
