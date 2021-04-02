/* By Tsuki Superior
 * Memory Nucleon
 * 
 * The wrapper nucleon for the memory quarks
 */

#ifndef __TSOS_NUCLEUS_MEMORY_NUCLEON__
#define __TSOS_NUCLEUS_MEMORY_NUCLEON__

#include "generic/memory_quark.hpp"
#include "generic/nucleon.hpp"
#include "generic/types.hpp"
#include "generic/current_config.hpp"

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
};

#endif
