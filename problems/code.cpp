#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        for(const auto& arr_value: nums) {
            std::cout << arr_value;
        }
        return result;
    }
};

int main() {
    int input;

    std::vector<int> nums;
    std::cout << "Array of nums:" << "\n";
    while (std::cin >> input) {
        nums.push_back(input);
    }


    int target;
    std::cout << "target value:";
    std::cin >> target;


    Solution solution;

    std::vector<int> result { solution.twoSum(nums, target) };

    return 0;
}