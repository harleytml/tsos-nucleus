//By Tsuki Superior
#pragma once

#include <generic/boot_quark.hpp>

class RPI3_BOOT_quark : public Boot_quark {
public:
    // Constructor
    RPI3_BOOT_quark(void);

    // Destructor
    ~RPI3_BOOT_quark();

    // Detect the type of system its running on
    bool detectsystem(void) final;

    void reset(void) final;

    // Reboot the system
    void reboot(void) final;

    // Shutdown the system
    void shutdown(void) final;
};
