#include <iostream>
#include <vector>
#include "utils.h"


using namespace utils;


class Solution
{
    public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
    {

    };
};


int main()
{
    std::string input_line;
    std::getline(std::cin, input_line);
    std::vector<int> flowerbed = fill_vector_from_string(input_line);

    int n;
    std::cin >> n;

    Solution solution;
    std::cout << solution.canPlaceFlowers(flowerbed, n) << "\n";

    return 0;
};