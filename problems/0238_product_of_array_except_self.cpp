#include <iostream>
#include <vector>
#include "../utils.h"


using namespace utils;


class Solution
{
    public:
    std::vector<int> productExceptSelf(std::vector<int> nums)
    {
        int length = nums.size();
        std::vector<int> pref1(length);
        std::vector<int> pref2(length);
        std::vector<int> answer(length);


        pref1[0] = 1;
        for (int i = 1; i < length; i++)
            pref1[i] = pref1[i - 1] * nums[i - 1];


        pref2[0] = 1;
        for (int i = 1; i < length; i++)
            pref2[i] = pref2[i - 1] * nums[length - i];



        for (int i = 0; i < length; i++)
            answer[i] = pref1[i] * pref2[length - i - 1];


        return answer;
    };
};


int main()
{
    std::string input_line;
    std::getline(std::cin, input_line);

    std::vector<int> nums = fill_vector_from_string(input_line);


    Solution solution;
    print_vector(solution.productExceptSelf(nums));


    return 0;
};