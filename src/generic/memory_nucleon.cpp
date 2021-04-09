//By Tsuki Superior
#include <generic/memory_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

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
  Memory_table_entry *possible_entry = nullptr;
  uintptr_t possible_address = LINKER_kernel_heap;
  uint32_t ispossiblecount = 0;
  for (uint32_t x = 0; x < MEMORY_BLOCK_COUNT; x++)
  {
    if (!memory_table[x].isactive)
    {
      possible_entry = &memory_table[x];
      possible_address = possible_entry->memory_start;
      break;
    }
  }
  if (possible_entry == nullptr)
  {
    // A free entry was not found
    return nullptr;
  }
  while (ispossiblecount < MEMORY_BLOCK_COUNT)
  {
    for (uint32_t x = 0; x < MEMORY_BLOCK_COUNT; x++)
    {
    }
  }

  // This should never make it here, but if it does, return nullptr
  return nullptr;
}

void Memory::freememory(void *mem)
{
  for (uint32_t x = 0; x < MEMORY_BLOCK_COUNT; x++)
  {
    if (memory_table[x].memory_start == (uintptr_t)mem && memory_table->isactive)
    {
      memory_table->isactive = false;
    }
  }
}
