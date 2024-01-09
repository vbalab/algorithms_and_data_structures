#include <iostream>
#define MAX 1000


// divide&conquer   for separable subproblems
// dynamic          for overlapping subproblems

int recursive_fib(const int n)
{
    if (n <= 1)
        return 1;
    return recursive_fib(n - 1) + recursive_fib(n - 2);
};


// memoization (top-down) - first time solving a problem then storing to use later
int lookup[MAX];
void _initialize()
{
    for (int i = 0; i < MAX; ++i)
        lookup[i] = -1;
};

int memoization_fib(const int n)
{
    if (lookup[n] == -1) {
        if (n <= 1)
            lookup[n] = 1;
        else
            lookup[n] = memoization_fib(n - 1) + memoization_fib(n - 2);
    }

    return lookup[n];
};


// tabulation (bottom-top) - linearly calculate before solving a problem to look up after
int tabulation_fib(const int n)
{
    int f[n];
    f[0] = 1;
    f[1] = 1;

    for (int i = 2; i < n + 1; i++)
        f[i] = f[i - 1] + f[i - 2];

    return f[n];
};


int main()
{
    _initialize();

    int n;
    std::cin >> n;

    std::cout << recursive_fib(n) << "\n";
    std::cout << memoization_fib(n) << "\n";
    std::cout << tabulation_fib(n) << "\n";

    return 0;
};
