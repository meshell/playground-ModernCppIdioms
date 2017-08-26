
#include <map>
#include <string>
#include <iostream>

using namespace std::string_literals;

struct address_t {
    std::string street;
    unsigned plz;
    std::string city;
};

int main() {

    std::map<std::string, address_t> address_book;

    const auto hans = "Hans Meister"s;
    const auto hans_address = address_t{"Maihofstrasse 49"s, 6000u, "Luzern"s};
    auto result = address_book.insert({hans, hans_address});

    std::cout << "inserted = " << result.second << std::endl;
    std::cout << "name = " << result.first->first << std::endl;
    std::cout << "address = " << result.first->second.street << ", "
              << result.first->second.plz << ", "
              << result.first->second.city << std::endl;

    auto it = address_book.find(hans);
    if (it != address_book.end()) {
        std::cout << hans << " is in address book\n";
    }

    const auto peter = "Peter Müller"s;
    it = address_book.find(peter);
    if (it == address_book.end()) {
        std::cout << peter << " is not in address book\n";
    }

    const auto peter_address = address_t{"Langstrasse 49"s, 8000u, "Zürich"s};
    result = address_book.insert({peter, peter_address});

    if (result.second) {
        std::cout << "Inserted " << result.first->first << std::endl;;
    } else {
        std::cout << "Did not insert " << result.first->first << std::endl;;
    }

    result = address_book.insert({peter, peter_address});

    if (result.second) {
        std::cout << "Inserted " << result.first->first << std::endl;;
    } else {
        std::cout << "Did not insert " << result.first->first << std::endl;;
    }

    for(const auto& entry : address_book)
    {
        std::cout << "\n name = " << entry.first << std::endl;
        std::cout << " address = " << entry.second.street << ", "
                  << entry.second.plz << ", "
                  << entry.second.city << std::endl;
    }
}




