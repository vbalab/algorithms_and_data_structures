#include <stack>
#include <string>
#include <iostream>
#include <algorithm>


class Solution {
public:
    std::string removeStars(std::string& s) {
        std::stack<char> stack;
        std::string result;


        for (char& letter: s) {
            if (letter == '*')
                stack.pop();
            else
                stack.push(letter);
        }

        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }

        std::reverse(result.begin(), result.end());

        return result;
    };
};


int main() {
    std::string s;
    std::cin >> s;

    Solution solution;
    std::cout << solution.removeStars(s) << '\n';


    return 0;
};
