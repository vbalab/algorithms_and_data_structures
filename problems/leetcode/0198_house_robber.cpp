#include <iostream>
#include <vector>

class Solution {
public:
    int32_t rob(std::vector<int32_t>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        std::vector<int32_t> dp = nums;     // could've worked solely with nums.

        int32_t size = dp.size();

        for (int32_t i = size - 1; i >= 0; --i) {
            int32_t choice = 0;
            int32_t upto = std::min(i + 4, size);

            for (int32_t j = i + 2; j < upto;  ++j) {
                choice = std::max(choice, dp[j]);
            }

            dp[i] += choice;
        }

        if (dp[0] < dp[1]) {
            return dp[1];
        }
        return dp[0];
    }
};

int main() {
    return 0;
}