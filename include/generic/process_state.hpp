// By Tsuki Superior
#pragma once

#include <generic/types.hpp>

// The possible state of processes
enum process_state
{
    // A running process
    RUNNING,

    // A halted process
    HALTED,

    // A hung process
    HUNG,

    // An idle process
    IDLE
};
