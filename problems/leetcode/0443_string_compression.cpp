#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    int32_t compress(std::vector<char>& chars) {
        int32_t left = chars.size() - 1;
        int32_t right = chars.size() - 1;

        while (right > 0) {
            while (left >= 0 && chars[left] == chars[right]) {
                --left;
            }

            if (right - left > 1) {
                int32_t diff = right - left;
                std::string diff_str = std::to_string(diff);

                for (int32_t i = diff_str.size() - 1; i >= 0; --i) {
                    chars[right--] = diff_str[i];
                }

                chars.erase(chars.begin() + left + 1, chars.begin() + right);

            }

            right = left;
        }

        return chars.size();
    }
};

int main() {
    std::vector<char> chars = {'a', 'a', 'b', 'b'};

    Solution s;
    s.compress(chars);

    return 0;
}
