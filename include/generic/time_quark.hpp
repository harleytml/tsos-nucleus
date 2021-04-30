/* By Tsuki Superior
 * Abstract Time Quark
 *
 * To make a new Time quark, simply have it inherit from this class
 *
 * The TS/OS Time api is pretty slim right now (as of version 0.0)
 */

#pragma once

#include <generic/quark.hpp>
#include <generic/types.hpp>

class Time_quark : public Quark
{
  public:
    // Constructor
    Time_quark(void);

    ~Time_quark();

    // Get the current time in seconds
    virtual uint64_t gettimestamp(void) = 0;
};
