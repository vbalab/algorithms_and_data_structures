#include <queue>
#include <vector>
#include <cstdint>
#include <iostream>

// class Solution {
// public:
//     int32_t longestOnes(const std::vector<int32_t>& nums, int32_t k) {
//         std::queue<int32_t> spans;

//         int32_t max = 0;
//         int32_t cur = 0;

//         std::size_t i = 0;

//         while (i < nums.size()) {
//             int32_t span = 0;
//             while (i < nums.size() && nums[i++] == 1) {
//                 ++span;
//             }

//             spans.push(span);
//             cur += span;

//             max = std::max(cur + static_cast<int32_t>(spans.size() - 1), max);

//             if (spans.size() > k) {
//                 cur -= spans.front();
//                 spans.pop();
//             }
//         }

//         return max;
//     }
// };

class Solution {
public:
    int32_t longestOnes(const std::vector<int32_t>& nums, int32_t k) {
        int32_t max = 0;

        int32_t l = 0;
        int32_t n_zeros = 0;

        for (int32_t r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) {
                ++n_zeros;

                while (n_zeros > k) {
                    if (nums[l] == 0) {
                       --n_zeros; 
                    }

                    ++l;
                }
            }

            max = std::max(max, r - l + 1);
        }

        return max;
    }
};
