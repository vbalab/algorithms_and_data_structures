#include <cstdint>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int32_t subarraySum(std::vector<int32_t>& nums, int k) {
        if (nums.size() == 1) {
            return nums[0] == k;
        }

        for (size_t i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }

        int32_t answer = 0;
        std::unordered_map<int32_t, int32_t> sums;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == k) {
                ++answer;
            }

            answer += sums[nums[i] - k];
            ++sums[nums[i]];
        }

        return answer;
    }
};

int main() {
    std::vector<int32_t> nums{-1, -1, 1};
    Solution s;

    s.subarraySum(nums, 0);

    return 0;
}