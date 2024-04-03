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


    selection_sort(v);

    for (int num: v)
        std::cout << num << ' ';
    std::cout << '\n';


    return 0;
};