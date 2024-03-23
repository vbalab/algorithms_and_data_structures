#include <vector>
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


void inorder_traversal(Node* node) {
    if (node != nullptr) {
        inorder_traversal(node->left);

        std::cout << node->data << ' ';

        inorder_traversal(node->right);
    };
};


void preorder_traversal(Node* node) {
    if (node != nullptr) {
        std::cout << node->data << ' ';

        preorder_traversal(node->left);
        preorder_traversal(node->right);
    };
};


void postorder_traversal(Node* node) {
    if (node != nullptr) {
        postorder_traversal(node->left);
        postorder_traversal(node->right);

        std::cout << node->data << ' ';
    };
};


int height(Node* node) {
    if (node == nullptr)
        return 0;

    return 1 + std::max(height(node->left), height(node->right));
};


int n_sum(int n) {
    int sum = 0;

    while (n != 0)
        sum += n--;

    return sum;
};


int max_of_tree(Node* node) {
    while (node->right != nullptr)
        node = node->right;
    
    return node->data;
};


void print_tree(std::vector<Node*> level_nodes, int height, int lenght_of_num) {
    if (height == 0)
        return;


    int spaces_between = n_sum(height) + lenght_of_num;
    std::vector<Node*> next_level_nodes;


    for (int i = 0; i < level_nodes.size() & level_nodes.size() > 1; i++) {
        std::cout.width(spaces_between);

        if (i % 2)
            std::cout << '\\';
        else
            std::cout << "/";
    };
    std::cout << '\n';


    for (const Node* node: level_nodes) {
        std::cout.width(spaces_between);

        if (node == nullptr) {
            std::cout << '-';

            next_level_nodes.push_back(nullptr);
            next_level_nodes.push_back(nullptr);
        }
        else {
            std::cout << node->data;

            next_level_nodes.push_back(node->left);
            next_level_nodes.push_back(node->right);
        };
    };
    std::cout << '\n';


    print_tree(next_level_nodes, --height, lenght_of_num);
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


    std::cout << "Inorder traversal: ";
    inorder_traversal(root);
    std::cout << '\n';

    std::cout << "Preorder traversal: ";
    preorder_traversal(root);
    std::cout << '\n';

    std::cout << "Postorder traversal: ";
    postorder_traversal(root);
    std::cout << '\n';


    std::cout << "Height: " << height(root) << '\n';
    std::cout << "Max value: " << max_of_tree(root) << '\n';

    std::cout << "Level traversal:";
    print_tree({root}, height(root), 2);


    std::cout << "Min value: " << min_value_node(root)->data << '\n';

    std::cout << "Address of 35: " << search_node_by_data(root, 35) << '\n';

    // delete_node_by_data(root, 25);
    // delete_node_by_data(root, 35);
    // delete_node_by_data(root, 10);
    // print_tree({root}, height(root), 2);


    return 0;
};
