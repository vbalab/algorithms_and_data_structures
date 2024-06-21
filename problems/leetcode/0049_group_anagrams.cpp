#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> anagrams;
        std::unordered_map<std::string, std::vector<std::string>> anagrams_map;


        for (const std::string& word : strs) {
            std::string word_to_sort = word;
            std::sort(word_to_sort.begin(), word_to_sort.end());

            anagrams_map[word_to_sort].push_back(word);
        }
        

        for (const auto& [k, v] : anagrams_map)
            anagrams.push_back(v);


        return anagrams;
    };
};


int main() {
    std::vector<std::string> strs = { "eat","tea","tan","ate","nat","bat" };

    Solution s;
    s.groupAnagrams(strs);


    return 0;
}
