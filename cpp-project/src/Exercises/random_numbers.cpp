#include <functional>
#include <map>
#include <algorithm>
#include <iostream>
#include <random>
#include <iomanip>

// Taken from "Modern C++ Programming Cookbook" by Marius Bancila
void generate_and_print(std::function<int()> rnd_generator,
                        const int iterations = 10000) {
    auto data = std::map<int, int>{};
    // generate random numbers
    for (auto n = 0; n < iterations; ++n) {
        ++data[rnd_generator()];
    }
    // find element with the most repetitions
    const auto& [_, max_rep] = *std::max_element(
            std::begin(data),
            std::end(data),
            [](const auto value_rep_pair_1, const auto& value_rep_pair_2) {
                return value_rep_pair_1.second < value_rep_pair_2.second;
            });

    // print bars
    constexpr char block_character= 219;
    const auto rep_unit_width = iterations / 50;
    for (auto i = max_rep / rep_unit_width; i > 0; --i) {
        for (const auto& [val, rep] : data) {
            std::cout << std::fixed
                      << std::setprecision(1)
                      << std::setw(3)
                      << ((rep / rep_unit_width) >= i ? block_character : ' ');
        }
        std::cout << "\n";
    }
    // print numbers
    for (const auto& [val, rep] : data) {
        std::cout << std::fixed
                  << std::setprecision(1)
                  << std::setw(3)
                  << val;
    }
    std::cout << "\n";
};

int main() {
    std::random_device rd{};
    // TODO play around with different engines.
    auto mtgen = std::mt19937{rd()};

    // TODO play around with different distributions.
    auto ud = std::uniform_int_distribution<>{1, 6};
    generate_and_print([&mtgen, &ud]{return ud(mtgen); });
    return 0;
}