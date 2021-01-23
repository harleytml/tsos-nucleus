//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_PROCESS__
#define __TSOS_NUCLEUS_PROCESS__

#include "core.hpp"

#define PROCESS_COUNT 0xff

// The main classes to control processes
class Process : public Module
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

class Process_driver : public Driver
{
public:
  virtual bool isvalidexecutable(char *path) = NULL;
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

#endif
