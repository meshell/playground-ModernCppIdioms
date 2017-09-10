# Pseudo-random number generation
The [random number library](http://en.cppreference.com/w/cpp/numeric/random) provides classes that generate random and pseudo-random numbers. The library
contains two types of components:
* _Engines_, which are generators of random numbers (both pseudo-random number generators, which generate integer sequences with a uniform distribution, and true random number generators if available)
* _Distributions_ which convert the output of random number engines into various statistical distributions

### Random number engines
All engines (except the `random_device`) produce integer numbers in a uniform distribution using seed data as entropy source.

### Random number distributions
Random number distributions post-processe the output of an random number engine in such a way that the resulting output is distributed according to a defined statistical probability density function.

## Example
The follwing example prints the uniform distribution of an random generator.

### TODO
Play around with different engines and distributions.

@[play around with different engines and distributions.]({"stubs": ["src/Exercises/random_numbers.cpp"],"command": "./random_numbers"})
