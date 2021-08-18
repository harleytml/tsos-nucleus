/* By Tsuki Superior
 * Abstract Quark
 *
 * This is the abstract class that all the subclasses of
 * quarks inherit from.
 *
 */

#pragma once

#include <generic/types.hpp>

// The class for quarks
class Quark
{
  public:
    // Constructor
    Quark(void);

    // Destructor
    ~Quark();

    // A function called to determine if a quark should be used.
    virtual bool detectsystem(void) = 0;

    virtual void reset(void) = 0;

    // The name of said quark
    char *name;
};
