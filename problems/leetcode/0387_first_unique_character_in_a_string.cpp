#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>


class Solution1 {
public:
    int firstUniqChar(std::string& s) {
        std::unordered_map<char, int> m;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (m.find(c) == m.end())
                m[c] = 1;
            else
                m[c] = m[c] + 1;
        };


        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1)
                return i;
        };


        return -1;
    };
};


class Solution2 {                               // much faster
public:
    int firstUniqChar(std::string& s) {
        std::vector<int> v(1000, 0);

        for (char& c: s) {
            v[c - 'a']++;                       // 'b' - 'a' = 1
        };

        for (int i = 0; i < s.size(); i++) {
            if (v[s[i] - 'a'] == 1)
                return i;
        };

        return -1;
    };
};


int main() {
    std::string s = "loveleetcode";


    Solution1 sol1;
    Solution2 sol2;

    std::cout << sol1.firstUniqChar(s) << ' ' << sol1.firstUniqChar(s) << '\n';


    return 0;
}
