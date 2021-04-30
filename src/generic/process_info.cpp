// By Tsuki Superior
#include <generic/process_info.hpp>

Process_info::Process_info(void) { state = HALTED; }

Process_info::Process_info(uint8_t p, process_state s) { state = s; }