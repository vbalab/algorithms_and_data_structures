#include <iostream>
#include <vector>
#include "../utils.h"


using namespace utils;


template <typename T>
T iterative_binary_search(std::vector<T> vect, T x)
{
    int l = 0;
    int m;
    int r = static_cast<int>(vect.size());

    while (l <= r)
    {
     m = l + (r - l) / 2;

     if (vect[m] == x) {
        return m;
     } else if (x < vect[m]) {
        r = m + 1;
     } else {
        l = m - 1;
     };
    };

    return NULL;
}


int main()
{
    int x;
    std::cin >> x;

    std::string input_line;
    std::getline(std::cin, input_line);
    std::vector<int> nums = fill_vector_from_string(input_line);

    iterative_binary_search(nums, x);
    return 0;
};