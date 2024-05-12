#include <vector>
#include <iostream>


int solve(int M, int N, std::vector<std::vector<bool>>& matrix) {
    std::vector<std::vector<int>> result(M, std::vector<int>(N, 0));
    std::vector<std::vector<std::vector<int>>> dp(M, std::vector<std::vector<int>>(N, std::vector<int>(3, 0)));


    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || j == 0 || !matrix[i][j])
                dp[i][j][0] == 0;
            else {
                if (!matrix[i - 1][j - 1])
                    dp[i][j][0] = 0;
                else
                    dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
            };
        };
    };


    for (int i = 0; i < M; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (i == 0 || j == N - 1 || !matrix[i][j])
                dp[i][j][1] == 0;
            else {
                if (!matrix[i - 1][j + 1])
                    dp[i][j][1] = 0;
                else
                    dp[i][j][1] = dp[i - 1][j + 1][1] + 1;
            };
        };
    };


    for (int i = M - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (i == M - 1 || j == 0 || !matrix[i][j])
                dp[i][j][2] == 0;
            else {
                if (!matrix[i + 1][j - 1])
                    dp[i][j][2] = 0;
                else
                    dp[i][j][2] = dp[i + 1][j - 1][2] + 1;
            };
        };
    };


    int y;
    int max_y = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] && (i == M - 1 || j == N - 1 || !matrix[i + 1][j + 1])) {
                result[i][j] = 1 + dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
                

                y = 1 + dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
                
                if (max_y < y)
                    max_y = y;
            };
        };
    };


    return max_y;
};


int main() {
    int M;
    int N;
    std::cin >> M >> N;

    char input;
    std::vector<std::vector<bool>> matrix(M, std::vector<bool>(N));


    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> input;
            matrix[i][j] = input == '1';
        };
    };

    std::cout << solve(M, N, matrix) << '\n';


    return 0;
};
