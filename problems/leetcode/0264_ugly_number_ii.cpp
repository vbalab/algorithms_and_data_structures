#include <vector>
#include <climits>
#include <iostream>


class Solution {
public:
    int N_MAX = 1690;
    std::vector<int> prime_factors = { 2, 3, 5 };
    std::vector<int> ugly_numbers = { 1 };


    Solution () {
        this->precalculate();
    };


    void precalculate();

    int nthUglyNumber(int n);
};


void Solution::precalculate() {
    int n = this->N_MAX;

    std::vector<int> pointers(this->prime_factors.size(), 0);
    int min_pointer;
    int min_value;
    int value;


    while (n) {
        int i;
        min_value = INT_MAX;

        for (i = 0; i < pointers.size(); i++) {
            value = this->ugly_numbers[pointers[i]] * this->prime_factors[i];

            if (value < min_value) {
                min_pointer = i;
                min_value = value;
            };
        };

        pointers[min_pointer]++;

        if (min_value != this->ugly_numbers.back()) {
            this->ugly_numbers.push_back(min_value);
            n--;
        };
    };
};


int Solution::nthUglyNumber(int n) {
    return this->ugly_numbers[n - 1];
};


int main() {
    Solution solution = Solution();

    std::cout << solution.nthUglyNumber(1352) << '\n';


    return 0;
};
