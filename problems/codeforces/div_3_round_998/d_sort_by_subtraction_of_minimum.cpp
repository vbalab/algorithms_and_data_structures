#include <vector>
#include <string>
#include <cstdint>
#include <iostream>

int main() {
    int32_t t;
    std::cin >> t;

    while (t--) {
        std::size_t n;
        std::cin >> n;

        std::vector<int32_t> nums(n);
        for (std::size_t i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        std::string answer = "yes\n";
        for (std::size_t i = 1; i < n; ++i) {
            int32_t min = std::min(nums[i - 1], nums[i]);
            nums[i - 1] -= min;
            nums[i] -= min;

            if (nums[i] < nums[i - 1]) {
                answer = "no\n";
                break;
            }
        }

        std::cout << answer;
    }

    return 0;
}