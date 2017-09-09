# Filesystem library

```C++ runnable
#include <experimental/filesystem>
#include <iostream>
#include <string>
#include <vector>


namespace fs = std::experimental::filesystem;
using namespace std::string_literals;

std::vector<fs::path> list_regular_files_in_directory(const fs::path& dir)
{
    std::vector<fs::path> regular_files;
    if (fs::exists(dir) && fs::is_directory(dir))
    {
        for (const auto& entry : fs::directory_iterator(dir))
        {
            if(fs::is_regular_file(entry.status()))
            {
                regular_files.emplace_back(entry.path());
            }
        }
    }
    return regular_files;
}



int main()
{
    const auto files = list_regular_files_in_directory("../src/Exercises/data"s);
    for (const auto& file_path : files)
    {
        std::cout << file_path.filename() << std::endl;
    }

    return 0;
}

```
