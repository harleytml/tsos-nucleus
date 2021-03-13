//By Tsuki Superior
#include "process_module.hpp"

Process::Process(void)
{
    static ELF_driver elf_driver = ELF_driver();

    if (attachdriver(elf_driver))
    {
        return;
    }
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
}

void Process::freememory(void *mem)
{
}
