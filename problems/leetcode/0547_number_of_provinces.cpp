#include <iostream>
#include <vector>

class Solution {
public:
    int32_t findCircleNum(std::vector<std::vector<int32_t>>& adj) {
        int32_t n_provinces = 0;
        std::vector<bool> visited(adj.size(), false);

        for (std::size_t i = 0; i < adj.size(); ++i) {
            if (!visited[i]) {
                BFS(adj, visited, i);
                ++n_provinces;
            }
        }

        return n_provinces;
    }

    void BFS(std::vector<std::vector<int32_t>>& adj, std::vector<bool>& visited, std::size_t index) {
        visited[index] = true;
        for (std::size_t i = 0; i < adj.size(); ++i) {
            if ((adj[index][i] == 1) && !visited[i]) {
                BFS(adj, visited, i);
            }
        }
    }
};
