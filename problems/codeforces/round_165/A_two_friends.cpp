#include <iostream>
#include <vector>


int solve(std::vector<int>& besties) {
    for (int i = 1; i < besties.size(); i++) {
        if (besties[besties[i]] == i)
            return 2;
    }

    return 3;
};


int main() {
    int t;
    std::cin >> t;

    int n;
    int input;
    std::vector<int> besties;

    while (t--) {
        besties.clear();
        besties.push_back(0);

        std::cin >> n;
        while (n--) {
            std::cin >> input;
            besties.push_back(input);
        };

        std::cout << solve(besties) << '\n';
    };


    return 0;
};
