/* By Tsuki Superior
 * Abstract Boot Quark
 *
 * To make a new Boot quark, simply have it inherit from this class
 */

#pragma once

#include <generic/quark.hpp>

class Boot_quark : public Quark
{
  public:
    // Constructor
    Boot_quark(void);

    // Destructor
    ~Boot_quark();

    // Reboot the system
    virtual void reboot(void) = 0;

    // Shutdown the system
    virtual void shutdown(void) = 0;
};
