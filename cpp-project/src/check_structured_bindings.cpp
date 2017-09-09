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
            show_message_on_techio("Great", "You used structured bindings");
            if (exists_in_file(pattern, file_path) < 3) {
                show_success(false);
                show_message_on_techio("...but", "Did you replace all occurrences?");
                return 1;
            }
            const auto pattern_2 = R"(\[\w+\s*,\s*\w+\]\s*:\s*address_book)"s;
            if (exists_in_file(pattern_2, file_path) > 0) {
                show_success(true);
            } else {
                show_success(false);
                show_message_on_techio("...but", "how about the range based for loop?");
                return 1;
            }
            const auto access_name_pattern = R"(\w+->first)"s;
            const auto access_address_pattern = R"(\w+->second)"s;
            if ((exists_in_file(access_name_pattern, file_path) > 0) ||
                (exists_in_file(access_address_pattern, file_path) > 0)){
                show_message_on_techio("However", "How about using structured binding to access the name and address?");
            }
        } else {
            show_success(false);
            show_message_on_techio("Oops! 🐞", "You didn't refactor the code");
            show_message_on_techio("Hint", "Use structured bindings where a tuple, pair or struct is returned.");
            return 1;
        }
    } catch (const exception& e) {
        show_success(false);
        show_message_on_techio("Oops! 🐞", e.what());
        return 1;
    }

    return 0;
}
