#include <vector>
#include <iostream>
#include <unordered_map>


class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        int cumsum = 0;
        int reminder = 0;
        std::unordered_map<int, int> remainderMap;
        remainderMap[0] = -1;


        for (int i = 0; i < nums.size(); i++) {
            cumsum += nums[i];

            reminder = cumsum % k;
            if (remainderMap.find(reminder) != remainderMap.end()) {
                if (i - remainderMap[reminder] > 1)
                    return true;
            }
            else
                remainderMap[reminder] = i;
        };


        return false;
    };
};


int main() {
    std::vector<int> v = {23,2,4,6,6};
    Solution s;
    std::cout << s.checkSubarraySum(v, 7) << '\n';

    return 0;
};
