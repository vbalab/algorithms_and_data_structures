#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <set>
#include <vector>

class Solution final {
    using FillingPart = std::vector<std::set<int64_t>>;
    using Part = std::vector<std::vector<int64_t>>;
    using It = std::vector<int32_t>::iterator;

public:
    void FillSums(It left, It right, FillingPart& sums, size_t max_k, size_t k,
                  int64_t sum) {
        if (k == max_k) {
            return;
        }

        for (; left != right; ++left) {
            int64_t new_sum = sum + *left;
            sums[k].insert(new_sum);
            FillSums(left + 1, right, sums, max_k, k + 1, new_sum);
        }
    }

    void FillSums(It left, It right, FillingPart& sums, size_t max_k) {
        sums[0].insert(0);
        FillSums(left, right, sums, max_k, 1, 0);
    }

    Part calculatePart(It left, It right) {
        size_t size = right - left + 1;

        FillingPart sums(size);
        FillSums(left, right, sums, size);

        Part part(size);
        for (size_t i = 0; i < size; ++i) {
            part[i] = std::vector<int64_t>(sums[i].begin(), sums[i].end());
        }

        return part;
    }

    void OutputPart(Part part) {
        std::ranges::for_each(part, [](std::vector<int64_t>& sums) {
            std::ranges::copy(sums,
                              std::ostream_iterator<int64_t>(std::cout, " "));
            std::cout << '\n';
        });
    }

    int64_t BinarySearch(std::vector<int64_t>& right, int64_t target) {
        size_t l = 0;
        size_t r = right.size() - 1;

        auto f = [target, &right](size_t m) {
            return std::abs(target - 2 * right[m]);
        };

        while (l < r) {
            size_t m = l + (r - l) / 2;

            if (f(m) < f(m + 1)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return f(l);
    }

    int32_t minimumDifference(std::vector<int32_t>& vec) {
        size_t n = vec.size() / 2;

        Part left_part = calculatePart(vec.begin(), vec.begin() + n);
        Part right_part = calculatePart(vec.begin() + n, vec.end());

        // OutputPart(left_part);
        // std::cout << '\n';
        // OutputPart(right_part);
        // std::cout << '\n';

        int64_t total = 0;
        for (int32_t val : vec) {
            total += val;
        }

        int64_t best_diff = INT64_MAX;
        for (size_t k = 0; k < n; ++k) {
            for (int64_t l : left_part[k]) {
                int64_t diff = BinarySearch(right_part[n - k], total - 2 * l);
                best_diff = std::min(diff, best_diff);
            }
        }

        return best_diff;
    }
};

int main() {
    std::vector<int32_t> vec{{3, 9, 7, 3}};

    Solution s;
    std::cout << s.minimumDifference(vec) << '\n';

    return 0;
}
