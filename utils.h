#include <iostream>
#include <string>
#include <vector>
#include <sstream>


namespace utils 
{
    template <typename T>
    void print_vector(const std::vector<T> v) 
    {
        for (const auto& index : v) 
        {
            std::cout << index << " ";
        };
        std::cout << std::endl;
    };


    // std::string input_line;
    // std::getline(std::cin, input_line);
    std::vector<int> fill_vector_from_string(std::string input_line)
    {
        std::vector<int> v;

        std::istringstream stream(input_line);
        int input;

        while (stream >> input)
            {
                v.push_back(input);
            };

        return v;
    };

};
