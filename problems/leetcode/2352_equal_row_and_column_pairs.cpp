#include <map>
#include <vector>
#include <cstdint>
#include <iostream>

class Solution {
public:
    int32_t equalPairs(std::vector<std::vector<int32_t>>& grid) {
        std::size_t n = grid.size();
        int32_t count = 0;

        std::map<std::vector<int32_t>, int32_t> mapa;

        for (const std::vector<int32_t>& vec: grid) {
            ++mapa[vec];
        }

        for (std::size_t i = 0; i < n; ++i) {
            std::vector<int32_t> vec(n);

            for (std::size_t j = 0; j < n; ++j) {
                vec[j] = grid[j][i];
            }

            count += mapa[vec];
        }

        return count;
    }
};
