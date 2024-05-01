#include <string>
#include <iostream>


long long solve(std::string& s) {
    long long counter = 0;
    int l = 0;
    int r = 0;

    while (r < s.size()) {
        while (s[r] == '1')
            r++;

        if (l < r && s[r] == '0')
            counter += r - l + 1;

        l++;
        r++;
    };

    return counter;
};


int main() {
    int t;
    std::cin >> t;

    std::string s;
    std::getline(std::cin, s);

    while (t--) {
        std::getline(std::cin, s);

        std::cout << solve(s) << '\n';
    };


    return 0;
};
