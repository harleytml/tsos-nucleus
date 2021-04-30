/* By Tsuki Superior
 * Memory Nucleon
 *
 * The wrapper nucleon for the memory quarks
 *
 * The allocation stratagy is to keep a statically sized table,
 * and every entry represents a single allocated piece of memory
 * The OS looks for free memory in the table, and if it cannot find any
 * It simply just returns nullptr
 */

#pragma once

#include <generic/current_config.hpp>
#include <generic/memory_quark.hpp>
#include <generic/nucleon.hpp>
#include <generic/types.hpp>

#define MEMORY_BLOCK_COUNT (10)

class Memory : public Nucleon<Memory_quark>
{
  public:
    // Constructor
    Memory(void);

    // Destructor
    ~Memory();

    // Allocate memory
    void *allocatememory(uint32_t len);

    // Free Memory
    void freememory(void *mem);

  private:
    class Memory_table_entry
    {
      public:
        Memory_table_entry(void);
        ~Memory_table_entry();

        // The start of the memory segment
        uintptr_t memory_start;

        // Length of the memory block
        size_t block_length;

        // Check if the block is active
        bool is_active;
    };

    Memory_table_entry memory_table[MEMORY_BLOCK_COUNT];
};
