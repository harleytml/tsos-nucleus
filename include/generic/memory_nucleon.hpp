/* By Tsuki Superior
 * Memory Nucleon
 * 
 * The wrapper nucleon for the memory quarks
 */

#ifndef __TSOS_NUCLEUS_MEMORY_NUCLEON__
#define __TSOS_NUCLEUS_MEMORY_NUCLEON__

#include <generic/memory_quark.hpp>
#include <generic/memory_table_entry.hpp>
#include <generic/nucleon.hpp>
#include <generic/types.hpp>
#include <generic/current_config.hpp>

#define MEMORY_BLOCK_COUNT 128
#define MEMORY_BLOCK_SIZE (4 * 1024)

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
