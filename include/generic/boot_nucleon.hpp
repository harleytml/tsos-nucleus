/* By Tsuki Superior
 * Generic Boot Nucleon
 *
 * This nucleon, like the other nucleons, acts as a wrapper to call the quarks
 * It has one more function, known as the fission, which is like the BSOD of
 * Windows, or the Kernel Panic of the *nix operating systems
 */

#pragma once

#include <generic/boot_quark.hpp>
#include <generic/current_config.hpp>
#include <generic/nucleon.hpp>
#include <generic/quark.hpp>
#include <generic/types.hpp>

// The main class controlling the system runtime
class Boot : public Nucleon<Boot_quark> {
public:
    // Constructor
    Boot(void);

    // Constructor
    ~Boot();

    // Reboot the system
    void reboot(void) const;

    // Shutdown the system
    void shutdown(void) const;

    // The equivelent kernel panic, or bsod,
    void fission(const char* errormsg) const;
};
