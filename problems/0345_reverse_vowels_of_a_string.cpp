#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


class Solution
{
    public:
    std::string reverseVowels(std::string s)
    {
        std::set<char> vowels { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' };
        int j = s.size();   // s.size() - 1 already in the loop


        for (int i = 0; i < j; i++)
        {
            if (vowels.find(s[i]) != vowels.end())
            {
                for (; j > i;)
                {
                    j--;

                    if (vowels.find(s[j]) != vowels.end())
                    {
                        std::swap(s[i], s[j]);

                        break;
                    };
                };
            };
        };

        return s;
    };
};


int main()
{
    std::string s;
    std::cin >> s;

    Solution solution;
    std::cout << solution.reverseVowels(s) << "\n";

    return 0;
};