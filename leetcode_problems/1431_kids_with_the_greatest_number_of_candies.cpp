#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"


using namespace utils;

class Solution
{
    public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        std::vector<bool> result;

        int maxCandies = *std::max_element(candies.begin(), candies.end());    // *, because it is an iterator

        for (const int& iCandies: candies)
            result.push_back(iCandies + extraCandies >= maxCandies);

        return result;
    };
};


int main()
{
    std::string input_line;
    std::getline(std::cin, input_line);
    std::vector<int> candies = fill_vector_from_string(input_line);

    int extraCandies;
    std::cin >> extraCandies;

    Solution solution;
    print_vector(solution.kidsWithCandies(candies, extraCandies));

    return 0;
};