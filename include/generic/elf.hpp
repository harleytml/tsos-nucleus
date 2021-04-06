/* By Tsuki Superior
 * Generic Elf Quark
 *
 * This is a quark for controlling system runtime, oriented
 * around the ELF format
 */

#ifndef __TSOS_ELF_QUARK__
#define __TSOS_ELF_QUARK__

#include <generic/process_quark.hpp>
#include <generic/filesystem_file.hpp>

class ELF_quark : public Process_quark
{
public:
  ELF_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  bool isvalidexecutable(char *path) final;
};

#endif