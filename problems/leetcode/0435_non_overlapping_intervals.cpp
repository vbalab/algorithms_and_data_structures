#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int32_t eraseOverlapIntervals(std::vector<std::vector<int32_t>>& intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }

        int32_t min_erased = 0;

        std::sort(intervals.begin(), intervals.end(), 
            [](std::vector<int32_t> a, std::vector<int32_t> b) {return a[0] < b[0];}
        );

        int32_t prev_end = intervals[0][1];
        for (std::size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= prev_end) {
                prev_end = intervals[i][1];
                continue;
            }

            if (prev_end > intervals[i][1]) {
                prev_end = intervals[i][1];
            }
            ++min_erased;
        }

        return min_erased;
    }
};
