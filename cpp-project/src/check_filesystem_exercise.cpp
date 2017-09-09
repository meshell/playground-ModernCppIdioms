
#include "helpers/helpers.h"
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

using namespace std::string_literals;
using namespace modern_cpp::helpers;

int main() {
    const auto current_path = fs::current_path();
    const auto data_path = current_path / "data";
    const auto new_data_path = current_path / "data_new";
    if (fs::exists(new_data_path) && fs::is_directory(new_data_path)) {
        if (fs::exists(new_data_path / "text3.txt")) {
            if (fs::exists(data_path / "text3.txt")) {
                show_message_on_techio("Great", "You copied the correct file to the correct new location"s);
                show_success(true);
                return 0;
            } else {
                show_message_on_techio("Oops!", "You moved the file instead of copying."s);
                show_message_on_techio("Oops!", ""s);
                show_message_on_techio("Oops!", "Try again !!"s);
            }
        } else {
            show_message_on_techio("Oops!", "You did not copy the correct file"s);
            show_message_on_techio("Oops!", ""s);
            show_message_on_techio("Oops!", "Try again !!"s);
        }
    } else {
        show_message_on_techio("Oops!", "You did not create a new folder data_new."s);
        show_message_on_techio("Oops!", ""s);
        show_message_on_techio("Oops!", "Try again !!"s);
    }
    show_success(false);
    return 1;
}
