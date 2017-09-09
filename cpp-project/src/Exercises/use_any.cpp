#include <typeindex>
#include <vector>
#include <string>
#include <iostream>

struct element
{
    void* elem;
    std::type_index type;
};

int main()
{
    std::vector<element> vec_of_any;

    vec_of_any.emplace_back(element{new int(1), std::type_index(typeid(int))});
    vec_of_any.emplace_back(element{new double(2.0), std::type_index(typeid(double))});
    vec_of_any.emplace_back(element{new std::vector<int>(2, 5), std::type_index(typeid(std::vector<int>))});
    vec_of_any.emplace_back(element{new std::string("Hello"), std::type_index(typeid(std::string))});

    for (const auto& elem : vec_of_any)
    {
        if (elem.type == std::type_index(typeid(int))) {
            std::cout << *(static_cast<int*>(elem.elem)) << std::endl;
        }
        if (elem.type == std::type_index(typeid(double))) {
            std::cout << *(static_cast<double*>(elem.elem)) << std::endl;
        }
        if (elem.type == std::type_index(typeid(std::vector<int>))) {
            const auto vec = static_cast<std::vector<int>*>(elem.elem);
            std::cout << "[";
            for(auto i = 0; i < vec->size(); ++i) {
                std::cout << vec->at(i);
                if (i < (vec->size()-1)) {
                    std:: cout << ", ";
                }
            }
            std::cout << "]\n";
        }
        if (elem.type == std::type_index(typeid(std::string))) {
            std::cout << *(static_cast<std::string*>(elem.elem)) << std::endl;
        }
    }
}