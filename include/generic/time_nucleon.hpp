/* By Tsuki Superior
 * Time Nucleon
 * 
 * The wrapper nucleon for the time quarks
 */

#pragma once

#include <generic/current_config.hpp>
#include <generic/nucleon.hpp>
#include <generic/quark.hpp>
#include <generic/time_quark.hpp>
#include <generic/types.hpp>

//The main class controlling Time
class Time : public Nucleon<Time_quark> {
public:
    // Constructor
    Time(void);

    // Destructor
    ~Time();

    // Get the current time stamp
    uint64_t gettimestamp(void);
};
