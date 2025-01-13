#include <iostream>

class Solution {
public:
    int32_t minFlips(int32_t a, int32_t b, int32_t c) {
        int32_t count = 0;

        for (std::size_t i = 0; i < 32; ++i) {
            
            if ((c >> i) & 1) {
                if (!(((a >> i) | (b >> i)) & 1)) {
                    ++count;
                }
            } else {
                if ((a >> i) & 1) {
                    ++count;
                }
                if ((b >> i) & 1) {
                    ++count;
                }
            }
        }

        return  count;
    }
};
