#include "elf.hpp"

ELF_driver::ELF_driver(void)
{
    name = "Executable and Linkable Format";
}

bool ELF_driver::detectsystem(void)
{
    return isvalidexecutable("/nucleus");
}

bool ELF_driver::isvalidexecutable(char *path)
{
    return true;
}