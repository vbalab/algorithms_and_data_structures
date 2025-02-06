#include <vector>
#include <cstdint>
#include <iostream>

class Solution {
public:
    int32_t longestSubarray(const std::vector<int32_t>& nums) {
        int32_t max = 0;
        int32_t span1 = 0;
        int32_t span2 = 0;

        std::size_t i = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                span1 = span2;
                span2 = 0;
            } else {
                ++span2;
            }

            max = std::max(max, span1 + span2);
            ++i;
        }

        if (max == nums.size()) {
            return max - 1;
        }

        return max;
    }
};
