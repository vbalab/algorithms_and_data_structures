#include <iostream>


class Solution {
public:
    // using tabulation
    int tribonacci(int n) {
        int t[n + 1];

        t[0] = 0;
        t[1] = 1;
        t[2] = 1;

        for (int i = 3; i <= n; i++)
            t[i] = t[i - 1] + t[i - 2] + t[i - 3];


        return t[n];
    };
};


int main() {
    Solution s;

    std::cout << s.tribonacci(1) << '\n';


    return 0;
};
