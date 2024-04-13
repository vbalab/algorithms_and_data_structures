#include <iostream>


void solve(int n, int m, int k) {
    int max_pieces = (n / m);
    if (n % m > 0)
        max_pieces++;

    if (n - k <= max_pieces)
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
};


int main() {
    int t;
    std::cin >> t;

    int n;
    int m;
    int k;


    while (t--) {
        std::cin >> n >> m >> k;

        solve(n, m, k);
    };

    return 0;
};
