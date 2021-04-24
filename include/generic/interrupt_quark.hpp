/* By Tsuki Superior
 * Abstract Interrupt Quark
 * 
 * To make a new Interrupt quark, simply have it inherit from this class
 * 
 */

#pragma once

#include <generic/quark.hpp>
#include <generic/types.hpp>

class Interrupt_quark : public Quark
{
public:
  //Constructor
  Interrupt_quark(void);

  //Destructor
  ~Interrupt_quark();

  void registerinterrupt(func_ptr func, uint16_t id);
};