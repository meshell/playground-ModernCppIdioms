#include <chrono>
#include <thread>

#include "Exercises/measure_duration.h"
#include "helpers/helpers.h"

using namespace modern_cpp;
using namespace modern_cpp::helpers;

int main() {
    try {

        const auto very_expensive_function = [](const int i, const int t) {
            std::this_thread::sleep_for(std::chrono::milliseconds(i * t));
        };

        const auto execution_time = duration(very_expensive_function, 2, 100);
        const auto execution_time_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(execution_time).count();
        assert_ge(execution_time_in_ms, 200l, "Measure execution time of an expensive function");
        show_message_on_techio("Great", "You correctly measured the execution time");
        show_message_on_techio("Remark", "Did you use a steady clock");
        show_message_on_techio("Remark",
                               "Can you change the code to return a differnt duration type, e.g. nanoseconds?");
        show_success(true);
    } catch (const std::exception& e) {
        show_success(false);
        show_message_on_techio("Oops! 🐞", e.what());
    }

    return 0;
}
