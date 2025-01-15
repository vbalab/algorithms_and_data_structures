#include <vector>
#include <iostream>

class Solution {
public:
    int32_t findPeakElement(const std::vector<int32_t>& nums) {
        int32_t l = 0;
        int32_t r = nums.size() - 1;

        while (l < r) {
            int32_t m = l + (r - l) / 2;

            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }
};
