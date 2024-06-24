#include <string>
#include <iostream>


class Solution {
public:
    int maxPower(std::string& s) {
        int max = 0;

        char element;
        int l = 0;
        int r = 0;
        int size = s.size();

        while (l < size) {
            element = s[l];

            while (r < size && element == s[r])
                r++;

            max = std::max(max, r - l);
            l = r;
        }


        return max;
    }
};


int main() {
    return 0;
}
