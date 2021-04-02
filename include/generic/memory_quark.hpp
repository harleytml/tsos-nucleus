/* By Tsuki Superior
 * Abstract Memory Quark
 * 
 * To make a new Memory quark, simply have it inherit from this class
 * 
 */

#ifndef __TSOS_NUCLEUS_MEMORY_QUARK__
#define __TSOS_NUCLEUS_MEMORY_QUARK__

#include "generic/quark.hpp"
#include "generic/types.hpp"

class Memory_quark : public Quark
{
public:
  Memory_quark(void);

  ~Memory_quark();

  virtual uintptr_t getstartoffreemem(void) = 0;
};

#endif