#include <vector>
#include <iostream>
#include <algorithm>
#include "../utils.h"


using namespace utils;


std::vector<int> isPairSum(std::vector<int>& A, int X)
{
    int N = A.size();

    int i = 0;
    int j = N - 1;

    while (i < j) {
 
        if (A[i] + A[j] == X) {
            return std::vector<int> {i, j};
            }
        else if (A[i] + A[j] < X) {
            i++;
        }
        else {
            j--;
        }
    };

    return std::vector<int> {-1, -1};
}


int main()
{
    std::vector<int> arr = { 2, 3, 5, 8, 9, 10, 11 };
    std::sort(arr.begin(), arr.end());

    print_vector(isPairSum(arr, 15));
    print_vector(isPairSum(arr, 125));

    return 0;
}
