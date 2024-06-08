#include <vector>
#include <string>
#include <iostream>


class ModifiedPrefixTree {
public:
    char c;
    int popularity;
    std::string most_popular_word;

    ModifiedPrefixTree* parent;
    std::vector<ModifiedPrefixTree*> children;


    ModifiedPrefixTree() {
        this->parent = nullptr;
        this->popularity = -1;
        this->most_popular_word = "-1";
        this->children = {};
    };


    ModifiedPrefixTree(char c) {
        this->c = c;
        this->parent = nullptr;
        this->popularity = -1;
        this->most_popular_word = "-1";
        this->children = {};
    };


    ModifiedPrefixTree(char c, std::string word, int popularity) {
        this->c = c;
        this->popularity = popularity;
        this->most_popular_word = word;
        this->parent = nullptr;
        this->children = {};
    };


    void insert(std::string word, int popularity);
    void insert_(std::string word, int popularity, int depth);
};


void ModifiedPrefixTree::insert(std::string word, int popularity) {
    if (popularity > this->popularity) {
        this->popularity = popularity;
        this->most_popular_word = word;
    };

    this->insert_(word, popularity, 0);
};


void ModifiedPrefixTree::insert_(std::string word, int popularity, int depth) {
    for (ModifiedPrefixTree* child: this->children) {
        if (child->c == word[depth]) {
            if (popularity > child->popularity) {
                child->most_popular_word = word;
                child->popularity = popularity;
            };

            if (depth < word.size())
                child->insert_(word, popularity, depth + 1);

            return;
        };
    };


    ModifiedPrefixTree* new_child = new ModifiedPrefixTree(word[depth], word, popularity);
    new_child->parent = this;
    this->children.push_back(new_child);

    if (depth < word.size()) {
        this->children.back()->insert_(word, popularity, depth + 1);
    };

    return;
};


void solve(char activity, char symbol, ModifiedPrefixTree*& curr) {
    if (activity == '+') {
        for (ModifiedPrefixTree* child: curr->children) {
            if (child->c == symbol) {
                curr = child;
                std::cout << curr->most_popular_word << '\n';

                return;
            };
        };


        ModifiedPrefixTree* new_child = new ModifiedPrefixTree(symbol);
        new_child->parent = curr;
        curr->children.push_back(new_child);

        curr = new_child;

        std::cout << curr->most_popular_word << '\n';

        return;
    }
    else {
        curr = curr->parent;

        std::cout << curr->most_popular_word << '\n';

        return;
    };
};


int main() {
    int N;
    int Q;
    std::cin >> N >> Q;


    ModifiedPrefixTree* head = new ModifiedPrefixTree();
    ModifiedPrefixTree* curr = head;
    std::string word;
    int popularity;

    while(N--) {
        std::cin >> word >> popularity;
        head->insert(word, popularity);
    };


    std::vector<char> activities (Q);
    std::vector<char> symbols (Q);

    for (int i = 0; i < Q; i++) {
        std::cin >> activities[i];

        if (activities[i] == '+')
            std::cin >> symbols[i];
        else
            symbols[i] = ' ';
    };

    for (int i = 0; i < Q; i++) {
        solve(activities[i], symbols[i], curr);
    };

    return 0;
};
