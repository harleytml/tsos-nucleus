/* By Tsuki Superior
 * Gameboy Advanced IO Port Quark 
 *
 * The quark for the GBA's io port
 * The GBA has a simple serial port that is usually used for transmitting game 
 * data.
 */

#ifndef __TSOS_GBA_IO_PORT_QUARK__
#define __TSOS_GBA_IO_PORT_QUARK__

#include "generic/serial_quark.hpp"

class GBA_IO_PORT_quark : public Serial_quark
{
public:
  GBA_IO_PORT_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isdevicethere(void) final;
  uint8_t exchangebyte(uint8_t b) final;
};

#endif
