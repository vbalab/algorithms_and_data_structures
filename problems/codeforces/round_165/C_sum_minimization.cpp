#include <iostream>
#include <vector>


long long solve(std::vector<int>& a, int k) {
    int diff;
    int neighbour;
    int index;

    while (k--) {
        diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (i > 0 && a[i] - a[i - 1] > diff) {
                diff = a[i] - a[i - 1];

                neighbour = i - 1;
                index = i;
            };

            if (i < a.size() - 1 && a[i] - a[i + 1] > diff) {
                diff = a[i] - a[i + 1];

                neighbour = i + 1;
                index = i;
            };
        };

        if (diff > 0)
            a[index] = a[neighbour];
    };

    long long sum = 0;
    for (int& val: a)
        sum += val;

    return sum;
};


int main() {
    int t;
    std::cin >> t;

    int k;
    int n;
    int input;
    std::vector<int> a;

    while (t--) {
        a.clear();

        std::cin >> n >> k;

        while (n--) {
            std::cin >> input;
            a.push_back(input);
        };

        std::cout << solve(a, k) << '\n';
    };

    return 0;
};
