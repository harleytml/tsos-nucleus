/* By Tsuki Superior
 * PC Memory Quark
 *
 */

#ifndef __TSOS_PC_MEM_QUARK__
#define __TSOS_PC_MEM_QUARK__

#include <generic/memory_quark.hpp>
#include <generic/filesystem_file.hpp>

class PC_MEM_quark : public Memory_quark
{
public:
  PC_MEM_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  uintptr_t getstartoffreemem(void) final;
};

#endif