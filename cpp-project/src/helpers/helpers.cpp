#include "helpers.h"


#include <fstream>
#include <functional>
#include <iostream>

namespace modern_cpp {
namespace helpers {

using namespace std;

bool exists_in_file(const string& str, const fs::path& filepath) {
    if (fs::exists(filepath)) {
        std::ifstream file(filepath);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.find(str) != string::npos) {
                    return true;
                }
            }
        }
    }
    return false;
}

}
}

