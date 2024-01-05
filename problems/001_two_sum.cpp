#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../utils.h"


using namespace utils;


// O(n), since map is O(1)
class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        std::unordered_map<int, int> m;
        // int length { static_cast<int>(nums.size()) };       

        for (std::size_t index{ 0 }; index < nums.size(); ++index) 
        {
            if (m.find(nums[index]) != m.end()) 
            {
                return {m[nums[index]], static_cast<int>(index)};
            };

            m[target - nums[index]] = index;
        };

        return {};
        };
};


int main() 
{
    int number;

    std::cout << "Array of nums: ";

    std::string input_line;
    std::getline(std::cin, input_line);

    std::vector<int> nums = fill_vector_from_string(input_line);
    print_vector(nums);

    int target;
    std::cout << "target value: ";
    std::cin >> target;


    Solution solution;
    std::vector<int> result { solution.twoSum(nums, target) };

    std::cout << "Result: ";
    print_vector(result);


    return 0;
}