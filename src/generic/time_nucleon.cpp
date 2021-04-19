//By Tsuki Superior
#include <generic/time_nucleon.hpp>
#include <generic/nucleus_instance.hpp>

Time::Time(void)
{

#ifdef __PERSONAL_COMPUTER__

  static CMOS_quark cmos_quark = CMOS_quark();
  attachquark(cmos_quark);
#endif
}

Time::~Time(void)
{
}