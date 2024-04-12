#include <vector>
#include <iostream>


class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int highest = 0;

        if (highest < gain[0])
                highest = gain[0];


        for (int i = 1; i < gain.size(); i++) {
            gain[i] += gain[i - 1];
 
            if (highest < gain[i])
                highest = gain[i];
        };

        return highest;
    };
};


int main() {
    return 0;
};