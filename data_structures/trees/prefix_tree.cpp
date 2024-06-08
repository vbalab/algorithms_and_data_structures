#include <string>
#include <vector>
#include <iostream>


class PrefixTree {
public:
    char c;
    int number;
    std::vector<PrefixTree*> children;


    PrefixTree() {
        this->number = -1;
        this->children = {};
    };


    PrefixTree(char c) {
        this->c = c;
        this->number = 1;
        this->children = {};
    };


    void insert(std::string& word);
    void preorder_traversal();
};


void PrefixTree::insert(std::string& word) {
    for (PrefixTree* child: this->children) {
        if (child->c == word[0]) {
            child->number++;

            word.erase(word.begin());
            if (word.size() > 0)
                child->insert(word);

            return;
        };
    };


    PrefixTree* new_child = new PrefixTree(word[0]);
    this->children.push_back(new_child);

    word.erase(word.begin());
    if (word.size() > 0) {
        this->children.back()->insert(word);
    };

    return;
};


void PrefixTree::preorder_traversal() {
    std::cout << this->c << ' ';

    for (PrefixTree* child: this->children)
            child->preorder_traversal();

    return;
};


int main() {
    PrefixTree* head = new PrefixTree();

    head->insert("trigonometria");
    head->insert("triotlon");

    head->preorder_traversal();


    return 0;
};
