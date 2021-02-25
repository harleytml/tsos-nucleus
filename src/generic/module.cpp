//By Tsuki Superior
#include "module.hpp"

template <class T>
Module<T>::Module(void) : name("")
{
}

template <class T>
Module<T>::~Module(void)
{
}

template <class T>
void Module<T>::attachdriver(const T &d)
{

    // The driver has to be for the right machine and run on that machine's configuration
    if (driver->detectsystem())
    {
        driver = &d;
    }
}