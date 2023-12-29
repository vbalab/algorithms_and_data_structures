#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        for(const auto& arr_value: nums) {
            // smth
        }
        // smth


        return result;
    }
};

int main() {
    int input;

    std::vector<int> nums;
    std::cout << "Array of nums:" << "\n";
    while (std::cin >> input) {
        if (input == 0) {
            break;
            };
        nums.push_back(input);
    }


    int target;
    std::cout << "target value:" << "\n";
    std::cin >> target;


    Solution solution;

    std::vector<int> result { solution.twoSum(nums, target) };

    return 0;
}