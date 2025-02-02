#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

int main () {
    int32_t t;
    std::cin >> t;

    while (t--) {
        std::size_t n;
        std::size_t l;
        std::size_t r;
        std::cin >> n >> l >> r;
        --l;
        --r;

        std::vector<int32_t> vec(n);
        for (std::size_t i = 0; i < n; ++i) {
            std::cin >> vec[i];
        }

        std::sort(vec.begin(), vec.begin() + l);
        std::sort(vec.begin() + l, vec.begin() + r + 1);
        std::sort(vec.begin() + r + 1, vec.end());

        int32_t default_sum = 0;
        for (std::size_t i = l; i <= r; ++i) {
            default_sum += vec[i];
        }

        std::size_t i;
        std::size_t j;

        i = 0;
        j = r;
        int32_t sum_left = default_sum;

        while (i < l && j >= l) {
            int32_t diff = vec[j--] - vec[i++];

            if (diff <= 0) {
                break;
            }

            sum_left -= diff;
        }

        i = r + 1;
        j = r;
        int32_t sum_right = default_sum;

        while (i < n && j >= l) {
            int32_t diff = vec[j--] - vec[i++];

            if (diff <= 0) {
                break;
            }

            sum_right -= diff;
        }

        std::cout << std::min(sum_left, sum_right) << '\n';
    }

    return 0;
}