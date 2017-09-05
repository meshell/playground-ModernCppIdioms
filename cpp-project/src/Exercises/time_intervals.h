#ifndef MODERN_CPP_TIME_INTERVALS_H
#define MODERN_CPP_TIME_INTERVALS_H

#include <chrono>

namespace modern_cpp {
namespace time_intervals {

using namespace std::chrono_literals;

// TODO define the following durations correctly
using day = std::chrono::hours;
using week = std::chrono::hours;
using year = std::chrono::hours;

// TODO define the following intervals correctly
static const std::chrono::hours half_day(1);
static const std::chrono::minutes half_hour(1);
static const std::chrono::seconds half_minute(1);
static const std::chrono::milliseconds half_second(1);
static const std::chrono::microseconds half_millisecond(1);
static const std::chrono::nanoseconds half_microsecond(1);

// TODO define the following intervals based on the type above
static const time_intervals::year week_in_years(1);
static const time_intervals::year day_in_years(1);
static const time_intervals::year hour_in_years(1);
static const time_intervals::year minute_in_years(1);
static const time_intervals::year second_in_years(1);

}
}

#endif //MODERN_CPP_TIME_INTERVALS_H
