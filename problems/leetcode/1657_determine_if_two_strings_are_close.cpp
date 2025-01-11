#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    bool closeStrings(const std::string& str1, const std::string& str2) {
        if (str1.size() != str2.size()) {
            return false;
        }

        std::unordered_map<char, std::size_t> m1;
        for (char c: str1) {
            ++m1[c];
        }

        std::unordered_map<char, std::size_t> m2;
        for (char c: str2) {
            ++m2[c];
        }

        std::set<char> chars1;
        std::vector<std::size_t> nums1;
        for (auto& [key, val]: m1) {
            chars1.insert(key);
            nums1.push_back(val);
        }

        std::set<char> chars2;
        std::vector<std::size_t> nums2;
        for (auto& [key, val]: m2) {
            chars2.insert(key);
            nums2.push_back(val);
        }

        if (chars1 != chars2) {
            return false;
        }

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        return nums1 == nums2;
    }
};

// BEST:
// class Solution {
// public:
//     bool closeStrings(string word1, string word2) {
//         if (word1.length() != word2.length())
//             return false;

//         vector<int> freq1(26, 0);
//         for (char c : word1)
//             freq1[c - 'a']++;

//         vector<int> freq2(26, 0);
//         for (char c : word2)
//             freq2[c - 'a']++;

//         for (int i = 0; i < 26; i++) {
//             if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0))
//                 return false;
//         }

//         sort(freq1.begin(), freq1.end());
//         sort(freq2.begin(), freq2.end());
//         return freq1 == freq2;
//     }
// };
