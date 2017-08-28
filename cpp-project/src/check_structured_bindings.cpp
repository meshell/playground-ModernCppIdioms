#include <string>
#include "helpers/helpers.h"

using namespace std;
using namespace modern_cpp::helpers;
using namespace std::string_literals;

int main() {
    try {

        static constexpr auto current_file = __FILE__;
        const auto src_path = fs::path{current_file}.parent_path();
        const auto file_path =  src_path / fs::path{"Exercises/structured_binding.cpp"};

        const auto pattern = R"(\[\w+\s*,\s*\w+\]\s*=\s*address_book.insert)"s;
        if (exists_in_file(pattern, file_path) > 0) {
            show_success(false);
            show_message_on_techio("Great", "You used structured bindings");
            if (exists_in_file(pattern, file_path) < 3) {
                show_message_on_techio("...but", "Did you replace all occurrences?");
            }
            const auto pattern_2 = R"(\[\w+\s*,\s*\w+\]\s*:\s*address_book)"s;
            if (exists_in_file(pattern_2, file_path) > 0) {
                show_success(true);
            } else {
                show_message_on_techio("...but", "how about the range based for loop?");
            }

        } else {
            show_success(false);
            show_message_on_techio("Oops! 🐞", "You didn't refactor the code");
            show_message_on_techio("Hint", "Did you use structured bindings where a tuple or pair is returned.");
        }

    } catch (const exception& e) {
        show_success(false);
        show_message_on_techio("Oops! 🐞", e.what());
    }

    return 0;
}
