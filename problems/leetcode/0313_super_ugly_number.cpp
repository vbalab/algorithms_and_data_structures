#include <vector>
#include <vector>
#include <climits>
#include <iostream>


class Solution {
public:
    std::vector<long long> ugly_numbers = { 1 };


    void precalculate(int n, std::vector<int>& primes);

    long long nthSuperUglyNumber(int n, std::vector<int>& primes);
};


void Solution::precalculate(int n, std::vector<int>& primes) {
    std::vector<int> pointers(primes.size(), 0);
    int min_pointer;
    long long min_value;
    long long value;


    while (n) {
        int i;
        min_value = INT_MAX;

        for (i = 0; i < pointers.size(); i++) {
            value = this->ugly_numbers[pointers[i]] * primes[i];

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


long long Solution::nthSuperUglyNumber(int n, std::vector<int>& primes) {
    precalculate(n, primes);

    return this->ugly_numbers[n - 1];
};


int main() {
    Solution solution = Solution();

    std::vector<int> primes = { 3, 7, 13, 19 };
    std::cout << solution.nthSuperUglyNumber(123, primes) << '\n';


    return 0;
};
