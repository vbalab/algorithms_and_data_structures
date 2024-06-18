#include <set>
#include <string>
#include <iostream>
#include <unordered_map>


class Solution {
public:
    int numJewelsInStones(const std::string jewels, const std::string stones) {
        int n_jewels = 0;
        std::set<char> unique_stones(stones.begin(), stones.end());
        std::unordered_map<char, int> m;

        for (const char& s: unique_stones)
            m[s] = 0;
        
        for (const char& s: stones)
            m[s]++;

        for (const char& j: jewels)
            n_jewels += m[j];
        

        return n_jewels;
    };
};


int main() {
    return 0;
}
