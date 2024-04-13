#include <vector>
#include <iostream>


int matrix_sum(std::vector<std::vector<int>> m) {
    int sum = 0;

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            sum += m[i][j];
        };
    };

    return sum;
};


int print_matrix(std::vector<std::vector<int>> m) {
    int sum = 0;

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            std::cout << m[i][j] << ' ';
        };
        std::cout << '\n';
    };

    return sum;
};


void solve(int n) {
    int count = 0;
    int p;
    int n2 = n;
    std::vector<std::vector<int>> m(n, std::vector<int>(n));

    while (n2) {
        for (int i = 0; i < n2; i++) {
            count++;
            p = 1;

            for (int j = 0; j < n; j++) {
                m[i][j] = p++;
            };
        };

        n2 = n2 / 2;

        if (n2) {
            for (int j = 0; j < n2; j++) {
                count++;
                p = 1;

                for (int i = 0; i < n; i++) {
                    m[i][j] = p++;
                };
            };
        };
        n2 = n2 / 2;
    };

    print_matrix(m);
    std::cout << matrix_sum(m) << ' ' << count;
};


int main() {
    int t;
    std::cin >> t;

    int n;

    while (t--) {
        std::cin >> n;

        solve(n);
    };
    return 0;
};