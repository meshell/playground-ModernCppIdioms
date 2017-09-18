# Filesystem library
## Possible solution

```C++ runnable
#include <experimental/filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace fs = std::experimental::filesystem;
using namespace std::string_literals;

/**
 * List all regular files in a directory
 * @param dir directory path
 * @return vector of paths of regular files in directory
 */
std::vector<fs::path> list_regular_files_in_directory(const fs::path& dir) {
    std::vector<fs::path> regular_files;
    if (fs::exists(dir) && fs::is_directory(dir)) {
        for (const auto& entry : fs::directory_iterator(dir)) {
            if (fs::is_regular_file(entry.status())) {
                regular_files.emplace_back(entry.path());
            }
        }
    }
    return regular_files;
}

/**
 * Check if a file contains a particular string
 * @param filepath path to the file that should be checked
 * @param str string to search for in file
 * @retval true if the string str was found in file filepath
 * @retval false otherwise
 */
bool file_contains_string(const fs::path& filepath, const std::string& str) {
    if (fs::exists(filepath)) {
        std::ifstream file(filepath);
        std::string line;
        while (getline(file, line)) {
            if (line.find(str) != std::string::npos) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    const auto current_path = fs::current_path();
    const auto data_path = current_path / "data";
    const auto files = list_regular_files_in_directory(data_path);
    for (const auto& file_path : files) {
        std::cout << file_path.filename() << std::endl;
        if (file_contains_string(file_path, "copy")) {
            auto error = std::error_code{};
            const auto new_data_path = current_path / "data_new";
            auto success = fs::create_directory(new_data_path, error);
            if (success) {
                success = fs::copy_file(file_path, new_data_path / file_path.filename(), error);
            }
            if (not success) {
                std::cout << "Failure: " << error.message() << std::endl;
            }
        }

    }
    return 0;
}
```
