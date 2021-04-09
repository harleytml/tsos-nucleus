/* By Tsuki Superior
 * PC Memory Quark
 *
 */

#ifndef __TSOS_PC_MEM_QUARK__
#define __TSOS_PC_MEM_QUARK__

#include <generic/memory_quark.hpp>
#include <generic/filesystem_file.hpp>

extern uintptr_t LINKER_kernel_heap;

class PC_MEM_quark : public Memory_quark
{
public:
  PC_MEM_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  uintptr_t getstartofheap(void) final;
  size_t getlengthofheap(void) final;
};

#endif