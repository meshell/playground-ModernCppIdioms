#ifndef UNIVERSE_HELPERS_H
#define UNIVERSE_HELPERS_H

#include <experimental/filesystem>
#include <string>

namespace modern_cpp {
namespace helpers {

namespace fs = std::experimental::filesystem;

bool exists_in_file(const std::string& str, const fs::path& filepath);

}
}


#endif //UNIVERSE_HELPERS_H
