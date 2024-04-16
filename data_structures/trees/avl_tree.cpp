#include <vector>
#include <iostream>


/* 
AVL tree - self-balancing BST with difference between heights of left and right subtrees for any node cannot be more than one.

balance factor (of the node) - the difference between the heights for any node.
*/


class AVLNode {
private:

    AVLNode* right_rotate();


public:
    int height();
    AVLNode* left_rotate();
    int data;
    AVLNode* left;
    AVLNode* right;

    AVLNode() {};

    AVLNode(int v) {
        this->data = v;
    };

    AVLNode* bst_insert(int data);

    AVLNode* insert(int data);
};


int AVLNode::height() {
    if (this == nullptr)
        return 0;
    
    return std::max(this->left->height(), this->right->height()) + 1;
};


AVLNode* AVLNode::left_rotate() {
    AVLNode* tmp = this->right;

    this->right = this->right->left;
    tmp->left = this;

    return tmp;
};


AVLNode* AVLNode::bst_insert(int data) {
    if (this == nullptr) {
        AVLNode* tmp = new AVLNode(data);
        return tmp;
    };

    if (data < this->data)
        this->left = this->left->bst_insert(data);
    else if (data > this->data)
        this->right = this->right->bst_insert(data);
    
    return this;
};


AVLNode* AVLNode::insert(int data) {
    this->bst_insert(data);

    // return node;
    return this;
};


int n_sum(int n) {
    int sum = 0;

    while (n != 0)
        sum += n--;

    return sum;
};


void print_tree(std::vector<AVLNode*> level_nodes, int height, int lenght_of_num) {
    if (height == 0)
        return;


    int spaces_between = n_sum(height) + lenght_of_num;
    std::vector<AVLNode*> next_level_nodes;


    for (int i = 0; i < level_nodes.size() & level_nodes.size() > 1; i++) {
        std::cout.width(spaces_between);

        if (i % 2)
            std::cout << '\\';
        else
            std::cout << "/";
    };
    std::cout << '\n';


    for (const AVLNode* node: level_nodes) {
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


int main() {
    AVLNode* root = new AVLNode(40);

    int nums[10] = { 25, 75, 11, 40, 15, 35, 45, 80, 55, 90 };    
    for (const int num: nums)
        root = root->insert(num);

    print_tree({root}, root->height(), 2);
    
    root = root->left_rotate();

    print_tree({root}, root->height(), 2);


    return 0;
};
