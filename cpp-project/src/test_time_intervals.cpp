#include <chrono>
#include <thread>

#include "Exercises/time_intervals.h"
#include "helpers/helpers.h"

using namespace modern_cpp;
using namespace modern_cpp::helpers;

int main() {
    try {
        assert_equal(time_intervals::half_day.count(), std::chrono::hours(12).count(), "Half day in hours.");
        assert_equal(time_intervals::half_hour.count(), std::chrono::minutes(30).count(), "Half hour in minutes.");
        assert_equal(time_intervals::half_minute.count(), std::chrono::seconds(30).count(), "Half minute in seconds.");
        assert_equal(time_intervals::half_second.count(), std::chrono::milliseconds(500).count(), "Half second in milliseconds.");
        assert_equal(time_intervals::half_millisecond.count(), std::chrono::microseconds(500).count(), "Half millisecond in microseconds");
        assert_equal(time_intervals::half_microsecond.count(), std::chrono::nanoseconds(500).count(), "Half microsecond in nanoseconds");
        const auto day_in_hours = std::chrono::duration_cast<std::chrono::hours>(time_intervals::day(1));
        assert_equal(day_in_hours.count(), std::chrono::hours(24).count(), "day in hours");
        const auto week_in_hours = std::chrono::duration_cast<std::chrono::hours>(time_intervals::week(1));
        assert_equal(week_in_hours.count(), std::chrono::hours(24 * 7).count(), "week in hours");
        const auto week_in_days = std::chrono::duration_cast<time_intervals::day>(time_intervals::week(1));
        assert_equal(week_in_days.count(), time_intervals::day(7).count(), "week in days");

        const auto week_in_years = std::chrono::duration_cast<time_intervals::year>(time_intervals::week(1));
        const auto day_in_years = std::chrono::duration_cast<time_intervals::year>(time_intervals::day(1));
        const auto hour_in_years = std::chrono::duration_cast<time_intervals::year>(std::chrono::hours(1));
        const auto minute_in_years = std::chrono::duration_cast<time_intervals::year>(std::chrono::minutes(1));
        const auto second_in_years = std::chrono::duration_cast<time_intervals::year>(std::chrono::seconds(1));

        assert_equal(time_intervals::week_in_years.count(), week_in_years.count(), "one week in years");
        assert_equal(time_intervals::day_in_years.count(), day_in_years.count(), "one day in years");
        assert_equal(time_intervals::hour_in_years.count(), hour_in_years.count(), "one hour in years");
        assert_equal(time_intervals::minute_in_years.count(), minute_in_years.count(), "one minute in years");
        assert_equal(time_intervals::second_in_years.count(), second_in_years.count(), "one second in years");



        show_message_on_techio("Great", "");
//        show_message_on_techio("Remark", "Did you use a steady clock? E.g. steady_clock?");
//        show_message_on_techio("Remark",
//                               "Can you change the code to return a differnt duration type? E.g. nanoseconds?");
        show_success(true);
    } catch (const std::exception& e) {
        show_success(false);
        show_message_on_techio("Oops! 🐞", e.what());
    }

    return 0;
}
