// By Tsuki Superior
#include "generic/elf.hpp"

ELF_quark::ELF_quark(void)
{
  name = "Executable and Linkable Format";
}

bool ELF_quark::detectsystem(void)
{
  return isvalidexecutable("/nucleus");
}

void ELF_quark::reset(void)
{
}

bool ELF_quark::isvalidexecutable(char *path)
{
  return true;
}
