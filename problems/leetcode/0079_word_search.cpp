#include <string>
#include <vector>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string& word) {
        if (word.empty()) {
            return true;
        }

        size_t m = board.size();
        if (m == 0) {
            return false;
        }

        size_t n = board[0].size();
        if (n == 0) {
            return false;
        }

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board, size_t i, size_t j,
             std::string& word, size_t index) {
        if (board[i][j] != word[index]) {
            return false;
        }

        if (index == word.size() - 1) {
            return true;
        }

        size_t m = board.size();
        size_t n = board[0].size();

        char symbol = board[i][j];
        board[i][j] = '#';

        if (i > 0 && dfs(board, i - 1, j, word, index + 1)) {
            return true;
        }

        if (j > 0 && dfs(board, i, j - 1, word, index + 1)) {
            return true;
        }

        if (i < m - 1 && dfs(board, i + 1, j, word, index + 1)) {
            return true;
        }

        if (j < n - 1 && dfs(board, i, j + 1, word, index + 1)) {
            return true;
        }

        board[i][j] = symbol;
        return false;
    }
};
