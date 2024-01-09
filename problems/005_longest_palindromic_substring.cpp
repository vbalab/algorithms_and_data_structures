#include <iostream>
#include <string>


class Solution
{
    public:
    std::string longestPalindrome(const std::string& s)
    {
        std::string palendrom = "";
        int k;
        int length = static_cast<int>(s.size());

        for (int i = 0; i < length; i++)
        {
            k = 0;
            while (i - k >= 0 and i + k <= length and s[i - k] == s[i + k])
                k++;

            if (palendrom.size() < 2 * k - 1)
                palendrom = s.substr(i - k + 1, 2 * k - 1);

            

            k = 0;
            while (i - k >= 0 and i + k + 1 <= length and s[i - k] == s[i + k + 1])
                k++;
            if (palendrom.size() < 2 * k)
                palendrom = s.substr(i - k + 1, 2 * k);
        };

        return palendrom;
    };
};


int main()
{
    std::string s;
    std::cin >> s;

    Solution solution;
    std::cout << solution.longestPalindrome(s) << "\n";

    return 0;
};