//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_PROCESS__
#define __TSOS_NUCLEUS_PROCESS__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"
#include "../../core/core.hpp"
#include "./process_driver.hpp"

#define PROCESS_COUNT 0xff

// The possible state of processes
enum process_state
{
  // A running process
  RUNNING,

  // A halted process
  HALTED,

  // A hung process
  HUNG,

  // An idle process
  IDLE
};

// The class holding the information of a process
class Process_info
{
public:
  // Constructor
  Process_info(uint8_t p, process_state s);

  // The PID of a process
  uint8_t pid;

  // The state of a process
  process_state state;
};

// The main classes to control processes
class Process : public Module<Process_driver>
{
public:
  // Constructor
  Process(void);

  // Destructor
  ~Process(void);

  // Spawn a process
  uint8_t spawn(char *path);

  // Kill a process
  void kill(uint8_t pid);

  // Kill all processes
  void killall(void);

  // Allocate memory
  uint8_t *allocatememory(uint32_t len);

private:
  // Process driver
  Process_driver *driver;

  // The table of processes
  Process_info processes[PROCESS_COUNT];
};

#endif
