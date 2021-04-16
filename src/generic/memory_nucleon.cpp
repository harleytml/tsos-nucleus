//By Tsuki Superior
#include <generic/memory_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

Memory::Memory(void)
{
#ifdef __PERSONAL_COMPUTER__
  static PC_MEM_quark pc_mem_quark = PC_MEM_quark();
  attachquark(pc_mem_quark);
#endif
}

Memory::~Memory(void)
{
}

// This memory allocation function is sketchy, but its sorta working
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

  while (is_possible_to_allocate_count <= MEMORY_BLOCK_COUNT)
  {
    is_possible_to_allocate_count = 0;
    for (uint32_t x = 0; x < MEMORY_BLOCK_COUNT; x++)
    {
      if (&memory_table[x] != possible_entry)
      {

        // Address is now outside the heap
        if (possible_address > (start_address + max_length))
        {
          return nullptr;
        }

        // We only need to check the addresses if the memory location is active
        if (memory_table->is_active)
        {

          // Make sure the memory blocks are not conflicting
          if ((possible_address <= memory_table[x].memory_start + memory_table[x].block_length) && (memory_table[x].memory_start <= possible_address + len))
          {
            is_possible_to_allocate_count++;
          }
          else
          {
            // The check failed, and there is a conflict in memory
            possible_address = 0;
            is_possible_to_allocate_count = 0;
          }
        }
        else
        {

          // The check passed, so we may continues
          is_possible_to_allocate_count++;
        }
      }
    }

    // Jump forward
    possible_address++;
  }
  possible_entry->block_length = len;
  possible_entry->is_active = true;
  possible_entry->memory_start = possible_address;
  return (void *)possible_address;
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

Memory::Memory_table_entry::Memory_table_entry() : memory_start((uintptr_t) nullptr), block_length(0), is_active(false)
{
}

Memory::Memory_table_entry::~Memory_table_entry()
{
}
