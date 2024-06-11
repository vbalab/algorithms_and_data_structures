#include <vector>
#include <iostream>
#include <unordered_map>


class Solution {
public:
    std::unordered_map<int, int> mem;

    int maximalAscendingSubsequence(std::vector<int>& v) {
        int max_n = 0;

        for (int i = 0; i < v.size(); i++)
            max_n = std::max(maximalAscendingSubsequence_(v, i), max_n);

        return max_n;
    };


    int maximalAscendingSubsequence_(std::vector<int>& v, int i_) {
        if (mem.find(i_) != mem.end())
            return mem[i_];


        int max_n = 1;

        for (int i = i_ + 1; i < v.size(); i++) {
            if (v[i_] < v[i]) {
                max_n = std::max(1 + maximalAscendingSubsequence_(v, i), max_n);
            };
        };


        mem[i_] = max_n;

        return max_n;
    };
};


int main() {
    std::vector<int> v = { 10, 4, 13, 5, 6, 17, 33, 11 };

    Solution s;
    std::cout << s.maximalAscendingSubsequence(v) << '\n';


    return 0;
};
