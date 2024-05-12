#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>


double calculate_lambda(int k_min, int k_max) {
    return 1 - static_cast<double>(k_min) / static_cast<double>(k_max);
}


void solve(std::vector<int>& A, int K) {
    int N = A.size();
    std::sort(A.begin(), A.end());

    double lambda_min = __INT_MAX__;
    double lambda;
    int i_min = 0;

    for (int i = 0; i + K <= N; i++) {
        lambda = calculate_lambda(A[i], A[i + K - 1]);

        if (lambda < lambda_min) {
            i_min = i;
            lambda_min = lambda;
        };
    };


    std::cout << std::setprecision(10) << lambda_min << '\n';

    for (int i = i_min; i - i_min < K; i++)
        std::cout << A[i] << ' ';
    std::cout << '\n';

    return;
};


int main() {
    int n;
    int k;
    std::cin >> n >> k;

    int input;
    std::vector<int> A;
    while (n--) {
        std::cin >> input;
        A.push_back(input);
    }

    solve(A, k);

    return 0;
};
