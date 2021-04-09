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
  // The memory table entry for the table
  Memory_table_entry *possible_entry = nullptr;

  // The start address of the heap
  uintptr_t start_address = quark->getstartofheap();

  // The possible address for the memory address
  uintptr_t possible_address = start_address;

  // A counter to make sure the new allocated space is not conflicting with the other entries
  uint32_t is_possible_to_allocate_count = 0;

  // The size of the heap
  size_t max_length = quark->getlengthofheap();

  uintptr_t end_address = start_address + max_length;

  // I am not even going to check for a block bigger than the free memory
  if (len > max_length)
  {
    return nullptr;
  }

  // Find a free point
  for (uint32_t x = 0; x < MEMORY_BLOCK_COUNT; x++)
  {
    if (!memory_table[x].is_active)
    {
      possible_entry = &memory_table[x];
      break;
    }
  }

  // Make sure a entry was actually found
  if (possible_entry == nullptr)
  {
    // A free entry was not found
    return nullptr;
  }

  while (is_possible_to_allocate_count < MEMORY_BLOCK_COUNT)
  {
    for (uint32_t x = 0; x < MEMORY_BLOCK_COUNT; x++)
    {
      if (possible_address > (start_address + max_length))
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
    if (memory_table[x].memory_start == (uintptr_t)mem && memory_table->is_active)
    {
      memory_table->is_active = false;
    }
  }
}
