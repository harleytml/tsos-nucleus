//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_PROCESS_MODULE__
#define __TSOS_NUCLEUS_PROCESS_MODULE__

#include "driver.hpp"
#include "module.hpp"
#include "types.hpp"
#include "process_driver.hpp"
#include "process_info.hpp"
#include "process_state.hpp"
#include "current_config.hpp"

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
