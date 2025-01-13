#include <iostream>
#include <vector>
#include <stack>

struct Day {
    int32_t temp;
    std::size_t day_ind;
};

class Solution {
public:
    std::vector<int32_t> dailyTemperatures(std::vector<int32_t>& temperatures) {
        std::stack<Day> decr_temps;

        for (std::size_t i = 0; i < temperatures.size(); ++i) {
            while (!decr_temps.empty() && temperatures[i] > decr_temps.top().temp) {
                temperatures[decr_temps.top().day_ind] = i - decr_temps.top().day_ind;
                decr_temps.pop();
            }

            decr_temps.push({temperatures[i], i});
        }

        while (!decr_temps.empty()) {
            temperatures[decr_temps.top().day_ind] = 0;
            decr_temps.pop();
        }

        return temperatures;
    }
};
