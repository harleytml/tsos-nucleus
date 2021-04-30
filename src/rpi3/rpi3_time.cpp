#include <generic/nucleus_instance.hpp>
#include <rpi3/rpi3_time.hpp>

RPI3_TIME_quark::RPI3_TIME_quark() { name = "Raspberry Pi 3 Time"; }

RPI3_TIME_quark::~RPI3_TIME_quark() { }

void RPI3_TIME_quark::reset() { }

bool RPI3_TIME_quark::detectsystem() { return true; }

uint64_t RPI3_TIME_quark::gettimestamp() { return 0; }