#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>


class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> nums_new (nums.size());
        int l = 0;
        int r = nums.size() - 1;


        int i = nums.size() - 1;
        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r]))
                nums_new[i--] = std::pow(nums[l++], 2);
            else
                nums_new[i--] = std::pow(nums[r--], 2);
        }

        return nums_new;
    }
};


int main() {
    int input;
    std::string input_line;
    std::istringstream stream;
    std::vector<int> v;


    std::getline(std::cin, input_line);

    stream.str(input_line);

    while (stream >> input)
        v.push_back(input);


    Solution s;

    for (const int& num: s.sortedSquares(v))
        std::cout << num << ' ';
    std::cout << '\n';


    return 0;
};
