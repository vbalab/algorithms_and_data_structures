#include <vector>
#include <iostream>
#include "../utils.h"


using namespace utils;


class Solution
{
    public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
    {
        int length = flowerbed.size();
        int left;
        int right;


        if (n > length / 2 + 1)
            return false;

        for (int i = 0; i < length; i++)
        {
            try {left = flowerbed.at(i - 1);}
            catch (std::out_of_range) {left = 0;}

            try {right = flowerbed.at(i + 1);}
            catch (std::out_of_range) {right = 0;}

            if (left == 0 and flowerbed[i] == 0 and right == 0)
            {
                flowerbed[i] = 1;
                n -= 1;
            }

            if (n <= 0)
                return true;
        };

        return false;
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