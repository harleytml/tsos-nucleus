// By Tsuki Superior
// Reference was skiftos
#pragma once

#include <generic/time_quark.hpp>

class CMOS_quark : public Time_quark
{
  public:
    // Constructor
    CMOS_quark();

    // Destructor
    ~CMOS_quark();

    bool detectsystem(void) final;

    void reset() final;

    uint64_t gettimestamp() final;

  private:
    const static uint8_t CMOS_ADDRESS = 0x70;
    const static uint8_t CMOS_DATA = 0x71;

    enum class time_register_t : uint8_t
    {
        second = 0x0,
        minute = 0x2,
        hour = 0x4,
        day = 0x7,
        month = 0x8,
        year = 0x9,
    };

    class Date
    {
      public:
        size_t second;
        size_t minute;
        size_t hour;
        size_t day;
        size_t month;
        size_t year;
        uint64_t totimestamp();
    };

    size_t bcd_to_int(size_t bcd);
    static bool is_leap_year(uint32_t year);
    uint8_t get_realtime_reg(time_register_t reg);
    bool is_cmos_update();

    friend Date;
};