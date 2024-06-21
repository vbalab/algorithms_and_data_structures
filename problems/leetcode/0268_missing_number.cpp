#include <vector>
#include <iostream>


class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int sum = 0;
        int max = -1;
        int min = __INT_MAX__;

        for (const int& num : nums) {
            sum += num;
            max = std::max(num, max);
            min = std::min(num, min);
        }

        for (int i = min; i <= max; i++)
            sum -= i;

        if (sum == 0) {
            if (min > 0)
                return --min;
            else
                return ++max;
        }
        else
            return abs(sum);
    }
};


int main() {
    return 0;
}