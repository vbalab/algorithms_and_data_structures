#include <vector>
#include <bitset>
#include <iostream>


class Solution {
public:
    // std::vector<int> countBits(int n) {
    //     std::vector<int> ans;
    //     int count;

    //     for (int i = 0; i <= n; i++) {
    //         count = 0;
    //         for (int j = 0; j < sizeof(int) * 8; j++)
    //             count += static_cast<int>((i & (1 << j)) != 0);

    //         ans.push_back(count);
    //     };

    //     return ans;
    // };


std::vector<int> countBits(int n) {
        std::vector<int> ans(n+1);
        std::bitset<32> bits;

        for (int i = 0; i <= n; i++) {
            bits = i;
            ans[i] = bits.count();
        };

        return ans;
    };
};


int main() {
    int n;
    std::cin >> n;


    Solution solution;

    for (int i: solution.countBits(n))
        std::cout << i << ' ';
    std::cout << '\n';


    return 0;
};