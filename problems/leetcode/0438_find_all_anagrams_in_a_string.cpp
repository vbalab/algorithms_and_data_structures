#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

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

    std::vector<int32_t> findAnagrams(const std::string& a,
                                      const std::string& b) {
        std::vector<int32_t> answers;

        size_t bsize = b.size();
        size_t asize = a.size();
        if (bsize > asize) {
            return {};
        }

        size_t max_start = asize - bsize;

        auto counter = CreateCounter(b);

        size_t l = 0;
        size_t r = 0;
        while (l <= max_start) {
            if (--counter[a[r]] < 0) {
                while (l <= r && counter[a[r]] < 0) {
                    ++counter[a[l++]];
                }
            }

            if (r - l == bsize - 1) {
                answers.push_back(l);
            }

            ++r;
        }

        return answers;
    }
};

int main() {
    std::string a("cbaebabacd");
    std::string b("bac");

    Solution s;
    s.findAnagrams(a, b);

    return 0;
}
