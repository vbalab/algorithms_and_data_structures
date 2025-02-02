#include <cstdint>
#include <iostream>

int main () {
    int32_t t;
    std::cin >> t;

    while (t--) {
        int32_t n;
        int32_t m;

        std::cin >> n >> m;

        int32_t perimeter = 4 * m;
        int32_t sum = perimeter;

        int32_t x;
        int32_t y;
        std::cin >> x >> y;
        n--;

        while (n--) {
            std::cin >> x >> y;

            sum += perimeter - 2 * (m - x + m - y);
        }

        std::cout << sum << '\n';
    }

    return 0;
}
