#include <string>
#include <vector>
#include <sstream>
#include <iostream>


/*
We apply the extended version of this gate in our bitwise XOR operator.
    A^A=0
    A^B^A=B
    (A^A^B) = (B^A^A) = (A^B^A) = B                 (This shows that position doesn't matter.)
*/


class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ans = 0;
        for (int num: nums)
            ans ^= num;

        return ans;
    };
};


int main() {
    std::string input_line;
    std::getline(std::cin, input_line);

    std::istringstream stream;
    stream.str(input_line);


    std::vector<int> nums;
    int input;
    while (stream >> input)
            nums.push_back(input);
    
    Solution solution;
    std::cout << solution.singleNumber(nums) << '\n';


    return 0;
};