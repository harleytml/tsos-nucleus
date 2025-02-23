//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_PROCESS_INFO__
#define __TSOS_NUCLEUS_PROCESS_INFO__

#include "generic/types.hpp"
#include "generic/process_state.hpp"

// The class holding the information of a process
class Process_info
{
public:
  Process_info(void);

  // Constructor
  Process_info(uint8_t p, process_state s);

protected:
  // The PID of a process
  uint8_t pid;

  // The state of a process
  process_state state;
};

#endif
