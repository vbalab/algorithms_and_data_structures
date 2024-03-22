#include<iostream>
#include<vector>


// bad approaches for implementation: array, linkedList


// better - dynamic array
class Node {
public:
    int data;
    std::vector<Node*> children;


    Node() {};

    Node(int data) {
        this->data = data;
    };
};


// best - 

int main() {
    Node* tree = new Node();
    tree->children
    return 0;
};