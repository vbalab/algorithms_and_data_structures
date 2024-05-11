#include <vector>
#include <iostream>


int calculate_plus(int M, int N, int i, int j, std::vector<std::vector<bool>>& matrix) {
    int plus = 1;

    for (int i_ = i + 1; i_ < M && matrix[i_][j]; i_++)
        plus++;
    for (int i_ = i - 1; i_ >= 0 && matrix[i_][j]; i_--)
        plus++;
    for (int j_ = j + 1; j_ < N && matrix[i][j_]; j_++)
        plus++;
    for (int j_ = j - 1; j_ >= 0 && matrix[i][j_]; j_--)
        plus++;

    return plus;
};


int solve(int M, int N, std::vector<std::vector<bool>>& matrix) {
    int plus;
    int max_plus = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1) {
                plus = calculate_plus(M, N, i, j, matrix);

                if (max_plus < plus)
                    max_plus = plus;
            };
        };
    };


    return max_plus;
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
