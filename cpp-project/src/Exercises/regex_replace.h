#ifndef MODERN_CPP_REGEX_REPLACE_H
#define MODERN_CPP_REGEX_REPLACE_H

#include <string>
#include <regex>

namespace modern_cpp {

/**
 * Replaces all words in 'input' containing exactly one vovel with the same word,
 * but all non-vovels are replaced by *, e.g.
 * "Lorem ipsum dolor sit amet" becomes "Lorem ipsum dolor *i* amet"
 * @param input text to "censor"
 * @return censored text
 */
std::string replace_words_with_one_vovel(const std::string& input) {
    return {};
};
}

#endif //MODERN_CPP_REGEX_REPLACE_H
