#include <iostream>
#include <vector>
#include <unordered_map>


int solve(std::vector<int> v) {
    int copies = 0;
    std::unordered_map<int, int> mapa;

    for (int num: v) {
        if (mapa.find(num) == mapa.end())
            mapa[num] = 1;
        else {
            mapa[num] = 2;
            copies++;
        }
    };

    return copies;
};


int main() {
    int t;
    std::cin >> t;

    int n;
    int input;
    std::vector<int> v;
    while (t--) {
        v.clear();
        
        std::cin >> n;
        while (n--) {
            std::cin >> input;
            v.push_back(input); 
        }

        std::cout << solve(v) << '\n';
    };
    
    return 0;
};