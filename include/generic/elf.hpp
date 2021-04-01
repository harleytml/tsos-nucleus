/* By Tsuki Superior
 * Generic Elf Driver
 *
 * This is a driver for controlling system runtime, oriented
 * around the ELF format
 */

#ifndef __TSOS_ELF_QUARK__
#define __TSOS_ELF_QUARK__

#include "generic/process_driver.hpp"
#include "generic/filesystem_file.hpp"

class ELF_driver : public Process_driver
{
public:
  ELF_driver(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isvalidexecutable(char *path) final;
  uintptr_t getstartoffreemem(void) final;
};

#endif