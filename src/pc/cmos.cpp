#include <pc/cmos.hpp>
#include <generic/nucleus_instance.hpp>

CMOS_quark::CMOS_quark()
{
}

CMOS_quark::~CMOS_quark()
{
}

void CMOS_quark::reset()
{
}

bool CMOS_quark::detectsystem()
{
  return true;
}

uint64_t CMOS_quark::gettime()
{
  uint64_t time = 0;
  Date date = Date();

  while (is_cmos_update())
  {
  }

  date.second = bcd_to_int(get_realtime_reg(time_register_t::second));
  date.minute = bcd_to_int(get_realtime_reg(time_register_t::minute));
  date.hour = bcd_to_int(get_realtime_reg(time_register_t::hour));
  date.day = bcd_to_int(get_realtime_reg(time_register_t::day));
  date.month = bcd_to_int(get_realtime_reg(time_register_t::month));
  date.year = bcd_to_int(get_realtime_reg(time_register_t::year));

  // This is only a rough calculation
  time += date.second;
  time += date.minute * 60;
  time += date.hour * 3600;
  time += date.day * 86400;
  time += date.month * 2628000;
  time += date.year * 31536000;

  return time;
}

size_t CMOS_quark::bcd_to_int(size_t bcd)
{
  return (((bcd) / 16) * 10 + ((bcd)&0xf));
}

uint8_t CMOS_quark::get_realtime_reg(time_register_t reg)
{
  tsos->io.out8(CMOS_ADDRESS, (uint8_t)reg);
  return tsos->io.in8(CMOS_DATA);
}

bool CMOS_quark::is_cmos_update()
{
  tsos->io.out8(CMOS_ADDRESS, 0x0A);
  return (tsos->io.in8(CMOS_DATA) & 0x80);
}