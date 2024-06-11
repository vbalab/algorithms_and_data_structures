#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iostream>


class Solution {
public:
    std::set<std::string> operations = {"+", "-", "*", "/"};


    int evalRPN(std::vector<std::string> tokens) {
        std::stack<int> numbers;

        int tmp1;
        int tmp2;
        for (std::string token: tokens) {
            if (this->operations.find(token) == this->operations.end()) 
                numbers.push(std::stoi(token));
            else {
                tmp1 = numbers.top();
                numbers.pop();
                tmp2 = numbers.top();
                numbers.pop();

                if (token == "+")
                    numbers.push(tmp2 + tmp1);
                else if (token == "-")
                    numbers.push(tmp2 - tmp1);
                else if (token == "*")
                    numbers.push(tmp2 * tmp1);
                else if (token == "/")
                    numbers.push(tmp2 / tmp1);
            };
        };


        return numbers.top();
    };
};


int main() {
    Solution s;

    std::cout << s.evalRPN({"4","3","-"}) << '\n';


    return 0;
};
