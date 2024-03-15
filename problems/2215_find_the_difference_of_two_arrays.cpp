// #include <set>
#include <unordered_set>
#include <vector>
#include <iostream>
#include "../utils.h"


using namespace utils;


class Solution {
    public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<std::vector<int>> answer(2);


        std::unordered_set<int> set1;
        for (int& num: nums1)
            set1.insert(num);

        std::unordered_set<int> set2;
        for (int& num: nums2)
            set2.insert(num);


        for (auto& num1: set1) {
            if (set2.count(num1) == 0)
                answer[0].push_back(num1);
        };

        for (auto& num2: set2) {
            if (set1.count(num2) == 0)
                answer[1].push_back(num2);
        };


        return answer;
    };
};


int main() {
    std::string input_line;


    std::getline(std::cin, input_line);
    std::vector<int> nums1 = fill_vector_from_string(input_line);


    std::getline(std::cin, input_line);
    std::vector<int> nums2 = fill_vector_from_string(input_line);

    Solution solution;

    std::vector<std::vector<int>> answer = solution.findDifference(nums1, nums2);
    print_vector(answer[0]);
    print_vector(answer[1]);

    return 0;
};
