#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int32_t nearestExit(std::vector<std::vector<char>>& maze, std::vector<int32_t>& entrance) {
        const int32_t m = maze.size();
        const int32_t n = maze[0].size();

        const std::vector<std::pair<int32_t, int32_t>> moves = {{0,-1},{-1,0},{0,1},{1,0}};

        std::queue<std::pair<int32_t, int32_t>> positions;
        positions.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int32_t count = 0;
        while (!positions.empty()) {
            ++count;

            int32_t size = positions.size();

            while (size--) {
                int32_t x_orig = positions.front().first;
                int32_t y_orig = positions.front().second;
                positions.pop();

                for (const std::pair<int32_t, int32_t>& move: moves) {
                    int32_t x = x_orig + move.first;
                    int32_t y = y_orig + move.second;

                    if (x < 0 || x >= m|| y < 0 || y >= n || maze[x][y] == '+') {
                        continue;
                    }

                    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                        return count;
                    }

                    positions.push({x, y});
                    maze[x][y] = '+';
                }
            }
        }

        return -1;
    }
};
