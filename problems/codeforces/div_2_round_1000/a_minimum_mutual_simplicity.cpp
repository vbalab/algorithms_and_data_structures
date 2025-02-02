#include <cstdint>
#include <numeric>
#include <iostream>

int main() {
    int32_t t;
    std::cin >> t;

    while (t--) {
        int64_t l;
        int64_t r;
        std::cin >> l >> r;

        // int64_t count = 0;

        // if (l == 1 && l != r) {
        //     ++count;
        //     ++l;
        // }

        // for (int64_t m = l; m <= r; ++m) {
        //     if (std::gcd(l, m) == 1) {
        //         ++count;
        //         l = m;
        //     }
        // }

        // std::cout << count << '\n';

        if (l == r && l == 1) {
            std::cout << r - l + 1 << '\n';
        } else {
            std::cout << r - l<< '\n';
        }
    }

    return 0;
}
