# Structured Bindings

[Structured bindings](http://en.cppreference.com/w/cpp/language/structured_binding)
is a new C++ language feature shipping with C++17.
It gives us the ability to declare multiple variables initialized from a `tuple`, `pair` or `struct`.

## Example
With C++11/14 you could use [`std::tie`](http://en.cppreference.com/w/cpp/utility/tuple/tie)
to bind the elements of a pair or tuple to variables:
```
auto tuple = std::make_tuple(1, 'a', 2.3);

// first declare the variables
int i;
char c;
double d;

// now we can unpack the tuple
std::tie(i, c, d) = tuple;
```

With C++17 this becomes much easier:
```
const auto [ i, c, d ] = std::make_tuple(1, 'a', 2.3);
```
## DIY

@[Refactor the code to use structured bindings when ever possible]({"stubs": ["src/Exercises/structured_binding.cpp"],"command": "bash /project/target/check_structured_bindings.sh"})
