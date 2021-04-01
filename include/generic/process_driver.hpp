/* By Tsuki Superior
 * Abstract Process Driver
 * 
 * To make a new Process driver, simply have it inherit from this class
 * 
 * This driver class will most likely only have elf inherit from it
 * The only other class would be COFF or maybe some windows format
 */

#ifndef __TSOS_NUCLEUS_PROCESS_DRIVER__
#define __TSOS_NUCLEUS_PROCESS_DRIVER__

#include "generic/driver.hpp"
#include "generic/types.hpp"

class Process_driver : public Driver
{
public:
  Process_driver(void);

  ~Process_driver();

  virtual bool isvalidexecutable(char *path) = 0;

  virtual uintptr_t getstartoffreemem(void) = 0;
};

#endif