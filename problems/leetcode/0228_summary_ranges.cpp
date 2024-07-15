#include <vector>
#include <string>
#include <iostream>


class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> ans;

        int l = 0;
        int r = 1;
        int size = nums.size();

        while (l < size) {
            while (r < size && (nums[r] == nums[r - 1] + 1))
                    r++;

            if (l == r - 1)
                ans.push_back(std::to_string(nums[l]));
            else
                ans.push_back(std::to_string(nums[l]) + "->" + std::to_string(nums[r - 1]));

            l = r++;
        }

        return ans;
    }
};


int main() {
    return 0;
}
