//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_PROCESS_DRIVER__
#define __TSOS_NUCLEUS_PROCESS_DRIVER__

#include "../../core/driver.hpp"
#include "../../core/types.hpp"

class Process_driver : public Driver
{
public:
    virtual bool isvalidexecutable(char *path) = 0;
};

#endif