#include <vector>
#include <iostream>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> permutations = {};


    void make_permutations(std::vector<int>& v) {
        std::sort(v.begin(), v.end());

        std::vector<int> tmp = {};
        step(v, tmp);

        return;
    };


    void step(std::vector<int>& v, std::vector<int>& filled) {
        if (v.size() == filled.size())
            this->permutations.push_back(filled);


        for (int val: v) {
            if (std::find(filled.begin(), filled.end(), val) == filled.end()) {
                filled.push_back(val);
                step(v, filled);
                filled.pop_back();
            };
        };

        return;
    };
};


int main() {
    std::vector<int> v = { 1, 4, 7, 9 };

    Solution s;

    s.make_permutations(v);
    for (std::vector<int> p: s.permutations) {
        for (int val: p)
            std::cout << val << ' ';
        
        std::cout << '\n';
    }


    return 0;
}
