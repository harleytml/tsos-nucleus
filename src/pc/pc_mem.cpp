// By Tsuki Superior
#include <pc/pc_mem.hpp>

PC_MEM_quark::PC_MEM_quark(void)
{
  name = "Personal Computer Memory";
}

bool PC_MEM_quark::detectsystem(void)
{
  return (bool)(__pentiumpro__);
}

void PC_MEM_quark::reset(void)
{
}

uintptr_t PC_MEM_quark::getstartofheap(void)
{
  return LINKER_kernel_heap;
}

size_t PC_MEM_quark::getlengthofheap(void)
{
  return 1024 * 4;
}
