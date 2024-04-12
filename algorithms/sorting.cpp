#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>


void selection_sort(std::vector<int>& nums) {       // O(n^2)
    int min_idx;

    for (int i = 0; i < nums.size() - 1; i++) {
        min_idx = i + 1;

        for (int j = i; j < nums.size(); j++) {
            if (nums[min_idx] > nums[j])
                min_idx = j;
        };

        std::swap(nums[min_idx], nums[i]);        
    };

    return;                                         // it is considered a good practice
};


void bubble_sort(std::vector<int>& nums) {          // O(n^2)
    int end = nums.size() - 1;

    while (end != 0) {
        for (int i = 0; i < end; i++) {
            if (nums[i + 1] < nums[i])
                std::swap(nums[i + 1], nums[i]);
        };

        end--;
    };

    return;
};


void insertion_sort(std::vector<int>& nums) {       // O(n^2)
    int val;
    int j;

    for (int i = 1; i < nums.size(); i++) {
        val = nums[i];

        for (j = i; j > 0 and val < nums[j - 1]; j--)
            nums[j] = nums[j - 1];

        nums[j] = val;
    };
    
    return;
};


std::vector<int> merge_sorting(std::vector<int>& nums) {
    if (nums.size() <= 1) {
        return nums;
    }


    int m = nums.size() >> 1;
    std::vector<int> left;
    std::vector<int> right;

    for (int i = 0; i < m; i++)
        left.push_back(nums[i]);
    for (int i = m; i < nums.size(); i++)
        right.push_back(nums[i]);

    left = merge_sorting(left);
    right = merge_sorting(right);


    int l = 0;
    int r = 0;

    for (int i = 0; i < nums.size(); i++) {
        if ((left[l] < right[r] and l < left.size()) or r == right.size())
            nums[i] = left[l++];
        else
            nums[i] = right[r++];
    };


    return nums;
};


void heap_sorting(std::vector<int>& nums) {
    std::make_heap(nums.begin(), nums.end());
    std::sort_heap(nums.begin(), nums.end());

    return;
};


int main() {
    std::string input_line;
    std::getline(std::cin, input_line);

    int input;
    std::istringstream stream;
    std::vector<int> v;


    stream.str(input_line);

    while (stream >> input)
            v.push_back(input);


    heap_sorting(v);

    for (int num: v)
        std::cout << num << ' ';
    std::cout << '\n';


    return 0;
};