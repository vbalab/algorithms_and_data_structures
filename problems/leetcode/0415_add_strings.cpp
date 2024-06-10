#include <string>
#include <iostream>


class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        if (num1.size() < num2.size())
            std::swap(num1, num2);

        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;


        int sum;
        int reminder = 0;
        for (int i = 0; i <= n1; i++) {
            if (i <= n2)
                sum = num1[n1 - i] + num2[n2 - i] - 48;
            else
                sum = num1[n1 - i];

            sum += reminder;


            reminder = 0;
            while (sum > 48 + 9) {
                sum -= 10;
                reminder++;
            };

            num1[n1 - i] = static_cast<char>(sum);
        };

        if (reminder)
            return '1' + num1;
        else
            return num1;
    };
};


int main() {
    Solution s;
    std::cout << s.addStrings("11", "123") << '\n';

    // std::cout << static_cast<int>('0') << '\n';
    // std::cout << static_cast<char>('9' + '8' - 48 - 10) << '\n';


    return 0;
};
