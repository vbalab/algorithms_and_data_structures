#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>


class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end());

        k--;
        while (k--) {
            std::pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        };
        

        return nums.front();
    };
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


    Solution solution;
    std::cout << solution.findKthLargest(v, 3);


    return 0;
};
