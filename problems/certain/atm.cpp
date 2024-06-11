#include <vector>
#include <iostream>
#include <unordered_map>


class Solution {
public:
    std::unordered_map<int, int> n_to_sum;

    int minBanknotesNumber(std::vector<int>& banknotes, int sum) {
        if (n_to_sum.find(sum) != n_to_sum.end())
            return n_to_sum[sum];


        int min = __INT_MAX__ - 1;
        int n;

        for (int b: banknotes) {
            if (sum - b < 0)
                return __INT_MAX__ - 1;
            else if (sum - b == 0)
                return 1;
            else
                min = std::min(1 + minBanknotesNumber(banknotes, sum - b), min);
        }

        n_to_sum[sum] = min;
        return min;
    };
};


int main() {
    std::vector<int> b = { 1, 6, 10 };

    Solution s;
    std::cout << s.minBanknotesNumber(b, 12313) << '\n';


    return 0;
};
