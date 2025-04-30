#include <algorithm>
#include <cstdint>

struct TreeNode {
    int32_t val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    int32_t longestZigZag(TreeNode* root) {  // NOLINT
        return std::max(LeftZigZag(root->left, 0), RightZigZag(root->right, 0));
    }

    static int32_t LeftZigZag(TreeNode* root, int32_t length) {
        if (root == nullptr) {
            return length;
        }

        return std::max(RightZigZag(root->right, length + 1),
                        LeftZigZag(root->left, 0));
    }

    static int32_t RightZigZag(TreeNode* root, int32_t length) {
        if (root == nullptr) {
            return length;
        }

        return std::max(LeftZigZag(root->left, length + 1),
                        RightZigZag(root->right, 0));
    }
};
