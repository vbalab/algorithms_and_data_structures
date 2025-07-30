#include <cstdint>
#include <random>

class Solution {
public:
    int32_t GetBase() {
        int32_t value = rand7();

        if (value > 5) {
            return GetBase();
        }
        return value * 2 - 1;
    }

    int32_t GetIncrement() {
        int32_t value = rand7();

        if (value == 7) {
            return GetIncrement();
        }

        return value <= 3 ? 0 : 1;
    }

    int32_t rand10() { return GetBase() + GetIncrement(); }

private:
    // returns hardware entropy (true randomness) uint32_t for seed value:
    std::random_device rd;

    // pseudorandom number engine initialized with random seed:
    std::mt19937 gen{rd()};

    std::uniform_int_distribution<int> dist{1, 7};

    int rand7() { return dist(gen); }
};
