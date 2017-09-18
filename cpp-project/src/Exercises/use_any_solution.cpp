#include <any>
#include <vector>
#include <string>
#include <iostream>

using element = std::any;
using namespace std::string_literals;

int main()
{
    std::vector<element> vec_of_any;

    vec_of_any.emplace_back(1);
    vec_of_any.emplace_back(2.0);
    vec_of_any.emplace_back(std::vector<int>(2, 5));
    vec_of_any.emplace_back("Hello"s);

    for (const auto& elem : vec_of_any)
    {
        if (elem.type() == typeid(int)) {
            std::cout << std::any_cast<int>(elem) << std::endl;
        }
        if (elem.type() == typeid(double)) {
            std::cout << std::any_cast<double>(elem) << std::endl;
        }
        if (elem.type() == typeid(std::vector<int>)) {
            const auto& vec = std::any_cast<const std::vector<int>&>(elem);
            std::cout << "[";
            for(auto i = 0; i < vec.size(); ++i) {
                std::cout << vec.at(i);
                if (i < (vec.size()-1)) {
                    std:: cout << ", ";
                }
            }
            std::cout << "]\n";
        }
        if (elem.type() == typeid(std::string)) {
            std::cout << std::any_cast<std::string>(elem) << std::endl;
        }
    }
}
