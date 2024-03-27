#include <cmath>
#include <string>
#include <iostream>
#include <limits.h>


class Solution
{
    public:
    int reverse(int x)
    {
        int y = 0;
        int digit;

        for (int i = 0; i < 9; i++)
        {
            digit = x % 10;
            x /= 10;

            y = y * 10 + digit;

            if (x == 0)
                return y;
        }

        if ((abs(x) > 2) or (y > INT_MAX / 10 or y < INT_MIN / 10))
            return 0;

        digit = x % 10;
        y = y * 10 + digit;

        return y;
    };
};


int main()
{
    int number;
    std::cin >> number;

    std::cout << INT_MAX << "\n";

    Solution solution;
    std::cout << solution.reverse(number);

    return 0;
};