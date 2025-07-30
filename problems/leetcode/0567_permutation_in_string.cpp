#include <cstdint>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<char, int32_t> CreateCounter(
        const std::string& pattern) {
        std::unordered_map<char, int32_t> map;

        for (char c : pattern) {
            ++map[c];
        }

        return map;
    }

    bool checkInclusion(const std::string& s1, const std::string& s2) {
        size_t s1size = s1.size();
        size_t s2size = s2.size();
        if (s1size > s2size) {
            return {};
        }

        size_t max_start = s2size - s1size;

        auto counter = CreateCounter(s1);

        size_t l = 0;
        size_t r = 0;
        while (l <= max_start) {
            if (--counter[s2[r]] < 0) {
                while (l <= r && counter[s2[r]] < 0) {
                    ++counter[s2[l++]];
                }
            }

            if (r - l == s1size - 1) {
                return true;
            }

            ++r;
        }

        return false;
    }
};
