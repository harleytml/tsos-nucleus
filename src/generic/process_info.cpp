//By Tsuki Superior
#include <generic/process_info.hpp>

Process_info::Process_info(void)
{
  state = HALTED;
  first_memory_block = nullptr;
}

Process_info::Process_info(uint8_t p, process_state s)
{
  state = s;
}