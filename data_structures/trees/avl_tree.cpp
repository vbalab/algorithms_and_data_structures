#include <vector>
#include <iostream>


/* 
AVL tree - self-balancing BST with difference between heights of left and right subtrees for any node cannot be more than one.

balance factor (of the node) - the difference between the heights for any node.

B-tree ~ N-ary AVL-tree.
*/


class AVLNode {
private:

    int n_sum(int n);

    int get_balance();

    AVLNode* bst_insert(int data);

    void print_nodes(std::vector<AVLNode*> level_nodes, int height, int lenght_of_num);


public:
    int data;
    AVLNode* left;
    AVLNode* right;

    AVLNode() {};

    AVLNode(int v) {
        this->data = v;
    };


    int height();

    AVLNode* insert(int data);

    AVLNode* left_rotate();

    AVLNode* right_rotate();

    AVLNode* rebalance();

    void print_tree();
};


int AVLNode::n_sum(int n) {
    int sum = 0;

    while (n != 0)
        sum += n--;

    return sum;
};


void AVLNode::print_nodes(std::vector<AVLNode*> level_nodes, int height, int lenght_of_num) {
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


    print_nodes(next_level_nodes, --height, lenght_of_num);
};


void AVLNode::print_tree() {
    print_nodes({ this }, this->height(), 2);

    return;
};


int AVLNode::height() {
    if (this == nullptr)
        return 0;
    
    return std::max(this->left->height(), this->right->height()) + 1;
};


int AVLNode::get_balance() {
    if (this == nullptr)
        return 0;

    return this->left->height() - this->right->height();
};


AVLNode* AVLNode::left_rotate() {
    AVLNode* tmp = this->right;

    this->right = this->right->left;
    tmp->left = this;

    return tmp;
};


AVLNode* AVLNode::right_rotate() {
    AVLNode* tmp = this->left;

    this->left = this->left->right;
    tmp->right = this;

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


AVLNode* AVLNode::rebalance() {
    if (this->height() <= 1)
        return this;


    AVLNode* node = this;


    node->left = this->left->rebalance();
    node->right = this->right->rebalance();


    while (node->get_balance() < -1 || node->get_balance() > 1) {
        std::cout << "BEFORE:\n";
        node->print_tree();

        if (node->get_balance() < -1) {
            if (node->right->get_balance() == 1)
                node->right = node->right->right_rotate();
            node = node->left_rotate();

        }
        else {
            if (node->left->get_balance() == 1)
                node->left = node->left->left_rotate();
            node = node->right_rotate();
        };

        std::cout << "AFTER:\n";
        node->print_tree();
    };


    return node;
};


AVLNode* AVLNode::insert(int data) {
    this->bst_insert(data);

    AVLNode* node = this->rebalance();

    return node;
    // return this;
};



int main() {
    AVLNode* root = new AVLNode(0);

    int nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };    
    for (const int num: nums)
        root = root->insert(num);

    root->print_tree();


    root = root->left_rotate();
    root->print_tree();


    root = root->right_rotate();
    root->print_tree();


    return 0;
};
