#include <vector>
#include <iostream>


template <class T>
int print_matrix(std::vector<std::vector<T>>& m) {
    int sum = 0;

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            std::cout << m[i][j] << ' ';
        };
        std::cout << '\n';
    };

    return sum;
};


int calculate_x(int M, int N, int i, int j, std::vector<std::vector<bool>>& matrix) {
    int x = 1;

    int i_ = i;
    int j_ = j;
    while (++i_ < M && ++j_ < N && matrix[i_][j_])
        x++;

    i_ = i;
    j_ = j;
    while (--i_ >= 0 && ++j_ < N && matrix[i_][j_])
        x++;

    i_ = i;
    j_ = j;
    while (++i_ < M && --j_ >= 0 && matrix[i_][j_])
        x++;

    i_ = i;
    j_ = j;
    while (--i_ >= 0 && --j_ >= 0 && matrix[i_][j_])
        x++;

    return x;
};


int solve(int M, int N, std::vector<std::vector<bool>>& matrix) {
    int x;
    int max_x = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1) {
                x = calculate_x(M, N, i, j, matrix);

                if (max_x < x)
                    max_x = x;
            };
        };
    };


    return max_x;
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
