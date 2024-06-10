#include <string>
#include <iostream>


class Solution {
public:
    std::string reverseWords(std::string s) {
        int l = 0;
        int r = 0;
        while (r < s.size()) {
            l = r;

            while (r < s.size() && s[r] != ' ')
                r++;

            for (int i = 0; i < (r - l) / 2; i++)
                std::swap(s[l + i], s[r - 1 - i]);

            r++;
        };

        return s;
    };
};


int main() {
    Solution s;
    std::cout << s.reverseWords("Let's take LeetCode contest") << '\n';

    return 0;
};
