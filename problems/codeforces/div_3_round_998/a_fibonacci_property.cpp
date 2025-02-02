#include <vector>
#include <cstdint>
#include <iostream>
#include <unordered_map>

int main () {
    int32_t t;
    std::cin >> t;

    while (t--) {
        int32_t a_1;
        int32_t a_2;
        int32_t a_4;
        int32_t a_5;
        std::cin >> a_1 >> a_2 >> a_4 >> a_5;

        int32_t max = 0;

        std::unordered_map<int32_t, int32_t> map;

        ++map[a_1 + a_2];
        ++map[a_4 - a_2];
        ++map[a_5 - a_4];

        for (const auto& [key, val]: map) {
            max = std::max(max, val);
        }

        std::cout << max << std::endl;
    }

    return 0;
}
