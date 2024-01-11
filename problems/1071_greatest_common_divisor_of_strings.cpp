#include <iostream>
#include <string>


class Solution
{
    public:
    std::string gcdOfStrings(std::string str1, std::string str2)
    {
        int length1;
        int length2;

        while (true)
        {
            length1 = str1.size();
            length2 = str2.size();


            if (length1 < length2)
            {
                if (str2.substr(0, 0 + length1) == str1)
                    str2 = str2.substr(length1, length2 - length1);
                else
                    return "";
            }
            else if (length1 > length2)
            {
                if (str1.substr(0, 0 + length2) == str2)
                    str1 = str1.substr(length2, length1 - length2);
                else
                    return "";
            }
            else
            {
                if (str1 == str2)
                    return str1;
                else
                    return "";
            };
        };
    };
};


int main()
{
    std::string str1;
    std::cin >> str1;

    std::string str2;
    std::cin >> str2;

    
    Solution solution;
    std::cout << solution.gcdOfStrings(str1, str2) << "\n";

    return 0;
};