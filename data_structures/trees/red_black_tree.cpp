#include <iostream>


/*
RBT tree - self-balancing BST satisfying:
1 - The root is black.
2 - Every NIL (i.e. leafs - NULL nodes) is black.
3 - The children of a red node are black.
4 - All the leaves have the same black depth.
5 - Every simple path from root to descendant leaf node contains same number of black nodes.


3 & 4 => R-B tree of height h has black-height >= h/2. 


AVL trees are more balanced, but they need more rotations for insertion & deletion.
*/


class RBNode {
private:
    
public:
    int val;
    bool black = true;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode() {};

    RBNode(int val, bool black, RBNode* parent) {
        this->val = val;
        this->black = black;
        this->parent = parent;
    };

    RBNode* uncle();

    RBNode* bst_insert(int val);

    void insert(int val);           // consists of 2 parts: recoloring & rotation
};


RBNode* RBNode::uncle() {
    if (this->parent == nullptr)
        return nullptr;
    else {
        if (this->parent->parent == nullptr)
            return nullptr;
        else {
            if (this->parent->parent->left == this->parent)
                return this->parent->parent->right;
            else
                return this->parent->parent->left;
        }
    };
};


RBNode* RBNode::bst_insert(int val) {
    if (this == nullptr) {
        RBNode* tmp = new RBNode(val, false, this->parent);
        return tmp;
    };

    if (val < this->val)
        this->left = this->left->bst_insert(val);
    else if (val > this->val)
        this->right = this->right->bst_insert(val);
    
    return this;
};


// void RBNode::insert(int val) {
//     RBNode* inserted = this->bst_insert(val);

//     RBNode* tmp = inserted;
//     while (!tmp->parent->black  tmp->uncle() && !tmp->uncle()->black) {
//         tmp->parent->black = true;
//         tmp->uncle()->black = true;
//         tmp->parent->parent->black = false;

//         tmp = tmp->parent->parent;
//     };
// };


int main() {
    RBNode* root = new RBNode(50, true, nullptr);


    return 0;
};
