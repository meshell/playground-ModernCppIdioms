#include "helpers.h"


#include <fstream>
#include <functional>
#include <iostream>
#include <regex>

namespace modern_cpp {
namespace helpers {

using namespace std;

unsigned int exists_in_file(const string& pattern, const fs::path& filepath) {
    auto matched = 0u;

    if (fs::exists(filepath)) {
        std::ifstream file(filepath);
        if (file.is_open()) {
            auto rx = std::regex{pattern};
            auto match = std::smatch{};
            string line;
            while (getline(file, line)) {
                if (std::regex_search(line, match, rx)) {
                    ++matched;
                }
            }
        }
    } else {
        std::cout << "file " << filepath << " doesn't exit \n";
    }
    return matched;
}

void show_message_on_techio(string_view channel, string_view msg) {
    cout << "TECHIO> message --channel \"" << channel << "\" \"" << msg << "\"\n";
}

void show_success(bool success) {
    cout << "TECHIO> success " << (success ? "true" : "false") << "\n";
}

}
}

