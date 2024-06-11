#include <vector>
#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long min_value = -__LONG_LONG_MAX__ - 1;
        long long max_value = __LONG_LONG_MAX__;

        return isValidBST_(root, min_value, max_value);
    };


    bool isValidBST_(TreeNode* root, long long min_value, long long max_value) {
        if (root == nullptr)
            return true;


        bool left = true;
        bool right = true;


        if (root->left != nullptr) {
            long long cur_max_value = std::min(static_cast<long long>(root->val), max_value);

            if (min_value < root->left->val && cur_max_value > root->left->val)
                left = isValidBST_(root->left, min_value, cur_max_value);         
            else
                left = false;
        };


        if (left && root->right != nullptr) {
            min_value = std::max(static_cast<long long>(root->val), min_value);

            if (min_value < root->right->val && max_value > root->right->val)
                right = isValidBST_(root->right, min_value, max_value);
            else
                right = false;
        };


        return (left && right);
    };
};


int main() {
    Solution s;
    TreeNode* root = new TreeNode(-2147483648);
    // root->left = new TreeNode(1);
    root->right = new TreeNode(2147483647);

    s.isValidBST(root);

    return 0;
};
