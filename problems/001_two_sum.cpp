#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>


template <typename T>
void print_vector(const std::vector<T> vect) {
    for (const auto& index : vect) {
        std::cout << index << " ";
    };
    std::cout << std::endl;
}


// O(n), since map is O(1)
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> m;
        int length { static_cast<int>(nums.size()) };            

        for (std::size_t index{ 0 }; index < length; ++index) {
            if (m.find(nums[index]) != m.end()) {
                return {m[nums[index]], static_cast<int>(index)};
            };

        m[target - nums[index]] = index;
        };

        return {};
        };
};


int main() {
    int number;
    std::vector<int> nums;
    std::string input_line;

    std::cout << "Array of nums: ";

    std::getline(std::cin, input_line);
    std::istringstream stream(input_line);
    while (stream >> number)
        nums.push_back(number);


    int target;
    std::cout << "target value: ";
    std::cin >> target;


    Solution solution;
    std::vector<int> result { solution.twoSum(nums, target) };

    std::cout << "Result: ";
    print_vector(result);


    return 0;
}