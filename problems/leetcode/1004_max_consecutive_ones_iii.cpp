#include <vector>
#include <queue>
#include <iostream>


class SolutionBad {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        std::queue<int> q;
        int size = nums.size();
        int len;
        int curr = 0;
        int max = 0;


        for (int i = 0; i < size; i++) {
            len = 0;
            if (!k)
                curr = 0;

            while (i < size && nums[i]) {
                len++;
                i++;
            }
            max = std::max(curr + len, max);

            if (i < size && !nums[i] && k) {
                len++;

                if (q.size() == k) {
                    curr -= q.front();
                    q.pop();
                }
            }

            curr += len;
            q.push(len);

            max = std::max(curr, max);
        }

        return max;
    }
};



class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int max = 0;
        int curr = 0;
        int n_zeros = 0;
        int l = 0;
        int r = 0;

        for (int r = 0; r < nums.size(); r++) {
            while (r < nums.size() && nums[r]) {
                curr++;
                r++;
            }

            if (r < nums.size() && !nums[r]) {
                curr++;
                n_zeros++;

                if (n_zeros > k) {
                    while (nums[l]) {
                        curr--;
                        l++;
                    }
                    n_zeros--;
                    l++;
                }
            }

            max = std::max(curr, max);
        }

        return max;
    }
};


int main() {
    std::vector<int> nums = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };

    Solution s;
    std::cout << s.longestOnes(nums, 3) << '\n';

    return 0;
}
