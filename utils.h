#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>


// static const int _ = [](){
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr); 
//     std::cout.tie(nullptr);

//     return 0;
// }();


namespace utils 
{
    template <typename T>
    void print_vector(const std::vector<T>& v) 
    {
        // for (const auto& value : v) 
        // {
        //     std::cout << value << " ";
        // };
        std::copy(
            v.begin(),
            v.end(),
            std::ostream_iterator<T>(std::cout, " ")
        );

        std::cout << std::endl;
    };


    // std::string input_line;
    // std::getline(std::cin, input_line);
    template <typename T>
    std::vector<T> fill_vector_from_string(const std::string& input_line)
    {
        T input;
        std::istringstream stream;
        std::vector<T> v;


        stream.str(input_line);

        while (stream >> input)
                v.push_back(input);


        return v;
    };

};
