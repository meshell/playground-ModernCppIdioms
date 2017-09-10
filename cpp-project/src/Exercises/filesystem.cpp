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
    // TODO search in the 'data' directory of the current directory for all files
    // which contain 'copy' in its content and copy them to a new folder 'data_new'.
    return 0;
}

