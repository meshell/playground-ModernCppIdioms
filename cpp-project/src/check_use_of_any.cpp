#include <string>
#include "helpers/helpers.h"

using namespace std;
using namespace modern_cpp::helpers;
using namespace std::string_literals;

int main() {
    static constexpr auto current_file = __FILE__;
    const auto src_path = fs::path{current_file}.parent_path();
    const auto file_path = src_path / fs::path{"Exercises/use_any.cpp"};
    bool success = true;

    const auto static_cast_pattern = R"(static_cast<)"s;
    if (exists_in_file(static_cast_pattern, file_path) > 0) {
        show_message_on_techio("Oops! 🐞", "You still use static_cast");
        success = false;
    }
    const auto any_pattern = R"(any_cast<)"s;
    if (not exists_in_file(any_pattern, file_path) > 0) {
        show_message_on_techio("Oops! 🐞", "You didn't use any_cast");
        success = false;
    }
    const auto compare_pattern = R"(type\(\s*\)\s*==\s*typeid\(\s*)"s;
    if (not exists_in_file(compare_pattern, file_path) > 0) {
        show_message_on_techio("Oops! 🐞", "You didn't check the type of the any type value.");
        success = false;
    }
    if (success) {
        show_message_on_techio("Great", "It seems that you refactored the code.");
    }
    show_success(success);
    return success;
}
