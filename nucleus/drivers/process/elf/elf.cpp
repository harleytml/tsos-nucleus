#include "./elf.hpp"

ELF_driver::ELF_driver(void)
{
    name = "Executable and Linkable Format";
}

bool ELF_driver::detectsystem(void)
{
    return isvalidexecutable();
}

bool ELF_driver::isvalidexecutable(char *path)
{
    File elffile = tsos.filesystem.open("/kernel.tse");
}