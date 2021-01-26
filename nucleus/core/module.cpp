#include "./module.hpp"

Module::Module(void)
{
}

Module::~Module(void)
{
    delete[] name;
}

templete<class T> void Module::attachdriver(T d) const
{

    // The driver has to be for the right machine and run on that machine's configuration
    if (driver->detectsystem())
    {
        driver = &d;
    }
    else
    {

        // Preventing overfill of the heap
        delete &d;
    }
}