#include <sstream>
#include <iostream>
#include <vector>


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


int main() {
    std::string input_line;
    std::getline(std::cin, input_line);

    int input;
    std::istringstream stream;
    std::vector<int> v;


    stream.str(input_line);

    while (stream >> input)
            v.push_back(input);


    insertion_sort(v);

    for (int num: v)
        std::cout << num << ' ';
    std::cout << '\n';


    return 0;
};