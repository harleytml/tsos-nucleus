//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_FILESYSTEM_DRIVER__
#define __TSOS_NUCLEUS_FILESYSTEM_DRIVER__

#include "../../core/driver.hpp"
#include "../../core/types.hpp"

class Filesystem_driver : public Driver
{
public:
    //Constructor
    Filesystem_driver(void);

    //Destructor
    ~Filesystem_driver();

    //Read the directory
    virtual char **readdir(char *path) = 0;

    //Rename a target
    virtual void rename(char *path, char *newPath) = 0;

    //Make sure a file actually exists
    virtual bool exists(char *path) = 0;
};

#endif