#include <iostream>

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        std::size_t left = 1;
        std::size_t mid;
        std::size_t right = n;

        while (left <= right) {
            mid = left + (right - left) / 2;

            int32_t ges = guess(mid);

            if (ges == -1) {
                right = mid - 1;
            } else if (ges == 1) {
                left = mid + 1;
            } else {
                return mid;
            }
        }

        return mid;
    }
};

int main() {
    return 0;
}
