/* By Tsuki Superior
 * Serial Nucleon
 * 
 * The wrapper nucleon for the serial quarks
 */

#ifndef __TSOS_NUCLEUS_SERIAL_NUCLEON__
#define __TSOS_NUCLEUS_SERIAL_NUCLEON__

#include "generic/quark.hpp"
#include "generic/nucleon.hpp"
#include "generic/types.hpp"
#include "generic/serial_quark.hpp"
#include "generic/current_config.hpp"
#include "generic/array.hpp"

// The main class controlling serial
class Serial : public Nucleon<Serial_quark>
{
public:
  // Constructor
  Serial(void);

  // Destructor
  ~Serial();

  void reset(void);

  // Send a byte
  void sendbyte(uint8_t byte) const;

  // Get a byte
  uint8_t getbyte(void) const;

  // Is device ready to take a byte
  bool isdevicereadytoreceive(void) const;

  // Is device ready to send a byte
  bool isdevicereadytotransmit(void) const;

  // Send a array of bytes
  void sendbytearray(Array<uint8_t> array) const;
};

#endif
