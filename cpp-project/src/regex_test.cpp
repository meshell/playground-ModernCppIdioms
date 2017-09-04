#include <regex>
#include <string>
#include <iostream>

#include "Exercises/regex_replace.h"
#include "helpers/helpers.h"

namespace {

using namespace std::string_literals;

static const auto text = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, "
        "sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, "
        "sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. "
        "Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet."s;

std::string my_replace_words_with_one_vovel(const std::string& text) {
    using replace_t = std::vector<std::pair<std::string, std::string>>;
    replace_t words_to_replace;
    const auto pattern = R"((\s+(?:[^aeiou]*[aeiou][^aeiou]*){1}\s+))"s;
    const auto rx = std::regex{pattern, std::regex_constants::icase};
    auto end = std::sregex_token_iterator{};
    for (auto it = std::sregex_token_iterator{std::begin(text), std::end(text), rx, 1}; it != end; ++it) {
        const auto word = std::string{*it};
        const auto new_word = std::regex_replace(word, std::regex{R"([^aeiou\s])"s, std::regex_constants::icase}, "*"s);
        words_to_replace.emplace_back(std::make_pair(word, new_word));
    }
    auto new_text = text;
    for (const auto&
        [word, new_word] : words_to_replace) {
        new_text = std::regex_replace(new_text, std::regex{word, std::regex_constants::icase}, new_word);
    }

    return new_text;
};

}

using namespace modern_cpp;
using namespace modern_cpp::helpers;

int main() {
    const auto censored_text = replace_words_with_one_vovel(text);
    const auto expected_text = my_replace_words_with_one_vovel(text);

    if (censored_text == expected_text) {
        show_message_on_techio("Great",
                               "You correctly censored the text:\n\'"s + text + "\'\n to \n\'"s + censored_text +
                               "\'"s);
        show_success(true);
    } else {
        show_success(false);
        show_message_on_techio("Oops!",
                               "Your output (\""s + censored_text + "\") is not exactly what we expected (\""s +
                               expected_text + "\")\n Try again !!!"s);
    }

    return 0;
}
