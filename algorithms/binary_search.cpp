#include <iostream>
#include <vector>
#include "../utils.h"


using namespace utils;


template <typename T>
T iterative_binary_search(const std::vector<T>& vect, T x)
{
    int l = 0;
    int m;
    int r = static_cast<int>(vect.size());

    while (l <= r) {
     m = l + (r - l) / 2;

     if (vect[m] == x)
        return m;
     else if (x < vect[m])
        r = m + 1;
     else
        l = m - 1;
    };

    return -1;
};


template <typename T>
T recursive_binary_search(const std::vector<T>& vect, T x, int l, int r)
{
    int m = l + (r - l) / 2;

    if (vect[m] == x)
        return m;
    else if (vect[m] < x)
        return recursive_binary_search(vect, x, m + 1, r);
    else
        return recursive_binary_search(vect, x, l, m - 1);

    return -1;
};


template <typename T>
int left_binary_search(long arr[], int l, int r, long target) {
    int m = (l + r) >> 1;

    if (arr[m] <= target & target < arr[m + 1])
        return m;
    else if (arr[m] < target)
        return binary_search(arr, m + 1, r, target);
    else
        return binary_search(arr, l, m - 1, target);
    
    return -1;
};


int main()
{
    int x;
 
    std::cout << "x: ";
    std::cin >> x;


    std::string input_line;

    std::cout << "vector: ";
    std::cin.ignore();
    std::getline(std::cin, input_line);

    std::vector<int> nums = fill_vector_from_string(input_line);

    std::cout << "Index of x is " << iterative_binary_search(nums, x) << "\n";
    std::cout << "Index of x is " << recursive_binary_search(nums, x, 0 , static_cast<int>(nums.size())) << "\n";

    return 0;
};