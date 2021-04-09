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

#ifndef __TSOS_NUCLEUS_MEMORY_NUCLEON__
#define __TSOS_NUCLEUS_MEMORY_NUCLEON__

#include <generic/memory_quark.hpp>
#include <generic/memory_table_entry.hpp>
#include <generic/nucleon.hpp>
#include <generic/types.hpp>
#include <generic/current_config.hpp>

#define MEMORY_BLOCK_COUNT (128)
#define MEMORY_BLOCK_SIZE (128)

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
  uintptr_t current_heap_offset;
  Memory_table_entry memory_table[MEMORY_BLOCK_COUNT];
};

#endif
