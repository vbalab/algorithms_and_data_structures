#include <string>
#include <cstdint>
#include <iostream>

class Solution {
public:
    std::string decodeString(std::string& s) {
        std::string result;

        while (i < s.size()) {
            if (s[i] == ']') {
                return result;
            }

            if (!isdigit(s[i])) {
                result += s[i];
                i++;
                continue;
            }

            std::string number;
            while (isdigit(s[i])) {
                number += s[i++];
            }
            int32_t k = std::stoi(number);
            ++i;

            std::string repeat;
            while (s[i] != ']') {
                repeat += decodeString(s);
            }

            while (k-- > 0) {
                result += repeat;
            }

            ++i;
        }

        return result;
    }

private:
    std::size_t i = 0;
};
