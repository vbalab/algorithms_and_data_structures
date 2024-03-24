#include<iostream>
#include<vector>


// Generic Trees == N-ary Trees

// bad approaches for implementation: array, linkedList


// better - dynamic array
class NodeDynamic {
public:
    int data;
    std::vector<NodeDynamic*> children;


    NodeDynamic() {};

    NodeDynamic(int data) {
        this->data = data;
    };
};


// best - first child / next sibling
class NodeSibling {
public:
    int data;
    NodeSibling* first_child;
    NodeSibling* sibling;


    NodeSibling(int data) {
        this->data = data;
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

    std::cout << d_root->children[1]->children[0]->data << '\n';


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

    std::cout << s_root->sibling->sibling->first_child->data << '\n';


    return 0;
};

// QUESTION: how after the scope of function linkedlist remembers the tmp pointer that should've been deleted
