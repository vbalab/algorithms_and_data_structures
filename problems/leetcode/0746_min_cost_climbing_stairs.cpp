#include <iostream>
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> dp = cost;

        for (int32_t i = cost.size() - 3; i >= 0; --i) {
            dp[i] += std::min(dp[i + 1], dp[i + 2]);
        }

        if (dp[0] < dp[1]) {
            return dp[0];
        }
        return dp[1];
    };
};


int main() {
    std::vector<int> v1 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::vector<int> v2 = {0, 1, 2, 2};
    std::vector<int> v3 = {0, 2, 2, 1};

    Solution s;

    std::cout << s.minCostClimbingStairs(v3) << '\n';

    return 0;
};
