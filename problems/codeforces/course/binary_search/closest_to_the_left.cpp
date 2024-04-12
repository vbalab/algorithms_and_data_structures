#include <iostream>


int binary_search(long arr[], int l, int r, long target) {
    int m = (l + r) >> 1;

    if (arr[m] <= target & target < arr[m + 1]) {
        return m;
    }


    if (arr[m] < target)
        return binary_search(arr, m + 1, r, target);
    else
        return binary_search(arr, l, m - 1, target);
};


int main() {
    int n;
    int k;
    std::cin >> n >> k;

    long arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];


    long target;
    while (k--) {
        std::cin >> target;

        if (target < arr[0])
            std::cout << 0 << '\n';
        else
            std::cout << binary_search(arr, 0, n - 1, target) + 1 << '\n';
    };


    return 0;
}