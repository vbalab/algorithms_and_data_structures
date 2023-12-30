#include <iostream>
#include <vector>
#include <string>
#include <map> 
#include <iterator>
#include <sstream>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;

        int length { static_cast<int>(nums.size()) };
            
        std::map<int, int> dictionary;
        
        for (std::size_t index{ 0 }; index < length; ++index) {
            if (nums[index] < target) {
                for(auto const& [key, val] : dictionary) {
                    if(val + nums[index] == target) {
                        result.insert(result.end(), {val, static_cast<int>(index)});
                        break;
                    }
                }

                dictionary[index] = nums[index];
            };

            if (static_cast<int>(nums.size()) > 0) break;
            };

        return result;
        }

        // smth


};

int main() {
    int number;
    std::vector<int> nums;
    std::string input_line;

    std::cout << "Array of nums:" << "\n";

    std::getline(std::cin, input_line);
    std::istringstream stream(input_line);
    while (stream >> number)
        nums.push_back(number);


    // std::vector<int> nums;
    // std::int input;
    // while (std::cin >> input) {
    //     if (not std::isdigit(input)) break;

    //     nums.push_back(input);
    // }


    // std::istream_iterator<int> begin(std::cin), end;
    // std::vector<int> nums(begin, end);


    int target;
    std::cout << "target value:" << "\n";
    std::cin >> target;


    Solution solution;
    std::vector<int> result { solution.twoSum(nums, target) };

    std::cout << "Result: \n";
    for (const auto& index : result) {
        std::cout << index << " ";
        }
    std::cout << std::endl;


    return 0;
}