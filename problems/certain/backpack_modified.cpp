#include <vector>
#include <iostream>
#include <unordered_map>
#include <boost/container_hash/hash.hpp> 


template <typename Container>
struct container_hash {
    std::size_t operator()(Container const& c) const {
        return boost::hash_range(c.begin(), c.end());
    }
};


class Solution {
public:
    std::unordered_map<std::vector<int>, int, container_hash<std::vector<int>>> mem;


    int maxBackpackValue(std::vector<int>& weights, std::vector<int>& values, int volume) {
        if (this->mem.find(weights) != this->mem.end())
            return this->mem[weights];

        int max_value = 0;
        int remained_volume;
        int current_weight = -1;


        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] != -1) {
                remained_volume = volume - weights[i];

                if (remained_volume < 0)
                    continue;
                else if (remained_volume == 0)
                    return values[i];
                else {
                    std::swap(current_weight, weights[i]);

                    max_value = std::max(values[i] + maxBackpackValue(weights, values, remained_volume), max_value);

                    std::swap(current_weight, weights[i]);
                };
            };
        };


        this->mem[weights] = max_value;

        return max_value;
    };
};


int main() {
    std::vector<int> w = { 7, 4, 6, 20 };
    std::vector<int> v = { 3, 5, 6, 30};
    Solution s;

    std::cout << s.maxBackpackValue(w, v, 15) << '\n';


    return 0;
};
