#include <iostream>
#include <vector>
#include <queue>

// Generic Trees == N-ary Trees

// bad approaches for implementation: array, linkedList


// better - dynamic array
class NodeDynamic {
public:
    int val;
    std::vector<NodeDynamic*> children;


    NodeDynamic() {};

    NodeDynamic(int val) {
        this->val = val;
    };


    void insert(int val);
    void preorder_traversal();
};


void NodeDynamic::insert(int val) {
    std::queue<NodeDynamic*> nodes;
    nodes.push(this);


    while (nodes.size() > 0) {
        if (nodes.front()->children.size() == 0)
            nodes.front()->children = { nullptr, nullptr };


        for (int i = 0; i < nodes.front()->children.size(); i++) {
            if (nodes.front()->children[i] == nullptr) {
                nodes.front()->children[i] = new NodeDynamic(val);
                return;
            };

            nodes.push(nodes.front()->children[i]);
        };

        nodes.pop();
    };
};


void NodeDynamic::preorder_traversal() {
    std::cout << this->val << ' ';

    for (NodeDynamic* child: this->children) {
        if (child != nullptr)
            child->preorder_traversal();
    };
};


// best - first child / next sibling
class NodeSibling {
public:
    int val;
    NodeSibling* first_child;
    NodeSibling* sibling;


    NodeSibling(int val) {
        this->val = val;
    };
};


int main() {
    // Dynamic array
    NodeDynamic* d_root = new NodeDynamic(0);
    NodeDynamic* d_child_1 = new NodeDynamic(1);
    NodeDynamic* d_child_2 = new NodeDynamic(2);
    NodeDynamic* d_child_2_1 = new NodeDynamic(3);

    d_root->children = { d_child_1, d_child_2 };
    d_child_2->children = { d_child_2_1 };

    d_root->insert(4);
    d_root->insert(5);

    d_root->preorder_traversal();
    std::cout << '\n';

    std::cout << d_root->children[1]->children[0]->val << '\n';


    // First child / Next sibling
    NodeSibling* s_root = new NodeSibling(0);
    NodeSibling* s_child_1 = new NodeSibling(1);
    NodeSibling* s_sibling_1 = new NodeSibling(2);
    NodeSibling* s_sibling_2 = new NodeSibling(3);
    NodeSibling* s_child_of_sibling = new NodeSibling(4);

    s_root->first_child = s_child_1;
    s_root->sibling = s_sibling_1;
    s_sibling_1->sibling = s_sibling_2;
    s_sibling_2->first_child = s_child_of_sibling;

    std::cout << s_root->sibling->sibling->first_child->val << '\n';


    return 0;
};
