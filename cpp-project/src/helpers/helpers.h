#ifndef UNIVERSE_HELPERS_H
#define UNIVERSE_HELPERS_H

#include <experimental/filesystem>
#include <string>

namespace modern_cpp {
namespace helpers {

namespace fs = std::experimental::filesystem;

unsigned exists_in_file(const std::string& pattern, const fs::path& filepath);
void show_message_on_techio(std::string_view channel, std::string_view msg);
void show_success(bool success);


}
}


#endif //UNIVERSE_HELPERS_H
