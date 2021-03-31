//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_PROCESS_MODULE__
#define __TSOS_NUCLEUS_PROCESS_MODULE__

#include "generic/driver.hpp"
#include "generic/module.hpp"
#include "generic/types.hpp"
#include "generic/process_driver.hpp"
#include "generic/process_info.hpp"
#include "generic/process_state.hpp"
#include "generic/current_config.hpp"

// The main classes to control processes
class Process : public Module<Process_driver>
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

  // Allocate memory
  void *allocatememory(uint32_t len);

  // Free Memory
  void freememory(void *mem);

  // The table of processes
  Process_info processes[16];

private:
  uintptr_t current_heap_offset;
};

#endif
