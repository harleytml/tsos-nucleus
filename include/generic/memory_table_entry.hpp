/* By Tsuki Superior
 * Memory Table Entry
 * 
 * The defination of the memory allocation table entry
 */

#ifndef __TSOS_NUCLEUS_MEMORY_TABLE_ENTRY__
#define __TSOS_NUCLEUS_MEMORY_TABLE_ENTRY__

#include <generic/types.hpp>

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
  bool isactive;
};

#endif