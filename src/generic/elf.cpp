// By Tsuki Superior
#include <generic/elf.hpp>
#include <generic/nucleus_instance.hpp>

ELF_quark::ELF_quark(void)
{
  name = "Executable and Linkable Format";
}

bool ELF_quark::detectsystem(void)
{
  return true;
  return isvalidexecutable("/nucleus");
}

void ELF_quark::reset(void)
{
}

bool ELF_quark::isvalidexecutable(char *path)
{
  uint8_t signature_length = 4;
  File file = tsos->filesystem.open(path);
  uint8_t *exec = tsos->filesystem.read(file, signature_length);
  return memcmp(exec, ELFMAG, signature_length) == 0;
}
