/* By Tsuki Superior
 * Generic Interrupt Nucleon
 *
 * This nucleon, like the other nucleons, acts as a wrapper to call the quarks
 * It has one more function, known as the fission, which is like the BSOD of
 * Windows, or the Kernel Panic of the *nix operating systems
 */

#pragma once

#include <generic/quark.hpp>
#include <generic/nucleon.hpp>
#include <generic/types.hpp>
#include <generic/interrupt_quark.hpp>
#include <generic/current_config.hpp>

// The main class controlling the system runtime
class Interrupt : public Nucleon<Interrupt_quark>
{
public:
  // Constructor
  Interrupt(void);

  // Constructor
  ~Interrupt();

  void registerinterrupt(func_ptr func, uint16_t id);
};