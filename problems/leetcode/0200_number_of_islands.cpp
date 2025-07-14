#include <cstdint>
#include <queue>
#include <vector>

class Solution {
public:
    int32_t numIslands(std::vector<std::vector<char>>& grid) const {
        if (grid.size() == 0 || grid[0].empty()) {
            return 0;
        }

        const size_t nrows = grid.size();
        const size_t ncols = grid[0].size();

        int32_t count = 0;

        for (size_t i = 0; i < nrows; ++i) {
            for (size_t j = 0; j < ncols; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }

                ++count;
                Discover(grid, i, j, nrows, ncols);
            }
        }

        return count;
    }

private:
    void Discover(std::vector<std::vector<char>>& grid, size_t row, size_t col,
                  size_t nrows, size_t ncols) const {
        std::queue<std::pair<size_t, size_t>> que;
        que.emplace(row, col);

        grid[row][col] = '0';

        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();

            if (i > 0 && grid[i - 1][j] == '1') {
                que.emplace(i - 1, j);
                grid[i - 1][j] = '0';
            }
            if (j > 0 && grid[i][j - 1] == '1') {
                que.emplace(i, j - 1);
                grid[i][j - 1] = '0';
            }
            if (i < nrows - 1 && grid[i + 1][j] == '1') {
                que.emplace(i + 1, j);
                grid[i + 1][j] = '0';
            }
            if (j < ncols - 1 && grid[i][j + 1] == '1') {
                que.emplace(i, j + 1);
                grid[i][j + 1] = '0';
            }
        }
    }
};
