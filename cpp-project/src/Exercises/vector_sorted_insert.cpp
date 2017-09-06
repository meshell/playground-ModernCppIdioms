#include <vector>
#include <iostream>
#include <algorithm>

#include "../helpers/helpers.h"


template<typename Cont, typename T>
void insert_sorted(Cont& container, const T& item) {
    // TODO implement insertion such that container is still sorted after insertion
};

using namespace modern_cpp::helpers;
using namespace std::string_literals;

int main() {
    try {
        std::vector<std::string> dictionary = {"some", "random", "words", "with", "no", "particular", "order"};
        assert_false(std::is_sorted(std::begin(dictionary), std::end(dictionary)), "Dictionary is sorted"s);
        std::sort(std::begin(dictionary), std::end(dictionary));
        assert_true(std::is_sorted(std::begin(dictionary), std::end(dictionary)), "Dictionary is sorted"s);

        const auto dictionary_elements = dictionary.size();

        insert_sorted(dictionary, "foo");
        insert_sorted(dictionary, "bar");
        insert_sorted(dictionary, "zeta");

        assert_true(std::is_sorted(std::begin(dictionary), std::end(dictionary)), "Dictionary is sorted after inserts"s);
        assert_equal(dictionary.size(), dictionary_elements + 3, "New dictionary size after insertion"s);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what();
        return 1;
    }
    return 0;
}


