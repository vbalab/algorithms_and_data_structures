#include <vector>
#include <cstdint>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int32_t maxOperations(std::vector<int32_t>& nums, int32_t k) {
        int32_t count = 0;
        std::unordered_map<int32_t, int32_t> mapa;

        for (int32_t num: nums) {
            if (mapa.contains(k - num) && mapa[k - num] > 0) {
                ++count;
                --mapa[k - num];
            } else {
                ++mapa[num];
            }
        }

        return count;
    }
};
