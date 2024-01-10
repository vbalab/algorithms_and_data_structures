#include <iostream>
#include <string>


class Solution
{
    public:
    std::string convert(std::string s, const int numRows)
    {
        if (numRows == 1)
            return s;

        std::string result;
        
        for (int n = 0; n < numRows; n++)
        {
            if (n == 0 or n == numRows - 1)
            {
                for (int i = n; i < s.size();)
                {
                    result.push_back(s[i]);
                    i += (numRows - 1) * 2;
                };
            }
            else
            {
                for (int i = n; i < s.size();)
                {
                    result.push_back(s[i]);
                    i += (numRows - 1) * 2 - 2 * n;
                };
            };
        };

        return result;
    };
};


int main()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;


    Solution solution;
    std::cout << solution.convert(s, n);

    return 0;
};