#include <iostream>
#include <string>


class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (s.size() == 0)
            return true;


        int si = 0;

        for (int ti = 0; ti < t.size(); ti++) {
            if (s[si] == t[ti])
                si++;
        };

        return si == s.size();
    };
};


int main() {
    std::string s;
    std::string t;

    std::cin >> s;
    std::cin >> t;


    Solution solution;
    std::cout << solution.isSubsequence(s, t) << '\n';


    return 0;
};