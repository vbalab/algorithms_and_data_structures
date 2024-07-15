#include <string>
#include <iostream>


class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string s_clean;

        for (const char& c: s) {
            if (isdigit(c))
                s_clean += c;
            else if (isalpha(c))
                s_clean += std::tolower(c);
        }

        for (int i = 0; i < s_clean.size() / 2; i++) {
            if (s_clean[i] != s_clean[s_clean.size() - i - 1])
                return false;
        }

        return true;
    }
};


int main() {
    std::string s = "Marge, let's \"[went].\" I await {news} telegram.";

    Solution sol;

    std::cout << sol.isPalindrome(s);

    return 0;
}
