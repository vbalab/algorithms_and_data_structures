#include <vector>
#include <iostream>


int calculate_near(int M, int N, int i, int j, std::vector<std::vector<bool>>& matrix) {
    int n = 0;

    if (i > 0)
        n += matrix[i - 1][j];
    if (i < M - 1)
        n += matrix[i + 1][j];
    if (j > 0)
        n += matrix[i][j - 1];
    if (j < N - 1)
        n += matrix[i][j + 1];

    return n;
};


int calculate_t(int M, int N, int i, int j, std::vector<std::vector<bool>>& matrix) {
    int t = 1;

    for (int i_ = i + 1; i_ < M && matrix[i_][j]; i_++)
        t++;
    for (int i_ = i - 1; i_ > 0 && matrix[i_][j]; i_--)
        t++;
    for (int j_ = j + 1; j_ < N && matrix[i][j_]; j_++)
        t++;
    for (int j_ = j - 1; j_ > 0 && matrix[i][j_]; j_--)
        t++;

    return t;
};


int solve(int M, int N, std::vector<std::vector<bool>>& matrix) {
    int t;
    int max_t = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1 && calculate_near(M, N, i, j, matrix) <= 3) {
                t = calculate_t(M, N, i, j, matrix);

                if (max_t < t)
                    max_t = t;
            };
        };
    };


    return max_t;
};


int main() {
    int M;
    int N;
    std::cin >> M >> N;

    int input;
    std::vector<std::vector<bool>> matrix(M, std::vector<bool>(N));


    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> input;
            matrix[i][j] = input;
        };
    };

    std::cout << solve(M, N, matrix) << '\n';


    return 0;
};
