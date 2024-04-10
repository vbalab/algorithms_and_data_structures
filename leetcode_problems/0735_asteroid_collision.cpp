#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>


class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> answer;
        std::stack<int> right_stack;


        for (int num: asteroids) {
            if (num > 0)
                right_stack.push(num);
            else {
                if (right_stack.size() == 0)
                    answer.push_back(num);
                else {
                    while (right_stack.size() > 0) {
                        if (-num > right_stack.top()) {
                            right_stack.pop();
                            if (right_stack.size() == 0)
                                answer.push_back(num);
                        }
                        else if (-num < right_stack.top()) {
                            break;
                        }
                        else {
                            right_stack.pop();
                            break;
                        };
                    };
                };
            };
        };

        if (right_stack.size() > 0) {
            std::vector<int> add;
            while (right_stack.size() > 0) {
                add.push_back(right_stack.top());
                right_stack.pop();
            }

            for (int i = add.size() - 1; i >= 0; i--)
                answer.push_back(add[i]);
        };


        return answer;
    };
};


int main() {
    int input;
    std::string input_line;
    std::istringstream stream;
    std::vector<int> v;

    std::getline(std::cin, input_line);
    stream.str(input_line);

    while (stream >> input)
        v.push_back(input);


    Solution solution;
    for (int num: solution.asteroidCollision(v))
        std::cout << num << ' ';
    std::cout << '\n';


    return 0;
};
