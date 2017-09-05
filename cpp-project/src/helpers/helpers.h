#ifndef UNIVERSE_HELPERS_H
#define UNIVERSE_HELPERS_H

#include <experimental/filesystem>
#include <string>
#include <sstream>

namespace modern_cpp {
namespace helpers {

namespace fs = std::experimental::filesystem;

template<typename T>
void assert_equal(T found, T&& expected, std::string message) {
    if (expected != found) {
        std::ostringstream error;
        error << message << " Expected: " << expected << ", Found: " << found << std::endl;
        throw std::logic_error(error.str());
    }
}

inline void assert_true(bool cond, std::string message) {
    if (not cond) {
        std::ostringstream error;
        error << message << " Expected to be true, but is false\n";
        throw std::logic_error(error.str());
    }
}

inline void assert_false(bool cond, std::string message) {
    if (cond) {
        std::ostringstream error;
        error << message << " Expected to be false, but is true\n";
        throw std::logic_error(error.str());
    }
}

template<typename T>
void assert_le(T found, T&& expected, std::string message) {
    if (found > expected) {
        std::ostringstream error;
        error << message << " Expected: " << found << " <= " << expected << std::endl;
        throw std::logic_error(error.str());
    }
}

template<typename T>
void assert_ge(T found, T&& expected, std::string message) {
    if (found < expected) {
        std::ostringstream error;
        error << message << " Expected: " << found << " >= " << expected << std::endl;
        throw std::logic_error(error.str());
    }
}

unsigned exists_in_file(const std::string& pattern, const fs::path& filepath);

void show_message_on_techio(std::string_view channel, std::string_view msg);

void show_success(bool success);


}
}


#endif //UNIVERSE_HELPERS_H
