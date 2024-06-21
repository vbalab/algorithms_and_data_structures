#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>


class Solution {
public:
    std::unordered_map<int, std::vector<std::string>> hints = {{0, {""}}};


    std::vector<std::string> generateParenthesis(int n) {
        if (hints.find(n) != hints.end())
            return hints[n];


        std::vector<std::string> ans;

        std::vector<std::string> middle = generateParenthesis(n - 1);
        for (const std::string& m : middle)
            ans.push_back('(' + m + ')');

        for (int k = 1; k < n; k++) {    
            std::vector<std::string> left = generateParenthesis(n - k);
            std::vector<std::string> right = generateParenthesis(k);

            for (const std::string& l : left) {
               for (const std::string& r : right)
                    ans.push_back(l + r);
            }
        }


        std::set<std::string> s( ans.begin(), ans.end() );
        ans.assign( s.begin(), s.end() );


        hints[n] = ans;
        return ans;
    }
};


int main() {
    Solution s;
    std::vector<std::string> ans = s.generateParenthesis(4);

    for (const std::string& par: ans)
        std::cout << par << ' ';
    std::cout << '\n';

    return 0;
}
