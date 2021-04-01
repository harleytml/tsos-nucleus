//By Tsuki Superior
#include "generic/process_nucleon.hpp"
#include "generic/nucleus_instance.hpp"

Process::Process(void) : current_heap_offset(0)
{
  static ELF_quark elf_quark = ELF_quark();

  attachquark(elf_quark);
}

Process::~Process(void)
{
  killall();
}

uint8_t Process::spawn(char *path)
{
  return 0;
}

void Process::kill(uint8_t pid)
{
}

void Process::killall(void)
{
}

void *Process::allocatememory(uint32_t len)
{
  uintptr_t memlocation = quark->getstartoffreemem() + current_heap_offset;
  current_heap_offset += len;
  return (void *)memlocation;
}

void Process::freememory(void *mem)
{
  current_heap_offset -= sizeof(&mem);
}
