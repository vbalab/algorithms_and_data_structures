#include <iostream>
#include <vector>
#include "../utils.h"


using namespace utils;


// class Solution
// {
//     public:
//     void moveZeroes(std::vector<int>& nums)
//     {
//         int i = nums.size() - 1;
//         while (nums[i] == 0 & i > 0)
//             i--;

//         int j = i - 1;

//         while (j >= 0)
//         {
//             if (nums[j] == 0) {
//                 int k = j;

//                 while(k < i) {
//                     std::swap(nums[k], nums[k+1]);
//                     k++;
//                 };
//                 i--;
//             }
//             else {
//                 j--;
//             };
//         };
//     };
// };


class Solution
{
    public:
    void moveZeroes(std::vector<int>& nums)
    {
        int l = 0;
        int r = 1;

        while (r < nums.size())
        {
            if (nums[l] != 0) {
                l++;
            }
            else {
                std::swap(nums[l], nums[r]);
            };

            if (l==r) {
                r++;
            };
        };
    };
};


int main()
{
    std::string input_line;
    std::getline(std::cin, input_line);
    std::vector<int> nums = fill_vector_from_string(input_line);

    Solution solution;
    solution.moveZeroes(nums);

    print_vector(nums);

    return 0;
};