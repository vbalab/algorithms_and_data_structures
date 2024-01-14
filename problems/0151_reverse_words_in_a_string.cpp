#include <iostream>
#include <string>
#include <algorithm>


class Solution
{
    public:
    std::string reverseWords(std::string s)
    {

        removeExtraWhitespaces(s);

        return s;
    };

    void removeExtraWhitespaces(std::string & s)
    {
        int lenght = s.size();

        for (int i = 0; i < lenght - 1;)
        {

            if (s[i] == ' ' and s[i + 1] == ' ')
            {
                s.erase(i, 1);
                lenght--;
            }
            else
                i++;
        };

        if (s[0] == ' ')
            s.erase(0, 1);


        if (s[lenght - 1] == ' ')
            s.erase(lenght - 1, 1);
    };
};


int main()
{
    std::string s;
    // std::cin >> s;                                   // WRONG - doesn't catch after ' '
    std::getline(std::cin, s);

    Solution solution;
    std::cout << solution.reverseWords(s) << '\n';

    return 0;
};