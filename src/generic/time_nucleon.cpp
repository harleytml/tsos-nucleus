// By Tsuki Superior
#include <generic/nucleus_instance.hpp>
#include <generic/time_nucleon.hpp>

Time::Time(void)
{

#ifdef __PERSONAL_COMPUTER__

    static CMOS_quark cmos_quark;

    attachquark(cmos_quark);

#endif

#ifdef __RASPBERRY_PI_3__

    static RPI3_TIME_quark rpi3_time_quark;

    attachquark(rpi3_time_quark);

#endif
}

Time::~Time(void) { }

uint64_t Time::gettimestamp(void) { return quark->gettimestamp(); }
