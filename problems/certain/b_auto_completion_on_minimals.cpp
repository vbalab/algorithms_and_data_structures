#include <string>
#include <vector>
#include <iostream>


int prefix_left_binary_search(std::vector<std::string>& v, int l, int r, std::string& x) {
    int m = (l + r) >> 1;

    std::string prefix = v[m].substr(0, x.size());
    if (l == r && prefix != x)
        return -1;


    if (prefix == x) {
        if (m > 0) {
            if (v[m - 1].substr(0, x.size()) < x)
                return m;
            else
                return prefix_left_binary_search(v, l, r - 1, x);
        }
        else
            return 0;
    }
    else if (prefix < x)
        return prefix_left_binary_search(v, m + 1, r, x);
    else
        return prefix_left_binary_search(v, l, m - 1, x);
};


int solve(std::vector<std::string>& words, int k, std::string p) {
    int ind = prefix_left_binary_search(words, 0, words.size(), p);


    if (ind >= 0 && ind + k < words.size() && words[ind + k].substr(0, p.size()) == p)
        return ind + k;
    else
        return -1;
};


int main() {
    int N;
    int Q;
    std::cin >> N >> Q;

    std::vector<std::string> words (N);
    for (int i = 0; i < N; i++)
        std::cin >> words[i];

    std::vector<int> k (Q);
    std::vector<std::string> p (Q);
    for (int i = 0; i < Q; i++)
        std::cin >> k[i] >> p[i];  

    for (int i = 0; i < Q; i++)
        std::cout << solve(words, k[i], p[i]) << '\n';


    return 0;
};
