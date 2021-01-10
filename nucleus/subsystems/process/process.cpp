//By Tsuki Superior
#include "process.hpp"

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
