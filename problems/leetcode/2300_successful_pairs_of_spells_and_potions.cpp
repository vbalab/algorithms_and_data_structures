#include <vector>
#include <algorithm>

std::size_t ConditionalBinarySearch(const std::vector<int32_t>& potions, int32_t spell, int64_t success) {
    std::size_t l = 0;
    std::size_t r = potions.size();

    while (l < r) {
        std::size_t m = l + (r - l) / 2;

        int64_t current = static_cast<int64_t>(potions[m]) * static_cast<int64_t>(spell);

        if (current >= success) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    return l;
}

class Solution {
public:
    std::vector<int32_t> successfulPairs(const std::vector<int32_t>& spells, std::vector<int32_t>& potions, int64_t success) {
        std::vector<int32_t> pairs(spells.size());

        std::sort(potions.begin(), potions.end());
        std::size_t size = potions.size();

        for (std::size_t i = 0; i < spells.size(); ++i) {
            pairs[i] = size - ConditionalBinarySearch(potions, spells[i], success);
        }

        return pairs;
    }
};

int main() {
    return 0;
}