#include <vector>
#include <numeric>
#include "../utils.h"

// Helps to solve O(nk) by O(n) + O(k)

// The notion is to use result from i-th iteration to calculate for i+1 with minor changes.
using namespace utils;

template <typename T>
std::vector<T> window_sum(const std::vector<T>& vect, const int w_size)
{
    std::vector<T> result;
    
    T w_sum = 0;
    for (std::size_t i = 0; i < w_size; ++i)
        w_sum += vect[i];

    result.push_back(w_sum);


    for (std::size_t i = w_size; i < vect.size(); ++i)
        result.push_back(result.back() + vect[i] - vect[i - w_size]);

    return result;
}


int main()
{
    std::vector<int> v(100);
    std::iota (std::begin(v), std::end(v), 0);

    print_vector(window_sum(v, 3));

    return 0;
};