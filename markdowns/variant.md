# std::variant
In the previous exercise we used `std::optional` to indicate failure.
But how about a more detailed error message?

Enter template class [`std::variant`](http://en.cppreference.com/w/cpp/utility/variant).
We could use `std::variant` to either hold a valid value or a detailed error.

## DIY
Refactor function `differentiate` to have return type `std::variant<double, std::string>` and
once again make the tests pass.
The variant should either be a valid value or an error string.

@[Refactor the code to use std::variant]({"stubs": ["src/Exercises/variant.h"],"command": "./run_catch_test.sh ./test_variant -s"})

