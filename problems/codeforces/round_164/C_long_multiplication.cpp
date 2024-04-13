#include <vector>
#include <iostream>


std::vector<int> from_number_to_vector(long long n) {
    std::vector<int> v;
    
    int i = 0;
    while (n > 0) {
        v.push_back(n % (10 ^ i));
        i++;
    }

    return v;
};


long long from_vector_to_number(std::vector<int> v) {
    int n = 0;
    
    for (int i = 0; i < v.size(); i++)
        n += v[i] * (10 ^ i);

    return n;
}


void solve(long long n1, long long n2) {
    std::vector<int> v1 = from_number_to_vector(n1);
    std::vector<int> v2 = from_number_to_vector(n2);

    std::cout << n1 << '\n';

    for (int num: v1)
        std::cout << num << '\n';
    // if (v1 == v2)
        // break;

    return;
};


int main() {
    int t;
    std::cin >> t;

    long long n1;
    long long n2;
    while(t--) {
        std::cin >> n1 >> n2;

        solve(n1, n2);
    };
    return 0;
};