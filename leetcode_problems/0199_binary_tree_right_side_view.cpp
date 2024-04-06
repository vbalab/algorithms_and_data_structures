#include <vector>
#include <iostream>


class Node {
public:
    int val;

    Node* left;
    Node* right;

    Node () {};

    Node (int val) {
        this->val = val;
    };
};


class Solution {
public:
    std::vector<int> rightSideView(Node* root) {
        if (!root)
            return { };


        std::vector<int> values;
        std::vector<Node*> nodes = { root };
        std::vector<Node*> new_nodes;


        while (nodes.size() > 0) {
            values.push_back(nodes.back()->val);

            new_nodes.clear();
            for (const Node* node: nodes) {
                if (node->left)
                    new_nodes.push_back(node->left);
                if (node->right)
                    new_nodes.push_back(node->right);
            };

            nodes = new_nodes;
        };

        return values;
    };
};


int main() {
    return 0;  
};