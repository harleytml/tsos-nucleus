//By Tsuki Superior
#include "generic/memory_nucleon.hpp"
#include "generic/nucleus_instance.hpp"

Memory::Memory(void) : current_heap_offset(0)
{
#ifdef __PERSONAL_COMPUTER__
  static PC_MEM_quark pc_mem_quark = PC_MEM_quark();
  attachquark(pc_mem_quark);
#endif
}

Memory::~Memory(void)
{
}

void *Memory::allocatememory(uint32_t len)
{
  uintptr_t memlocation = quark->getstartoffreemem() + current_heap_offset;
  current_heap_offset += len;
  return (void *)memlocation;
}

void Memory::freememory(void *mem)
{
  current_heap_offset -= sizeof(&mem);
}
