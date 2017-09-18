# Working with vectors

## Remove multiple items from a vector
We looked already at the Erase-Remove Idiom in the [Januar 2016 Meeting](http://cpp-ug-luzern.blogspot.ch/2016/02/c-idioms.html).
The Erase-Remove Idiom is considered the correct way of removing multiple items from a standard library container.

```C++ runnable
#include <vector>
#include <iostream>
#include <algorithm>

template<typename T, typename U>
void remove_multiples(std::vector<T>& vec, U multiple_of) {
    vec.erase(std::remove_if(std::begin(vec),
                             std::end(vec),
                             [=](const auto& elem) {
                                 return elem % multiple_of == 0;
                             }),
              std::end(vec));
    // reduce the capacity (Note that this may lead to reallocation of memory)
    vec.shrink_to_fit();
}

int main() {
    const auto print_numbers = [](const auto& numbers) { ;
        for (const auto& i : numbers) {
            std::cout << i << ", ";
        }
        std::cout << "size is " << numbers.size() << "\n";
    };

    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    remove_multiples(numbers, 2);
    print_numbers(numbers);
    remove_multiples(numbers, 5);
    print_numbers(numbers);
    if (numbers.size() != 4) {
        std::cout << "\nFailure Not all items removed\n";
        return 1;
    }
    return 0;
}
```

## Deleting items from an unsorted vector in $`O(1)`$
Deleting an element from the middle of an `std::vector` with the Erase-Remove idiom takes $`O(n)`$, because the resulting gap must be filled by moving all the items after the gap to the left.
This might be expensive if the items are complex and/or very large. If preserving the order of the items is not important, the deletion can be optimized.

```C++ runnable
#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
void quick_remove_at(std::vector<T>& vec, std::size_t idx) {
    if (idx < vec.size()) {
        vec.at(idx) = std::move(vec.back());
        vec.pop_back();
    }
}

template<typename T>
void quick_remove_at(std::vector<T>& vec, typename std::vector<T>::iterator it) {
  if (it != std::end(vec)) {
      *it = std::move(vec.back());
      vec.pop_back();
  }
}

int main() {
    const auto print_numbers = [](const auto& numbers) { ;
        for (const auto& i : numbers) {
            std::cout << i << ", ";
        }
        std::cout << "size is " << numbers.size() << "\n";
    };

    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_numbers(numbers);
    quick_remove_at(numbers, 2);
    print_numbers(numbers);
    quick_remove_at(numbers, std::find(std::begin(numbers), std::end(numbers), 6));
    print_numbers(numbers);
    if(std::count(std::begin(numbers), std::end(numbers), 6) != 0) {
        std::cout << "\nFailure: Element 6 was not removed.\n";
        return 1;
    }
    return 0;
}
```
## Keep std::vector sorted
Sometimes you want a sorted vector to be still sorted after insertion of an element. Try to implement a sorted insertion.

@[Implement insert_sorted method]({"stubs": ["src/Exercises/vector_sorted_insert.cpp"],"command": "./vector_sorted_insert"})
