#ifndef MODERN_CPP_MEASURE_DURATION_H
#define MODERN_CPP_MEASURE_DURATION_H

#include <chrono>

namespace modern_cpp {

using time_interval_t = std::chrono::microseconds;

template<typename Func, typename... Args>
static time_interval_t duration(Func&& func, Args... args) {

    return {};
};
}

#endif //MODERN_CPP_MEASURE_DURATION_H
