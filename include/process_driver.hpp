//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_PROCESS_DRIVER__
#define __TSOS_NUCLEUS_PROCESS_DRIVER__

#include "driver.hpp"
#include "types.hpp"

class Process_driver : public Driver
{
public:
    Process_driver(void);

    ~Process_driver();

    virtual bool isvalidexecutable(char *path) = 0;
};

#endif