# Measure Time Intervals
C++11 provides a flexible date and time library as part of the standard library that allows to define time points and time intervals. The library is called [`chrono`](http://en.cppreference.com/w/cpp/chrono) and is available in the `<chrono>` header in the `std::chrono` namespace.

## Exercise

@[Write a method which measures the execution time of a function]({"stubs": ["src/Exercises/measure_duration.h"],"command": "./test_measure_duration"})

# Time intervals
## Exercise
@[Define the durations and intervals (i.e. do the TODOs)]({"stubs": ["src/Exercises/time_intervals.h"],"command": "./test_time_intervals"})

## Bonus exercise
Define [user defined literals](http://en.cppreference.com/w/cpp/language/user_literal) for day/days and week/weeks and use them together with the chrono literals to define the intervals in the exercise above.
