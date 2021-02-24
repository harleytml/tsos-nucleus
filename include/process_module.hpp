//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_PROCESS_MODULE__
#define __TSOS_NUCLEUS_PROCESS_MODULE__

 #include "driver.hpp" 
 #include "module.hpp"
 #include "types.hpp"
#include "process_driver.hpp"
#include "process_info.hpp"
#include "process_state.hpp"

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

private:
  // Process driver
  Process_driver *driver;

  // The table of processes
  Process_info processes[255];
};

#endif
