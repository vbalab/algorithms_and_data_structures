#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

class Solution {
public:
    int32_t findMinArrowShots(  // NOLINT
        std::vector<std::vector<int32_t>>& points) {
        int32_t shoots{0};

        std::sort(points.begin(), points.end(),
                  [](const std::vector<int32_t>& lhs,
                     const std::vector<int32_t>& rhs) {
                      if (lhs[0] == rhs[0]) {
                          return lhs[1] < rhs[1];
                      }
                      return lhs[0] < rhs[0];
                  });

        // std::ranges::for_each(points, [](const auto& point) {
        //     std::ranges::copy(point,
        //                       std::ostream_iterator<int>(std::cout, " "));
        //     std::cout << '\n';
        // });

        int32_t end = points[0][1];
        for (const std::vector<int32_t>& point : points) {
            if (end < point[0]) {
                ++shoots;
                end = point[1];
            } else {
                end = std::min(end, point[1]);
            }
        }
        ++shoots;

        return shoots;
    }
};
