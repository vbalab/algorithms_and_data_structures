#include <iostream>
#include <vector>
#include <cstdint>

// class Solution {
// public:
//     std::vector<std::vector<int32_t>> dp = std::vector<std::vector<int32_t>>(101, std::vector<int32_t>(101, -1));

//     int32_t uniquePaths(int32_t m, int32_t n) {
//         if (m == 1 && n == 1) {
//             return 1;
//         }

//         if (m < 1 || n < 1) {
//             return 0;
//         }

//         if (dp[m][n] >= 0) {
//             return dp[m][n];
//         }

//         dp[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);

//         return dp[m][n];
//     }
// };

// class Solution {
// public:
//     int32_t uniquePaths(int32_t m, int32_t n) {
//         std::vector<std::vector<int32_t>> dp(m, std::vector<int32_t>(n, 1));

//         for (std::size_t i = 1; i < m; ++i) {
//             for (std::size_t j = 1; j < n; ++j) {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }

//         return dp[m - 1][n - 1];
//     }
// };

class Solution {
public: 
    int32_t uniquePaths(int32_t m, int32_t n) {
        std::vector<int32_t> dp(n, 1);

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};
