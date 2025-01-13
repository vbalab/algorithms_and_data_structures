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
    int32_t pathSum(TreeNode* root, int64_t targetSum) {
        if (!root) {
            return 0;
        }

        int32_t count = pathSumCount(root, targetSum);

        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }

    int32_t pathSumCount(TreeNode* root, int64_t targetSum) {
        if (!root) {
            return 0;
        }

        int64_t remainder = targetSum - root->val;

        int32_t count = 0;
        if (remainder == 0) {
            count++;
        }

        count += pathSumCount(root->left, remainder);
        count += pathSumCount(root->right, remainder);

        return count;
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->right = new TreeNode(-3);
    root->right->right = new TreeNode(11);

    Solution s;
    std::cout << s.pathSum(root, 8) << std::endl;

    return 0;
}
