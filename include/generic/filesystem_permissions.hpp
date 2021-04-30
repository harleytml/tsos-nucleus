/* By Tsuki Superior
 * Generic Filesystem permissions
 * 
 * The permissions class is how the nucleus represents the 
 * file permissions internally
 */

#pragma once

#include <generic/quark.hpp>
#include <generic/types.hpp>

class Permissions {
public:
    Permissions();

    //Constructor
    Permissions(bool r, bool w, bool e);

    //Read permission
    bool read;

    //Write permission
    bool write;

    //Execute permission
    bool execute;
};
