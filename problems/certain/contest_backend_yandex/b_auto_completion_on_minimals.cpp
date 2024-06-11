#include <string>
#include <vector>
#include <iostream>


// PREFIX TREE SOLUTION
class PrefixTree {
public:
    char c;
    int number;
    int first_index = -1;
    std::vector<PrefixTree*> children;


    PrefixTree() {
        this->number = -1;
        this->children = {};
    };


    PrefixTree(char c, int index) {
        this->c = c;
        this->number = 1;
        if (this->first_index == -1)
            this->first_index = index;
        this->children = {};
    };


    void insert(std::string& word, int index);
    std::vector<int> search(std::string& prefix);
    std::vector<int> search_(std::string& prefix, int depth);
};


void PrefixTree::insert(std::string& word, int index) {
    for (PrefixTree* child: this->children) {
        if (child->c == word[0]) {
            child->number++;

            word.erase(word.begin());
            if (word.size() > 0)
                child->insert(word, index);

            return;
        };
    };


    PrefixTree* new_child = new PrefixTree(word[0], index);
    this->children.push_back(new_child);

    word.erase(word.begin());
    if (word.size() > 0) {
        this->children.back()->insert(word, index);
    };

    return;
};


std::vector<int> PrefixTree::search(std::string& prefix) {
    return this->search_(prefix, 0);
};


std::vector<int> PrefixTree::search_(std::string& prefix, int depth) {
    if (depth == prefix.size())
        return {this->first_index, this->number};
    
    for (PrefixTree* child: this->children) {
        if (child->c == prefix[depth]) {
            return child->search_(prefix, depth + 1);
        };
    };

    return {-1, -1};
};


int solve(PrefixTree*& head, int k, std::string& prefix) {
    std::vector<int> search_result = head->search(prefix);
    
    if (search_result[0] == -1 || k > search_result[1])
        return -1;

    return search_result[0] + k;
};


int main() {
    int N;
    int Q;
    std::cin >> N >> Q;

    PrefixTree* head = new PrefixTree();

    std::string word;
    for (int i = 0; i < N; i++) {
        std::cin >> word;
        head->insert(word, i);
    };

    std::vector<int> k (Q);
    std::vector<std::string> p (Q);
    for (int i = 0; i < Q; i++)
        std::cin >> k[i] >> p[i];

    for (int i = 0; i < Q; i++)
        std::cout << solve(head, k[i], p[i]) << '\n';


    return 0;
};


// BINARY SEARCH SOLUTION
// int prefix_left_binary_search(std::vector<std::string>& v, int l, int r, std::string& x) {
//     int m = (l + r) >> 1;

//     std::string prefix = v[m].substr(0, x.size());
//     if (l == r) {
//         if (prefix != x)
//             return -1;
//         else
//             return l;
//     }


//     if (prefix == x) {
//         while (m > 0 && v[m - 1].substr(0, x.size()) >= x)
//             m--;

//         return m;
//     }
//     else if (prefix < x)
//         return prefix_left_binary_search(v, m + 1, r, x);
//     else
//         return prefix_left_binary_search(v, l, m - 1, x);
// };


// int solve(std::vector<std::string>& words, int k, std::string p) {
//     int ind = prefix_left_binary_search(words, 0, words.size() - 1, p);


//     if (ind >= 0 && ind + k - 1 < words.size() && words[ind + k - 1].substr(0, p.size()) == p)
//         return ind + k;
//     else
//         return -1;
// };


// int main() {
//     int N;
//     int Q;
//     std::cin >> N >> Q;

//     std::vector<std::string> words (N);
//     for (int i = 0; i < N; i++)
//         std::cin >> words[i];

//     std::vector<int> k (Q);
//     std::vector<std::string> p (Q);
//     for (int i = 0; i < Q; i++)
//         std::cin >> k[i] >> p[i];  

//     for (int i = 0; i < Q; i++)
//         std::cout << solve(words, k[i], p[i]) << '\n';


//     return 0;
// };
