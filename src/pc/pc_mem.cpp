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

uintptr_t PC_MEM_quark::getstartoffreemem(void)
{
  extern uintptr_t _kernelend;
  return _kernelend;
}
