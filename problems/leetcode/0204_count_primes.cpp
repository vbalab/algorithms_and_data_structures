#include <vector>
#include <cstdint>
#include <iostream>

// Sieve Of Eratosthenes
class Solution {
public:
    int32_t countPrimes(int32_t n) {
        if (n <= 1) {
            return 0;
        }

        std::vector<bool> prime(n, true);
        int32_t count = 0;

        for (std::size_t i = 2; i < n; ++i) {
            if (prime[i]) {
                ++count;

                for (std::size_t j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        return count;
    }
};
