#include <vector>
#include <iostream>
#include <unordered_map>


class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> intersection;
        std::unordered_map<int, int> counts;

        for (int v: nums1) {
            if (counts.find(v) != counts.end())
                counts[v]++;
            else
                counts[v] = 1;
        };

        for (int v: nums2) {
            if (counts.find(v) != counts.end() && counts[v] > 0) {
                intersection.push_back(v);
                counts[v]--;
            };
        };

        return intersection;
    };
};


int main() {
    return 0;
};
