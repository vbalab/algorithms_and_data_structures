#include <iostream>


static const int _ = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);

    return 0;
}();


class Node {
public:
    int val;

    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;

        this->left = nullptr;
        this->right = nullptr;
    };
};


class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;

        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    };
};


int main() {
    Node* root = new Node(0);
    root->left = new Node(0);
    root->right = new Node(0);
    root->right->right = new Node(0);
    root->right->right->left = new Node(0);


    Solution solution;
    std::cout << solution.maxDepth(root) << '\n';


    return 0;
};