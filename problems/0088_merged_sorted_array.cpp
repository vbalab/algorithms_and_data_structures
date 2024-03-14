#include <iostream>
#include <vector>
#include "../utils.h"


using namespace utils;


class Solution {
    public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        m--;
        n--;

        if (n < 0) 
            return;

        while (true) {
            if (m < 0) {
                while (n >= 0) {
                    nums1[m + n + 1] = nums2[n];
                    n--;
                    }
                break;
            };

            if (n < 0) {;
                while (m >= 0) {
                    nums1[m + n + 1] = nums1[m];
                    m--;
                    }
                break;
            };


            if (nums1[m] > nums2[n]) {
                nums1[m + n + 1] = nums1[m];
                m--;
                }
            else {
                nums1[m + n + 1] = nums2[n];
                 n--;
                 }


        };
    };
};


int main() {
    std::string input_line;


    std::getline(std::cin, input_line);
    std::vector<int> nums1 = fill_vector_from_string(input_line);

    int m = nums1.size() - 1;
    while (nums1[m] == 0)
        m--;
    m++;



    std::getline(std::cin, input_line);
    std::vector<int> nums2 = fill_vector_from_string(input_line);

    int n = nums2.size();


    Solution solution;
    solution.merge(nums1, m, nums2, n);
 
    print_vector(nums1);

    return 0;
};
