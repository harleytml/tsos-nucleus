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

// The main class controlling serial
class Serial : public Nucleon<Serial_quark>
{
public:
  // Constructor
  Serial(void);

  // Destructor
  ~Serial();

  // Send a byte
  void sendbyte(uint8_t byte);

  // Get a byte
  uint8_t getbyte(void);

  // Is device ready to take a byte
  bool isdevicereadytoreceive(void);

  // Is device ready to send a byte
  bool isdevicereadytotransmit(void);
};

#endif
