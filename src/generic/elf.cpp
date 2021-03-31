// By Tsuki Superior
#include "generic/elf.hpp"

ELF_driver::ELF_driver(void)
{
  name = "Executable and Linkable Format";
}

bool ELF_driver::detectsystem(void)
{
  return isvalidexecutable("/nucleus");
}

void ELF_driver::reset(void)
{
}

bool ELF_driver::isvalidexecutable(char *path)
{
  return true;
}

// This needs to give back the address to the first free memory location in the os, that can be used for a primitive heap
uintptr_t ELF_driver::getstartoffreemem(void)
{

#ifdef __PERSONAL_COMPUTER__
  extern uintptr_t _kernelend;
  return _kernelend;
#endif

#ifdef __GAMEBOY_ADVANCED__
  return 0x03000000;
#endif

#ifdef __NSPIRE__
  extern uintptr_t _kernelend;
  return _kernelend;
#endif

#ifdef __RASPBERRY_PI_3__
  extern uintptr_t _kernelend;
  return _kernelend;
#endif

#ifdef __NINTENDO_DUAL_SCREEN__

#endif
  return 0;
}
