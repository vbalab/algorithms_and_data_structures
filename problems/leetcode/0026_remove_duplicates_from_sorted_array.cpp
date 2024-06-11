#include <vector>
#include <iostream>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n_unique = 1;
        int l = 0;

        for (int r = 1; r < nums.size(); r++) {
            if (nums[l] < nums[r]) {
                n_unique++;
                l++;
                nums[l] = nums[r];
            }
        };

        return n_unique;
    };
};


int main() {
    std::vector<int> v = { 1, 1, 2, 3 };

    Solution s;
    std::cout << s.removeDuplicates(v) << '\n';


    return 0;
};
