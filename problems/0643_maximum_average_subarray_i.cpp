#include <iostream>
#include <vector>


class Solution {
    double findMaxAverage(std::vector<int>& nums, int k) {
        double sum_current = 0;

        for (int i = 0; i < k; i++)
            sum_current += nums[i];


        double sum_max = sum_current;

        for (int i = k; i < nums.size(); i++) {
            sum_current += nums[i] - nums[i - k];

            if (sum_max < sum_current)
                sum_max = sum_current;
        }


        return sum_max / k;  
    };
};


int main() {
    return 0;
};