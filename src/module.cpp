//By Tsuki Superior
#include "module.hpp"

template <class T>
Module<T>::Module(void) : name("")
{
}

template <class T>
Module<T>::~Module(void)
{
    delete[] name;
}

template <class T>
void Module<T>::attachdriver(T &d) const
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