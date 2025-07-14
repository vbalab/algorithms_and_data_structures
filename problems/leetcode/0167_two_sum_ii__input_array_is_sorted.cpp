#include <algorithm>
#include <cstdint>
#include <stdexcept>
#include <vector>

class Solution {
public:
    size_t BinarySearch(size_t left, size_t right,
                        const std::vector<int32_t>& numbers, int32_t target) {
        while (left < right) {
            size_t mid = left + (right - left) / 2;

            if (numbers[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    std::vector<int32_t> twoSum(const std::vector<int32_t>& numbers,
                                int32_t target) {
        size_t size = numbers.size();
        for (size_t i = 0; i < size; ++i) {
            int32_t dbl = 2 * numbers[i];
            size_t j;

            if (dbl < target) {
                j = BinarySearch(i + 1, size - 1, numbers, target - numbers[i]);
            } else if (dbl > target) {
                j = BinarySearch(0, i - 1, numbers, target - numbers[i]);
            } else {
                j = i + 1;
            }

            if (numbers[i] + numbers[j] == target) {
                int32_t index1 = i + 1;
                int32_t index2 = j + 1;

                if (index1 < index2) {
                    return {index1, index2};
                }
                return {index2, index1};
            }
        }

        throw std::runtime_error("Indicies weren't found.");
    }
};

int main() { return 0; }