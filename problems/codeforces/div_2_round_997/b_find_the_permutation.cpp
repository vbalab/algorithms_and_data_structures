#include <vector>
#include <string>
#include <cstdint>
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int32_t t;
    std::cin >> t;

    while (t--) {
        int32_t n;
        std::cin >> n;

        std::vector<std::vector<int32_t>> mat(n, std::vector<int32_t>(n));

        for (std::size_t i = 0; i < n; ++i) {
            std::string line;
            std::cin >> line;

            for (std::size_t j = 0; j < n; ++j) {
                mat[i][j] = static_cast<int32_t>(line[j] == '1');
            }
        }
        auto comp = [&mat](int32_t i, int32_t j) {
            if (i < j) {
                return mat[i - 1][j - 1] == 1;
            }
            return mat[i - 1][j - 1] == 0;
        };

        std::vector<int32_t> vec(n);
        for (std::size_t i = 0; i < n; ++i) {
            vec[i] = i + 1;
        }

        std::sort(vec.begin(), vec.end(), comp);

        for (std::size_t i = 0; i < n; ++i) {
            std::cout << vec[i] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}