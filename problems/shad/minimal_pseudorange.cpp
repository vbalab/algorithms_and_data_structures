#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>


double calculate_lambda(int s_max, int s_min, int a_max, int a_min) {
    return static_cast<double>(a_max - a_min) / static_cast<double>(s_max - s_min);
}


void solve(std::vector<int>& S) {

    int N = S.size();
    std::sort(S.begin(), S.end());
    
    double lambda_min;
    double lambda;
    int i_min = 0;
    int i = 0;
    int s_max = N - 1;
    int s_min = N / 2;


    lambda_min = calculate_lambda(S[s_max], S[s_min], S[i + N / 2], S[i]);

    for (i = 1; i + N / 2 < N; i++) {
        lambda = calculate_lambda(S[N - 1], S[0], S[i + N / 2 - 1], S[i]);

        if (lambda < lambda_min) {
            s_max = N - 1;
            s_min = 0;
            i_min = i;
            lambda_min = lambda;
        };
    };

    lambda = calculate_lambda(S[N / 2 - 1], S[0], S[i + N / 2 - 1], S[i]);

    if (lambda < lambda_min) {
        s_max = N / 2 - 1;
        s_min = 0;
        i_min = i;
        lambda_min = lambda;
    };


    std::cout << std::setprecision(10) << lambda_min << '\n';

    for (int i = i_min; i <= i_min + N / 2 - 1; i++)
        std::cout << S[i] << ' ';

    std::cout << '\n';

    return;
};


int main() {
    int n;
    std::cin >> n;

    int input;
    std::vector<int> S;
    while (n--) {
        std::cin >> input;
        S.push_back(input);
    }

    solve(S);

    return 0;
};
