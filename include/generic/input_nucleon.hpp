/* By Tsuki Superior
 * Input Nucleon
 * 
 * The wrapper nucleon for the input quarks
 */

#ifndef __TSOS_NUCLEUS_INPUT_NUCLEON__
#define __TSOS_NUCLEUS_INPUT_NUCLEON__

#include "generic/quark.hpp"
#include "generic/nucleon.hpp"
#include "generic/types.hpp"
#include "generic/input_quark.hpp"
#include "generic/input_key_identifier.hpp"
#include "generic/current_config.hpp"

// The main class controlling input
class Input : public Nucleon<Input_quark>
{
public:
  // Constructor
  Input(void);

  // Destructor
  ~Input();

  // Get the key pressed
  key_identifier getkey(void);

  // Wait for a key to be pressed
  void waitkey(void);
};

enum key_position
{
  RIGHT,
  LEFT,
  MIDDLE
};

#endif
