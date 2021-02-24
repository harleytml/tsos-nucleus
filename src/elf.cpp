#include "elf.hpp"

ELF_driver::ELF_driver(void)
{
    name = "Executable and Linkable Format";
}

bool ELF_driver::detectsystem(void)
{
    return isvalidexecutable("/bin/nucleus.tse");
}

bool ELF_driver::isvalidexecutable(char *path)
{
    //Doesn't work right now
    /*
    File elffile = tsos.filesystem.open("/kernel.tse");
    */
   return true;
}