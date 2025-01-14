#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int64_t maxScore(std::vector<int32_t>& nums1, std::vector<int32_t>& nums2, int32_t k) {
        std::vector<std::pair<int64_t, int64_t>> nums(nums1.size());
        for (std::size_t i = 0; i < nums.size(); ++i) {
            nums[i] = {nums1[i], nums2[i]};
        }
        std::sort(nums.begin(), nums.end(), [](std::pair<int64_t, int64_t>& a, std::pair<int64_t, int64_t>& b) { return a.second > b.second;});

        std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> kernel;

        int64_t max = 0;
        int64_t sum = 0;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (kernel.size() == k) {
                sum -= kernel.top();
                kernel.pop();
            }

            sum += nums[i].first;
            kernel.push(nums[i].first);

            if (kernel.size() == k) {
                max = std::max(max, sum * nums[i].second);
            }
        }

        return max;
    }
};
