#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

std::vector<std::size_t> FindPermutation(std::vector<std::vector<int32_t>>& cowscards) {
    std::size_t n = cowscards.size();
    std::size_t m = cowscards[0].size();

    for (std::vector<int32_t>& cards: cowscards) {
        std::sort(cards.begin(), cards.end());
    }

    std::vector<std::size_t> order(n);
    for (std::size_t i = 0; i < order.size(); ++i) {
        order[i] = i;
    }

    std::sort(order.begin(), order.end(), [&](int32_t a, int32_t b) {
        return cowscards[a][0] < cowscards[b][0];
    });

    int32_t before = cowscards[order[0]][0];
    for (std::size_t j = 0; j < m; ++j) {
        for (std::size_t i = 0; i < n; ++i) {
            int32_t now = cowscards[order[i]][j];
            if (now < before) {
                return {};
            }
            before = now;
        }
    }

    return order;
}

int main() {
    int32_t t;
    std::cin >> t;

    while (t--) {
        std::size_t n;
        std::size_t m;
        std::cin >> n >> m;

        std::vector<std::vector<int32_t>> cowscards(n, std::vector<int32_t>(m));

        for (std::size_t i = 0; i < n; ++i) {
            for (std::size_t j = 0; j < m; ++j) {
                std::cin >> cowscards[i][j];
            }
        }

        std::vector<std::size_t> permut = FindPermutation(cowscards);

        if (permut.empty()) {
            std::cout << -1;
        } else {
            for (const std::size_t p: permut) {
                std::cout << p + 1 << ' ';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}