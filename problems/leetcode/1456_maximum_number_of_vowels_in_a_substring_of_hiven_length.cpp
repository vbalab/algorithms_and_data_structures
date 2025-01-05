#include <iostream>
#include <string>
#include <set>

static std::set<char> kVowels = {'a', 'e', 'i', 'o', 'u'};

class Solution {
public:
    int32_t maxVowels(const std::string& s, int32_t k) {
        int32_t cur = 0;
        int32_t max = 0;

        for (std::size_t i = 0; i < k; ++i) {
            if (kVowels.contains(s[i])) {
                ++cur;
            }
        }
        max = cur;

        for (std::size_t i = k; i < s.size(); ++i) {
            if (kVowels.contains(s[i])) {
                ++cur;
            }
            if (kVowels.contains(s[i - k])) {
                --cur;
            }

            max = std::max(max, cur);
        }

        return max;
    }
};

int main() {
    return 0;
}