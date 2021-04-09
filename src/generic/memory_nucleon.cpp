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
  uintptr_t start_address = quark->getstartofheap();
  uintptr_t possible_address = start_address;

  uint32_t ispossiblecount = 0;
  size_t maxlength = quark->getlengthofheap();

  // I am not even going to check for a block bigger than the free memory
  if (len > maxlength)
  {
    return nullptr;
  }
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
      if (possible_address > (start_address + maxlength))
      {
        return nullptr;
      }
    }
    possible_address++;
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
