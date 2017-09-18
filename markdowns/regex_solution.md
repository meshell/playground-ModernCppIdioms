# Regular expressions
## Possible solution

```C++
#ifndef MODERN_CPP_REGEX_REPLACE_H
#define MODERN_CPP_REGEX_REPLACE_H

#include <string>
#include <regex>

namespace modern_cpp {
using namespace std::string_literals;

/**
 * Replaces all words in 'input' containing exactly one vovel with the same word,
 * but all non-vovels are replaced by *, e.g.
 * "Lorem ipsum dolor sit amet" becomes "Lorem ipsum dolor *i* amet"
 * @param input text to "censor"
 * @return censored text
 */
std::string replace_words_with_one_vovel(const std::string& input) {
    using replace_t = std::vector<std::pair<std::string, std::string>>;
    replace_t words_to_replace;
    const auto pattern = R"((\s+(?:[^aeiou]*[aeiou][^aeiou]*){1}\s+))"s;
    const auto rx = std::regex{pattern, std::regex_constants::icase};
    auto end = std::sregex_token_iterator{};
    for (auto it = std::sregex_token_iterator{std::begin(input), std::end(input), rx, 1};
         it != end; ++it) {
        const auto word = std::string{*it};
        const auto new_word = std::regex_replace(word,
                                                 std::regex{R"([^aeiou\s])"s,
                                                 std::regex_constants::icase},
                                                 "*"s);
        words_to_replace.emplace_back(std::make_pair(word, new_word));
    }
    auto new_text = input;
    for (const auto& [word, new_word] : words_to_replace) {
        new_text = std::regex_replace(new_text, std::regex{word, std::regex_constants::icase}, new_word);
    }
    return new_text;
};
}
#endif //MODERN_CPP_REGEX_REPLACE_H
```
