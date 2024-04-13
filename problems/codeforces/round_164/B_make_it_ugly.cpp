#include <vector>
#include <iostream>
#include <algorithm>


int solve(std::vector<int> array) {
    int min = __INT32_MAX__;
    int n = 0;
    int sym = array[0];

    for (int i = 0; i < array.size(); i++) {
        if (array[i] == sym)
            n++;
        else {
            min = std::min(min, n);

            n = 0;
        };
    };
    min = std::min(min, n);

    if (min == __INT_MAX__ || min == array.size())
        return -1;
    else
        return min;
};


int main() {
    int t;
    std::cin >> t;

    int n;
    int input;
    std::vector<int> array;

    while (t--) {
        std::cin >> n;

        array.clear();
        while (n--) {
            std::cin >> input;
            array.push_back(input);
        };

        std::cout << solve(array) << '\n';
    }

    return 0;
};