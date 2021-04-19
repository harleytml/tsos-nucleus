//By Tsuki Superior
#include <generic/process_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

Process::Process(void)
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