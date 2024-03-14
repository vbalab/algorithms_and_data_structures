#include <map>
#include <vector>
#include <iostream>
#include "../utils.h"


using namespace utils;


class Solution {
    public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {

    };
};


int main() {
    std::string input_line;


    std::getline(std::cin, input_line);
    std::vector<int> nums1 = fill_vector_from_string(input_line);


    std::getline(std::cin, input_line);
    std::vector<int> nums2 = fill_vector_from_string(input_line);

    Solution solution;
    print_vector(solution.findDifference(nums1, nums2));

    return 0;
};
