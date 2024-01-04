#include <iostream>
#include <string>


class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int length;
        std::string subs;

        for (char& letter: s)
        {
            std::cout << subs;
            // subs.erase(subs.begin());
            subs += letter;
        };
        return length;
    }
};


int main()
{
    std::string name;

    std::cout << "Please, enter your full name: ";
    std::getline (std::cin,name);
    std::cout << "Hello, " << name << "!\n";

    // std::string s;
    // // std::cin >> s;                                           // Segmentation fault (core dumped) ????????
    // std::getline(std::cin, s);
 
    // Solution solution;
    // std::cout << solution.lengthOfLongestSubstring(s) + "\n";

    return 0;
};