# Measure Time Intervals
## Possible solution

```C++ runnable
#ifndef MODERN_CPP_MEASURE_DURATION_H
#define MODERN_CPP_MEASURE_DURATION_H

#include <chrono>
#include <functional>

namespace modern_cpp {

using time_interval_t = std::chrono::microseconds;
using clock = std::chrono::high_resolution_clock;

template<typename Func, typename... Args>
static time_interval_t duration(Func&& func, Args... args) {
    const auto start = clock::now();
    std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
    return std::chrono::duration_cast<time_interval_t>(clock::now() - start);
};
}
#endif //MODERN_CPP_MEASURE_DURATION_H
```

# Time intervals
## Possible solution

```C++ runnable
#ifndef MODERN_CPP_TIME_INTERVALS_H
#define MODERN_CPP_TIME_INTERVALS_H

#include <chrono>

namespace modern_cpp {
namespace time_intervals {

using namespace std::chrono_literals;

using day = std::chrono::duration<double, std::ratio_multiply<std::chrono::hours::period, std::ratio<24>>>;

constexpr day operator"" _days (long double d) {
    return time_intervals::day{d};
}

constexpr day operator"" _days (unsigned long long d) {
    return time_intervals::day{d};
}

constexpr day operator"" _day (unsigned long long d) {
    return time_intervals::day{d};
}

using week = std::chrono::duration<double, std::ratio_multiply<day::period, std::ratio<7>>>;
using year = std::chrono::duration<double, std::ratio_multiply<day::period, std::ratio<365>>>;

static const auto half_day = 12h;
static const auto half_hour = 30min;
static const auto half_minute = 30s;
static const auto half_second = 500ms;
static const auto half_millisecond = 500us;
static const auto half_microsecond = 500ns;

static const auto week_in_years = std::chrono::duration_cast<time_intervals::year>(7_days);
static const auto day_in_years = std::chrono::duration_cast<time_intervals::year>(1_day);
static const auto hour_in_years = std::chrono::duration_cast<time_intervals::year>(std::chrono::hours(1));
static const auto minute_in_years = std::chrono::duration_cast<time_intervals::year>(std::chrono::minutes(1));
static const auto second_in_years = std::chrono::duration_cast<time_intervals::year>(std::chrono::seconds(1));
}
}
#endif //MODERN_CPP_TIME_INTERVALS_H
```
