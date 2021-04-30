#include <generic/nucleus_instance.hpp>
#include <pc/cmos.hpp>

CMOS_quark::CMOS_quark()
{
    name = "Complementary Metal Oxide Semiconductor Real Time Clock";
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

uint64_t CMOS_quark::gettimestamp()
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

    return date.totimestamp();
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

bool CMOS_quark::is_leap_year(uint32_t year)
{
    return ((!((year) % 4) && (year) % 100) || !((year) % 400));
}

uint64_t CMOS_quark::Date::totimestamp()
{
    uint64_t timestamp = 0;

    const uint16_t EPOCH_YEAR = 1970;
    const uint32_t SECONDS_PER_MINUTE = 60;
    const uint32_t SECONDS_PER_HOURS = SECONDS_PER_MINUTE * 60;
    const uint32_t SECONDS_PER_DAY = SECONDS_PER_HOURS * 24;
    const uint32_t MONTH_PER_YEAR = 12;
    const static uint16_t DAYS_PER_YEAR[2] = {365, 366};

    const static uint8_t DAYS_PER_MONTH[2][MONTH_PER_YEAR] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    };

    for (uint32_t x = EPOCH_YEAR; x < year; x++)
    {
        timestamp += DAYS_PER_YEAR[CMOS_quark::is_leap_year(year)] * SECONDS_PER_DAY;
    }

    for (uint32_t y = 0; y < month - 1; y++)
    {
        timestamp += DAYS_PER_MONTH[CMOS_quark::is_leap_year(year)][month] * SECONDS_PER_DAY;
    }

    timestamp += (day - 1) * SECONDS_PER_DAY;

    timestamp += hour * SECONDS_PER_HOURS;
    timestamp += minute * SECONDS_PER_MINUTE;
    timestamp += second;

    return timestamp;
}
