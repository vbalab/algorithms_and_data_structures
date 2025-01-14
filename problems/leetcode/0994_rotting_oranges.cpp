#include <queue>
#include <iostream>

class Solution {
public:
    int32_t orangesRotting(std::vector<std::vector<int32_t>>& grid) {
        int32_t m = grid.size();
        int32_t n = grid[0].size();

        std::vector<Position> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        int32_t fresh_number = 0;
        std::queue<Position> rotten;
        for (std::size_t i = 0; i < m; ++i) {
            for (std::size_t j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++fresh_number;
                } else if (grid[i][j] == 2) {
                    rotten.push(Position(i, j));
                }
            }
        }

        if (fresh_number == 0) {
            return 0;
        }

        int32_t count = -1;
        while (rotten.size() > 0) {
            ++count;
            int32_t size = rotten.size();

            while (size--) {
                Position pos = rotten.front();
                rotten.pop();

                for (const Position& move: moves) {
                    Position new_pos = pos + move;

                    if ((new_pos.i >= 0) && 
                        (new_pos.j >= 0) && 
                        (new_pos.i < m) && 
                        (new_pos.j < n) && 
                        (grid[new_pos.i][new_pos.j] == 1)) {
                        --fresh_number;
                        rotten.push(new_pos);
                        grid[new_pos.i][new_pos.j] = 2;
                    }
                }
            }
        }

        if (fresh_number > 0) {
            return -1;
        }

        return count;
    }

private:
    struct Position {
        int32_t i;
        int32_t j;

        Position(int32_t x, int32_t y) : i(x), j(y) {}

        Position operator+(const Position& other) const {
            return {i + other.i, j + other.j};
        }
    };
};
