//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_PROCESS_STATE__
#define __TSOS_NUCLEUS_PROCESS_STATE__

#include "../../core/types.hpp"

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

#endif
