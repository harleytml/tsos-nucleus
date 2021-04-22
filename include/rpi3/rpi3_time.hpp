// By Tsuki Superior
#pragma once

#include <generic/time_quark.hpp>

class RPI3_TIME_quark : public Time_quark
{
public:
  //Constructor
  RPI3_TIME_quark();

  //Destructor
  ~RPI3_TIME_quark();

  bool detectsystem(void) final;

  void reset() final;

  uint64_t gettimestamp() final;
};