#include <cmath>
#include <string>
#include <iostream>


class Solution
{
    public:
    std::string mergeAlternately(std::string word1, std::string word2)
    {
        std::string merged;

        std::string& shortest = (word1.size() < word2.size()) ? word1 : word2;
        std::string& longest = (word1.size() >= word2.size()) ? word1 : word2;

        int i;

        for (i = 0; i < shortest.size(); i++)
        {
                merged.push_back(word1[i]);
                merged.push_back(word2[i]);
        };

        for (; i < longest.size(); i++)
                merged.push_back(longest[i]);

        return merged;  
    };
};


int main()
{
    std::string word1;
    std::cin >> word1;

    std::string word2;
    std::cin >> word2;


    Solution solution;
    std::cout << solution.mergeAlternately(word1, word2);

    return 0;
};