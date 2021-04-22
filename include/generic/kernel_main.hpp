/* By Tsuki Superior
 * Kernel Main
 * 
 * This is the entry point for the TS/OS kernel
 */

#pragma once

#include <generic/nucleus_instance.hpp>

extern "C"
{
#ifdef __i386__

  char *itoa(int value, char *str, int base);

#endif
  void kernel_main(void);
  void debug_msg(char *str);
}
