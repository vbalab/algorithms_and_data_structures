#include <set>
#include <vector>
#include <string>
#include <iostream>


class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> labels;
        std::set<char> chars;
        int label_size;


        for (int i = 0; i < s.size(); i++) {
            chars.clear();
            chars.insert(s[i]);
            label_size = 1;


            for (int j = i + 1; j < s.size(); j++) {
                if (chars.find(s[j]) != chars.end()) {
                    for (int k = i + 1; k < j + 1; k++) {
                        chars.insert(s[k]);
                        label_size++;
                        i++;
                    }
                }
            }

            labels.push_back(label_size);
        }


        return labels;
    }
};


int main() {
    std::string str = "ababcbacadefegdehijhklij";

    Solution s;
    std::vector<int> ans = s.partitionLabels(str);

    for (const int& str_ : ans)
        std::cout << str_ << ' ';
    std::cout << '\n';


    return 0;
}
