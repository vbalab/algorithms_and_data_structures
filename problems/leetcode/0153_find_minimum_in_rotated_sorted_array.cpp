#include <cstdint>
#include <vector>

class Solution {
public:
    int32_t findMin(const std::vector<int32_t>& nums) {
        size_t l = 0;
        size_t r = nums.size() - 1;

        while (l < r) {
            if (nums[l] < nums[r]) {
                return nums[l];
            }

            size_t m = l + (r - l) / 2;

            if (nums[l] <= nums[m]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return nums[l];
    }
};

int main() {
    std::vector<int32_t> vec{4, 5, 6, 7, 0, 1, 2};
    Solution s;
    s.findMin(vec);

    return 0;
}

// 3 4 0 1 2
