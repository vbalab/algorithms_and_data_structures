#include <cstddef>
#include <cstdint>
#include <vector>

class Solution {
public:
    std::vector<int32_t> getAverages(std::vector<int32_t>& nums, int32_t k) {  // NOLINT
        if (k == 0) {
            return nums;
        }

        std::vector<int32_t> results(nums.size(), -1);

        const int64_t kSize = nums.size();
        const int64_t kSizeElems = 2 * k + 1;

        if (kSize < kSizeElems) {
            return results;
        }

        int64_t sum = 0;
        for (size_t i = 0; i < kSizeElems; ++i) {
            sum += nums[i];
        }

        for (size_t i = k; i < kSize - k - 1; ++i) {
            results[i] = sum / kSizeElems;
            sum -= nums[i - k];
            sum += nums[i + k + 1];
        }

        results[kSize - k - 1] = sum / kSizeElems;

        return results;
    }
};
