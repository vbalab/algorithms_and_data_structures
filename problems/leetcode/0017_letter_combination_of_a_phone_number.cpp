#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

static std::unordered_map<char, std::vector<char>> keypad = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}
};

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.size() == 0) {
            return {};
        }

        std::vector<std::string> combs = {""};

        for (char digit: digits) {
            std::vector<char> letters = keypad[digit];
            std::size_t letters_size = letters.size();
            std::size_t combs_size = combs.size();

            for (std::size_t i = 0; i < letters_size - 1; ++i) {
                for (std::size_t j = 0; j < combs_size; ++j) {
                    combs.push_back(combs[j] + letters[i]);
                }
            }

            for (std::size_t j = 0; j < combs_size; ++j) {
                combs[j] += letters.back();
            }
        }
        return combs;
    }
};

int main() {
    return 0;
}