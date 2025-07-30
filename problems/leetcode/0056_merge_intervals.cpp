#include <algorithm>
#include <cstdint>
#include <vector>

class Solution {
    using Interval = std::vector<int32_t>;

public:
    void SortIntervals(std::vector<Interval>& intervals) {
        auto comparator = [](const Interval& lhs, const Interval& rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] < rhs[1];
            }
            return lhs[0] < rhs[0];
        };

        std::sort(intervals.begin(), intervals.end(), comparator);
    }

    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        std::vector<Interval> merged;

        SortIntervals(intervals);

        int32_t l = intervals[0][0];
        int32_t r = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (r < intervals[i][0]) {
                merged.push_back(std::vector<int32_t>{l, r});

                l = intervals[i][0];
                r = intervals[i][1];
            } else {
                r = std::max(r, intervals[i][1]);
            }
        }

        merged.push_back(std::vector<int32_t>{l, r});

        return merged;
    }
};
