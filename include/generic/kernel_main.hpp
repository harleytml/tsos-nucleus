/* By Tsuki Superior
 * Kernel Main
 * 
 * This is the entry point for the TS/OS kernel
 */

#pragma once

#include <generic/nucleus_instance.hpp>

extern "C" {
char* itoa(int value, char* str, int base);
void kernel_main(void);
void debug_msg(const char* str);
}
