//By Tsuki Superior
#include "./process_module.hpp"

Process::Process(void)
{
}

Process::~Process(void)
{
    killall();
}

uint8_t Process::spawn(char *path)
{
}

void Process::kill(uint8_t pid)
{
}

void Process::killall(void)
{
}

uint8_t *Process::allocatememory(uint32_t len)
{
}
