#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>


template <typename T>
void print_vector(const std::vector<T> vect) 
{
    for (const auto& index : vect) 
    {
        std::cout << index << " ";
    };
    std::cout << std::endl;
}


template <typename T>
std::vector<T> fillvector(std::vector<T> vect)
{
    int input;
    std::string input_line;

    std::getline(std::cin, input_line);
    std::istringstream stream(input_line);

    while (stream >> input)
        {
            vect.push_back(input);
        };

    return vect;
}


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
    std::vector<int> nums;

    std::cout << "Array of nums: ";
    nums = fillvector(nums);
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