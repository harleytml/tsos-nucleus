/* By Tsuki Superior
 * PC Memory Quark
 *
 */

#pragma once

#include <generic/filesystem_file.hpp>
#include <generic/memory_quark.hpp>

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
