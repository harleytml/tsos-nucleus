/* By Tsuki Superior
 * Process Nucleon
 * 
 * The wrapper nucleon for the process quarks
 */

#ifndef __TSOS_NUCLEUS_PROCESS_NUCLEON__
#define __TSOS_NUCLEUS_PROCESS_NUCLEON__

#include "generic/nucleon.hpp"
#include "generic/types.hpp"
#include "generic/process_quark.hpp"
#include "generic/process_info.hpp"
#include "generic/process_state.hpp"
#include "generic/current_config.hpp"

// The main classes to control processes
class Process : public Nucleon<Process_quark>
{
public:
  // Constructor
  Process(void);

  // Destructor
  ~Process();

  // Spawn a process
  uint8_t spawn(char *path);

  // Kill a process
  void kill(uint8_t pid);

  // Kill all processes
  void killall(void);

private:
  // The table of processes
  Process_info processes[16];
};

#endif
