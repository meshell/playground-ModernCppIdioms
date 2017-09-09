# std::optional
C++17 adds template [`std::optional`](http://en.cppreference.com/w/cpp/utility/optional) to manage an optional value.

## DIY
Try to make pass the tests for error cases. Do not worry about the good case test,
if it fails because of formating or precision issues.

Make the tests pass by refactoring function `differentiate` to return std::optional<double> instead of double.
Does it help to make use of `value_or()`?

@[Refactor the code to use std::optional]({"stubs": ["src/Exercises/optional.h"],"command": "./check_optional.sh"})

## Bonus exercise
Replace the type for time with something better than than double.
