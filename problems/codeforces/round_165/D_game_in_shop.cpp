#include <vector>
#include <iostream>
#include <algorithm>


int solve(std::vector<int> a, std::vector<int> b, int k) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= b[i]) {
            a.erase(a.begin() + i);
            b.erase(b.begin() + i);
            i--;
        }
    };

    if (k >= a.size())
        return 0;

    std::vector<int> selected_a;


    std::max_element();
};


int main() {
    int t;
    std::cin >> t;

    int n;
    int k;
    int input;
    std::vector<int> a;
    std::vector<int> b;

    while (t--) {
        a.clear();
        b.clear();

        std::cin >> n >> k;

        for (int i = 0; i < n; i++) {
            std::cin >> input;
            a.push_back(input);
        }

        for (int i = 0; i < n; i++) {
            std::cin >> input;
            b.push_back(input);
        }


        std::cout << solve(a, b, k) << '\n';
    };

    return 0;
};
