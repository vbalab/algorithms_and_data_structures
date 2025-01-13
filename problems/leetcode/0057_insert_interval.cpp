#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int32_t>> insert(std::vector<std::vector<int32_t>>& intervals, std::vector<int32_t>& newInterval) {
        int n = intervals.size();
        if (n == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }

        int32_t start = newInterval[0];
        int32_t end = newInterval[1];

        int32_t l;
        int32_t r;
        int32_t m;

        l = 0;
        r = n - 1;
        while (l < r) {
            m = l + (r - l) / 2;

            if (intervals[m][1] < start) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int32_t new_start_ind = r;

        l = 0;
        r = n - 1;
        while (l < r) {
            m = l + (r - l) / 2;

            if (intervals[m][0] <= end) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        int32_t new_end_ind = l;

        newInterval = {std::min(intervals[new_start_ind][0], newInterval[0]), std::max(intervals[new_end_ind][1], newInterval[1])};

        if (new_start_ind < new_end_ind) {
            intervals.erase(intervals.begin() + new_start_ind, intervals.begin() + new_end_ind);
        }
        intervals[new_start_ind] = newInterval;

        return intervals;
    }
};
