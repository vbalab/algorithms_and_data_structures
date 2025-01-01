#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int32_t>& arr) {
        std::unordered_map<int32_t, int32_t> occurrences;

        for (int32_t& element: arr) {
            ++occurrences[element];
        }

        std::unordered_map<int32_t, bool> check;

        for (auto& [key, value]: occurrences) {
            if (!check[value]) {
                check[value] = true;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    return 0;
}