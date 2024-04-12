#include <iostream>


bool binary_search(int arr[], int l, int r, int target) {       // CAN'T: int& arr[], because arr[] is array of references itself - https://stackoverflow.com/questions/1164266/why-are-arrays-of-references-illegal
    int m = (r + l) >> 1;

    if (arr[m] == target)
        return true;
    else if (l == r)
        return false;

    if (target > arr[m])
        return binary_search(arr, m + 1, r, target);
    else
        return binary_search(arr, l, m, target);
};


int main() {
    int n;
    int k;
    std::cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    int target;
    while (k--) {
        std::cin >> target;
        if (binary_search(arr, 0, n, target))
            std::cout << "YES" << "\n";
        else
            std::cout << "NO" << "\n";
    };

    return 0;  
};