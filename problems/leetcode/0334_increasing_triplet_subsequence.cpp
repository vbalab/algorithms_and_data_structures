#include <vector>
#include <string>
#include <iostream>
#include <limits.h>
#include "../utils.h"


using namespace utils;


class Solution
{
    public:
    bool increasingTriplet(std::vector<int>& nums)
    {
        int left = INT_MAX;
        int mid = INT_MAX;
        
        
        for(int i = 0; i < nums.size(); i ++)
        {
            if(nums[i] > mid)
            {
                return true;
            }
            else if(nums[i] > left && nums[i] < mid)
            {
                mid = nums[i];
            }
            else if(nums[i] < left)
            {
                left = nums[i];
            };

            // std::cout << "i: " << left << ", j: " << mid << ", k: " << nums[i] << '\n';
        }
        
        return false;
    }
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