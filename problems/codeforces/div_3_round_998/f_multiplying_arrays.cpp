#include <cmath>
#include <cstdint>
#include <iostream>
#include <unordered_map>

constexpr int64_t kModulo = 998244353;

std::unordered_map<int64_t, int64_t> FindPrimeFactors(int64_t number) {
    std::unordered_map<int64_t, int64_t> primeCounts;

    // Handle 2 as a special case (even numbers)
    while (number % 2 == 0) {
        primeCounts[2]++;
        number /= 2;
    }

    // Check odd numbers up to sqrt(number)
    for (int64_t i = 3; i <= std::sqrt(number); i += 2) {
        while (number % i == 0) {
            primeCounts[i]++;
            number /= i;
        }
    }

    // If the remaining number is greater than 2, it is a prime factor
    if (number > 2) {
        primeCounts[number] = 1;
    }

    return primeCounts;
}

int64_t Helper(std::unordered_map<int64_t, int64_t> nums, int64_t len, int64_t n) {
    while (len < n) {

    }
}

int64_t FindNumberOfUniqueArrays(int64_t k, int64_t n) {
    int64_t count = 0;
    for (int64_t x = 1; x <= k; ++x) {
        std::unordered_map<int64_t, int64_t> primes = FindPrimeFactors(x);

        int64_t len = 0;
        for (const auto& [key, val]: primes) {
            len += val;
        }

        count += Helper(primes, len, n) % kModulo;
        count %= count;
    }

    return count;
}

int main() {
    int32_t t;
    std::cin >> t;

    while (t--) {
        int64_t k;
        int64_t n;
        std::cin >> k >> n;

        std::cout << FindNumberOfUniqueArrays(k, n) << '\n';
    }

    return 0;
}