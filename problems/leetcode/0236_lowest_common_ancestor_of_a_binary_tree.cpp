#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode*& root, TreeNode*& p, TreeNode*& q) {
        if (!root || root->val == p->val || root->val == q->val)
            return root;


        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);


        if (!left)
            return right;
        if (!right)
            return left;
        return root;
    }
};


int main() {
    return 0;
}
