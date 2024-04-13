#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    int t;
    std::cin >> t;

    int k;
    int q;


    int input;
    std::vector<int> a;

    while (t--) {
        std::cin >> k >> q;

        a.clear();
        while (k--) {
            std::cin >> input;
            a.push_back(input);
        };


        while (q--) {
            std::cin >> input;
            std::cout << std::min(a[0] - 1, input) << ' ';
        };
        std::cout << '\n';
    };

    return 0;
};
