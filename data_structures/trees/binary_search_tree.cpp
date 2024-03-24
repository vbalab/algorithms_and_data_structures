#include <string>
#include <iostream>
#include <algorithm>


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


Node* min_value_node(Node*& node) {
    if (node->left == nullptr)
        return node;

    return min_value_node(node->left);
};


Node* max_value_node(Node*& node) {
    if (node->right == nullptr)
        return node;

    return min_value_node(node->right);
};


Node* search_node_by_data(Node* node, int data) {
    while (node->data != data & node != nullptr) {
        if (node->data > data)
            node = node->left;
        else
            node = node->right;
    };

    return node;
};


// void delete_node_by_data(Node*& root, int data) {
//     Node* found = search_node_by_data(root, data);

//     Node* tmp = found;

//     if (tmp->right != nullptr)
//         tmp = min_value_node(tmp->right);
//     else if (tmp->left != nullptr)
//         tmp = max_value_node(tmp->left);      
//     else if (tmp->left != nullptr & tmp->right != nullptr) {
//         Node* parent = ;
//     };

// };


// Node* delete_node_by_data(Node*& node, int data) {
//     if (node == nullptr)    // data not found
//         return node;


//     if (node->data > data)
//         return delete_node_by_data(node->left, data);
//     else if (node->data < data)
//         return delete_node_by_data(node->right, data);
//     else {
//         // one child cases:
//         if (node->left == nullptr & node->right == nullptr) {
//             std::cout << '\n' << node->data << '\n';
//             free(node);
//             return nullptr;
//         }
//         else if (node->left == nullptr) {
//             Node* temp = node->right;
//             free(node);

//             return temp;
//         } 
//         else if (node->right == nullptr) {
//             Node* temp = node->left;
//             free(node);

//             return temp;
//         };


//         Node* temp = min_value_node(node->right);
//         // Node* temp = max_value_node(node->left);

//         node->data = temp->data;

//         // std::cout << min_value_node(node->right)->data;
//         // temp->data = 1000;
//         // temp = nullptr;
//         // free(temp);
//         // delete temp;
//         // std::cout << min_value_node(node->right)->data;

//         // delete_node_by_data(node->right, temp->data);
//         node->right = delete_node_by_data(node->right, temp->data);
//     };

//     return node;
// };


int main() {
    Node* root = new Node(50);


    int nums[10] = { 25, 75, 11, 40, 10, 15, 35, 45, 60, 55 };    
    for (const int num: nums)
        insert(root, num);


    std::cout << "Min value: " << min_value_node(root)->data << '\n';

    std::cout << "Address of 35: " << search_node_by_data(root, 35) << '\n';

    // delete_node_by_data(root, 25);
    // delete_node_by_data(root, 35);
    // delete_node_by_data(root, 10);
    // print_tree({root}, height(root), 2);


    return 0;
};
