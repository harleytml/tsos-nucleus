/* By Tsuki Superior
 * Abstract Memory Quark
 *
 * To make a new Memory quark, simply have it inherit from this class
 *
 */

#pragma once

#include <generic/quark.hpp>
#include <generic/types.hpp>

class Memory_quark : public Quark
{
  public:
    Memory_quark(void);

    ~Memory_quark();

    virtual uintptr_t getstartofheap(void) = 0;

    virtual size_t getlengthofheap(void) = 0;
};
