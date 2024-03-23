#include <iostream>


struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
    };
};


Node* insert(Node* node, int data) {
    if (node == nullptr) {
        Node* tmp = new Node(data);
        return tmp;
    };

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);


    return node;
};


void inorder_traversal(Node* node) {
    if (node != nullptr) {
        inorder_traversal(node->left);

        std::cout << node->data << " ";

        inorder_traversal(node->right);
    };
};


int main() {
    Node* root = new Node(0);


    int nums[10] = { 7, 8, 9, 10, 4, 5, 6, 1, 2, 3 };    
    for (const int num: nums)
        insert(root, num);


    inorder_traversal(root);
    std::cout << '\n';


    return 0;
};
