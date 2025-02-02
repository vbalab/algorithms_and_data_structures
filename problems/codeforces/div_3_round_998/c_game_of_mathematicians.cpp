#include <vector>
#include <cstdint>
#include <iostream>
#include <unordered_map>

int32_t FindNSumEqual(std::vector<int32_t>& nums, int32_t k) {
    int32_t count = 0;

    std::unordered_map<int32_t, int32_t> map;

    for (int32_t num: nums) {
        ++map[num];
    }

    for (int32_t num: nums) {
        if (map[k - num] > 0) {
            --map[k - num];
            ++count;
        }
    }

    return count / 2;
}

int main() {
    int32_t t;
    std::cin >> t;

    while (t--) {
        int32_t n;
        int32_t k;
        std::cin >> n >> k;

        std::vector<int32_t> nums(n);
        for (std::size_t i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        std::cout << FindNSumEqual(nums, k) << std::endl;
    }

    return 0;
}