#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>


class Solution
{
    public:
    std::string reverseWords(std::string s)
    {
        std::string reversed = "";
        std::string word = "";

        int i = 0;
        int lenght = s.size();

        // for the first word:
        while (s[i] == ' ')
            i++;
        while (i < lenght and s[i] != ' ')
            reversed += s[i++];


        while (i < lenght)
        {
            while (i < lenght and s[i] != ' ')
                word += s[i++];

            if (word != "")
            {
                reversed = word + ' ' + reversed;
                word = "";
            }

            if (s[i] == ' ')
                i++;
        };
        
        return reversed;
    };
};


int main()
{
    std::string s;
    // std::cin >> s;                                   // WRONG - doesn't catch after ' '
    std::getline(std::cin, s);

    Solution solution;
    std::cout << solution.reverseWords(s) << '.' << '\n';

    return 0;
};