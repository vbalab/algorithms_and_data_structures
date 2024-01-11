#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>


class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int length = 0;
        std::string subs = "";
        std::unordered_map<char, int> m;

        int i = 0;
        for (char& letter: s)
        {
            if (m.find(letter) != m.end())
                subs.erase(0, subs.find(letter) + 1);

            subs += letter;
            m[letter] = i;

            std::cout << subs << "\n";

            length = std::max(length, static_cast<int>(subs.size()));

            i++;
        };

        return length;
    }
};


int main()
{
    std::string s;
    std::cin >> s;                                          // OR std::getline(std::cin, s);

    Solution solution;
    std::cout << solution.lengthOfLongestSubstring(s) << "\n";

    return 0;
};