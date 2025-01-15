#include <iostream>

struct TreeNode {
    int32_t val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int32_t x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int32_t x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int32_t val) {
        if (root->val == val) {
            return root;
        }

        while (root) {
            if (root->left) {
                TreeNode* left = searchBST(root->left, val);
                if (left) {
                    return left;
                }
            }

            root = root->right;
            if (root && root->val == val) {
                return root;
            };
        }

        return nullptr;
    }
};
