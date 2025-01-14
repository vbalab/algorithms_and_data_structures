#include <iostream>
#include <vector>

// class Solution {
// public:
//     int32_t maxArea(std::vector<int32_t>& height) {
//         std::vector<int32_t> left;
//         std::vector<int32_t> right;

//         int32_t max = 0;
//         for (int32_t i = 0; i < height.size(); ++i) {
//             if (height[i] > max) {
//                 left.push_back(i);
//                 max = height[i];
//             }
//         }

//         max = 0;
//         for (int32_t i = height.size() - 1; i >= 0; --i) {
//             if (height[i] > max) {
//                 right.push_back(i);
//                 max = height[i];
//             }
//         }

//         int32_t most = 0;
//         for (int32_t l: left) {
//             for (int32_t r: right) {
//                 if (l >= r) {
//                     break;
//                 }

//                 most = std::max(most, (r - l) * std::min(height[l], height[r]));
//             }
//         }

//         return most;
//     }
// };

class Solution {
public:
    int32_t maxArea(std::vector<int32_t>& height) {
        int32_t n = height.size();
        int32_t l = 0;
        int32_t r = n - 1;

        int32_t most = 0;

        while (l < r) {
            most = std::max(most, (r - l) * std::min(height[l], height[r]));

            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return most;
    }
};
