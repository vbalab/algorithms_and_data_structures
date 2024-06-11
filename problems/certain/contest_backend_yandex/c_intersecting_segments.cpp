#include <vector>
#include <iostream>
#include <algorithm>


int solve(std::vector<std::vector<int>>& ab, int N) {
    std::sort(ab.begin(), ab.end());


    std::vector<int> a(2 * N + 1, 0);
    for (int i = 1; i < 2 * N + 1; i++) {
        a[i] = a[i - 1];
        for (int j = 0; j < N && ab[j][0] <= i; j++)
            a[i] = std::max(a[i], ab[j][1]);
    };


    std::sort(
        ab.begin(), 
        ab.end(),
        [](const std::vector<int>& v1, const std::vector<int>& v2) { return v1[1] < v2[1]; }
    );

    std::vector<int> b(2 * N + 1, 0);
    for (int i = 1; i < 2 * N + 1; i++) {
        b[i] = b[i - 1];
        for (int j = 0; j < N && ab[j][1] <= i; j++)
            b[i] = std::max(b[i], ab[j][0]);
    };


    int nonoverlapping = 0;
    for (int i = 0; i < N; i++) {
        if (a[ab[i][0] - 1] < ab[i][1] && b[ab[i][1] - 1] < ab[i][0])
            nonoverlapping++;
    };

    return nonoverlapping;
};


int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> ab(N, std::vector<int> (2));

    for (int i = 0; i < N; i++) 
        std::cin >> ab[i][0] >> ab[i][1];

    std::cout << solve(ab, N) << "\n";

    return 0; 
};
