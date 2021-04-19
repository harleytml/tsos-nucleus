// By Tsuki Superior
#pragma once

#include <generic/time_quark.hpp>

class CMOS_quark : public Time_quark
{
public:
  //Constructor
  CMOS_quark();

  //Destructor
  ~CMOS_quark();

  bool detectsystem(void) final;

  void reset() final;
};