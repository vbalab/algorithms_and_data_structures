#include <iostream>
#include <vector>
#include <string>
#include "utils.h"


using namespace utils;
2 3 1 4;

class Solution
{
    public:
    bool increasingTriplet(std::vector<int>& nums)
    {
        int min = nums[0];
        int mean = nums[0];
        int max = nums[0];


        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < min)
            {
                mean = min;
                min = nums[i];
            };

            if (nums[i] > max)
            {
                mean = max;
                max = nums[i];
            };

            if (min < mean and mean < max)
                return true;
        }


        return false;
    };
};


int main()
{
    std::string input_line;
    std::getline(std::cin, input_line);
    
    std::vector<int> nums = fill_vector_from_string(input_line);


    Solution solution;
    std::cout << solution.increasingTriplet(nums);


    return 0;
};