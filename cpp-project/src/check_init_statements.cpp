#include <string>
#include "helpers/helpers.h"

using namespace std;
using namespace modern_cpp::helpers;
using namespace std::string_literals;

int main() {
    try {

        static constexpr auto current_file = __FILE__;
        const auto src_path = fs::path{current_file}.parent_path();
        const auto file_path =  src_path / fs::path{"Exercises/init_statements.cpp"};

        const auto pattern = R"(if\s*\([^;]+;[^;]+\)\s*\{)"s;
        if (exists_in_file(pattern, file_path) > 0) {
            show_message_on_techio("Great", "You used init statements in if");
            if (exists_in_file(pattern, file_path) < 2) {
                show_success(false);
                show_message_on_techio("...but", "Did you replace all occurrences?");
                return 0;
            }
        } else {
            show_success(false);
            show_message_on_techio("Oops! 🐞", "You didn't refactor the code");
            show_message_on_techio("Hint", "Use init statements in the if.");
        }
    } catch (const exception& e) {
        show_success(false);
        show_message_on_techio("Oops! 🐞", e.what());
    }

    return 0;
}
